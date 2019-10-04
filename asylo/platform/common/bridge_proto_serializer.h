/*
 *
 * Copyright 2017 Asylo authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef ASYLO_PLATFORM_COMMON_BRIDGE_PROTO_SERIALIZER_H_
#define ASYLO_PLATFORM_COMMON_BRIDGE_PROTO_SERIALIZER_H_

#include <ifaddrs.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/inotify.h>

#include <cstddef>
#include <queue>
#include <string>

#include "absl/strings/string_view.h"
#include "asylo/platform/common/bridge_proto_types.pb.h"

// This file provides a set of type definitions used both inside and outside the
// enclave.

namespace asylo {

constexpr int kIn6AddrNumBytes = 16;

bool SerializeInotifyEvents(char *buf, size_t buf_len, char **out, size_t *len);

bool DeserializeInotifyEvents(absl::string_view in,
                              std::queue<struct inotify_event *> *events);

}  // namespace asylo

#endif  // ASYLO_PLATFORM_COMMON_BRIDGE_PROTO_SERIALIZER_H_
