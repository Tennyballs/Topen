#include <cstdint>
#include <stdio.h>
#include "World.hpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

World::World(const char *filePath)
{
    FILE *worldFile = fopen(filePath, "rb");

    fread(&mapVersion, sizeof(int32), 1, worldFile);
    if (mapVersion >= 135)
    {
        terrariaEnum = (String)malloc(sizeof(char) * 8);
        fgets(terrariaEnum, 8, worldFile);
        fread(&fileType, sizeof(char), 1, worldFile);
        fseek(worldFile, 12, SEEK_CUR);
    }
    // else if (mapVersion >= 88)
    // {
    //     fread(&sections, sizeof(int16), 1, worldFile);
    //     section = (int32 *)malloc(sizeof(int32) * sections);
    //     for (size_t i = 0; i < sections; i++)
    //     {
    //         fread(&section[i], sizeof(int32), 1, worldFile);
    //     }
    //     printf("Read %d sections.\n", sections);
    // }

    fclose(worldFile);
}

World::~World()
{
}
