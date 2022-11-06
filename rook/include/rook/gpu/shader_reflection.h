#pragma once

#include "rook/base.h"

#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>
#include <EASTL/vector.h>

namespace rook::gpu {
enum class ShaderKind {
  eUnknown = 0,
  ePixel,
  eVertex,
  eGeometry,
  eCompute,
  eLibrary,
  eRayGeneration,
  eIntersection,
  eAnyHit,
  eClosestHit,
  eMiss,
  eCallable,
  eMesh,
  eAmplification,
};

struct EntryPoint {
  eastl::string name;
  ShaderKind eind;
  uint32_t payload_size;
  uint32_t attribute_size;
};

struct InputParameterDescriptor {
  uint32_t location;
  eastl::string semantic_name;
  Format format;
};

struct OutputParameterDescriptor {
  uint32_t slot;
};

enum class VariableType {
  eStruct,
  eFloat,
  eInt,
  eUint,
  eBool,
};

struct VariableLayout {
  eastl::string name;
  VariableType type;
  uint32_t offset;
  uint32_t size;
  uint32_t rows;
  uint32_t columns;
  uint32_t elements;
  eastl::vector<VariableLayout> members;
};

struct ShaderFeatureInfo {
  bool resource_descriptor_heap_indexing = false;
  bool sampler_descriptor_heap_indexing = false;
  uint32_t numthreads[3] = {};
};

class ShaderReflection : public interface {
public:
  ~ShaderReflection() override = default;
  [[nodiscard]] virtual auto get_entry_points() const
      -> eastl::vector<EntryPoint> const & = 0;
  [[nodiscard]] virtual auto get_bindings() const
      -> eastl::vector<ResourceBindingDescriptor> const & = 0;
  [[nodiscard]] virtual auto get_variable_layouts() const
      -> eastl::vector<VariableLayout> const & = 0;
  [[nodiscard]] virtual auto get_input_parameters() const
      -> eastl::vector<InputParameterDescriptor> const & = 0;
  [[nodiscard]] virtual auto get_output_parameters() const
      -> eastl::vector<OutputParameterDescriptor> const & = 0;
  [[nodiscard]] virtual auto get_shader_feature_info() const
      -> ShaderFeatureInfo const & = 0;
};
} // namespace rook::gpu