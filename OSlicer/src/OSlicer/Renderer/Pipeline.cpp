#include "hzpch.h"
#include "Pipeline.h"

#include "Renderer.h"
#include "Hazel/Platform/Vulkan/VulkanPipeline.h"
#include "Hazel/Renderer/RendererAPI.h"

namespace OSlicer {

	Ref<Pipeline> Pipeline::Create(const PipelineSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::Vulkan:  return Ref<VulkanPipeline>::Create(spec);
		}
		OS_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}