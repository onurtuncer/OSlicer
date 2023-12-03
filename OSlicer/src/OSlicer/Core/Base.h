#pragma once

#include <memory>
#include "Ref.h"

namespace OSlicer {

	void InitializeCore();
	void ShutdownCore();
} // namespace OSlicer

#if !defined(OS_PLATFORM_WINDOWS) && !defined(OS_PLATFORM_LINUX)
	#error Unknown platform.
#endif

#define BIT(x) (1u << x)

#if defined(__clang__)
	#define OS_COMPILER_CLANG
#elif defined(_MSC_VER)
	#define OS_COMPILER_MSVC
#endif

#define OS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#ifdef OS_COMPILER_MSVC
	#define OS_FORCE_INLINE __forceinline
#elif defined(OS_COMPILER_CLANG)
	#define OS_FORCE_INLINE __attribute__((always_inline)) inline
#else
	#define OS_FORCE_INLINE inline
#endif

#include "Assert.h"

namespace OSlicer {

	// Pointer wrappers
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	using byte = uint8_t;

	/** A simple wrapper for std::atomic_flag to avoid confusing
		function names usage. The object owning it can still be
		default copyable, but the copied flag is going to be reset.
	*/
	struct AtomicFlag
	{
		OS_FORCE_INLINE void SetDirty() { flag.clear(); }
		OS_FORCE_INLINE bool CheckAndResetIfDirty() { return !flag.test_and_set(); }

		explicit AtomicFlag() noexcept { flag.test_and_set(); }
		AtomicFlag(const AtomicFlag&) noexcept {}
		AtomicFlag& operator=(const AtomicFlag&) noexcept { return *this; }
		AtomicFlag(AtomicFlag&&) noexcept {};
		AtomicFlag& operator=(AtomicFlag&&) noexcept { return *this; }

	private:
		std::atomic_flag flag;
	};

	struct Flag
	{
		OS_FORCE_INLINE void SetDirty() noexcept { flag = true; }
		OS_FORCE_INLINE bool CheckAndResetIfDirty() noexcept
		{
			if (flag)
				return !(flag = !flag);
			else
				return false;
		}

		OS_FORCE_INLINE bool IsDirty() const noexcept { return flag; }

	private:
		bool flag = false;
	};

}