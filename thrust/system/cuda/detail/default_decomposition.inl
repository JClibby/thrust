/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <thrust/detail/config.h>
#include <thrust/system/cuda/detail/arch.h>

namespace thrust
{
namespace system
{
namespace cuda
{
namespace detail
{

template <typename IndexType>
thrust::detail::backend::uniform_decomposition<IndexType> default_decomposition(IndexType n)
{
  // TODO eliminate magical constant
  arch::device_properties_t properties = arch::device_properties();
  return thrust::detail::backend::uniform_decomposition<IndexType>(n, properties.maxThreadsPerBlock, 10 * properties.multiProcessorCount);
}

} // end namespace detail
} // end namespace cuda
} // end namespace system
} // end namespace thrust
