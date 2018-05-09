workspace "SFMLRaytracer"
    configurations { "Debug", "Release" }
	language "C++"
	location "build"
	
project "SFMLRaytracer"
	kind "WindowedApp"
	
	files {
		"src/**.hpp",
		"src/**.cpp",
	}
	
	location "build/"
	
	includedirs  {
		"thirdparty/SFML/include",
		"thirdparty/glm/",
		"src"
	}
	
	links { "sfml-audio", "sfml-main", "sfml-graphics", "sfml-system", "sfml-window" }
	
	libdirs { "thirdparty/SFML/lib/" }
		
	filter "configurations:Debug"
		defines { "DEBUG" }
		cppdialect "C++17"
		
	filter "configurations:Release"
		optimize "On"
		cppdialect "C++17"
	