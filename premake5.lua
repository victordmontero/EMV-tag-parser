workspace "EmvTagParserLib"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64", "Linux" }

project "EmvTagParserLib"
   kind "StaticLib"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"
   objdir "obj"
   targetname("tlvparser")

   --removefiles{"thirdparty/EMV-tag-parser/main.c"}

   includedirs {
		  "include"
   }

   files ({
		"**.h*",
		"src/**.c*",
		"*.lua"
	})

  filter "configurations:Debug"
    defines { "DEBUG", "_DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

  filter "platforms:Win32"
    defines{"WIN32"}
    system "windows"
    architecture "x86"

  filter "platforms:Win64"
    defines{"WIN64"}
    system "windows"
    architecture "x86_64"

  filter "platforms:Linux"
    defines{"LINUX"}
    system "linux"

project "EmvParserTests"
   kind "ConsoleApp"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"
   objdir "obj"

   includedirs {
		"include"
   }

   links{
		"tlvparser",
		"EmvTagParserLib"
   }

   files ({
		"tests/**.h*",
		"tests/**.c*",
		"*.lua"
	})

  filter "configurations:Debug"
    defines { "DEBUG", "_DEBUG" }
    symbols "On"

	libdirs{
		"bin/Debug"
	}

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

	libdirs{
		"bin/Release"
	}

  filter "platforms:Win32"
    defines{"WIN32"}
    system "windows"
    architecture "x86"

  filter "platforms:Win64"
    defines{"WIN64"}
    system "windows"
    architecture "x86_64"

  filter "platforms:Linux"
    defines{"LINUX"}
    system "linux"

	--buildoptions{"`wx-config --cxxflags`"}
	--linkoptions{"`wx-config --libs`"}