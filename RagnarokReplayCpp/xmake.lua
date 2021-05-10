target("RagnarokReplayCpp")
	set_default("true")
	set_languages("c99", "cxx17")
	set_kind("static")

	add_cxxflags("-O2", "-Wall", "-Wextra", "-Werror", "-g")

	add_files("$(projectdir)/*.cpp")
	del_files("$(projectdir)/main.cpp")
target_end()

target("analysis_tool")
	set_default("true")
	set_languages("c99", "cxx17")
	set_kind("binary")

	add_deps("RagnarokReplayCpp")

	add_cxxflags("-O2", "-Wall", "-Wextra", "-Werror", "-g")

	add_files("$(projectdir)/analysis_tool/*.cpp")
	add_includedirs("$(projectdir)/")
target_end()
