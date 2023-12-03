#pragma once

#include <string>

namespace OSlicer {

	class Platform{
	public:
		static uint64_t GetCurrentDateTimeU64();
		static std::string GetCurrentDateTimeString();

	};

} // namespace OSlicer