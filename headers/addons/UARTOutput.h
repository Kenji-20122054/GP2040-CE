#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available();
    virtual void setup();
    virtual void preprocess(); // ★この1行を追加してください
    virtual void process();
    virtual std::string name() { return "UART Output"; }
};

#endif
