#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <drivers/shutdown.h>

void drivers_shutdown_halt()
{
#ifdef ASM_X86
    // Disable interrupts
    __asm__ __volatile__("cli");
#endif

    volatile int x = 0;
    for (;;) ++x;
}

void drivers_shutdown_poweroff()
{
#ifdef ASM_X86
    // QEMU >= 2.0
    __asm__ __volatile__("outw %1, %0" : : "dN" (0x604), "a" (0x2000));
    // QEMU < 2.0
    __asm__ __volatile__("outw %1, %0" : : "dN" (0xB004), "a" (0x2000));
#endif

    // If we can't poweroff then we halt
    drivers_shutdown_halt();
}
