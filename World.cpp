#include <stdio.h>
#include <vector>
#include "World.h"

static std::vector<World *> OpenWorlds = std::vector<World *>();

World::World(char *filename)
{
    this->worldfile = fopen(filename, "rwb");
    if (this->worldfile == NULL)
    {
        return;
    }
    OpenWorlds.push_back(this);
    this->ParseHeader();
}

World::~World()
{
    if (this->worldfile)
    {
        fclose(this->worldfile);
        this->worldfile = NULL;
    }
}
