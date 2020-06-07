#pragma once

#include <Arduino.h>


class pletacka_eeprom
{
private:
    struct eepromConfig
    {
        eepromConfig()
        : eepromSize(20) {

        }
        size_t eepromSize; //number of bytes you want to access
    };

    eepromConfig eepromCfg;
    
public:
    void init(pletackaConfig config);
};


