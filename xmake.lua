set_project( "NetworkingHelper" )

set_version( "0.5.0", { build = "%Y%m%d", soname = true } )

set_warnings( "allextra" )

add_rules( "mode.debug", "mode.release", "mode.releasedbg", "mode.minsizerel" )
add_rules( "plugin.compile_commands.autoupdate", { outputdir = ".vscode" } )

if is_plat( "windows" ) then
    set_languages( "cxx17" )

    add_cxflags( "/Zc:__cplusplus" )
    add_cxflags( "/Zc:preprocessor" )

    add_cxflags( "/permissive-" )
else
    set_languages( "c++17" )
end

add_requireconfs( "*", { configs = { shared = get_config( "kind" ) == "shared" } } )

add_requires( "bitsery" )
add_requires( "nng" )

-- test framework
add_requires( "gtest" )

target( "NetworkingHelper" )
    set_kind( "$(kind)" )
    set_default( true )
    set_group( "LIBS" )

    if is_kind( "shared" ) then
        if is_plat( "linux" ) then
            add_defines( "NETWORKINGHELPER_DO_EXPORT_LINUX" )
        elseif is_plat( "macosx" ) then
            add_defines( "NETWORKINGHELPER_DO_EXPORT_MACOSX" )
        elseif is_plat( "windows" ) then
            add_defines( "NETWORKINGHELPER_DO_EXPORT_WINDOWS" )
        end
    end
    if is_plat( "windows" ) then
        add_defines( "NETWORKINGHELPER_WINDOWS_LONGDOUBLE_8_BYTES" )
    end

    add_packages( "bitsery", { public = true } )
    add_packages( "nng", { public = true } )

    add_includedirs( "include", { public = true } )
    add_headerfiles( "include/(networkingHelper/*.hpp)" )
    add_files( "src/*.cpp" )

target( "NetworkingHelper_Tests" )
    set_kind( "binary" )
    set_default( false )
    set_group( "TESTS" )

    add_deps( "NetworkingHelper", { shared = get_config( "kind" ) == "shared", public = true } )
    add_packages( "gtest", { public = true } )

    add_files( "test/*.cpp" )
