# COS214_Prac4 - TaskForge

Team:

## Build & Run (Docker)

    docker build -t taskforge .
    docker run -it --rm taskforge
    make
    ./taskforge

## GDB

    docker run -it --rm taskforge
    make
    gdb ./taskforge

## Valgrind

    docker run -it --rm taskforge
    make
    valgrind --leak-check=full --show-leak-kinds=all ./taskforge

## Domain
    (add after Task1 design)