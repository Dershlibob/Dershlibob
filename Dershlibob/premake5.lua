workspace "Dershlibob"
	architecture "x86"
	startproject "Application"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
IncludeDir = {}
IncludeDir["GLFW"] = "Dershlibob/vendor/GLFW/include"
IncludeDir["GLAD"] = "Dershlibob/vendor/GLAD/include"
IncludeDir["glm"] = "Dershlibob/vendor/glm"
IncludeDir["stb_image"] = "Dershlibob/vendor/stb_image"
IncludeDir["resources"] = "Dershlibob/res"


include "Dershlibob/vendor/GLFW"
include "Dershlibob/vendor/GLAD"

project "Dershlibob"
	location "Dershlibob"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/stb_image/stb_image.h",
		"%{prj.name}/vendor/stb_image/stb_image.cpp",
		"%{prj.name}/res/**.shader",
		"%{prj.name}/res/**.jpg",
		"%{prj.name}/res/**.png",
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.resources}"
	}
	
	links
	{
		"GLFW",
		"GLAD"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"DB_PLATFORM_WINDOWS",
			"DERSHLIBOB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		filter "configurations:Debug"
		defines "DB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DB_RELEASE"
		runtime "Release"
		optimize "on"
	
		filter "configurations:Dist"
		defines "DB_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
		
	includedirs
	{
		"Dershlibob/src"
	}
	
	links
	{
		"Dershlibob"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		filter "configurations:Debug"
		defines "DB_DEBUG"
		runtime "Debug"
		symbols "on"

		filter "configurations:Release"
		defines "DB_RELEASE"
		runtime "Release"
		optimize "on"

		filter "configurations:Dist"
		defines "DB_DIST"
		runtime "Release"
		optimize "on"
		