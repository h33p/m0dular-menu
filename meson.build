project('m0dular-menu', 'cpp', 'c', default_options : ['c_std=c11', 'cpp_std=c++17', 'b_ndebug=if-release'])

dependency_list = []

linker_args = []
compile_args = []
combined_args = []
external_link = []
system_includes = []
libraries = []

thread_dep = dependency('threads')

dependency_list += thread_dep

file_list = ['menu.cpp', 'imgui/imgui.cpp', 'imgui/imgui_demo.cpp', 'imgui/imgui_draw.cpp', 'imgui/imgui_widgets.cpp']

cc = meson.get_compiler('cpp')
cpu_family = host_machine.cpu_family()

if host_machine.system() == 'windows'

  file_list += ['dx9menu.cpp', 'standalone_dx9.cpp', 'imgui/examples/imgui_impl_dx9.cpp', 'imgui/examples/imgui_impl_win32.cpp']

  if meson.is_cross_build()
    compile_args += ['-Wno-msvc-not-found', '-D_CRT_SECURE_NO_WARNINGS', '-D_WINSOCK_DEPRECATED_NO_WARNINGS', '-fms-extensions', '-fms-compatibility', '-fms-compatibility-version=19.14.26428', '-Wno-non-virtual-dtor']
    combined_args += ['-target', 'i386-pc-windows-msvc19.14.26428', '-fuse-ld=lld']

    bf_dir = get_option('msvc_dir')

    bf_includes = ['clang', 'msvc', 'ucrt', 'um', 'shared', 'winrt', 'boost']
    bf_libraries = ['clang']
    bf_libraries_cpu = ['msvc', 'ucrt', 'um', 'shared', 'winrt', 'boost']

    foreach p : bf_includes
      system_includes += join_paths(bf_dir, 'include', p)
    endforeach

    foreach p : bf_libraries
      libraries += join_paths(bf_dir, 'lib', p)
    endforeach

    foreach p : bf_libraries_cpu
      libraries += join_paths(bf_dir, 'lib', p, cpu_family)
    endforeach
  endif

  #Meson does not handle C++ language standard properly on msvc
  if cc.get_id() == 'msvc'
    compile_args += ['-std:c++17', '-GR-']
  endif

  external_link += ['kernel32', 'd3d9', 'user32']

  if get_option('buildtype').startswith('debug')
    external_link += ['msvcrtd']
  else
    external_link += ['msvcrt']
  endif

else
  file_list += ['sdlmenu.cpp', 'standalone_sdl2.cpp', 'imgui/examples/imgui_impl_opengl2.cpp', 'imgui/examples/imgui_impl_sdl.cpp']
  sdl_dep = dependency('sdl2')
  gl_dep = dependency('gl')
  dependency_list += [sdl_dep, gl_dep]
  external_link += ['dl', 'rt']
endif

if cc.get_id() != 'msvc'
  foreach d : system_includes
    compile_args += ['-isystem'+d]
  endforeach

  foreach p : libraries
    linker_args += '-L'+p
  endforeach
endif

linker_args += '-Bdynamic'
foreach p : external_link
  linker_args += '-l' + p
endforeach

add_inc_dir = get_option('additional_include_dir')

if add_inc_dir != ''
  includes += [add_inc_dir]
endif

incdir = include_directories(['imgui'])

menu = executable('menu_standalone', files(file_list), include_directories: incdir, dependencies : dependency_list, cpp_args : compile_args + combined_args, link_args : linker_args + combined_args)