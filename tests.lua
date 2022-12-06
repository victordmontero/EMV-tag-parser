project "EmvParserTests"
   kind "ConsoleApp"
   language "C"
   targetdir "bin"
   objdir "obj"
   
   dependson {"EmvTagParserLib"}

   includedirs {
		"include"
   }

   files ({
		"tests/**.h*",
		"tests/**.c*",
		"*.lua"
	})
	
	libdirs{
		"bin"
	}

  filter "configurations:Debug"
    defines { "DEBUG", "_DEBUG" }
    symbols "On"
	targetsuffix "%{cfg.architecture}d"
	
	links{
		"tlvparser-%{cfg.architecture}-d"
	}

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
	targetsuffix "%{cfg.architecture}"
	
	links{
		"tlvparser-%{cfg.architecture}"
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