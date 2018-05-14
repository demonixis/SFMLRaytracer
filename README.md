SFMLRaytracer
=============

![Preview](https://github.com/demonixis/SFMLRaytracer/blob/master/images/preview.jpg)

A work in progress realtime and offline raytracer written in C++ using SFML. It supports multi-threading, the more CPU, the more fast is the render!

## Key binding
| Key | Action |
|-----|--------|
| F11 | Toggle `realtime` / `offline` |
| F12 | Force the raytracer to render a new frame (offline) |
| PageUp | Increase the number of samples |
| PageDown | Decrease the number of samples |
| Up / Down | Move Forward/Backward |
| Left / Right | Move Left/Right |

## How to build the project
This project uses [Premake5](https://premake.github.io/download.html#v5) as a build system.

### Dependencies
- [SFML](https://github.com/SFML/SFML) 
- [glm](https://github.com/g-truc/glm) libraries.

You have to create a new folder called `thirdparty` and put the `SFML` and the `glm` folders into it.
The premake file is not configured to work with native libraries on Linux/Mac yet but you can follow the same step used for Windows.

Don't forget to copy runtime libraries (dll on windows) in the `build/[Debug|Release]/` folder.

## Shortime Roadmap
- Texture support
- Boxes / Quad / Triangles

### Longtime Roadmap
- BVH
- Compute Shader (if possible)

## License
The project is released under the MIT license.