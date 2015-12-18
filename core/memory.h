/* Declarations for memory.c */

#ifndef MEMORY_H
#define MEMORY_H

#include <core/apb.h>

#ifdef __cplusplus
extern "C" {
#endif

struct mem_state {
    uint8_t *flash;     // Flash mem
    uint8_t *ram;       // RAM
    uint8_t *vram;      // VRAM
    int flash_mapped;
    int flash_unlocked;
    int wait_state; // XXX should be unsigned
};

// Type definitions
typedef struct mem_state mem_state_t;

// Global MEMORY state
extern mem_state_t mem;

// Available Functions
uint8_t *phys_mem_ptr(uint32_t address, uint32_t size);

int mem_wait_states(void); // XXX unsigned
void mem_reset_wait_states(void);

typedef struct apb_map_entry apb_map_entry;

void mem_init(void);
void mem_free(void);

uint8_t memory_read_byte(uint32_t address, int *cycles);
void memory_write_byte(uint32_t address, uint8_t value, int *cycles);

#ifdef __cplusplus
}
#endif

#endif
