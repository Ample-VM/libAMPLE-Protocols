// MIT License
// 
// Copyright (c) 2023 Ample VM
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __AMPLE__PROTOCOLS__I2C__I2CBUS__H__
#define __AMPLE__PROTOCOLS__I2C__I2CBUS__H__

#include <stdint.h>

#define AMPLE_PROTOCOLS_I2C_I2CBUS_SUCCESS(Result) (0 <= Result)
#if defined(__linux__) || defined(__FreeBSD__)
    #define AMPLE_PROTOCOLS_I2C_I2CBUS_DEFAULT {    \
        ._initialized = 0,                          \
        ._busId = 0,                                \
        ._fd = -1                                   \
    }
#else
    #define AMPLE_PROTOCOLS_I2C_I2CBUS_DEFAULT {    \
        ._initialized = 0,                          \
        ._busId = 0                                 \
    }
#endif

struct AMPLE_Protocols_I2c_I2cBus_t
{
    _Bool _initialized;
    const uint8_t _busId;
#if defined(__linux__) || defined(__FreeBSD__)
    int _fd;
#endif
};

enum AMPLE_Protocols_I2c_I2cBus_Create_ReturnValues
{
    AMPLE_Protocols_I2c_I2cBus_Create_Fail = -1,
    AMPLE_Protocols_I2c_I2cBus_Create_Success = 0
};

enum AMPLE_Protocols_I2c_I2cBus_Duplicate_ReturnValues
{
    AMPLE_Protocols_I2c_I2cBus_Duplicate_Fail = -1,
    AMPLE_Protocols_I2c_I2cBus_Duplicate_Success = 0
};

enum AMPLE_Protocols_I2c_I2cBus_GetBusId_ReturnValues
{
    AMPLE_Protocols_I2c_I2cBus_GetBusId_Fail = -1,
    AMPLE_Protocols_I2c_I2cBus_GetBusId_Success = 0
};

enum AMPLE_Protocols_I2c_I2cBus_Create_ReturnValues AMPLE_Protocols_I2c_I2cBus_Create(
    struct AMPLE_Protocols_I2c_I2cBus_t *const p_i2cBus,
    const uint8_t busId);

enum AMPLE_Protocols_I2c_I2cBus_Duplicate_ReturnValues AMPLE_Protocols_I2c_I2cBus_Duplicate(
    struct AMPLE_Protocols_I2c_I2cBus_t *const p_i2cBus,
    const struct AMPLE_Protocols_I2c_I2cBus_t *const p_object);

enum AMPLE_Protocols_I2c_I2cBus_GetBusId_ReturnValues AMPLE_Protocols_I2c_I2cBus_GetBusId(
    const struct AMPLE_Protocols_I2c_I2cBus_t *const p_i2cBus,
    uint8_t *const p_busId);

void AMPLE_Protocols_I2c_I2cBus_Destroy(struct AMPLE_Protocols_I2c_I2cBus_t *const p_i2cBus);

#endif//__AMPLE__PROTOCOLS__I2C__I2CBUS__H__
