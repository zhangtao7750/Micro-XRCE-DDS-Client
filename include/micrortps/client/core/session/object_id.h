// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MICRORTPS_CLIENT_CORE_SESSION_OBJECT_ID_H_
#define _MICRORTPS_CLIENT_CORE_SESSION_OBJECT_ID_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct ObjectId
{
    uint16_t id;
    uint8_t prefix;

} ObjectId;

#ifdef __cplusplus
}
#endif

#endif //_MICRORTPS_CLIENT_CORE_SESSION_OBJECT_ID_H_
