project "Kernel"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    files { "Source/**.h", "Source/**.cpp" }
    includedirs { "Source/" }