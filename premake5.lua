workspace "DuggooEngine"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "DG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DG_DIST"
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
		"DuggooEngine/src"
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
		symbols "On"

	filter "configurations:Release"
		defines "DG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DG_DIST"
		optimize "On"