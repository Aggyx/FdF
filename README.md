# FdF

Pack your tiny cartographer’s compass: this program turns a humble text file into a mountain-range adventure.

## Project

FdF is a C wireframe renderer for the 42 FdF project. It reads a grid of elevation values from a `.fdf` map and displays the terrain as a 3D-style projection in a window. Map points may also include colors.

## Build and run

The Makefile uses GCC with `-Wall -Wextra -Werror`. It expects the project’s Libft library in `inc/libft`; Linux builds also expect MiniLibX in `inc/mlx` and the X11 development libraries. On macOS, the Makefile links MiniLibX and the OpenGL and AppKit frameworks. Make sure these dependencies are available in the paths and formats expected by the Makefile before building.

```sh
make
./FdF maps/42.fdf
```

The default `all` target builds `FdF`. To build the bonus executable instead:

```sh
make bonus
./bonus maps/42.fdf
```

Other useful targets are `make clean` (remove standard object files), `make fclean` (also remove `FdF` and clean Libft), and `make re` (clean and rebuild the standard executable). The bonus equivalents are `make cleanb`, `make fcleanb`, and `make rebonus`.

Maps are whitespace-separated rows of elevations; a point can optionally have a hexadecimal color after a comma, for example `0,0xFF00FF`. Sample maps are in `maps/`.

## Technical concepts

- **Map parsing:** the input is read into a grid of elevation and color values. The renderer converts each grid position into a 3D point.
- **Projection math:** points are scaled and transformed with trigonometry to create the isometric view, then centered in the window. The bonus version also supports an alternate projection and adjusts the height scale.
- **Rasterization:** neighboring points in each row and column are connected with Bresenham’s line algorithm. Pixels are written directly to a MiniLibX image buffer using its address, bytes-per-pixel, and line length.
- **Events and rendering loop:** MiniLibX hooks handle keyboard and window events; a loop redraws the map into an off-screen image and presents that image in the window.
- **Memory management:** map grids, projected points, split input strings, and graphics resources are allocated and released explicitly. The project uses Libft helpers for parsing and allocation.

The standard executable exits on Escape or when its window is closed. The bonus build adds keyboard controls for zooming, moving the map, adjusting elevation, and switching projection.

## Architecture

The code is split by responsibility, with parallel implementations for the standard and bonus builds:

- `src/` and `src_bonus/` each contain the entry point, initialization, map reader, projection and line drawing, pixel/window handling, and event controller.
- `inc/utils.h` and `inc/utils_bonus.h` define the map, point, image, and MiniLibX state structures and declare the functions shared within each build.
- `maps/` contains example `.fdf` inputs.
- The Makefile selects the source set, compiles its object files, builds Libft (and MiniLibX on Linux), and links the executable.

At runtime, the entry point reads the map, initializes the window and image, builds point coordinates, registers event hooks, and starts the MiniLibX loop. Each frame projects the points, draws horizontal and vertical grid edges, and displays the image.
