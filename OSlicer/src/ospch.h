#pragma once

#ifdef OS_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <memory>
#include <random>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <filesystem>

#include <OSlicer/Core/Assert.h>
#include <OSlicer/Core/Base.h>
#include <OSlicer/Core/Events/Event.h>
#include <OSlicer/Core/Log.h>
#include <OSlicer/Core/Math/Mat4.h>
#include <OSlicer/Core/Memory.h>
#include <OSlicer/Core/Delegate.h>

/* // Jolt (Safety because this file has to be included before all other Jolt headers, at all times)
#ifdef OS_DEBUG // NOTE(Emily): This is a bit of a hacky fix for some dark magic that happens in Jolt
				// 				We'll need to address this in future.
#define JPH_ENABLE_ASSERTS
#endif
#include <Jolt/Jolt.h> */