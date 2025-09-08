#ifndef WORLD_HPP
#define WORLD_HPP

#include <sys/types.h>

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;
typedef u_int64_t uint64;
typedef u_int32_t uint32;
typedef u_int16_t uint16;
typedef u_int8_t uint8;
typedef char Byte;
typedef char *String;

class World
{

private:
    int32 mapVersion;    // first 4 bytes
    String terrariaEnum; // next 7 bytes
    Byte fileType;       // next byte
    char revision[12];   // skip 12 bytes
    int16 sections;
    int32 *section;

public:
    World(const char *filePath);
    ~World();
};

#endif // WORLD_HPP