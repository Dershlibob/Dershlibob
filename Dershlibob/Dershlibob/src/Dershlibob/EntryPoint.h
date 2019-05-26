#pragma once

extern DB::Application* DB::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DB::CreateApplication();
	app->Run();
	delete app;
}