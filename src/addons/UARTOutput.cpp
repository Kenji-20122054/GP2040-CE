#include "addons/UARTOutput.h"
#include "storagemanager.h"
#include "gamepad.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"

// 設定: 使うUARTチャンネルとピン、ボーレート
#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0  // GP0
#define UART_RX_PIN 1  // GP1

bool UARTOutputAddon::available() {
    // 常に有効にする
    return true;
}

void UARTOutputAddon::setup() {
    // UARTの初期化
    uart_init(UART_ID, BAUD_RATE);
    
    // GPIOピンをUART機能に割り当て
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

// ★ここが不足していた関数です
void UARTOutputAddon::preprocess() {
    // 前処理は不要なので何もしない
}

void UARTOutputAddon::process() {
    // 現在のゲームパッドの状態を取得
    Gamepad * gamepad = Storage::getInstance().GetGamepad();
    
    // ボタンの状態（ビットマスク）を取得
    uint16_t buttonState = gamepad->state.buttons;
    uint8_t dpadState = gamepad->state.dpad;

    // バイナリで送る
    // ヘッダ(0xFF) + ボタン上位バイト + ボタン下位バイト + 方向キー
    if (uart_is_writable(UART_ID)) {
        uart_putc(UART_ID, 0xFF); // 同期用ヘッダ
        uart_putc(UART_ID, (buttonState >> 8) & 0xFF);
        uart_putc(UART_ID, buttonState & 0xFF);
        uart_putc(UART_ID, dpadState);
    }
}
