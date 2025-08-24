#include <iostream>
#include "World.h"

int main(int argc, char **argv)
{
    char fileName[10] = "World.wld";
    World *myWorld = new World(fileName);
    return 0;
}