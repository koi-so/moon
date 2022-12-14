add_repositories("koiso https://github.com/koi-so/pkgindex.git main")

if is_mode("debug") then
	add_rules("mode.debug")
	set_runtimes("MDd")
elseif is_mode("release") then
	add_rules("mode.release")
	set_runtimes("MD")
end

add_requires("eastl master", { configs = { shared = true } })
add_requires("directx-headers main", {})

target("rook")
	set_kind("shared")
	add_includedirs("rook/include", { public = true })
	add_defines("ROOK_CONFIG_SHARED_LIB", "ROOK_EXPORTS")
	set_languages("cxx17")
	-- not including platform code
	add_files("rook/src/**.cpp|platform/*/**.cpp|gpu/*/**.cpp")

	if is_plat("windows") then
		add_syslinks("User32", "Shell32", "Gdi32", "Kernel32", "DXGI", "D3D12")
		add_files("rook/src/platform/win32/**.cpp")
		add_files("rook/src/gpu/dx12/**.cpp")
		add_defines("ROOK_GPU_DX12")
	end

	add_packages("eastl")
	add_packages("directx-headers")

target("pilot")
	set_kind("binary")
	add_files("pilot/src/**.cpp")
	set_languages("cxx17")
	add_defines("ROOK_CONFIG_SHARED_LIB")
	add_deps("rook")
	add_packages("eastl")
