# Coditation-Assignment
An infinite two-dimensional orthogonal grid of square cells, each of which is in one of two
possible states, live or dead. Every cell interacts with its eight neighbors, which are the cells that are
directly horizontally, vertically, or diagonally adjacent.

At each step in time (tick), the following transitions occur:
1. Any live cell with fewer than two live neighbors dies, as if by loneliness.
2. Any live cell with more than three live neighbors dies, as if by overcrowding.
3. Any live cell with two or three live neighbors lives, unchanged, to the next generation.
4. Any dead cell with exactly three live neighbors comes to life.

The initial pattern constitutes the 'seed' (randomly placed 500 cells) of the system. The first generation is
created by applying the above rules simultaneously to every cell in the seed — births and deaths happen
simultaneously, and the discrete moment at which this happens is called a tick. (In other words, each
generation is a pure function of the one before.)

This is a program in Cpp(C plus plus) with following guidelines:
1. Accepts a user input of new cells (max 100 at every step/tick) to be placed; each cell should have a unique name which is to be accepted by the user. This input is accepted through a CLI.
2. Then the program calculate the state of every cell.
3. The program output the state of the cells and changes (0 for Dead and 1 for Alive).
4. The program provides a way to search by the coordinates of the cell and show the current state of the cell.
5. The program ends on termination or chosing option 4.


# Instructions on building and running:

# Building:
The program have a .cpp extension file which can be compiled using any IDE to generate an executable file.

# Running:
The executable file can be run simply by double clicking on it or opening it in CLI.
