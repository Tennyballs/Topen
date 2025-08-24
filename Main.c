#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *relogic = "relogic";

char readUInt8(FILE *file)
{
    char dest;
    fread(&dest, sizeof(int), 1, file);
    return dest;
}

short readInt16(FILE *file)
{
    short dest;
    fread(&dest, sizeof(int), 2, file);
    return dest;
}

int readInt32(FILE *file)
{
    int dest;
    fread(&dest, sizeof(int), 1, file);
    return 0;
}

char *readString(FILE *file, size_t size)
{
    char *dest = (char *)malloc(sizeof(char) * size + 1);
    // fread(&dest, sizeof(int), size, file);
    return fgets(dest, size + 1, file);
    // return dest;
}
int main(int argc, char **argv)
{
    FILE *world = fopen("World.wld", "rb");
    if (world == NULL)
    {
        println("ERROR.");
        return -1;
    }
    println("Successfully opened the world file.");

    int worldVersion = readInt32(world);
    char *secret = readString(world, 7);

    // make sure version is WORLD_VERSION as its the only one supported rn.
    if (worldVersion != WORLD_VERSION)
    {
        println("Invalid World file.");
        exit(1);
    }

    // makes sure the signature is correct
    if (strcmp(secret, relogic))
    {
        println("Invalid World file.");
        exit(1);
    }
    // println("Valid World file.");

    fclose(world);

    world = NULL;

    // if number

    return 0;
}

// EOF