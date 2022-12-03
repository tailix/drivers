#ifndef INCLUDED_DRIVERS_CONSOLE
#define INCLUDED_DRIVERS_CONSOLE

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

void drivers_console_putc(char c);

void drivers_console_print(const char *s);
void drivers_console_puts(const char *s);
void drivers_console_write(const char *data, size_t size);

__attribute__((format(printf, 1, 2)))
void drivers_console_printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
