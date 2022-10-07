add_repositories("koiso https://github.com/koi-so/pkgindex.git main")

if is_mode("debug") then
	add_rules("mode.debug")
elseif is_mode("release") then
	add_rules("mode.release")
end

add_requires("zinc main", { configs = { shared = true } })


target("moon")
    set_kind("shared")
    add_includedirs("moon/include", { public = true })
    add_defines("MOON_CONFIG_SHARED_LIB", "MOON_EXPORTS")
    set_languages("cxx17")
    -- not including platform code
    add_files("moon/src/**.cpp|platform_glue/*/**.cpp")

    if is_plat("windows") then
        add_syslinks("User32", "Shell32", "Gdi32", "Kernel32")
        add_files("moon/src/platform_glue/win32/**.cpp")
    end

    add_packages("zinc")

target("pilot")
    set_kind("binary")
    add_files("pilot/src/**.cpp")
    set_languages("cxx17")
    add_defines("MOON_CONFIG_SHARED_LIB")
    add_deps("moon")
    add_packages("zinc")
