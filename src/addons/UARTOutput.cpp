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

void UARTOutputAddon::preprocess() {
    // 何もしない
}

void UARTOutputAddon::process() {
    Gamepad * gamepad = Storage::getInstance().GetGamepad();
    
    if (uart_is_writable(UART_ID)) {
        uart_putc(UART_ID, 0xFF);
        uart_putc(UART_ID, (gamepad->state.buttons >> 8) & 0xFF);
        uart_putc(UART_ID, gamepad->state.buttons & 0xFF);
        uart_putc(UART_ID, gamepad->state.dpad);
    }
}

// ★以下を追加（コンパイルを通すために必須）★

void UARTOutputAddon::postprocess(bool) {
    // 処理不要
}

void UARTOutputAddon::reinit() {
    // 再初期化処理（今回は初期化と同じことをするか、何もしなくてOK）
    uart_init(UART_ID, BAUD_RATE);
}
