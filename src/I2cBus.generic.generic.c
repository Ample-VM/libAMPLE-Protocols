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

#include "AMPLE/Protocols/I2c/I2cBus.h"

#include <stddef.h>
#include <stdint.h>

enum AMPLE_Protocols_I2c_I2cBus_GetBusId_ReturnValues AMPLE_Protocols_I2c_I2cBus_GetBusId(
    const struct AMPLE_Protocols_I2c_I2cBus_t *const p_i2cBus,
    uint8_t *const p_busId)
{
    // Guard
    _Bool nullI2cBus = (p_i2cBus == (struct AMPLE_Protocols_I2c_I2cBus_t *const)NULL);
    _Bool nullBusId = (p_busId == (uint8_t *const)NULL);
    _Bool invalidArguments = (nullI2cBus || nullBusId);
    if (invalidArguments)
    {
        return AMPLE_Protocols_I2c_I2cBus_GetBusId_Fail;
    }

    // Logic
    *p_busId = p_i2cBus->_busId;

    // Result
    return AMPLE_Protocols_I2c_I2cBus_GetBusId_Success;
}
