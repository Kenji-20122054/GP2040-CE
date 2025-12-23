#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"
#include <string>

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available();
    virtual void setup();
    virtual void preprocess();
    virtual void process();

    // ★ログで指摘されていた不足関数 1 (引数の bool が重要)
    virtual void postprocess(bool);

    // ★ログで指摘されていた不足関数 2
    virtual void reinit();

    // ★ログで指摘されていた不足関数 3 (ここで中身も実装します)
    virtual std::string name() { return "UART Output"; }
};

#endif
