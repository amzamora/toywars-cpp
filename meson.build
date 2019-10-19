project('toywars', 'cpp', 'c', default_options : ['cpp_std=c++14'])

cc = meson.get_compiler('c')
libdl = cc.find_library('dl', required : false)
dependencies = [dependency('sdl2'), dependency('GL'), dependency('glm'),
                dependency('x11'), dependency('threads'), dependency('xrandr'),
                dependency('xi'), libdl]

sources = ['src/main.cpp', 'src/Game.cpp', 'include/glad/glad.c', 'src/Window.cpp',
           'src/play_screen/Board.cpp', 'src/Viewport.cpp', 'src/play_screen/game_objects/Tank.cpp',
           'src/play_screen/game_objects/Water.cpp', 'src/play_screen/game_objects/Rocks.cpp']

inc = include_directories('include')

executable('toywars', sources, include_directories : inc, dependencies: dependencies)
