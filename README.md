# Computational Geometry Library 

## Table of Contents
- [Getting Started](#getting-started)
- [Pre Requirements](#pre-requirements)
- [Compile And Run](#compile-and-run)
- [Contribution](#contribution)
- [Licence](#licence)
- [References](#references)

## Getting Started
- Computational Geometry Library have three stuff:
  1. [Computional Geomerty Summary](https://github.com/basmaashouur/ComputationalGeometryLibrary/blob/master/CGsummary.md) Which is a list of computational geometry sup topic's resources, tags, terminologies and explanations.
  2. [Computional Geomerty Codes](https://github.com/basmaashouur/ComputationalGeometryLibrary/blob/master/CGcodes.md) Which is a file contains code snippets of the computational geometry codes.
  3. [Computional Geomerty Solver](https://github.com/basmaashouur/ComputationalGeometryLibrary/tree/master/CGsolver) Which is a program to solve computational geometry problems.


## Pre Requirements
- g++

## Compile And Run
- Clone this Repo 
```console
git clone https://github.com/basmaashouur/ComputationalGeometryLibrary.git
```
- Go to the directory 
```console
cd ComputationalGeometryLibrary/CGsolver
```
- Compile the files 
```console
g++ -c main.cpp Tools.cpp Points.cpp Lines.cpp Segments.cpp Rectangle.cpp Triangles.cpp Circles.cpp Quadlitrals.cpp Polygons.cpp
```
- This produces a .o files, We can then link them using
```console
g++ main.o Tools.o Points.o Lines.o Segments.o Rectangle.o Triangles.o Circles.o Quadlitrals.o Polygons.o
```
- Execute the compiled program `./a.out`


## Contribution
- Feel free to dive in! [Open an issue](https://github.com/basmaashouur/ComputationalGeometrySolver/issues/new) or submit PRs.

## Licence

[![Creative Commons Attribution 4.0 International](https://i.creativecommons.org/l/by/4.0/88x31.png)](https://creativecommons.org/licenses/by/4.0/)

Computational Geometry Library is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).

## References
- [Competitive Programming 3](https://cpbook.net/#CP3details)
- [Programming Challenges](https://www.amazon.com/Programming-Challenges-Contest-Training-Computer/dp/0387001638)
- [The Art and Craft of Problem Solving](https://www.amazon.com/Art-Craft-Problem-Solving/dp/0471789011The) 
- [Geometry Algorithms](http://geomalgorithms.com/index.html)
- [Geometry Topics](https://en.wikipedia.org/wiki/List_of_geometry_topics)
- [GeeksforGeeks](https://www.geeksforgeeks.org/geometric-algorithms/)
- [Stackoverflow](https://stackoverflow.com/) 

