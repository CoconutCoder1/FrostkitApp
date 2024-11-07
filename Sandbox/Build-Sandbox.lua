project "Sandbox"
    language "C++"
    cppdialect "C++20"

    files { "Source/**.h", "Source/**.cpp" }
    includedirs { "Source/", "../Core/Source", "../Kernel/Source" }

    links { "Core", "Kernel" }

    filter "configurations:Debug"
        kind "ConsoleApp"
        defines { "FK_CONSOLE" }
    
    filter "configurations:Release"
        kind "WindowedApp"