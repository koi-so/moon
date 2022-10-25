#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
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
  zinc::string name;
  ShaderKind eind;
  u32 payload_size;
  u32 attribute_size;
};

struct InputParameterDesc {
  u32 location;
  zinc::string semantic_name;
  Format format;
};

struct OutputParameterDesc {
  u32 slot;
};

enum class VariableType {
  eStruct,
  eFloat,
  eInt,
  eUint,
  eBool,
};

struct VariableLayout {
  zinc::string name;
  VariableType type;
  u32 offset;
  u32 size;
  u32 rows;
  u32 columns;
  u32 elements;
  zinc::vector<VariableLayout> members;
};

struct ShaderFeatureInfo {
  bool resource_descriptor_heap_indexing = false;
  bool sampler_descriptor_heap_indexing = false;
  u32 numthreads[3] = {};
};

class ShaderReflection : public zinc::interface {
public:
  virtual ~ShaderReflection() = default;
  virtual auto get_entry_points() const -> const zinc::vector<EntryPoint> & = 0;
  virtual auto get_bindings() const
      -> const zinc::vector<ResourceBindingDescriptor> & = 0;
  virtual auto get_variable_layouts() const
      -> const zinc::vector<VariableLayout> & = 0;
  virtual auto get_input_parameters() const
      -> const zinc::vector<InputParameterDesc> & = 0;
  virtual auto get_output_parameters() const
      -> const zinc::vector<OutputParameterDesc> & = 0;
  virtual auto get_shader_feature_info() const -> const ShaderFeatureInfo & = 0;
};
} // namespace moon::gpu