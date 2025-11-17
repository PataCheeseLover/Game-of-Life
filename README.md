# Conway's Game of Life (ASCII)

A simple implementation of Conway's Game of Life in C++ using an ASCII grid. The board is padded to simplify neighbor calculations, and the game updates in real time in the terminal.

## Features

- ASCII visualization of the board
- Customizable board size
- Add initial live cells with `Point` coordinates
- Implements Conway's rules:
  - Any live cell with fewer than 2 or more than 3 neighbors dies
  - Any dead cell with exactly 3 neighbors becomes alive
- Includes example pattern: glider

## How to Run

1. Compile the program:

```bash
g++ -std=c++17 -o game_of_life main.cpp
````

2. Run the executable:

```bash
./game_of_life
```

3. Observe the simulation in your terminal. Press `Ctrl+C` to stop.

## Example Initial Pattern

```cpp
std::vector<Point> glider = {
    {1, 2},
    {2, 3},
    {3, 1},
    {3, 2},
    {3, 3}
};
```

## Notes

* The board is padded to avoid boundary issues during updates.
* Currently, the game runs indefinitely with a fixed time step (`1000ms`).
