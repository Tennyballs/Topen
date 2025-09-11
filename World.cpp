#include <stdio.h>
#include "World.hpp"
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool *parseBitsByte(int size, FILE *file) {
    
}

World::World(const char *filePath)
{
    FILE *worldFile = fopen(filePath, "rb");

    fread(&mapVersion, sizeof(int32), 1, worldFile);
    
    // allocate memory b7
    magicNumber = (String) malloc(sizeof(char) * 8);
    fgets(magicNumber, 8, worldFile);
    magicNumber[7] = '\0';

    uint8 fileType = fgetc(worldFile);
    fread(&revision, sizeof(uint32), 1, worldFile);
    favorite = !!fgetc(worldFile);

    fseek(worldFile, 7, SEEK_CUR);

    int16 pointerCount = 0;
    fread(&pointerCount, sizeof(int16), 1, worldFile);
    
    int32 *pointers = (int32 *)malloc(sizeof(int32) * pointerCount);
    for (size_t i = 0; i < pointerCount; i++)
    {
        fread(&pointers[i], sizeof(int32), 1, worldFile);
    }

    
    
    
    printf("Magic number: %s\n", magicNumber);
    printf("filetype: %d\n", fileType);
    printf("revision: %d\n", revision);
    favorite ? printf("favorite: true\n") : printf("favorite: false\n");
    printf("Skipped 7 bytes\n");
    printf("read %d pointers\n", pointerCount);


    fclose(worldFile);
}

World::~World()
{
}
