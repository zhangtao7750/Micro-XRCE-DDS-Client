// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef _MICRORTPS_CLIENT_OUTPUT_RELIABLE_STREAM_H_
#define _MICRORTPS_CLIENT_OUTPUT_RELIABLE_STREAM_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct MicroBuffer MicroBuffer;

typedef struct OutputReliableStream
{
    uint8_t* buffer;
    uint8_t* iterator;
    size_t size;
    size_t history;

    uint16_t last_sent;
    uint16_t last_acknown;
    uint16_t nack_bitmap;
    uint32_t next_heartbeat_time_stamp;

} OutputReliableStream;

void init_output_reliable_stream(OutputReliableStream* stream, uint8_t* buffer, size_t size, size_t history, uint8_t offset);
bool prepare_next_reliable_buffer_to_send(OutputReliableStream* stream, uint8_t** buffer, size_t* length, bool* is_fragment);
bool prepare_reliable_stream_to_write(OutputReliableStream* stream, MicroBuffer* mb, int size);

bool output_reliable_stream_must_notify(OutputReliableStream* stream, uint32_t current_timestamp);
bool output_reliable_stream_must_send(OutputReliableStream* stream, uint8_t** buffer, size_t *length);
void process_acknack(OutputReliableStream* stream, uint16_t bitmap, uint16_t first_unacked_seq_num);
int write_heartbeat(OutputReliableStream* stream, MicroBuffer* mb);

#ifdef __cplusplus
}
#endif

#endif // _MICRORTPS_CLIENT_OUTPUT_RELIABLE_STREAM_H_
