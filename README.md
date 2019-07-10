# Toywars


## How to build and run

For building, in the root folder of the project run:
```
meson builddir
cp -r assets builddir/assets
cp -r src/shaders builddir/shaders 
cd builddir
ninja
```

And to run execute:
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
