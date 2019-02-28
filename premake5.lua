workspace "DuggooEngine"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "DuggooEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "DuggooEngine/vendor/Glad/include"
IncludeDir["glm"] = "DuggooEngine/vendor/glm"

include "DuggooEngine/vendor/GLFW"
include "DuggooEngine/vendor/Glad"

project "DuggooEngine"
	location	"DuggooEngine"
	kind		"SharedLib"
	language	"C++"
	
	targetdir	("bin/" .. outputdir .. "/%{prj.name}")
	objdir		("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DG_PLATFORM_WINDOWS",
			"DG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "DG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DG_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location	"Sandbox"
	kind		"ConsoleApp"
	language	"C++"

	targetdir	("bin/" .. outputdir .. "/%{prj.name}")
	objdir		("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DuggooEngine/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"DuggooEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			
		}
		
	filter "configurations:Debug"
		defines "DG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DG_DIST"
		buildoptions "/MD"
		optimize "On"