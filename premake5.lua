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
	
	if os.ishost("windows") then
		links { "sfml-main" }
	end
	
	if os.ishost("linux") then
		linkoptions { "-pthread" }
	end
	
	links { "sfml-audio", "sfml-graphics", "sfml-system", "sfml-window" }
	
	libdirs { "thirdparty/SFML/lib/" }
		
	filter "configurations:Debug"
		defines { "DEBUG" }
		cppdialect "C++17"
		symbols "on"

		if os.ishost("linux") then
			buildoptions { "-fmax-errors=3", "-Wall", "-Wextra" }
		end
		
	filter "configurations:Release"
		optimize "On"
		cppdialect "C++17"
	