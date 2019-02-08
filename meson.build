project('toywars', 'cpp', default_options : ['cpp_std=c++14'])

dependencies = dependency('sdl2')
sources = ['src/main.cpp', 'src/Game.cpp']
inc = include_directories('include')

executable('toywars', sources, include_directories : inc, dependencies: dependencies)
