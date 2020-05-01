workspace "Artem"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug", 
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include Dir Table/Struct
IncludeDir = {}
IncludeDir["spdlog"] = "Artem/vendor/spdlog/include"
IncludeDir["GLFW"] = "Artem/vendor/GLFW/include"
IncludeDir["Glad"] = "Artem/vendor/Glad/include"
IncludeDir["ImGui"] = "Artem/vendor/ImGui"
IncludeDir["glm"] = "Artem/vendor/glm"

group "Dependencies"
    include "Artem/vendor/GLFW"
    include "Artem/vendor/Glad"
    include "Artem/vendor/ImGui"
group ""

project "Artem"
    location "Artem"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("obj/"..outputdir.."/%{prj.name}")

    pchheader "atpch.h"
    pchsource "%{prj.name}/src/atpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "AT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AT_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AT_DIST"
        runtime "Release"
        optimize "on"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("obj/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h}",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Artem/vendor/spdlog/include",
        "Artem/src",
        "Artem/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Artem"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "AT_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
        defines "AT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AT_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AT_DIST"
        runtime "Release"
        optimize "on"



