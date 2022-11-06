#pragma once

#include "rook/platform/context_handle.h"
#include <InitGuid.h>

#include <directx/d3d12.h>
#include <directx/d3dx12.h>

#include <dxgi1_4.h>
#include <dxgi1_6.h>

#include <wrl.h>
using namespace Microsoft::WRL;

#define ASSERT_SUCCEEDED(hr, ...) (void)(hr)