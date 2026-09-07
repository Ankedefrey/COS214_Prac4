# COS214_Prac4 - TaskForge

## Team
- Anke de Frey - u24611400
- Rynhardt - u
- Terrence - u

## Build & Run (Docker)
Build the image
    `docker build -t taskforge .`
Start a container and get a shell inside it:
    `docker run -it --rm taskforge`
Inside the container, build and run:
    `make`
    `./taskforge`

## GDB
From the same container shell, after 'make':
    `gdb ./taskforge`

Example session (used during development to diagnose a display() bug where
decorated tasks printed their undecorated raw values — see the PDF for the
full symptom/cause/correction writeup):

    break ProductionTask::display
    run
    continue
    print this->name
    print this->duration
    print this->cost
    bt
    frame 1
    print wrapped

## Valgrind
From the same container shell, after 'make':

    
    valgrind --leak-check=full --show-leak-kinds=all ./taskforge

## Repository structure
- Source files (.cpp/.h) and main.cpp - project root
- Makefile, Dockerfie - project root
- docs/ - class diagram, object diagram, state diagram, and 3 activity diagrams

## Domain
(add after Task1 design)