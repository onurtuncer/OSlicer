#pragma once

#include <cstdlib>
#include "OSlicer/Core/Ref.h"
#include "OSlicer/Scene/Scene.h"
#include "OSlicer/Project/Project.h"
#include "OSlicer/Core/Events/Event.h"

namespace OSlicer {

	class EditorPanel : public RefCounted
	{
	public:
		virtual ~EditorPanel() = default;

		virtual void OnImGuiRender(bool& isOpen) = 0;
		virtual void OnEvent(Event& e) {}
		virtual void OnProjectChanged(const Ref<Project>& project){}
		virtual void SetSceneContext(const Ref<Scene>& context){}
	};

} // namespace OSlicer