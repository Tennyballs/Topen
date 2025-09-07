#include <stdio.h>
#include "World.hpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

World::World(const char *filePath)
{
    FILE *worldFile = fopen(filePath, "rb");
    String relogic = (String)malloc(sizeof(char) * 7);
    Byte fileType;

    if (!worldFile)
    {
        printf("ERROR: Couldn't open the file '%s'\n", filePath);
        return;
    }

    fread(&mapVersion, sizeof(int32), 1, worldFile);

    if (mapVersion >= 135) // if atleast 135
    {
        fgets(relogic, 7, worldFile);
        fread(&fileType, 1, 1, worldFile);
        // String voidData = (String)malloc(sizeof(char) * 12); // useless data
        // fgets(voidData, 12, worldFile);
        // free(voidData);
        fseek(worldFile, 12, SEEK_CUR);
    }

    if (mapVersion >= 88) // if atleast 88
    {
        int16 sections;
        fread(&sections, sizeof(int16), 1, worldFile);
        int32 offsets[sections] = {0};
        printf("Initialized array of offsets to size (%d).\n", sections);

        for (size_t i = 0; i < sections; i++)
        {
            fread(&offsets[i], sizeof(int32), 1, worldFile);
        }
        printf("Finished reading %d sections!\n", sections);

        int16 numOfTilesInMask;
        fread(&numOfTilesInMask, sizeof(int16), 1, worldFile);

        printf("%fd\n", numOfTilesInMask);
    }

    fclose(worldFile);
}

World::~World()
{
}
