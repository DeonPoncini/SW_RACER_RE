#ifndef HOOK_H
#define HOOK_H

#include <stdint.h>
#include "hook_addresses.h"

// Sections
#define SWR_BASE_ADDR_ 0x00400000
#define SWR_TEXT_ADDR_ 0x00401000
#define SWR_DATA_ADDR_ 0x004AC000
#define SWR_RESERVED_ADDR_ 0x00ED0000

// Offsets to base
#define SWR_TEXT_OFFSET 0x00001000 // SWR_TEXT_ADDR_ - SWR_BASE_ADDR_
#define SWR_DATA_OFFSET 0x000AC000 // SWR_DATA_ADDR_ - SWR_BASE_ADDR_

// Length of sections
#define SWR_TEXT_LEN 0x00AB000 // SWR_DATA_ADDR_ - SWR_TEXT_ADDR_
#define SWR_ADDR_LEN 0x00A24000 // SWR_RESERVED_ADDR_ - SWR_DATA_ADDR_

// Globals holding the ASLR addresses
extern uint8_t *g_SWR_BASE_ADDR;
extern uint8_t *g_SWR_TEXT_ADDR;
extern uint8_t *g_SWR_DATA_ADDR;

void hook_init();
void hook_function(uint32_t hook_addr, uint8_t *hook_dst);
void hook_abort(uint8_t *hook_addr);

#endif // HOOK_H
