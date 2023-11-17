#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef struct LoaderConfig
{
    uint32_t assetBufferByteSize;
    int changeWindowFlags;
    float cameraFOV;
    int developperMode;
} LoaderConfig;

extern LoaderConfig g_config;

void setDefaultConfigValues();
void parseConfig();
void printConfig();

#endif // CONFIG_H
