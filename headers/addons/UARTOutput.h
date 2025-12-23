#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available() override;
    virtual void setup() override;
    virtual void preprocess() override;
    virtual void process() override;
    virtual void postprocess(bool) override; // ここが重要
    virtual void reinit() override;
    virtual std::string name() override { return "UART Output"; }
};

#endif
