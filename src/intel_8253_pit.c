#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <drivers/intel_8253_pit.h>

#include <stdint.h>

void drivers_intel_8253_pit_initialize(const unsigned int freq)
{
    const unsigned int divisor = 1193180 / freq;

    const uint8_t l = divisor & 0xff;
    const uint8_t h = (divisor >> 8) & 0xff;

    __asm__ __volatile__("outb %1, %0" : : "dN" (0x43), "a" (0x36));
    __asm__ __volatile__("outb %1, %0" : : "dN" (0x40), "a" (l));
    __asm__ __volatile__("outb %1, %0" : : "dN" (0x40), "a" (h));
}
