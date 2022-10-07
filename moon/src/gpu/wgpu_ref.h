#pragma once

#include "moon/gpu/base.h"

namespace moon::gpu::native {

template <typename T> struct WGPURefCountedTraits {
  static constexpr T *Null = nullptr;
  static void reference(T *value) { value->reference(); }
  static void release(T *value) { value->release(); }
};

template <typename T>
class WGPURef : public zinc::ref_base<T *, WGPURefCountedTraits<T>> {
public:
  using zinc::ref_base<T *, WGPURefCountedTraits<T>>::ref_base;

  virtual void reference() {}
  virtual void release() {}

private:
  virtual void dropping() = 0;
};

template <typename T> auto AcquireWGPURef(T *pointer) -> WGPURef<T> {
  WGPURef<T> ref;
  ref.Acquire(pointer);
  return ref;
}

} // namespace moon::gpu::native