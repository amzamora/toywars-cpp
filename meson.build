project('toywars', 'cpp', default_options : ['cpp_std=c++14'])

dependencies = [dependency('sdl2'), dependency('SDL2_image')]
sources = ['src/main.cpp', 'src/Game.cpp', 'src/objects/Window.cpp',
           'src/objects/Board.cpp', 'src/objects/game_objects/Tank.cpp']
inc = include_directories('include')

executable('toywars', sources, include_directories : inc, dependencies: dependencies)
