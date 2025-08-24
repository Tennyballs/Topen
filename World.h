#ifndef WORLD_H
#define WORLD_H

class World
{
private:
    FILE *worldfile;

    size_t index;

    int version = 0;
    char *magicNumber = "unknown";
    char fileType = 0;
    std::vector<int> pointers = std::vector<int>();

    inline void Skip(size_t offset) { this->index += offset; };
    int8_t ReadString(void *);

    int8_t ReadInt8();
    int16_t ReadInt16();
    int32_t ReadInt32();
    int64_t ReadInt64();

    u_int8_t ReadUInt8();
    u_int16_t ReadUInt16();
    u_int32_t ReadUInt32();
    u_int64_t ReadUInt64();

    void ParseHeader();

public:
    World(char *);
    ~World();
};

#endif