// Copyright 2024 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_GEMMA_CPP_GEMMA_BACKWARD_H_
#define THIRD_PARTY_GEMMA_CPP_GEMMA_BACKWARD_H_

#include "backprop/prompt.h"
#include "gemma/activations.h"
#include "gemma/common.h"
#include "hwy/contrib/thread_pool/thread_pool.h"

namespace gcpp {

void CrossEntropyLossBackwardPass(const Model& model, const Prompt& prompt,
                                  const ByteStorageT& weights,
                                  const ByteStorageT& forward,
                                  ByteStorageT& grad, ByteStorageT& backward,
                                  RowVectorBatch<float>& inv_timescale,
                                  hwy::ThreadPool& pool);

}  // namespace gcpp

#endif  // THIRD_PARTY_GEMMA_CPP_GEMMA_BACKWARD_H_
