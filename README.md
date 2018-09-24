# Sorting Algorithms

This repository contains the implementation of several sorting algorithms.

The algorithms were constructed using the C++ language, in conjunction with a graphical library developed with [SFML](https://www.sfml-dev.org/) for visualization at runtime of the operation of the algorithms.

The library was developed by [Professor David Sena](https://www.quixada.ufc.br/docente/david-sena-oliveira/) ([UFC](http://www.ufc.br/)).

## How to run

After doing the project clone, download the sfml library to your computer.

```shell
$ sudo apt install libsfml-dev
```

To run, you must modify the `main.cpp` file. It contains the main function that will contain several calls from other commented functions.

```c++
int main()
{
    ....

    //minimum_sort(vet);
    //quick_sort(vet, 0, vet.size());
    //bubble_sort(vet);

    ....
}
```

Just uncomment the one you want to view, after that, execute `make` to compile your code and an executable file named `sort` will be generated, just by running it.

```shell
$ make
$ ./sort
```

<p align="center">
    <img src="example.gif">
</p>

And ready! On the screen will contain instructions on how to handle the execution of the algorithm.