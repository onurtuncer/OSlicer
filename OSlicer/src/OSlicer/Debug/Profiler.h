#pragma once

#define OS_ENABLE_PROFILING !HZ_DIST

#if OS_ENABLE_PROFILING 
#include <tracy/Tracy.hpp>
#endif

#if OS_ENABLE_PROFILING
#define OS_PROFILE_MARK_FRAME			FrameMark;
#define OS_PROFILE_FUNC(...)			ZoneScoped##__VA_OPT__(N(__VA_ARGS__))
#define OS_PROFILE_SCOPE(...)			OS_PROFILE_FUNC(__VA_ARGS__)
#define OS_PROFILE_SCOPE_DYNAMIC(NAME)  ZoneScoped; ZoneName(NAME, strlen(NAME))
#define OS_PROFILE_THREAD(...)          tracy::SetThreadName(__VA_ARGS__)
#else
#define OS_PROFILE_MARK_FRAME
#define OS_PROFILE_FUNC(...)
#define OS_PROFILE_SCOPE(...)
#define OS_PROFILE_SCOPE_DYNAMIC(NAME)
#define OS_PROFILE_THREAD(...)
#endif