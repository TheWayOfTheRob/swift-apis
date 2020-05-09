/*
 * Copyright 2020 TensorFlow Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>

#include "absl/types/span.h"
#include "tensorflow/compiler/tf2xla/xla_tensor/ir.h"
#include "tensorflow/compiler/xla/xla_client/device.h"

namespace swift_xla {
namespace ir {

class DumpUtil {
 public:
  static std::string ToDot(absl::Span<const Node* const> nodes);

  static std::string PostOrderToDot(absl::Span<const Node* const> post_order,
                                    absl::Span<const Node* const> roots);

  static std::string ToText(absl::Span<const Node* const> nodes);

  static std::string PostOrderToText(absl::Span<const Node* const> post_order,
                                     absl::Span<const Node* const> roots);

  static std::string ToHlo(absl::Span<const Value> values,
                           const Device& device);

  static std::string GetGraphChangeLog(absl::Span<const Node* const> roots);
};

}  // namespace ir
}  // namespace swift_xla
