# SDL game core

This library is the result of me trying to make a game using **SDL3**. Because I wanted to first make some tools for the development I moved all the rendering to a seperate library. So my hobby project "SDL game" became a "SDL game core" library.

The library is in early development. Right now it wraps basic SDL functionality allowing for loading and rendering images. It also support tile based rendering with tileset style images as source. The tiles are stored by tile storage classes.

The library also implements asset managmentent. It allows for serializing and deserializing assets into custom binary format called SGC Packages.

There is also some basic vector math implemented. I add things as I need them.

The SGC is meant to be multi platform but because I made a map editor thats Win32 based I have some win32 specific functionality. I seperated it into a seperate file from other SDL function wrappers.

