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

#ifdef __cplusplus
}
#endif

#endif
