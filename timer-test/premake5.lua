project "timer-test"
    language "C++"
    cppdialect "C++20"
		
    targetdir 	("%{wks.location}/bin/%{prj.name}/" .. outputDir)
    objdir 		("%{wks.location}/obj/%{prj.name}/" .. outputDir)

    files 
    { 
        "src/**.h", 
        "src/**.cpp",
    }
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs
    {
        "%{IncludeDir.libtimers}",
        "%{IncludeDir.magic_enum}",
    }

	links
	{
        "timer-pool"
	}
	
    filter "system:windows"
        kind "ConsoleApp"
        staticruntime "off"
        systemversion "latest"
		
	filter "system:linux"
        kind "ConsoleApp"
        staticruntime "off"
        pic "On"
        systemversion "latest"
        --prebuildcommands 
        --{
        --    "{MKDIR} %{wks.location}/bin/%{prj.name}//%{outputDir}",
        --    "{COPYFILE} %{wks.location}/bin/timer-pool/%{outputDir}/libtimer-pool.so %{wks.location}/bin/%{prj.name}//%{outputDir}/libtimer-pool.so",
        --}

    filter "configurations:Debug"
		runtime "Debug"
        symbols "on"
    filter "configurations:Release"
		runtime "Release"
        optimize "on"