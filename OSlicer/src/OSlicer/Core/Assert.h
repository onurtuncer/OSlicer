#pragma once

#include "OSlicer/Core/Base.h"
#include "Log.h"

#ifdef OS_PLATFORM_WINDOWS
	#define OS_DEBUG_BREAK __debugbreak()
#elif defined(OS_COMPILER_CLANG)
	#define OS_DEBUG_BREAK __builtin_debugtrap()
#else
	#define OS_DEBUG_BREAK
#endif

#ifdef OS_DEBUG
	#define OS_ENABLE_ASSERTS
#endif

#define OS_ENABLE_VERIFY

#ifdef OS_ENABLE_ASSERTS
	#ifdef OS_COMPILER_CLANG
		#define OS_CORE_ASSERT_MESSAGE_INTERNAL(...)  ::OSlicer::Log::PrintAssertMessage(::Oslicer::Log::Type::Core, "Assertion Failed", ##__VA_ARGS__)
		#define OS_ASSERT_MESSAGE_INTERNAL(...)  ::Oslicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Client, "Assertion Failed", ##__VA_ARGS__)
	#else
		#define OS_CORE_ASSERT_MESSAGE_INTERNAL(...)  ::Oslicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Core, "Assertion Failed" __VA_OPT__(,) __VA_ARGS__)
		#define OS_ASSERT_MESSAGE_INTERNAL(...)  ::Oslicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Client, "Assertion Failed" __VA_OPT__(,) __VA_ARGS__)
	#endif

	#define OS_CORE_ASSERT(condition, ...) { if(!(condition)) { OS_CORE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); OS_DEBUG_BREAK; } }
	#define OS_ASSERT(condition, ...) { if(!(condition)) { OS_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); OS_DEBUG_BREAK; } }
#else
	#define OS_CORE_ASSERT(condition, ...)
	#define OS_ASSERT(condition, ...)
#endif

#ifdef OS_ENABLE_VERIFY
	#ifdef OS_COMPILER_CLANG
		#define OS_CORE_VERIFY_MESSAGE_INTERNAL(...)  ::OSlicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Core, "Verify Failed", ##__VA_ARGS__)
		#define OS_VERIFY_MESSAGE_INTERNAL(...)  ::Oslicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Client, "Verify Failed", ##__VA_ARGS__)
	#else
		#define OS_CORE_VERIFY_MESSAGE_INTERNAL(...)  ::OSlicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Core, "Verify Failed" __VA_OPT__(,) __VA_ARGS__)
		#define OS_VERIFY_MESSAGE_INTERNAL(...)  ::OSlicer::Log::PrintAssertMessage(::OSlicer::Log::Type::Client, "Verify Failed" __VA_OPT__(,) __VA_ARGS__)
	#endif

	#define OS_CORE_VERIFY(condition, ...) { if(!(condition)) { OS_CORE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); OS_DEBUG_BREAK; } }
	#define OS_VERIFY(condition, ...) { if(!(condition)) { OS_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); OS_DEBUG_BREAK; } }
#else
	#define OS_CORE_VERIFY(condition, ...)
	#define OS_VERIFY(condition, ...)
#endif