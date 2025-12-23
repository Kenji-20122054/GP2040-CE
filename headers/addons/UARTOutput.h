#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available() override;
    virtual void setup() override;
    virtual void preprocess() override; // ★これだけが必要でした
    virtual void process() override;
    virtual std::string name() override { return "UART Output"; }
};

#endif
