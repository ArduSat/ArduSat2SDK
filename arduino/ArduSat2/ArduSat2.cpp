/**
 * ArduSat2 SDK
 * Copyright (c) 2013 NanoSatisfi, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <Arduino.h>
#include <Wire.h>

#include "ArduSat.h"

// ArduSat2 I2C backend - Arduino implementation

as2_i2c_t as2_i2c_handle = (as2_i2c_t) &Wire;

uint8_t as2_i2c_begin_tx(as2_i2c_t i2c, uint8_t address) {
    Wire *wire = (Wire *) i2c;
    if (!wire) {
        return AS2_ERR_NULLPTR;
    }

    wire->beginTransmission(address);
    return AS2_SUCCESS;
}

uint8_t as2_i2c_end_tx(as2_i2c_t i2c) {
    Wire *wire = (Wire *) i2c;
    if (!wire) {
        return 0;
    }

    return wire->endTransmission();
}

uint8_t as2_i2c_write(as2_i2c_t i2c, uint8_t *data, uint8_t length) {
    Wire *wire = (Wire *) i2c;
    if (!wire) {
        return 0;
    }

    return wire->write(const_cast<const uint8_t *>(data),
                       static_cast<size_t>(length));
}

uint8_t as2_i2c_request_from(as2_i2c_t i2c, uint8_t address, uint16_t length) {
    Wire *wire = (Wire *) i2c;
    if (!wire) {
        return 0;
    }

    return wire->requestFrom(address, length);
}

uint8_t as2_i2c_read(as2_i2c_t i2c, uint8_t *out, uint8_t length) {
    if (!i2c || !out) {
        return AS2_ERR_NULLPTR;
    }

    uint8_t count = 0;
    Wire *wire = (Wire *) i2c;
    for (; count < length; count++, out++) {
        int byte = wire->read();
        if (byte == -1) {
            return count;
        }
        *out = (uint8_t) byte;
    }

    return count;
}
