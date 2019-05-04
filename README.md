# Toywars


## How to build and run

For building, in the root folder of the project run:
```
meson builddir
cd builddir
ninja
```

Then move the assets folder to builddir and to execute the game run in it:
```
./toywars
```
## To do

- [ ] Make a viewport
        - [ ] Determine how to represent world coordinates
        - [ ] Determine to interface between de Vieport and the rest of the classes
        - [ ] Add movement with keyboard keys
        - [ ] Add zoom with mouse
- [ ] Make art look pretty
- [ ] Add movement of tanks
