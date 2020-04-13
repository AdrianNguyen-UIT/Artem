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
IncludeDir["GLFW"] = "Artem/vendor/GLFW/include"
IncludeDir["Glad"] = "Artem/vendor/Glad/include"
IncludeDir["ImGui"] = "Artem/vendor/ImGui"


include "Artem/vendor/GLFW"
include "Artem/vendor/Glad"
include "Artem/vendor/ImGui"

project "Artem"
    location "Artem"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("obj/"..outputdir.."/%{prj.name}")

    pchheader "atpch.h"
    pchsource "%{prj.name}/src/atpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "AT_PLATFORM_WINDOWS",
            "AT_BUILD_DLL"
        }

        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox") --copy Artem.dll file into Sandbox folder next to Sandbox.exe-- 
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
        "Artem/src"
    }

    links
    {
        "Artem"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
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



