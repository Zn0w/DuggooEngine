workspace "DuggooEngine"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DuggooEngine"
	location "DuggooEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("obj/" .. output_dir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"dependencies/GLFW/include"
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
			("{COPY} %{cfg.buildtarget.relpath}" .. "/bin" .. output_dir .. "/Sandbox")
		}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. output_dir .. "/%{prj.name}")
	objdir ("obj/" .. output_dir .. "/%{prj.name}")

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

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath}" .. "/bin" .. output_dir .. "/Sandbox")
		}