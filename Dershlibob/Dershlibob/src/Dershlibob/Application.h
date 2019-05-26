#pragma once

#include "core.h"


namespace DB
{
	class DERSHLIBOB_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
		void InitApplication();
		//Window* window;
	private:
		bool bIsRunning = true;
	};

	Application* CreateApplication();
	
}