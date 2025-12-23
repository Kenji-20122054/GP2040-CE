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
    return true;
}

void UARTOutputAddon::setup() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

// ★この関数が不足していたためエラーになっていました
void UARTOutputAddon::preprocess() {
    // 何もしなくてOKですが、定義だけは必須です
}

void UARTOutputAddon::process() {
    Gamepad * gamepad = Storage::getInstance().GetGamepad();
    
    // ボタン入力を取得
    uint16_t buttonState = gamepad->state.buttons;
    uint8_t dpadState = gamepad->state.dpad;

    // UART送信 (ヘッダ0xFF + データ)
    if (uart_is_writable(UART_ID)) {
        uart_putc(UART_ID, 0xFF);
        uart_putc(UART_ID, (buttonState >> 8) & 0xFF);
        uart_putc(UART_ID, buttonState & 0xFF);
        uart_putc(UART_ID, dpadState);
    }
}
