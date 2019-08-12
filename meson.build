project('toywars', 'cpp', 'c', default_options : ['cpp_std=c++14'])

cc = meson.get_compiler('c')
libdl = cc.find_library('dl', required : false)
dependencies = [dependency('sdl2'), dependency('GL'), dependency('glm'),
                dependency('x11'), dependency('threads'), dependency('xrandr'),
                dependency('xi'), libdl]

sources = ['src/main.cpp', 'src/Game.cpp', 'include/deps/glad/glad.c', 'src/objects/Window.cpp',
           'src/objects/Board.cpp', 'src/objects/Viewport.cpp', 'src/objects/game_objects/Tank.cpp',
           'src/objects/game_objects/Water.cpp', 'src/objects/game_objects/Rocks.cpp']

inc = include_directories('include')

executable('toywars', sources, include_directories : inc, dependencies: dependencies)
