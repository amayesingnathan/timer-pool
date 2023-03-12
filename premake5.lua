workspace "timer-pool"

    configurations 
    { 
        "Debug",
        "Release"
    }
    
    platforms
    {
        "x64",
        "ARM32",
        "ARM64"
    }

	filter "platforms:x64"
		architecture "x86_64"

	filter "platforms:ARM32"
		architecture "ARM"

 	filter "configurations:ARM64"
		architecture "ARM64"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["libtimers"] 	= "%{wks.location}/timer-pool/src"
IncludeDir["magic_enum"]    = "%{wks.location}/timer-pool/dependencies/magic_enum"

include "timer-pool"
include "timer-test"