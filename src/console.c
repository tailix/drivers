#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <drivers/console.h>

#include <stddef.h>

void drivers_console_putc(const char c)
{
#if defined(ASM_X86)
    __asm__ __volatile__("outb %1, %0" : : "dN" (0x3f8), "a" (c));
#else
    (void)c;
#endif
}

void drivers_console_print(const char *const s)
{
    for (const char *c = s; *c; ++c) {
        drivers_console_putc(*c);
    }
}

void drivers_console_puts(const char *const s)
{
    drivers_console_print(s);
    drivers_console_putc('\n');
}

void drivers_console_write(const char *const data, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        drivers_console_putc(data[i]);
    }
}
