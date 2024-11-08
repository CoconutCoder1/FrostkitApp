project "Core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    files { "Core/**.h", "Core/**.cpp" }
    includedirs { "../Kernel" }