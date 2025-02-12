#ifndef TYPES_H
#define TYPES_H

// Ghidra: File -> Parse C Source -> Add types.h -> Parse to Program -> Use open archive

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "types_a3d.h"
#include "types_directx.h"
#include "types_enums.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct swrModel_unk;
    struct swrUI_unk;
    struct swrUI_unk2;
    struct swr_unk3;
    struct RdFace;
    struct swrDisplayMode;
    struct swrSoundUnk2;
    struct RdModel3;
    struct RdPuppet;
    struct RdPolyline;
    struct rdSprite3;
    struct RdParticle;

    typedef struct
    {
        union
        {
            struct
            {
                unsigned short size_short; // -8
                unsigned short pad;
            };
            uint32_t size; // -8
        };
        uint32_t unk1; // -4
        uint8_t data[]; // 0 Pointer which is actually returned
    } Allocation;

    typedef POINT tagPOINT;
    /*{
        long x;
        long y;
    } tagPOINT;*/

    typedef FILE* stdFile_t;

    typedef struct rdVector2
    {
        float x;
        float y;
    } rdVector2; // sizeof(0x8)

    typedef struct rdVector3
    {
        float x;
        float y;
        float z;
    } rdVector3; // sizeof(0xc)

    typedef struct rdVector4
    {
        float x;
        float y;
        float z;
        float w;
    } rdVector4; // sizeof(0x10)

    typedef struct rdMatrix33
    {
        rdVector3 rvec;
        rdVector3 lvec;
        rdVector3 uvec;
    } rdMatrix33; // sizeof(0x30)

    typedef struct rdMatrix34
    {
        rdVector3 rvec;
        rdVector3 lvec;
        rdVector3 uvec;
        rdVector3 scale;
    } rdMatrix34; // sizeof(0x3c)

    typedef struct rdMatrix44
    {
        rdVector4 vA;
        rdVector4 vB;
        rdVector4 vC;
        rdVector4 vD;
    } rdMatrix44; // sizeof(0x40)

    typedef struct rdClipFrustum
    {
        int bFarClip;
        float zNear;
        float zFar;
        float nearPlane;
        float farPlane;
        float orthoLeftPlane;
        float orthoTopPlane;
        float orthoRightPlane;
        float orthoBottomPlane;
        float topPlane;
        float bottomPlane;
        float leftPlane;
        float rightPlane;
        rdVector3 leftPlaneNormal;
        rdVector3 rightPlaneNormal;
        rdVector3 topPlaneNormal;
        rdVector3 bottomPlaneNormal2;
    } rdClipFrustum; // sizeof(0x64) == 100

    // Indy
    typedef struct RdLight
    {
        int num;
        int unknown1;
        int bIlluminateFace;
        int unknown3;
        int numLights;
        int unknown5;
        rdVector4 color;
        float minRadius;
        float maxRadius;
    } RdLight;

    // jkdf2
    typedef struct rdLight
    {
        uint32_t id;
        int32_t type;
        uint32_t active;
        rdVector3 direction;
        float intensity;
        float color;

        // #ifdef JKM_LIGHTING
        //         float angleX;
        //         float cosAngleX;
        //         float angleY;
        //         float cosAngleY;
        //         float lux;
        // #else
        float dword20;
        uint32_t dword24;
        // #endif
        float falloffMin;
        float falloffMax;
    } rdLight;

    typedef struct rdTexFormat // == ColorInfo. use ColorInfo
    {
        rdTexFormatMode mode;
        uint32_t bpp;
        uint32_t r_bits;
        uint32_t g_bits;
        uint32_t b_bits;
        uint32_t r_shift;
        uint32_t g_shift;
        uint32_t b_shift;
        uint32_t r_bitdiff;
        uint32_t g_bitdiff;
        uint32_t b_bitdiff;
        uint32_t alpha_bits;
        uint32_t alpha_shift;
        uint32_t alpha_bitdiff;
    } rdTexFormat; // sizeof(0x38)

    typedef struct stdVBufferTexFmt // == tRasterInfo. Use tRasterInfo
    {
        int32_t width;
        int32_t height;
        uint32_t texture_size_in_bytes;
        uint32_t width_in_bytes;
        uint32_t width_in_pixels;
        rdTexFormat format;
    } stdVBufferTexFmt; // sizeof(76)

    typedef struct rdDDrawSurface
    {
        IDirectDrawSurface4Vtbl* lpVtbl; // 0x0
        uint32_t direct3d_tex; // 0x4
        DDSURFACEDESC2 surface_desc; // 0x8
        uint32_t texture_id;
        uint32_t texture_loaded;
        uint32_t is_16bit;
        uint32_t width;
        uint32_t height;
        uint32_t texture_area;
        uint32_t gpu_accel_maybe;
        rdDDrawSurface* tex_prev;
        rdDDrawSurface* tex_next;
    } rdDDrawSurface;

    typedef struct stdFileSearch
    {
        int searchMode;
        int isNotFirst;
        char path[128];
        intptr_t filesearchHandle;
    } stdFileSearch; // sizeof 0x8c = 140

    typedef struct stdFileSearchResult
    {
        char fpath[256];
        int field_100;
        int is_subdirectory;
        int time_write;
    } stdFileSearchResult;

    /* 1130 */
    typedef struct StdDisplayDevice // Jones
    {
        char aDeviceName[128];
        char aDriverName[128];
        int bHAL;
        int bGuidNotSet;
        int bWindowRenderNotSupported;
        int totalVideoMemory;
        int freeVideoMemory;
        DDCAPS_DX5 ddcaps; // Modified DX6
        GUID guid;
    } StdDisplayDevice;

    typedef struct stdVBuffer // 0x00ec8da0. == tVBuffer. Use tVBuffer
    {
        uint32_t bSurfaceLocked;
        uint32_t lock_cnt;
        stdVBufferTexFmt format;
        void* palette;
        char* surface_lock_alloc; // sizeof(width_in_pixels)
        uint32_t transparent_color;
        rdDDrawSurface* ddraw_surface; // 0x00ec8e00 = offset 96 = 0x60
        DDSURFACEDESC2 desc;
    } stdVBuffer; // sizeof (224), Allocated at FUN_004881c0

    typedef struct rdCanvas
    {
        // OpenJKDF2
        // uint32_t bIdk;
        // stdVBuffer* vbuffer;
        // float screen_height_half;
        // float screen_width_half;
        // stdVBuffer* d3d_vbuf;
        // uint32_t field_14;
        // int xStart;
        // int yStart;
        // int widthMinusOne;
        // int heightMinusOne;

        uint32_t bIdk;
        stdVBuffer* vbuffer;
        float screen_height_half;
        float screen_width_half;
        int xStart; // 0x10
        int yStart; // 0x14
        int widthMinusOne; // 0x18
        int heightMinusOne; // 0x1c
    } rdCanvas; // sizeof 0x20

    typedef struct rdCamera
    {
        rdCameraProjectType projectType; // 0x0
        rdCanvas* canvas; // 0x4
        rdMatrix34 view_matrix; // 0x8
        float fov; // 0x38
        float fov_y; // 0x3c
        float screenAspectRatio; // 0x40
        float orthoScale; // 0x44
        rdClipFrustum* pClipFrustum; // 0x48
        void (*fnProject)(rdVector3*, rdVector3*); // 0x4c
        void (*fnProjectLst)(rdVector3*, rdVector3*, unsigned int); // 0x50
        float ambientLight;
        uint32_t unk;
        rdVector4 unk2;
        int numLights; // 0x6c
        rdLight* lights[128]; // Jkdf 64, Indy 128. really 128 ?
        rdVector3 lightPositions[128];
        float attenuationMin;
        float attenuationMax;
    } rdCamera; // sizeof 0x878 ok

    typedef struct HostServices
    {
        float some_float;
        int (*messagePrint)(const char*, ...);
        int (*statusPrint)(const char*, ...);
        int (*warningPrint)(const char*, ...);
        int (*errorPrint)(const char*, ...);
        int (*debugPrint)(const char*, ...);
        void (*assert)(const char*, const char*, int);
        uint32_t unk_0;
        void* (*alloc)(unsigned int);
        void (*free)(void*);
        void* (*realloc)(void*, unsigned int);
        uint32_t (*getTimerTick)();
        stdFile_t (*fileOpen)(const char*, const char*);
        int (*fileClose)(stdFile_t);
        size_t (*fileRead)(stdFile_t, void*, size_t);
        char* (*fileGets)(stdFile_t, char*, size_t);
        size_t (*fileWrite)(stdFile_t, void*, size_t);
        int (*feof)(stdFile_t);
        int (*ftell)(stdFile_t);
        int (*fseek)(stdFile_t, int, int);
        int (*fileSize)(stdFile_t);
        int (*filePrintf)(stdFile_t, const char*, ...);
        wchar_t* (*fileGetws)(stdFile_t, wchar_t*, size_t);
        void* (*allocHandle)(size_t);
        void (*freeHandle)(void*);
        void* (*reallocHandle)(void*, size_t);
        uint32_t (*lockHandle)(uint32_t);
        void (*unlockHandle)(uint32_t);
    } HostServices;

    typedef LRESULT (*Window_MSGHANDLER)(HWND, UINT, WPARAM, LPARAM, UINT*);
    typedef Window_MSGHANDLER* Window_MSGHANDLER_ptr;

    typedef enum TGADataType
    {
        TGADataType_NOIMAGEDATA = 0,
        TGADataType_UNCOMPRESSEDCOLORMAPPED = 1,
        TGADataType_UNCOMPRESSEDRGB = 2,
        TGADataType_UNCOMPRESSEDBW = 3,
        TGADataType_RLECOLORMAPPED = 9,
        TGADataType_RLERGB = 10,
        TGADataType_COMPRESSEDBW = 11,
        TGADataType_COMPRESSEDCOLORMAPPED = 32,
        TGADataType_COMPRESSEDCOLORMAPPEDQUADTREE = 33,
    } TGADataType;

    typedef struct TGAHeader
    {
        char idlength;
        char colormaptype;
        TGADataType datatypecode;
        short int colormaporigin;
        short int colormaplength;
        char colormapdepth;
        short int x_origin;
        short int y_origin;
        short width;
        short height;
        char bitsperpixel;
        char imagedescriptor;
    } TGAHeader; // sizeof(18); PACK 1 !

    typedef struct swrSpriteTexturePage
    {
        unsigned short width; // 0x0
        unsigned short height; // 0x2
        uint32_t offset; // 0x4
    } swrSpriteTexturePage; // sizeof(0x8)

    typedef struct swrSpriteTextureHeader
    {
        unsigned short width; // 0x0
        unsigned short height; // 0x2
        uint8_t format; // 0x4 actual format?
        uint8_t page_width_align; // 0x5 page width alignment: 0=0x10, 1=0x8, 2=0x4, 3=0x2, 7=0x2. all other values are undefined
        unsigned short unk3; // 0x6 always zero?
        uint32_t palette_offset; // 0x8 palette pointer
        unsigned short page_count; // 0xC page count
        unsigned short unk6; // 0xE always 32 [bits per pixel?]
        swrSpriteTexturePage* page_table; // 0x10 pagetable pointer
        // 0x14 bytes total, but will be followed by its page, palette and pixel data normally
    } swrSpriteTextureHeader; // sizeof(0x14)

    typedef struct swrSpriteTexture
    {
        swrSpriteTextureHeader header;
        swrSpriteTexturePage* pages; // Exists as a 0 sized array
        // char[] palette; // Exists as a 0 sized array under pages
    } swrSpriteTexture;

    typedef struct swrSprite
    {
        short x; // Position x
        short y; // Position y
        short unk0x4; // 0x4, written in sub_4286C0
        short unk0x6; // 0x6, written in sub_4286C0
        float width; // 0x8 Size X
        float height; // 0xC Size Y
        uint32_t unk0x10; // written in sub_428720
        uint32_t flags; // Flags:
                        // 0x10000 = position is again different + size is different
                        // 0x8000 = colors are weird? might be unrelated?!
                        // 0x4000 = can't find the image on screen?!
                        // 0x2000 = ???
                        // 0x1000 = offsets the image
                        // 0x800 = ???
                        // 0x400 = ???
                        // 0x200 = ???
                        // 0x100 = tiles differently
                        // 0x80 = tiles the image somewhat?
                        // 0x40 = ???
                        // 0x20 = stay in memory?
                        // 0x10 = ???
                        // 0x8 = mirror vertically
                        // 0x4 = mirror horizontally
                        // 0x2 = ???
                        // 0x1 = used/displayed?
        uint8_t r; // 0x18 R
        uint8_t g; // 0x19 G
        uint8_t b; // 0x1A B
        uint8_t a; // 0x1B A
        swrSpriteTexture* texture; // 0x1C, written in sub_4282F0
        // 32 bytes
    } swrSprite;

    typedef struct swrSpriteTexItem
    {
        swrSpriteTexture* texture;
        int id; // 0x4
    } swrSpriteTexItem; // sizeof(0x8)

    typedef struct swrSprite_BBox
    {
        unsigned int x;
        unsigned int y;
        unsigned int x2;
        unsigned int y2;
    } swrSprite_BBox; // sizeof(0x10)

    typedef struct swrTranslationRotation
    {
        rdVector3 translation;
        rdVector3 yaw_roll_pitch;
    } swrTranslationRotation;

    typedef struct PodHandlingData
    {
        float antiSkid;
        float turnResponse;
        float maxTurnRate;
        float acceleration;
        float maxSpeed;
        float airBrakeInv;
        float deceleration_interval;
        float boost_thrust;
        float heatRate;
        float coolRate;
        float hoverHeight;
        float repairRate;
        float bumpMass;
        float damageImmunity;
        float intersectRadius;
    } PodHandlingData; // sizeof(0x3c) == 0xf floats OK

    // Used to do the C-style "Inheritance" for different game objects
    typedef struct swrObj
    {
        int event;
        short id; // 0x4
        short flags; // 0x6
    } swrObj; // sizeof(0x8)

    typedef struct swrRace // swrObjTest
    {
        swrObj obj;
        swrTranslationRotation translation_rotation; // 0x8. See fun_00454d40. FUN_00473f40
        rdMatrix44 transform; // 0x20
        uint32_t flags0;
        uint32_t flags1;
        char unk1_1[2];

        float antiskid; // 0x6c. Something is wrong here. void* ?
        float turnResponse; // 0x70. Something is also wrong here. Is it really turnResponse ?
        float maxTurnRate; // 0x74
        char unk2[4];
        float topSpeed; // 0x7c
        float airBrakeInterval; // 0x80
        float decelerationInterval; // 0x84
        float boostThrust; // 0x88
        float heatRate; // 0x8c
        float coolRate; // 0x90
        float hoverHeight; // 0x94
        float repairRate; // 0x98
        float scaleUnk; // 0x9c
        uint32_t damageImmunity; // 0xa0
        float intersectRadius; // 0xa4
        char unk4[4];
        rdMatrix34 unk4_mat; // 0xac
        char unk4_0100[34];
        int unk4_0101; // 0x100
        char unk4_0102[8];
        short unk4_0103; // 0x10c
        short unk4_0104; // 0x10e
        int unk4_0105; // 0x110
        int unk4_0106; // 0x114
        rdVector4 unk4_0107; // 0x118
        char unk4_0108[20];
        swrModel_unk* model_unk; // 0x13c
        char unk4_02[4];
        rdVector3 unk4_021; // 0x144
        int unk4_022; // 0x148
        rdVector3 unk4_03; // 0x154
        rdVector3 unk4_1; // 0x160
        rdVector3 currentPos; // 0x16c. Same as 0x2cc position ?
        char unk5[12];
        float groundToPodMeasure; // 0x184. Same as 0x94 hoverHeight ?
        float thrust; // 0x18c. default 0.1, 1.0 with thrust, 1.32 thrust nose down, 0.68 thrust nose up
        float gravityMultiplier; // 0x190
        float unk6; // float, 0x194, fall related
        rdVector3 unk6_1; // 0x198
        float speedValue; // 0x1a0
        float speedValue2; // 0x1a4 ??
        float boostValue; // 0x1a8
        float speedMultiplier; // 0x1ac
        float fallRate; // 0x1b0
        float fallValue; // 0x1b4
        rdVector3 speedDir; // 0x1b8
        rdVector3 unk7; // 0x1c4
        rdVector3 unk7_1; // 0x1d0
        rdVector3 unk7_11; // 0x1e4
        char unk7_2[4];
        float unk7_3; // 0x1ec
        float projTurnRate; // 0x1f0
        float unk8; // 0x1f4
        float unk8_1; // 0x1f8
        float unk8_11; // 0x1fc
        float unk8_12; // 0x200
        float unk8_13; // 0x204
        float tilt; // 0x208 -1 tilt left, 0 neutral, 1 tilt right
        int unk9; // 0x20c
        uint32_t boostIndicatorStatus; // 0x210 0 not ready, 1 charging, 2 ready
        float boostChargeProgress; // 0x214
        float engineTemp; // 0x218
        char unk10[4];
        float unk10_1; // 0x220
        float unk10_2; // 0x224
        int unk10_3; // 0x228
        uint32_t multiplayerStats; // 0x22c. This is weird. Should be float ?
        char unk11[16];
        float terrainSpeedOffset; // 0x240
        float terrainSpeedMultiplier; // 0x244
        float terrainSkidModifier; // 0x248
        float slide; // 0x24c
        int unk11_1; // 0x250
        char unk12[16];
        float unk12_1; // 0x264
        float unk12_2; // 0x268 an angle of some kind ?
        int unk12_3; // 0x. Some flag. See FUN_0047a930
        char unk12_4[24]; // engine health related
        float engineHealth[6]; // 0x288 left top-mid-bot, right top-mid-bot
        char unk13[28]; // engine flag ?
        float repairTimer; // 0x2bc
        char unk14[4];
        float totalDamage; // 0x2c4
        float oobTimer; // 0x2c8
        rdVector3 position; // 0x2cc
        char unk15[12];
        rdVector3 turnInput; // 0x2e4
        char unk16[12];
        float pitch; // 0x2fc .8 pitch down -.8 pitch up
        // Behold the great unknown
        char unk17__19[64 * 3];
        rdVector3 unk19_0; // 0x3c0
        char unk20[52];
        rdVector3 unk20_0; // 0x400
        char unk21[52];
        char unk440[6704];
        char unk1e70[184]; // 0x1e70
    } swrRace; // at 0x00e29c44 sizeof(?). From Objs: sizeof(0x1f28)

    typedef struct swrObjToss
    {
        swrObj obj;
        char unk8[24];
        rdMatrix44 mat;
        int unk60;
        int unk64;
        float unk68_ms;
        float unk6c;
        char unk70;
        char unk71;
        char unk72;
        char unk73;
        void* unk74;
        void* unk78;
    } swrObjToss; // sizeof(0x7c)

    typedef struct swrObjTrig
    {
        swrObj obj;
        int modelId; // 0x8 // supposed modelId
        int flag; // 0xc
        float unk10_ms;
        float unk14_ms;
        char unk18[12];
        rdVector3 unk24;
        rdVector3 unk30;
        int unk3c;
        int unk40;
        int unk44;
        void* unk48;
        void* unk4c;
        void* unk50;
        int unk54;
    } swrObjTrig; // sizeof(0x58)

    typedef struct swrObjHang
    {
        swrObj obj;
        swrObjHang_STATE state;
        char unkc[4];
        int unk10;
        int flag;
        char unk18[8];
        swrModel_unk* unk20_model;
        swrModel_unk* unk24_model;
        char unk28[4];
        swrModel_unk* unk2c_model;
        char unk30[4];
        int unk34_index;
        int unk38;
        char unk3c[4];
        int unk40_index;
        char unk44[4];
        char unk48[24];
        char unk60;
        char unk61[11];
        char unk6c[64];
        char unkac[36];
    } swrObjHang; // sizeof(0xd0)

    typedef struct swrObjJdge
    {
        swrObj obj;
        int flag;
        float unkc_ms;
        swrModel_unk* unk10;
        void* unk14;
        void* unk18;
        void* unk1c;
        void* unk20;
        void* unk24;
        swrModel_unk* unk28_model;
        int unk2c_spline;
        int unk30;
        int unk34;
        float unk38;
        int unk3c;
        int unk40;
        char unk44[16];
        int unk54;
        int unk58;
        int unk5c;
        int unk60;
        rdMatrix44 unk64_mat;
        rdMatrix44 unk80_mat;
        rdMatrix44 unkbc_mat;
        int unk124;
        int event;
        char unk128[4];
        void* unk12c;
        rdMatrix44 unk134_mat;
        rdMatrix44 unk170_mat;
        int unk1a4;
        int unk1a8;
        int unk1ac_index;
        char unk1b0[4];
        int unk1b4_splineId;
        int unk1b8_splineId;
        int unk1bc_count;
        int unk1c0_type;
        char unk1c4[4];
        int unk1c8_index;
        float unk1cc_ms;
        float best_lap_time_ms;
        char unk1d4[4];
        int unk1d8;
        int unk1dc;
        int unk1e0;
        float unk1e4;
    } swrObjJdge; // sizeof(0x1e8)

    typedef struct swrObjScen
    {
        swrObj obj;
        int unk8;
        int unkc;
        char unk0_0[64];
        int unk50;
        char unk0_1[48];
        rdMatrix44 unk84_mat;
        int unkc4;
        char unkc8[72];
        char unk110[264];
        char unk218[264];
        char unk320[264];
        char unk428[264];
        char unk530[264];
        char unk0_2[264];
        char unk0_3[264];
        char unk0_4[264];
        char unk0_5[264];
        char unk0_6[208];
        rdMatrix44 unkb28_mat;
        char unk0_7[264];
        char unk0_8[264];
        char unk0_9[264];
        char unk0_10[264];
        char unk0_11[264];
        char unk0_12[264];
        char unk0_13[264];
        char unk0_14[264];
        char unk0_15[264];
        char unk0_16[264];
        char unk0_17[264];
        char unk0_18[264];
        char unk0_19[264];
        char unk0_20[264];
        char unk0_21[264];
        char unk0_22[108];
    } swrObjScen; // sizeof(0x1b4c)

    typedef struct swrObjElmo
    {
        swrObj obj;
        int unk8;
        int unkc;
        char unk10[4];
        void* unk14;
        float unk18_ms;
        float unk1c_ms;
        char unk1c[16];
        swrModel_unk** unk30;
        void* unk34;
        char unk38[16];
        float unk48_angle_degrees;
        char unk4c[4];
        rdVector3 unk50;
        char unk5c[12];
        float unk68;
        float unk6c_angle_degrees;
        int unk70;
        char unk74[8];
        char unk7c[12];
        int unk88;
        char unk8c[8];
        int unk94;
        char unk98[14];
        float unka8_ms;
        float unkac_ms;
        char unkb0[4];
        int unkb4;
        char unkb8[8];
    } swrObjElmo; // sizeof(0xc0)

    typedef struct swrObjSmok
    {
        swrObj obj;
        char unk8[32];
        char unk28[32];
        char unk48[24];
        int unk60;
        int unk64;
        float unk68_ms;
        char unk6c[4];
        int unk70;
        float unk74;
        float unk78;
        float unk7c;
        char unk80[4];
        float unk84;
        float unk88;
        float unk8c;
        float unk90;
        float unk94;
        float unk98;
        float unk9c;
        float unka0;
        float unka4;
        float unka8_ms;
        char unkac[28];
        char unkc8[12];
        float unkd4_ms;
        float unkd8_ms;
        char unkdc[12];
        char unke8[8];
        float unkf0;
        swrModel_unk* unkf4_model;
        float unkf8;
        float unkfc;
        float unk100;
        float unk104;
    } swrObjSmok; // sizeof(0x108)

    typedef struct swrObjcMan
    {
        swrObj obj;
        rdVector3 unk8;
        rdVector3 unk14;
        rdMatrix44 unk20_mat;
        int unk60;
        int unk64;
        int unk6c;
        int unk6c_count;
        float unk70_ms;
        int unk74_count;
        int unk78;
        int unk7c_type;
        int unk80;
        rdMatrix34 unk84_mat;
        rdMatrix44 unkb4_mat;
        swrRace* unkf4_objTest;
        int unkf8;
        rdVector3 unkfc;
        rdMatrix44 unk108_mat;
        float unk148;
        float unk14c;
        int unk150;
        int unk154;
        int unk158;
        float unk15c[12];
        char unk0_0[12];
        float unk198;
        float unk19c;
        float unk1a0;
        int unk1a4;
        int unk1a8;
        int unk1ac;
        int unk1b0;
        rdMatrix44 unk1b4_mat;
        rdMatrix44 unk1e4_mat;
        rdMatrix44 unk224_mat;
        rdMatrix44 unk264_mat;
        int unk2a4;
        int unk2a8_flag;
        unsigned int unk2ac_flag;
        float unk2b0;
        float unk2b4;
        float unk2b8;
        unsigned int unk2bc;
        unsigned int unk2c0;
        unsigned int unk2c4;
        unsigned int unk2c8;
        unsigned int unk2cc;
        unsigned int unk2d0;
        float unk2d4;
        float unk2d8;
        float unk2dc;
        float unk2e0;
        unsigned int unk2e4_flag;
        float unk2e8;
        float unk2ec;
        float unk2f0;
        rdVector3 unk2f4;
        rdVector3 unk300;
        rdVector3 unk30c;
        float unk310;
        float unk314;
        float unk318;
        float unk31c;
        float unk320;
        float unk324;
        float unk330;
        float unk334;
        float unk338;
        float unk33c;
        rdVector3 unk340;
        float unk34c;
        float unk350;
        float unk354;
        rdVector3 unk358;
        float unk35c;
        rdVector3 unk368;
        rdVector3 unk374;
        rdVector3 unk380;
        rdVector3 unk38c;
        float unk398_ms;
        float unk39c;
        float unk3a0;
        float unk3a4;
    } swrObjcMan; // sizeof(0x3a8)

    typedef struct swrEventManager
    {
        int event; // 0x0 Trig, Test,...
        int flags; // 0x4.
        int count; // 0x8
        int size; // 0xca
        swrObj* head; // 0x10
        void (*f0)(swrObj* obj); // 0x14
        void (*f1)(swrObj* obj); // 0x18
        void (*f2)(swrObj* obj); // 0x1c
        void (*f3)(swrObj* obj); // 0x20
        void (*f4)(swrObj* obj, int* subEvent); // 0x24 int[2] subEvent
    } swrEventManager; // sizeof(0x28)

    typedef struct swrObj_Message // Unused but documentation purpose
    {
        unsigned int subevent;
        // Cman: Shak, Deth, CBut, Swee, RSet, Load, NAsn
        // Jdge: Slep, Mstr, Begn, Wake, Load
        // All!: Abrt, Fini, Paws
        // Scen: Begn, Wake, Step, Load
        // Hang: Stop, Load
        // Test: Load
        // Smok: Load
        // Toss: Load
        // Trig: Load
        // Elmo: Load
        union
        {
            struct swrObj_CmanMessageShak
            {
                float unk4;
                float unk8;
            } cmanShak;
            struct swrObj_CmanMessageDeth
            {
                swrRace* objTest;
            } cmanDeth;
            struct swrObj_CmanMessageCBut
            {
                swrRace* objTest;
            } cmanCBut;
            struct swrObj_CmanMessageSwee
            {
                unsigned int bunk4;
            } cmanSwee;
            struct swrObj_CmanMessageNAsn
            {
                unsigned int id;
            } cmanNAsn;
            struct swrObj_AllMessagePaws
            {
                int i; // 1 | -1
            };
            struct swrObj_ScenMessageBegn
            {
                void* obj_unk;
                int unk_count;
                int unk_index;
                MODELID modelId;
                SPLINEID splineId1;
                SPLINEID splineId2;
                int unk_type;
                float unk_ms;
                int unk_index;
                char unused[8];
                void* unk_ptr;
                int bUnk;
                int unk_e;
            };
        } u;
    } swrObj_Message;

    typedef struct swrScore
    {
        float time_unk;
        int identifier; // AAll, Locl
        int flag;
        char unkc;
        char unkd;
        char unke[2];
        int unk10;
        int unk14;
        int unk18;
        PodHandlingData podStats;
        short unk58;
        short unk5a;
        int results_P1_Position;
        float results_P1_Lap1;
        float results_P1_Lap2;
        float results_P1_Lap3;
        float results_P1_Lap4;
        float results_P1_Lap5;
        float results_P1_total_time;
        float results_P1_Lap;
        int unk7c;
        float lastRaceDamage;
        void* P1_ui_writer;
    } swrScore; // sizeof(0x88)

    typedef struct swrRace_unk
    {
        char unk[4]; // 0x0
        int unk1; // 0x4
        int unk2; // 0x8
        char unk3[8];
        rdMatrix44 unk4; // 0x14
        char unk5[24];
        rdVector4 unk6; // 0x6c
    } swrRace_unk; // sizeof(0x7c). At 0x04b91c4 ?

    typedef struct swr_unk1 // == RdModel3
    {
        char unk[120];
        swr_unk3* unk2_swrunk3;
        char unk3[20];
    } swr_unk1; // sizeof(0x90). Match RdModel3 0x0050c6b0. See FUN_00408e40

    typedef struct swr_unk2
    {
        char unk[0xd8cc0];
    } swr_unk2; // sizeof(0xd8cc0). See FUN_00408e40

    typedef struct swr_unk3
    {
        char unk[0x1abbc0];
    } swr_unk3; // sizeof(0x1abbc0). See FUN_00408e40

    typedef struct swrSound
    {
        int unk0;
        int id;
        int unk;
        int unk1;
        int unk2;
        float pitch;
        int unk4;
        short unk5;
        short unk51;
        IA3dSource* source;
        char unk6[8];
        rdVector3 pos;
        int unk7;
        float maxDist;
        float minDist;
    } swrSound; // sizeof(0x44) in [8] ?. See DAT_00e68080

    typedef int (*swrUI_unk_F1)(swrUI_unk* self, int param_2, void* param_3, int param_4);
    typedef int (*swrUI_unk_F2)(swrUI_unk* self, unsigned int param_2, void* param_3, swrUI_unk* ui2);

    typedef struct swrUI_unk2
    {
        int flag;
        int unk0;
        int sprite_ingameId;
        float unk2;
        float unk3;
        int unk31;
        int unk32;
        int unk33;
        int unk34;
        void* unk35;
        void* unk36;
        int unk37;
        int unk38;
        char unk4;
        char unk5;
        char unk6;
        char unk7;
    } swrUI_unk2; // sizeof(0x38) in a [20]

    typedef struct swrUI_unk
    {
        swrUI_unk* prev2;
        swrUI_unk* next2;
        swrUI_unk* prev;
        swrUI_unk* next;
        swrUI_unk_F1 fun;
        swrUI_unk_F2 fun2;
        int unk00_6;
        int id;
        int unk00_flag;
        int unk00_7;
        int unk00_8;
        int unk00_9;
        int unk00_10;
        char unk01[8];
        int size_unk1;
        int size_unk2;
        char* unk01_10;
        char unk01_11[20];
        int sprite_count;
        swrUI_unk2 unk0_0[20];
        char unk0_0_99;
        char unk0_0_100;
        char unk0_0_101;
        char unk0_0_102;
        char unk0_0_103;
        char unk0_0_104;
        char unk0_0_105;
        char unk0_0_106;
        char unk0_0_107;
        char unk0_0_108;
        char unk0_0_109;
        char unk0_0_110;
        char unk0_0_111;
        char unk0_0_112;
        char unk0_0_113;
        char unk0_0_114;
        char unk0_0_115;
        char unk0_0_116;
        char unk0_0_117;
        char unk0_0_118;
        char* str_allocated;
        char unk0_0_119[4];
        int unk0_index;
        int unk0_100;
        int unk0_101;
        int unk0_102;
        int unk0_103;
        unsigned int unk0_flag;
        char unk1[64];
        int unk1_50;
        char unk2[4232];
    } swrUI_unk; // sizeof(0x15c0 + unk size)

    typedef struct swrModel_unk // ~ cMan
    {
        unsigned int flag;
        int unk4;
        int unk8;
        int unkc;
        short unk10;
        short unk12;
        short unk14;
        short unk16;
        short unk18;
        short unk1a;
        short unk1c;
        short unk1e;
        float unk20;
        float unk24;
        int unk28;
        int unk2c;
        rdMatrix44 unk_mat1; // 0x30
        rdMatrix44 unk_mat2;
        rdMatrix44 unk_mat3;
        rdMatrix44 clipMat; // 0xf0;
        short unk130;
        short unk132;
        float fov_y_degrees; // 0x134;
        float aspect_ratio; // 0x138;
        float unk13c;
        float near_clipping; // 0x140;
        float far_clipping; // 0x144;
        float unk148;
        int unk14c;
        float unk150;
        float unk154;
        int unk158;
        int unk15c;
        int unk160;
        int unk164;
        int unk168;
    } swrModel_unk; // sizeof(0x16c)

    typedef struct stdTextureFormat
    {
        rdTexFormat texFormat;
        int bColorKey;
        LPDDCOLORKEY pColorKey;
        DDPIXELFORMAT pixelFormat;
    } stdTextureFormat; // sizeof(0x60)

    // See Jones Device3D. Matching for meaning but not size
    typedef struct swr3DDevice
    {
        unsigned int flags;
        unsigned int TriTexCapsUnk1;
        unsigned int hasZBuffer;
        int TriTexCapsUnk4;
        int TriTexCapsUnk2;
        int TriTexCapsUnk3;
        int hasTexBlendUnk;
        int TriTexCapsUnk5;
        int minTexWidth;
        int minTexHeight;
        int maxTexWidth;
        int maxTexHeight;
        int maxVertexCount;
        char name[128];
        char description[128];
        char unk1[8];
        D3DDEVICEDESC deviceDesc;
        GUID guid; // 0x238
        char unk[0x288];
    } swr3DDevice; // sizeof(0x368)

    typedef struct swrDrawDevice // = StdDisplayDevice
    {
        char driver_desc[128];
        char driver_name[128];
        int isEmulationOrHardware;
        int supportUnk1;
        int useActiveDevice; // !isEmulationOrHardware
        int supportUnk2;
        int unk2;
        int unk3;
        char unk1[380];
        GUID guid; // 0x294
    } swrDrawDevice; // sizeof(0x2a4)

    typedef struct swrDrawDevice3D
    {
        swrDrawDevice drawDevice; // 0x0
        int nbDisplayModes; // 0x2a4
        swrDisplayMode* displayModes; // 0x2a8
        int nb3dDevices; // 0x2ac
        swr3DDevice* swr3dDevices; // 0x2b0
    } swrDrawDevice3D; // sizeof(0x2b4)

    typedef struct swrDrawDevices
    {
        unsigned int nbDevices;
        swrDrawDevice* devices;
    } swrDrawDevices;

    typedef struct swrDisplayWindow
    {
        float aspectRatio; // 0x0
        int width; // 0x4
        int height; // 0x8
        int size; // 0xc
        unsigned int linearSize; // 0x10
        unsigned int halfLinearSize; // 0x14
    } swrDisplayWindow;

    typedef struct swrDisplayMode // = StdVideoMode
    {
        swrDisplayWindow displayWindow;
        rdTexFormat texFormat;
    } swrDisplayMode; // sizeof(0x50)

    typedef struct swrRenderUnk
    {
        char unk[64];
    } swrRenderUnk; // sizeof(0x40)

    typedef struct swrSoundUnk
    {
        int prime_nbUnks2;
        swrSoundUnk2* unks2; // sizeof(prime * 16)
        void* f;
    } swrSoundUnk; // sizeof(0xc)

    typedef struct swrSoundUnk2
    {
        char unk[0x10];
    } swrSoundUnk2; // sizeof(0x10)

    typedef struct swrUI_Unk3 // == rdThing. Size OK
    {
        int unk0;
        swr_unk1* unk1;
        int unk2;
        int unk3;
        int unk4_canvas;
        int unk5;
        int unk6;
        int unk7_alloc;
        int unk71_alloc;
        int unk8_alloc;
        int unk9;
        int unk10;
        int unk11;
        int unk12;
        char unk13[4];
        int unk14;
    } swrUI_Unk3; // sizeof(0x40)

    typedef struct ColorInfo ColorInfo;

    typedef struct swrMaterial // use RdMaterial instead
    {
        char filename[64];
        char unk40[4];
        ColorInfo colorInfo;
        int unk_mat_flag;
        char unk80[8];
        unsigned int nbTextures;
        int unk8c;
        void* textures_alloc;
    } swrMaterial; // sizeof(0x94)

    typedef struct rdMaterialHeader
    {
        uint8_t magic[4];
        uint32_t revision;
        uint32_t type;
        uint32_t num_texinfo;
        uint32_t num_textures;
        rdTexFormat tex_format;
    } rdMaterialHeader; // sizeof(0x4c) OK

    // typedef struct rdMaterial // OpenJKDF
    // {
    //     uint32_t tex_type;
    //     char mat_fpath[32];
    //     uint32_t id;
    //     rdTexFormat tex_format;
    //     rdColor24* palette_alloc;
    //     uint32_t num_texinfo;
    //     uint32_t celIdx;
    //     rdTexinfo* texinfos[16];
    //     uint32_t num_textures;
    //     rdTexture* textures;
    // } rdMaterial; // sizeof(0xb4) DOESNT MATCH. 32 bytes too much

    typedef struct IDirect3DTexture2* LPDIRECT3DTEXTURE2;
    typedef struct tSystemTexture // Jones
    {
        DDSURFACEDESC2 ddsd;
        LPDIRECT3DTEXTURE2 pD3DSrcTexture;
        LPDIRECT3DTEXTURE2 pD3DCachedTex;
        int textureSize;
        int frameNum;
        tSystemTexture* pPrevCachedTexture;
        tSystemTexture* pNextCachedTexture;
    } tSystemTexture;

    typedef struct RdMaterial // == swrMaterial
    {
        char aName[64];
        int num;
        ColorInfo colorInfo;
        int width;
        int height;
        char unk[4];
        int curCelNum;
        int numCels;
        tSystemTexture* aTextures;
    } RdMaterial; // sizeof(0x94) OK

    typedef struct rdColor24
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    } rdColor24;

    typedef struct rdTexture // for rdFace. Used in game ?
    {
        uint32_t alpha_en;
        uint32_t unk_0c;
        uint32_t color_transparent;
        uint32_t width_bitcnt;
        uint32_t width_minus_1;
        uint32_t height_minus_1;
        uint32_t num_mipmaps;
        stdVBuffer* texture_struct[4];
        rdDDrawSurface alphaMats[4];
        rdDDrawSurface opaqueMats[4];
    } rdTexture;

    typedef struct rdTexinfoHeader // for rdFace
    {
        uint32_t texture_type;
        uint32_t field_4;
        uint32_t field_8;
        uint32_t field_C;
        uint32_t field_10;
        uint32_t field_14;
    } rdTexinfoHeader;

    typedef struct rdTexinfo // for rdFace
    {
        rdTexinfoHeader header;
        uint32_t texext_unk00;
        rdTexture* texture_ptr;
    } rdTexinfo;

    typedef int32_t rdGeoMode_t;
    typedef int32_t rdLightMode_t;
    typedef int32_t rdTexMode_t;

    typedef struct rdFace
    {
        uint32_t num;
        uint32_t type;
        rdGeoMode_t geometryMode;
        rdLightMode_t lightingMode;
        rdTexMode_t textureMode;
        uint32_t numVertices;
        int* vertexPosIdx;
        int* vertexUVIdx;
        RdMaterial* material;
        uint32_t wallCel;
        rdVector2 clipIdk;
        float extraLight;
        rdVector3 normal;
    } rdFace; // sizeof(0x40) OK

    typedef struct rdColormap // rdProcEntry
    {
        char colormap_fname[32];
        uint32_t flags;
        rdVector3 tint;
        rdColor24 colors[256];
        void* lightlevel;
        void* lightlevelAlloc;
        void* transparency;
        void* transparencyAlloc;
        void* dword340;
        void* dword344;
        void* rgb16Alloc;
        void* dword34C;
    } rdColormap;

    // from jkdf2 rdCache
    typedef struct rdProcEntry
    {
        uint32_t extraData;
        int type;
        rdGeoMode_t geometryMode;
        rdLightMode_t lightingMode;
        rdTexMode_t textureMode;
        uint32_t anonymous_4;
        uint32_t anonymous_5;
        uint32_t numVertices;
        rdVector3* vertices;
        rdVector2* vertexUVs;
        float* vertexIntensities; // weird here. sizeof 0x10 ? rdCache_GetProcEntry
        RdMaterial* material;
        uint32_t wallCel;
        float ambientLight;
        float light_level_static;
        float extralight;
        rdColormap* colormap;
        uint32_t light_flags;
        int32_t x_min;
        uint32_t x_max;
        int32_t y_min;
        uint32_t y_max;
        float z_min;
        float z_max;
        int y_min_related;
        int y_max_related;
        uint32_t vertexColorMode;
    } rdProcEntry; // sizeof(0x6c) unsure

    // Indy3D for stdComm_SessionToSettings
    // Real sizeof is 0x41 or 0x104 or 0x82 (FUN_00487450)?
    typedef struct StdCommSessionSettings
    {
        GUID guid;
        int maxPlayers;
        int numCurrentPlayers;
        wchar_t aSessionName[64];
        char aSomething[64];
        wchar_t aPassword[32];
        int user1;
        int user2;
        int user3;
    } StdCommSessionSettings;

    // Indy stdDisplay_SetMode
    typedef struct ColorInfo // rdTexFormat. Use ColorInfo. Rename to rdTexFormat one day ?
    {
        tColorMode colorMode;
        int bpp;
        int redBPP;
        int greenBPP;
        int blueBPP;
        int redPosShift;
        int greenPosShift;
        int bluePosShift;
        int RedShr;
        int GreenShr;
        int BlueShr;
        int alphaBPP;
        int alphaPosShift;
        int AlphaShr;
    } ColorInfo;

    // Indy stdDisplay_SetMode
    typedef struct tRasterInfo
    {
        int width;
        int height;
        int size;
        int rowSize;
        int rowWidth;
        ColorInfo colorInfo;
    } tRasterInfo;

    // Indy stdDisplay_SetMode
    typedef struct StdVideoMode // TODO: StdVideoMode ~= swrDisplayMode !
    {
        float aspectRatio;
        tRasterInfo rasterInfo;
    } StdVideoMode;

    // Indy stdDisplay_VBufferFill
    typedef struct LECRECT
    {
        int left;
        int top;
        int right;
        int bottom;
    } LECRECT;

    typedef struct tagRECT
    {
        LONG left;
        LONG top;
        LONG right;
        LONG bottom;
    } tagRECT;

    typedef struct tagMSG
    {
        HWND hwnd;
        unsigned int message;
        WPARAM wParam;
        LPARAM lParam;
        DWORD time;
        POINT pt;
    } tagMSG;

    // Indy stdDisplay_VBufferFill
    typedef struct tVSurface
    {
        LPDIRECTDRAWSURFACE4 pDDSurf;
        DDSURFACEDESC2 ddSurfDesc;
    } tVSurface; // sizeof(0x80) OK

    // Indy stdDisplay_VBufferFill
    typedef struct tVBuffer // == stdVBuffer. Use tVBuffer
    {
        int lockRefCount;
        int lockSurfRefCount;
        int bVideoMemory;
        tRasterInfo rasterInfo;
        BYTE* pPixels;
        int dword5C;
        tVSurface pVSurface;
    } tVBuffer; // sizeof(0xe0) OK

    // Indy ~= swr3DDevice
    typedef struct Device3D // ~= swrDrawDevice3D
    {
        int bHAL;
        int bTexturePerspectiveSupported;
        int hasZBuffer;
        int bColorkeyTextureSupported;
        int bAlphaTextureSupported;
        int bStippledShadeSupported;
        int bAlphaBlendSupported;
        int bSqareOnlyTexture;
        int minTexWidth;
        int minTexHeight;
        int maxTexWidth;
        int maxTexHeight;
        int maxVertexCount;
        char deviceName[128];
        char deviceDescription[128];
        int totalMemory;
        int availableMemory;
        D3DDEVICEDESC d3dDesc;
        GUID duid;
        int unknown146;
        int unknown147;
        int unknown148;
        int unknown149;
        int unknown150;
        int unknown151;
        int unknown152;
        int unknown153;
        int unknown154;
        int unknown155;
        int unknown156;
        int unknown157;
        int unknown158;
        int unknown159;
        int unknown160;
        int unknown161;
        int unknown162;
        int unknown163;
        int unknown164;
        int unknown165;
        int unknown166;
        int unknown167;
        int unknown168;
        int unknown169;
        int unknown170;
        int unknown171;
        int unknown172;
        int unknown173;
        int unknown174;
        int unknown175;
        int unknown176;
        int unknown177;
        int unknown178;
        int unknown179;
        int unknown180;
        int unknown181;
        int unknown182;
        int unknown183;
        int unknown184;
        int unknown185;
        int unknown186;
        int unknown187;
        int unknown188;
        int unknown189;
        int unknown190;
        int unknown191;
        int unknown192;
        int unknown193;
        int unknown194;
        int unknown195;
        int unknown196;
        int unknown197;
        int unknown198;
        int unknown199;
        int unknown200;
        int unknown201;
        int unknown202;
        int unknown203;
        int unknown204;
        int unknown205;
        int unknown206;
        int unknown207;
        int unknown208;
        int unknown209;
        int unknown210;
        int unknown211;
        int unknown212;
        int unknown213;
        int unknown214;
        int unknown215;
        int unknown216;
        int unknown217;
    } Device3D;

    // StdDisplayEnvironment* std3D_BuildDisplayEnvironment()
    typedef struct StdDisplayInfo // == swrDrawDevice
    {
        StdDisplayDevice displayDevice;
        int numModes;
        StdVideoMode* aModes;
        int numDevices;
        Device3D* aDevices;
    } StdDisplayInfo;

    // StdDisplayEnvironment* std3D_BuildDisplayEnvironment()
    typedef struct StdDisplayEnvironment // == swrDrawDevices
    {
        int numInfos;
        StdDisplayInfo* aDisplayInfos;
    } StdDisplayEnvironment;

    typedef struct tLinkListNode
    {
        tLinkListNode* prev;
        tLinkListNode* next;
        const char* name;
        void* data;
    } tLinkListNode;

    typedef unsigned int (*tHashFunc)(char*, int);
    typedef struct tHashTable
    {
        int numNodes;
        tLinkListNode* paNodes;
        tHashFunc hashFunc;
    } tHashTable;

    // rdCache_GetProcEntry
    typedef struct RdCacheProcEntry
    {
        RdFaceFlag flags;
        RdLightMode lightingMode;
        int numVertices;
        LPD3DTLVERTEX aVertices;
        rdVector4* aVertIntensities;
        RdMaterial* pMaterial;
        int matCelNum;
        rdVector4 extraLight;
        float distance;
    } RdCacheProcEntry;

    // stdEffect_GetFadeFactor
    typedef struct tStdFadeFactor
    {
        int bEnabled;
        float factor;
    } tStdFadeFactor;

    typedef struct SithCollide
    {
        SithCollideType type;
        float movesize;
        float size;
        float width;
        float height;
        float unkWidth;
        float unkHeight;
    } SithCollide;

    // jkdf2
    typedef struct sithSound
    {
        char sound_fname[32];
        int id;
        int isLoaded;
        uint32_t bufferBytes;
        uint32_t sampleRateHz;
        int bitsPerSample;
        int bStereo; // stdSound_buffer_t*
        uint32_t sound_len;
        int seekOffset;
        int field_40;
        int infoLoaded;
        void* dsoundBuffer2; // stdSound_buffer_t*
    } sithSound;

    typedef struct Box3f
    {
        rdVector3 v0;
        rdVector3 v1;
    } Box3f;

    typedef struct SithSectorLight
    {
        rdVector3 pos;
        rdVector4 color;
        float minRadius;
        float maxRadius;
    } SithSectorLight;

    // Since SithSector, SithSurface and SithSurfaceAdjoin are cyclic dependencies, forward declare here
    typedef struct SithSector SithSector;

    // Similarly between SithSurfaceAdjoin and SithSurface
    typedef struct SithSurface SithSurface;

    typedef struct SithSurfaceAdjoin
    {
        SithSurfaceAdjoinFlag flags;
        SithSector* pAdjoinSector;
        SithSurface* pAdjoinSurface;
        SithSurfaceAdjoin* pMirrorAdjoin;
        SithSurfaceAdjoin* pNextAdjoin;
        SithSurfaceAdjoin* pNextVisibleAdjoin;
        float distance;
    } SithSurfaceAdjoin;

    // Indy
    typedef struct RdFace
    {
        int num;
        RdFaceFlag flags;
        RdGeometryMode geometryMode;
        RdLightMode lightingMode;
        unsigned int numVertices;
        int* aVertIdxs;
        int* aTexIdxs;
        RdMaterial* pMaterial;
        int matCelNum;
        rdVector2 texVertOffset;
        rdVector4 extraLight;
        rdVector3 normal;
    } RdFace;

    typedef struct SithSurface
    {
        int renderTick;
        SithSector* pSector;
        SithSurfaceAdjoin* pAdjoin;
        SithSurfaceFlag flags;
        RdFace face;
        rdVector4* aIntensities;
        int msLastTouched;
    } SithSurface;

    // Similarly between SithSector and following, and SithThing
    typedef struct SithThing SithThing;

    typedef struct SithSector
    {
        SithSectorFlag flags;
        rdVector4 ambientLight;
        rdVector4 extraLight;
        rdVector3 tint;
        int numVertices;
        int* aVertIdxs;
        int numSurfaces;
        SithSurface* pFirstSurface;
        SithSurfaceAdjoin* pFirstAdjoin;
        SithThing* pFirstThingInSector;
        rdVector3 center;
        rdVector3 thrust;
        sithSound* hAmbientSound;
        float ambientSoundVolume;
        Box3f collideBox;
        Box3f boundBox;
        float radius;
        int renderTick;
        int bBuildingSector;
        rdClipFrustum* pClipFrustum; // jkdf stops here
        int pvsIdx;
        SithSectorLight light;
    } SithSector;

    typedef union SithAttach
    {
        SithThing* pThingAttached;
        SithSurface* pSurfaceAttached;
    } SithAttach;

    typedef struct SithThingLight
    {
        rdVector4 color;
        rdVector4 emitColor;
        float minRadius;
        float maxRadius;
    } SithThingLight;

    typedef struct SithSoundClassEntry
    {
        sithSound* hSnd;
        SoundPlayFlag playflags;
        float maxVolume;
        float minRadius;
        float maxRadius;
        int numEntries;
        SithSoundClassEntry* pNextMode;
    } SithSoundClassEntry;

    typedef struct SithSoundClass
    {
        char aName[64];
        SithSoundClassEntry* aEntries[141];
    } SithSoundClass;

    // forward declaration for RdKeyFrame
    typedef struct RdKeyframe RdKeyframe;

    // Indy
    typedef struct SithPuppetClassSubmode
    {
        RdKeyframe* pKeyframe;
        RdKeyframeFlag flags;
        int lo;
        int hi;
    } SithPuppetClassSubmode;

    // Indy
    typedef struct SithPuppetClass
    {
        char aName[64];
        SithPuppetClassSubmode aModes[24][84];
        int aJoints[10];
    } SithPuppetClass;

    typedef struct SithPuppetTrack
    {
        SithPuppetClassSubmode* pSubmode;
        int trackNum;
        SithPuppetSubMode submode;
        SithPuppetTrack* pNextTrack;
    } SithPuppetTrack;

    typedef struct SithPuppetState
    {
        int armedMode;
        SithPuppetMoveMode moveMode;
        int majorMode;
        SithPuppetSubMode submode;
        SithPuppetTrack* pFirstTrack;
        unsigned int msecLastFidgetStillMoveTime;
    } SithPuppetState;

    typedef union RdThingData
    {
        RdModel3* pModel3;
        RdPolyline* pPolyline;
        rdSprite3* pSprite3;
        RdParticle* pParticle;
        rdCamera* pCamera;
        rdLight* pLight;
    } RdThingData;

    // Indy
    // ~= swrUnk3
    typedef struct RdThing // doesn't seem to match swe1r
    {
        RdThingType type;
        RdThingData data;
        char unk8[4];
        char unkc[4];
        RdPuppet* pPuppet;
        int bSkipBuildingJoints;
        int rdFrameNum;
        rdMatrix34* paJointMatrices;
        rdVector3* apTweakedAngles;
        int* paJointAmputationFlags;
        int matCelNum; // 0x28
        int geosetNum; // 0x2c
        char unk30[4];
        RdLightMode lightMode; // 0x34
        int frustumCullStatus;
        SithThing* pThing; // 0x3c
    } RdThing;

    typedef struct SithSpriteInfo
    {
        SithThing* pMeshAttachedThing;
        int meshNumToAttachedThing;
        float width;
        float height;
        float alpha;
        float rollAngle;
        int unknown6;
        int unknown7;
        int unknown8;
        int unknown9;
        int unknown10;
        int unknown11;
        int unknown12;
        int unknown13;
        int unknown14;
        int unknown15;
        int unknown16;
        int unknown17;
        int unknown18;
        int unknown19;
        int unknown20;
        int unknown21;
        int unknown22;
        int unknown23;
        int unknown24;
        int unknown25;
        int unknown26;
        int unknown27;
        int unknown28;
        SithSector* pUnknownSector;
        int unknown30;
        int unknown31;
        int unknown32;
        int unknown33;
        int unknown34;
        int unknown35;
        int unknown36;
        int unknown37;
        int unknown38;
        int unknown39;
        rdMatrix34 orient;
        int unknown52;
        int unknown53;
        int unknown54;
        int unknown55;
        int unknown56;
        int unknown57;
        RdThing rdThing;
    } SithSpriteInfo;

    typedef struct SithParticleInfo
    {
        SithParticleFlag flags;
        int numParticles;
        RdMaterial* pMaterial;
        float size;
        float growthSpeed;
        float minRadius;
        float maxRadius;
        float pitchRange;
        float yawRange;
        float timeoutRate;
        float curGrowthSize;
        float secElapsed;
    } SithParticleInfo;

    // Does swe1r uses actor, weapon, item, explosion ?
    typedef union SithThingInfo
    {
        // SithActorInfo actorInfo;
        // SithWeaponInfo weaponInfo;
        // SithItemInfo itemInfo;
        // SithExplosionInfo explosionInfo;
        SithSpriteInfo spriteInfo;
        SithParticleInfo particleInfo;
    } SithThingInfo;

    // forward declare arguments
    typedef struct SithAIControlBlock SithAIControlBlock;
    typedef struct SithAIInstinct SithAIInstinct;
    typedef struct SithAIInstinctState SithAIInstinctState;

    typedef int (*SithAIInstinctFunc)(SithAIControlBlock*, SithAIInstinct*, SithAIInstinctState*, SithAIEventType, void*);

    typedef struct SithAIInstinct
    {
        SithAIMode updateModes;
        SithAIMode updateBlockModes;
        SithAIEventType triggerEvents;
        float fltArg[24];
        int intArg[24];
        SithAIInstinctFunc pfInstinct;
    } SithAIInstinct;

    typedef struct SithAIClass
    {
        int num;
        int unknown1;
        int armedMode;
        float alignment;
        float rank;
        float maxStep;
        float sightDistance;
        float heardDistance;
        float fov;
        float weakupDistance;
        float accurancy;
        float degTurnAlign;
        int numInstincts;
        SithAIInstinct aInstincts[16];
        char aName[64];
    } SithAIClass;

    typedef struct SithAIInstinctState
    {
        SithAIInstinctFlag flags;
        unsigned int msecNextUpdate;
        float param0;
        float param1;
        float param2;
        float param3;
    } SithAIInstinctState;

    typedef struct SithAIControlBlock
    {
        SithThing* pOwner;
        SithAIClass* pClass;
        SithAIMode mode;
        SithAISubMode submode;
        SithAIInstinctState aInstinctStates[16];
        int numInstincts;
        int msecNextUpdate;
        rdVector3 goalLVec;
        rdVector3 lookPos;
        rdVector3 movePos;
        rdVector3 moveDirection;
        float moveDistance;
        float moveSpeed;
        SithThing* pFleeFromThing;
        rdVector3 vecUnknown4;
        SithThing* pTargetThing;
        rdVector3 targetPos;
        int unknown124;
        rdVector3 toTarget;
        float distance;
        int targetSightState;
        rdVector3 vecUnknown122;
        unsigned int msecAttackStart;
        rdVector3 weaponFirePos;
        SithThing* goalThing;
        rdVector3 vecUnknown6;
        int unknown141;
        rdVector3 vecUnknown0;
        float targetDistance;
        int unknown146;
        rdVector3 vecUnknown5;
        int unknown150;
        rdVector3 homePos;
        rdVector3 homeOrient;
        float aimError;
        SithAIUtilFireFlags fireFlags;
        int fireWeaponNum;
        float fireDot;
        float minFireDist;
        float maxFireDist;
        int unknown163;
        int unknown164;
        int unknown165;
        int unknown166;
        int unknown167;
        int unknown168;
        unsigned int msecFireWaitTime;
        unsigned int msecPauseMoveUntil;
        rdVector3* aFrames;
        int numFrames;
        int sizeFrames;
        int allowedSurfaceTypes;
        rdVector3 vecUnknown3;
        rdVector3 vecUnknown;
        float maxHomeDist;
    } SithAIControlBlock;

    typedef struct SithAIControlInfo
    {
        SithAIClass* pClass;
        SithAIControlBlock* pLocal;
    } SithAIControlInfo;

    typedef union SithControlInfo
    {
        SithAIControlInfo aiControl;
    } SithControlInfo;

    typedef struct SithPathFrame
    {
        rdVector3 pos;
        rdVector3 pyr;
    } SithPathFrame;

    typedef struct SithPathMoveInfo
    {
        int sizeFrames;
        int numFrames;
        SithPathFrame* aFrames;
        SithPathMoveMode mode;
        rdVector3 vecDeltaPos;
        float moveTimeRemaining;
        float moveVel;
        rdMatrix34 curOrient;
        float rotDeltaTime;
        rdVector3 rotOffset;
        rdVector3 goalPYR;
        rdVector3 rotateToPYR;
        float rotDelta;
        int numBlockedMoves;
        int currentFrame;
        int nextFrame;
        int goalFrame;
    } SithPathMoveInfo;

    typedef struct SithPhysicsInfo
    {
        SithPhysicsFlags flags;
        rdVector3 velocity;
        rdVector3 angularVelocity;
        rdVector3 thrust;
        rdVector3 rotThrust;
        float mass;
        float height;
        float airDrag;
        float surfDrag;
        float staticDrag;
        float maxRotationVelocity;
        float maxVelocity;
        float orientSpeed;
        float buoyancy;
        rdVector3 gravityForce;
        rdVector3 deltaVelocity;
        float physicsRolloverFrames;
    } SithPhysicsInfo;

    typedef union SithMoveInfo
    {
        SithPathMoveInfo pathMovement;
        SithPhysicsInfo physics;
    } SithMoveInfo;

    typedef union SithCogValue
    {
        void* pointerValue;
        float floatValue;
        int intValue;
        char* pString;
        rdVector3 vecValue;
    } SithCogValue;

    typedef struct SithCogSymbolValue
    {
        SithCogValueType type;
        SithCogValue val;
    } SithCogSymbolValue;

    typedef struct SithCogSymbol
    {
        int id;
        SithCogSymbolValue val;
        int label;
        char* pName;
    } SithCogSymbol;

    typedef struct SithCogSymbolTable
    {
        SithCogSymbol* aSymbols;
        tHashTable* pHashtbl;
        int numUsedSymbols;
        int tableSize;
        int firstId;
        int bIsCopy;
    } SithCogSymbolTable;

    typedef struct SithCogScriptMsgHandler
    {
        SithCogMsgType type;
        int codeOffset;
        int id;
    } SithCogScriptMsgHandler;

    typedef struct SithCogSymbolRef
    {
        SithCogSymbolRefType type;
        int bLocal;
        int linkId;
        int mask;
        int symbolId;
        char* pDescription;
        char aValue[64];
    } SithCogSymbolRef;

    typedef struct SithCogScript
    {
        SithCogFlag flags;
        char aName[64];
        int* pCode;
        unsigned int codeSize;
        SithCogSymbolTable* pSymbolTable;
        int numHandlers;
        SithCogScriptMsgHandler aHandlers[32];
        SithCogSymbolRef aSymRefs[256];
        int numSymbolRefs;
    } SithCogScript;

    typedef struct SithCogCallstackElement
    {
        int execPos;
        SithCogStatus execStatus;
        int statusParam;
        SithCogMsgType execMsgType;
    } SithCogCallstackElement;

    // Does swe1r really use COG ? would be crazy
    typedef struct SithCog
    {
        SithCogScript* pScript;
        SithCogFlag flags;
        int idx;
        SithCogStatus status;
        int execPos;
        int statusParams[2];
        unsigned int msecPulseInterval;
        unsigned int msecNextPulseTime;
        unsigned int msecTimerTimeout;
        int linkId;
        int senderIdx;
        SithCogSymbolRefType senderType;
        int sourceIdx;
        SithCogSymbolRefType sourceType;
        SithCogMsgType execMsgType;
        int params[4];
        int returnValue;
        SithCogCallstackElement callstack[4];
        int callDepth;
        SithCogSymbolTable* pSymbolTable;
        SithCogSymbolValue stack[256];
        int stackSize;
        char aName[64];
        char aSymRefValues[64][256];
        SithCogSymbolValue* aHeap;
        int heapSize;
    } SithCog;

    typedef struct SithThingSwapEntry
    {
        int entryNum;
        int meshNum;
        RdModel3* pSrcModel;
        int meshNumSrc;
        SithThingSwapEntry* pNextEntry;
    } SithThingSwapEntry;

    // Since its so indy related, lets just void* here and find on our own.
    // Maybe doors and moving vehicles are listed here ?
    typedef union SithUserBlockUnion
    {
        // SithMineCarUserBlock* pMinecar;
        // SithJeepUserBlock* pJeep;
        // SithQuetzUserBlock* pQuetz;
        // SithFairyDustUserBlock* pFairydust;
        void* unk;
    } SithUserBlockUnion;

    typedef struct SithThing
    {
        SithThingFlag flags;
        int idx;
        int guid;
        SithThingType type;
        SithThingMoveType moveType;
        SithControlType controlType;
        SithThingMoveStatus moveStatus;
        int unknown1;
        unsigned int msecLifeLeft;
        unsigned int msecTimerTime;
        unsigned int msecNextPulseTime;
        unsigned int msecPulseInterval;
        SithCollide collide;
        SithAttach attach;
        SithSector* pInSector;
        SithThing* pNextThingInSector;
        SithThing* pPrevThingInSector;
        SithThing* pAttachedThing;
        SithThing* pNextAttachedThing;
        SithThing* pPrevAttachedThing;
        int signature;
        const SithThing* pTemplate;
        SithThing* pCreateThingTemplate;
        SithThing* pParent;
        int parentSignature;
        rdMatrix34 orient;
        rdVector3 pos;
        rdVector3 forceMoveStartPos;
        RdThing renderData;
        rdVector3 transformedPos;
        SithThingLight light;
        int renderFrame;
        SithSoundClass* pSoundClass;
        SithPuppetClass* pPuppetClass;
        SithPuppetState* pPuppetState;
        SithThingInfo thingInfo;
        int aiState;
        int aiArmedModeState;
        SithMoveInfo moveInfo;
        int moveFrame;
        float distanceMoved;
        rdVector3 vecUnknown1;
        SithControlInfo controlInfo;
        char aName[64];
        SithCog* pCog;
        SithCog* pCaptureCog;
        int gap295;
        int unknownFlags;
        float alpha;
        float userval;
        int numSwapEntries;
        SithThingSwapEntry* pSwapList;
        int perfLevel;
        SithUserBlockUnion userblock;
    } SithThing;

    // Indy
    typedef struct rdModel3Mesh
    {
        char name[64];
        int num;
        RdGeometryMode geoMode;
        RdLightMode lightMode;
        rdVector3* apVertices;
        rdVector2* apTexVertices;
        rdVector4* aVertColors;
        rdVector4* aLightIntensities;
        rdVector4 meshColor;
        RdFace* aFaces;
        rdVector3* aVertNormals;
        int numVertices;
        int numTexVertices;
        int numFaces;
        float radius;
        int someFaceFlags;
    } rdModel3Mesh;

    // Indy
    typedef struct rdModel3GeoSet
    {
        int numMeshes;
        rdModel3Mesh* aMeshes;
    } rdModel3GeoSet;

    // Indy
    typedef struct rdModel3HNode
    {
        char aName[128];
        int num;
        int type;
        int meshIdx;
        rdModel3HNode* pParent;
        int numChildren;
        rdModel3HNode* pChild;
        rdModel3HNode* pSibling;
        rdVector3 pivot;
        rdVector3 pos;
        rdVector3 pyr;
        rdMatrix34 meshOrient;
    } rdModel3HNode;

    // Indy
    typedef struct RdModel3
    {
        char aName[64];
        int num;
        rdModel3GeoSet aGeos[4];
        int numGeos;
        RdMaterial** apMaterials;
        int numMaterials;
        int curGeoNum;
        int numHNodes;
        rdModel3HNode* aHierarchyNodes;
        float radius;
        float size;
        rdVector3 insertOffset;
    } RdModel3;

    // Indy
    typedef struct RdPolyline
    {
        char aName[64];
        float length;
        float baseRadius;
        float tipRadius;
        RdGeometryMode geoMode;
        RdLightMode lightMode;
        RdFace face;
        rdVector2* apUVs;
    } RdPolyline;

    // Indy
    typedef struct rdSprite3
    {
        char aName[64];
        int type;
        float radius;
        int unknown18;
        int unknown19;
        float width;
        float height;
        float widthHalf;
        float heightHalf;
        RdFace face;
        rdVector2* aTexVerts;
        rdVector3 offset;
        float rollAngle;
    } rdSprite3;

    // Indy
    typedef struct RdParticle
    {
        char aName[64];
        int lightningMode;
        int numVertices;
        rdVector3* aVerticies;
        int* aVertMatCelNums;
        rdVector4* aExtraLights;
        float size;
        float sizeHalf;
        RdMaterial* pMaterial;
        float radius;
        rdVector3 insertOffset;
    } RdParticle;

    typedef struct RdKeyframeMarker
    {
        float frame;
        RdKeyMarkerType type;
    } RdKeyframeMarker;

    typedef struct RdKeyframeNodeEntry // rdAnimEntry in jkdf
    {
        float frame;
        unsigned int flags;
        rdVector3 pos;
        rdVector3 rot;
        rdVector3 dpos;
        rdVector3 drot;
    } RdKeyframeNodeEntry;

    typedef struct RdKeyframeNode // rdJoint in jkdf
    {
        char aMeshName[64]; // 32 in jkdf
        int nodeNum;
        int numEntries;
        RdKeyframeNodeEntry* aEntries;
    } RdKeyframeNode;

    typedef struct RdKeyframe
    {
        char aName[64]; // jkdf 32, indy 64. 32 ?
        int idx;
        RdKeyframeFlag flags;
        int type;
        float fps;
        int numFrames;
        int numJoints;
        RdKeyframeNode* aNodes;
        int numMarkers;
        RdKeyframeMarker aMarkers[16]; // 8 in jkdf, ordered float[8] and markerType[8]
    } RdKeyframe;

    typedef void (*RdPuppetTrackCallback)(SithThing* pThing, int trackNum, RdKeyMarkerType markerType);

    // Indy
    typedef struct RdPuppetTrack
    {
        RdPuppetTrackStatus status;
        int unknown0;
        int lo;
        int hi;
        float fps;
        float noise;
        float playSpeed;
        float fadeSpeed;
        int aNodes[64];
        float curFrame;
        float prevFrame;
        RdKeyframe* pKFTrack;
        RdPuppetTrackCallback pfCallback;
        unsigned int guid;
    } RdPuppetTrack;

    // Indy
    typedef struct RdPuppet
    {
        int unknown;
        RdThing* pThing;
        RdPuppetTrack aTracks[8]; // Jkdf has 4. TODO: Check !
    } RdPuppet;

    typedef struct rdPrimit3
    {
        size_t numVertices;
        int* aVertIdxs;
        int* aTexVertIdxs;
        rdVector3* aVertices;
        rdVector2* aTexVertices;
        rdVector4* aVertLights;
        rdVector4* aVertIntensities;
        int unknown2;
    } rdPrimit3;

    // JKDF
    typedef struct rdMeshinfo
    {
        uint32_t numVertices;
        int* vertexPosIdx;
        int* vertexUVIdx;
        rdVector3* verticesProjected;
        rdVector2* vertexUVs;
        float* paDynamicLight;
        float* intensities;
        rdVector3* verticesOrig;
    } rdMeshinfo;

    // size doesn't check out
    typedef struct tSithMessage
    {
        unsigned int msecTime;
        unsigned int length;
        unsigned short type;
        BYTE data[2620];
    } tSithMessage; // supposed sizeof(0xa48)

    // Inaccurate
    typedef struct SithPlayer
    {
        wchar_t awName[32];
        SithPlayerFlag flags;
        wchar_t unk[32];
        DPID playerNetId;
        SithThing* pThing;
        char unk8c[24];
        SithSector* pInSector;
        int respawnMask;
        unsigned int msecLastCommTime;
    } SithPlayer; // sizeof(0xb0) ? in SWR. Doesnt fit the name and the unk

    typedef struct StdConffileArg
    {
        char* argName;
        char* argValue;
    } StdConffileArg;

    typedef struct StdConffileEntry
    {
        int numArgs;
        StdConffileArg aArgs[512];
    } StdConffileEntry;

    typedef struct StdControlAxis
    {
        StdControlAxisFlag flags;
        int min;
        int max;
        int xOffset;
        int yOffset;
        float fltMedian;
    } StdControlAxis; // sizeof(0x18)

    typedef struct StdCommPlayerInfo
    {
        wchar_t aName[20];
        DPID id;
    } StdCommPlayerInfo; // sizeof(0x2c)

    typedef struct StdCommConnection
    {
        wchar_t name[128];
        GUID guid;
        void* lpConnection;
        int lpConnectionSize;
    } StdCommConnection; // sizeof(0x41). or 0x8c ?

    typedef struct swrMaterialSlot
    {
        void* data;
        swrMaterialSlot* next;
    } swrMaterialSlot; // sizeof(0x8)

    typedef struct swrMainDisplaySettings
    {
        int RegFullScreen;
        int RegFixFlicker;
        int RegDevMode;
        int RegUseFett;
        int currentDevice;
        unsigned int _3DDeviceIndex;
        int nb3DDevices;
        int unk1c;
        RdGeometryMode geometryMode;
        RdLightMode lightMode;
        int backbufferFill;
    } swrMainDisplaySettings; // sizeof(0x24)

    typedef struct WindowsInputItem
    {
        WPARAM virtualKeyCode;
        unsigned short keystrokeMessageFlags;
        uint8_t keydown;
        uint8_t unused;
    } WindowsInputItem; // sizeof(0x8)

    typedef struct stdControlInputItem
    {
        uint8_t virtualKeyCode;
        uint8_t unused;
        unsigned short keystrokeMessageFlags;
    } stdControlInputItem;

    typedef struct keyMapping
    {
        int id;
        char name[4]; // virtual keycode ?
    } keyMapping; // sizeof(0x8)

    typedef struct keyMapping2
    {
        int id;
        char name[4];
        int otherId;
    } keyMapping2; // sizeof(0xc)

    // TODO: joystick device sizeof(0x9d). see stdControlJoystickDevice[]

    // Wildy inaccurate. TODO: base on the file format data with magic 'ANIM'
    typedef struct swrAnimationNode
    {
        char unk[0x124];
    } swrAnimationNode; // sizeof(>= 0x124)

    typedef struct swrRacerData
    {
        int id;
        MODELID pod_modelID;
        MODELID pod_alt_modelID;
        char unkc[8];
        char* name;
        char* lastname;
        char unk1c[4];
        float float20;
        char unk24[4];
        SPRTID pilot_spriteId;
        char unk2c[4];
        MODELID puppet_modelId;
    } swrRacerData; // sizeof(0x34)

#ifdef __cplusplus
}
#endif
#endif // TYPES_H
