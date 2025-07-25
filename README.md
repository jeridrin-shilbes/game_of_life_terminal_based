# Conway's Game of Life — Terminal Simulation in C

This repository contains a C implementation of **Conway's Game of Life**, a classic cellular automaton simulation. The simulation displays evolving generations of cells in the terminal, using Unicode characters to represent live and dead cells.

## 🔬 What is Conway's Game of Life?

It's a zero-player game where you set the initial state, and the system evolves over time according to specific rules:
- A cell survives if it has 2 or 3 live neighbors.
- A dead cell becomes alive if it has exactly 3 live neighbors.
- All other cells die or remain dead.

More: [Wikipedia - Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## 🧠 Main gist

- The simulation runs on a `100x100` grid.
- Initial live cell positions are specified in the `alive` array.
- Future iterations are aimed to have keypress integration to select the alive cell at the start of every iteration of sim
- The grid evolves for a predefined number of generations (`GENERATION_LIMIT`).(line 35 could be switched for a while loop to run simulations infinitely)
- Each generation is displayed in the terminal using:
  - `⬜` for **live** cells
  - `⬛` for **dead** cells

## 📁 File Structure

- `game.c` — Contains the full implementation including:
- 'README.md'- you are reading it right now

## 🚀 How to Run

1. **Clone the repository:**
```for bash:
           git clone https://github.com/jeridrin-shilbes/game_of_life_terminal_based
           cd game-of-life-c
           gcc game.c -o game
```
   
