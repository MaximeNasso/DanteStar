# Dante's Star

* First year epitech project
* Lasts 4 Weeks
* Grade : 100%
* Group : [Maxime Nasso](https://github.com/MaximeNasso) | [Emmanuel Lena](https://github.com/ScihaproQ)

- - -

# Subject

The goal of this project is to generate mazes, solve them and print the solution.
> :warning: System functions and libC are allowed, but no external libraries

## What is a maze ?

- Here is the maze format description:
    - Mazes are rectangular.
    - They are coded in ASCII.
    - The ‘X’s represent the walls and the’*’s represent the free spaces.
    - It is possible to move to the four surrounding squares (up, down, right, left).
    - “Start” is in the upper left-hand corner (0;0)
    - “Finish” is in the bottom right-hand corner.
    - A solution is a series of free, adjacent squares, from “Start” to “Finish” included.
    - “Start” and “Finish” can be occupied. In this case, there is no solution.
    - The last line of the maze doesn’t terminate with a return line.
    - Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path

### Perfect Maze

A perfect maze is a maze that has no loops and no clusters; therefore, following a wall makes us cross theentire maze.

### Imperfect maze

An imperfect maze must contain clusters.\
The requirements are the same as for perfect mazes.\
The generation method is up to you, but it must work in an acceptable amount of time.

### Solving maze

The resolution program should take the name of a file containing the maze and write the solution on the standard output.
You can choose the algorithm you want but be careful, you will be ask to solve perfect and imperfect mazes.

## Usage

**You need to compile the source files using ```make``` before trying to execute the binaries.**

### Generator

```./generator/generator x_size y_size [perfect]```

If the perfect flag is present, a perfect maze will be generated.

### Solver

```./solver/solver mazefile.txt```

- - -

# Bonus

In the bonus file, you can run the solver and the generator in graphical version.\
**You need to compile the source files using ```make``` before trying to execute the binaries.**\
**You need to have the SDL and CSFM libraries in your environment**

### Generator

 ```./bonus/generator/generator x_size y_size [perfect] -graphic```

> :warning: Only work with perfect mazes.

graphic: two flags are available: -SDL, -CSFML.

### Solver

 ```./bonus/solver/solver x_size y_size mazefile.txt -graphic```
 
 graphic: two flags are available: -SDL, -CSFML.
