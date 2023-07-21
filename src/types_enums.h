#ifndef TYPES_ENUMS_H
#define TYPES_ENUMS_H

typedef enum rdCameraProjectType
{
    rdCameraProjectType_Ortho = 0,
    rdCameraProjectType_Perspective = 1,
    rdCameraProjectType_PerspMVP = 2
} rdCameraProjectType;

typedef enum swrLoader_TYPE
{
    swrLoader_TYPE_MODEL_BLOCK = 0,
    swrLoader_TYPE_SPRITE_BLOCK = 1,
    swrLoader_TYPE_SPLINE_BLOCK = 2,
    swrLoader_TYPE_TEXTURE_BLOCK = 3
} swrLoader_TYPE;
#endif // TYPES_ENUMS_H
