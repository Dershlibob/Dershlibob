#pragma once

#ifdef DERSHLIBOB_BUILD_DLL
	#define DERSHLIBOB_API __declspec(dllexport)
#else
	#define DERSHLIBOB_API __declspec(dllimport)
#endif