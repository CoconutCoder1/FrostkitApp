workspace "Frostkit"
    configurations { "Debug", "Release" }
    platforms { "Win64" }
    
    targetdir "Build/Binary/%{cfg.buildcfg}-%{cfg.platform}"
    objdir "Build/Intermediate/%{prj.name}/%{cfg.buildcfg}-%{cfg.platform}"

    filter "configurations:Debug"
        defines { "FK_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "FK_RELEASE" }
        optimize "On"

    filter "platforms:Win64"
        architecture "x86_64"
        defines { "FK_WIN64" }

include "Core/Build-Core.lua"
include "Kernel/Build-Kernel.lua"
include "Sandbox/Build-Sandbox.lua"