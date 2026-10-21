# FdF

Grab your compass—this little program turns a text file into a mountain-range adventure.

## What it does

FdF is a C wireframe renderer for the 42 project. It reads a grid of elevations from a `.fdf` file and displays the terrain as a 3D-style map; points can include optional hexadecimal colors.

## Build and run

The Makefile uses GCC (`-Wall -Wextra -Werror`). Builds expect Libft in `inc/libft`; Linux also needs MiniLibX in `inc/mlx` and X11 development libraries. macOS links MiniLibX, OpenGL, and AppKit.

```sh
make
./FdF maps/42.fdf
```

`make` (the `all` target) builds `FdF`. Build and run the bonus version with:

```sh
make bonus
./bonus maps/42.fdf
```

Cleanup/rebuild targets: `clean`, `fclean`, `re`; bonus equivalents: `cleanb`, `fcleanb`, `rebonus`.

Maps are whitespace-separated rows of elevations, optionally colored (e.g. `0,0xFF00FF`). Samples are in `maps/`.

## Concepts and design

- **Parsing and projection:** map values become 3D points, scaled and transformed with trigonometry into an isometric view.
- **Rendering:** Bresenham’s algorithm connects neighboring points; pixels are drawn into a MiniLibX image buffer and presented in the event loop.
- **Input and memory:** MiniLibX handles keyboard/window events. Libft and explicit allocation/free manage parsing, map data, points, and graphics resources.

The base program exits on Escape or window close; bonus adds zoom, pan, height adjustment, and alternate projection. `src/` and `src_bonus/` separate the two implementations into startup, parsing, rendering, and event modules. Headers in `inc/` define their data structures; `maps/` holds examples. At runtime, each entry point loads a map, initializes graphics and event hooks, then renders its grid in the MiniLibX loop.
