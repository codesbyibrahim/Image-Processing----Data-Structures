# [Heading]

## Introduction

This readme gives a description for the parallel implementation of K shortest paths using  openMPI and openMP, the project was submitted by for Muhammad ibrahim sultan i210582,Laiba nadeem i210690, and  Muhammad hamza i210869.

## Contents

- [Introduction](#introduction)
- [Files](#files)
- [Usage](#usage)

## Files

There are a total of 5 submitted code files:
- One `.cpp` file
- One `.c` file
- One `.txt` file
- Two header files

The `.cpp` file contains the serial implementation of the algorithm, while the `.c` file contains the OpenMPI + OpenMP implementation.

## Usage

To compile the `.c` file, use the following command:

```bash
mpicc -fopenmp -o myobj <filename>.c
```

Once the file is compiled we can define the number of processes and execute the object file with following command

```bash
mpiexec -n <number of process> ./myobj
```
