#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <drivers/console.h>

#include <stdarg.h>
#include <stddef.h>

int kernaux_vfprintf(
    void (*out)(char, void*),
    void *data,
    const char* format,
    va_list va
);

static void file_putc(char c, void *arg);

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

void drivers_console_printf(const char *const format, ...)
{
    va_list va;
    va_start(va, format);
    kernaux_vfprintf(file_putc, NULL, format, va);
    va_end(va);
}

void drivers_console_vprintf(const char *const format, va_list va)
{
    kernaux_vfprintf(file_putc, NULL, format, va);
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

void file_putc(char c, void *arg __attribute__((unused)))
{
    drivers_console_putc(c);
}
