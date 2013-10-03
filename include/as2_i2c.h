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
#ifndef AS2_I2C_H
#define AS2_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#define AS2_SUCCESS     0
#define AS2_ERR_NULLPTR 1

typedef void* as2_i2c_t;
uint8_t as2_i2c_begin_tx(as2_i2c_t i2c, uint8_t address);
uint8_t as2_i2c_end_tx(as2_i2c_t i2c);
uint8_t as2_i2c_write(as2_i2c_t i2c, uint8_t *data, uint8_t length);

uint8_t as2_i2c_request_from(as2_i2c_t i2c, uint8_t address, uint16_t length);
uint8_t as2_i2c_read(as2_i2c_t i2c, uint8_t *out, uint8_t length);

#ifdef __cplusplus
}
#endif

#endif // ARDUSAT2_I2C_H
