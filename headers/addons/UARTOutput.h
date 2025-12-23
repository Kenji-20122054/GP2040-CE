#ifndef _UARTOUTPUT_H_
#define _UARTOUTPUT_H_

#include "gpaddon.h"

class UARTOutputAddon : public GPAddon {
public:
    virtual bool available() override;
    virtual void setup() override;
    virtual void process() override;
    virtual void preprocess() override{}
    // name() は削除しました
};

#endif
