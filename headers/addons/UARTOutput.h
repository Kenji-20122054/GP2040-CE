#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available(); // アドオンが有効かどうか
    virtual void setup();     // 初期化処理（UART設定など）
    virtual void process();   // 毎フレーム実行される処理
    virtual std::string name() { return "UART Output"; }
};

#endif
