#ifndef DRIVERS_INCLUDED_SHUTDOWN
#define DRIVERS_INCLUDED_SHUTDOWN

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noreturn)) void drivers_shutdown_halt();
__attribute__((noreturn)) void drivers_shutdown_poweroff();

#ifdef __cplusplus
}
#endif

#endif
