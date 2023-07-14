#ifndef GLOBALS_H
#define GLOBALS_H

// This file is auto-generated by scripts/GenerateGlobalHeaderFromSymbols.py and data_symbols.syms
// using Jinja template globals.h.j2

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif
    
    // Line 0: Window_UUID 0x004af9b0 uint32_t[4] = { 0xC95FB584, 0x11D2FA31, 0xAA009D90, 0xAD22A300 }
    uint32_t Window_UUID[4] = { 0xC95FB584, 0x11D2FA31, 0xAA009D90, 0xAD22A300 };
    
    // Line 2: Main_force_feedback 0x004b4938 int = 1
    int  Main_force_feedback = 1;
    
    // Line 3: Main_nut_delay_ms 0x004b6718 int = 32
    int  Main_nut_delay_ms = 32;
    
    // Line 4: Main_sound 0x004b6d20 int = 1
    int  Main_sound = 1;
    
    // Line 5: Main_sound_unk 0x004b6d2c int = 1
    int  Main_sound_unk = 1;
    
    // Line 6: Main_fullscreen_unk 0x004b79f8 int = 1
    int  Main_fullscreen_unk = 1;
    
    // Line 7: Main_display_intro_scene 0x004b7a00 int = 1
    int  Main_display_intro_scene = 1;
    
    // Line 8: Main_sound_3dimpact 0x004c7aa8 int = -1
    int  Main_sound_3dimpact = -1;
    
    // Line 9: Main_sound_doppler_scale 0x004c7d74 float = 1.0
    float  Main_sound_doppler_scale = 1.0;
    
    // Line 10: Main_sound_rolloff 0x004c7d78 float = 0.15
    float  Main_sound_rolloff = 0.15;
    
    // Line 12: rdMatrixStack34_modified 0x004c3c0c int
    int rdMatrixStack34_modified;
    
    // Line 14: wuRegistry_lpClass 0x004d55cc LPSTR
    LPSTR wuRegistry_lpClass;
    
    // Line 16: Main_settings_menu_only 0x0050b5b0 int
    int Main_settings_menu_only;
    
    // Line 17: Main_settings_debug_hud 0x0050b5c0 int
    int Main_settings_debug_hud;
    
    // Line 19: rdMatrixStack44_size 0x0050c5e8 int
    int rdMatrixStack44_size;
    
    // Line 20: rdMatrixStack34_size 0x0050c6f4 int
    int rdMatrixStack34_size;
    
    // Line 22: stdFilePrintf_buffer 0x0052e658 char[0x800]
    char stdFilePrintf_buffer[0x800];
    
    // Line 24: Window_UUID_0 0x0052ee60 uint32_t
    uint32_t Window_UUID_0;
    
    // Line 25: Window_UUID_1 0x0052ee64 uint32_t
    uint32_t Window_UUID_1;
    
    // Line 26: Window_UUID_2 0x0052ee68 uint32_t
    uint32_t Window_UUID_2;
    
    // Line 27: Window_UUID_3 0x0052ee6c uint32_t
    uint32_t Window_UUID_3;
    
    // Line 28: Window_hWnd 0x0052ee70 HWND
    HWND Window_hWnd;
    
    // Line 29: Window_hinstance 0x0052ee74 HINSTANCE
    HINSTANCE Window_hinstance;
    
    // Line 31: stdConsole_hConsoleOutput 0x0052ee78 HANDLE
    HANDLE stdConsole_hConsoleOutput;
    
    // Line 32: stdConsole_wAttributes 0x0052ee7c WORD
    WORD stdConsole_wAttributes;
    
    // Line 34: g_hWnd 0x00dfaa28 HWND
    HWND g_hWnd;
    
    // Line 35: g_nCmdShow 0x00dfaa2c int
    int g_nCmdShow;
    
    // Line 36: g_WndProc 0x00dfaa30 Window_MSGHANDLER_ptr
    Window_MSGHANDLER_ptr g_WndProc;
    
    // Line 37: Window_width 0x00dfaa34 int
    int Window_width;
    
    // Line 38: Window_height 0x00dfaa38 int
    int Window_height;
    
    // Line 39: wuRegistry_bInitted 0x00dfaa3c int
    int wuRegistry_bInitted;
    
    // Line 40: wuRegistry_lpSubKey 0x00dfaa40 LPCSTR
    LPCSTR wuRegistry_lpSubKey;
    
    // Line 41: wuRegistry_hKey 0x00dfaa44 HKEY
    HKEY wuRegistry_hKey;
    
    // Line 43: rdMatrix44_00e37580 0x00e37580 rdMatrix44
    rdMatrix44 rdMatrix44_00e37580;
    
    // Line 44: rdMatrixStack34 0x00e375c0 rdMatrix34[0x30]
    rdMatrix34 rdMatrixStack34[0x30];
    
    // Line 46: rdMatrixStack44 0x00e985c0 rdMatrix44[0x30]
    rdMatrix44 rdMatrixStack44[0x30];
    
    // Line 47: stdPlatform_hostServices 0x00e9f280 HostServices
    HostServices stdPlatform_hostServices;
    
    // Line 49: std_output_buffer 0x00ecbc20 char[0x800]
    char std_output_buffer[0x800];
    
    // Line 51: stdPlatform_hostServices_ptr 0x00ecc420 HostServices*
    HostServices* stdPlatform_hostServices_ptr;
    
#ifdef __cplusplus
}
#endif

#endif // GLOBALS_H