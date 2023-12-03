#pragma once

#include "OSlicer/Core/Application.h"

extern OSlicer::Application* OSlicer::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace OSlicer {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			InitializeCore();
			Application* app = CreateApplication(argc, argv);
			OS_CORE_ASSERT(app, "Client Application is null!");
			app->Run();
			delete app;
			ShutdownCore();
		}
		return 0;
	}

} // namespace OSlicer

#if OS_DIST && OS_PLATFORM_WINDOWS

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return OSlicer::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return OSlicer::Main(argc, argv);
}

#endif // OS_DIST