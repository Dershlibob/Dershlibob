#include "Dershlibob.h"


class App : public DB::Application
{
public:
	App()
	{

	}
	
	~App()
	{

	}

};

DB::Application* DB::CreateApplication()
{
	return new App();
}