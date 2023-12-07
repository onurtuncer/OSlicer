#pragma once

#include "OSlicer/Core/Ref.h"

struct GLFWwindow;

namespace OSlicer {

	class RendererContext : public RefCounted
	{
	public:
		RendererContext() = default;
		virtual ~RendererContext() = default;

		virtual void Init() = 0;

		static Ref<RendererContext> Create();
	};

}