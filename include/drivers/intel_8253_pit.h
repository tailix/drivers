/**
 * @brief A driver for Intel 8253-compatible programmable interval timer
 *
 * @see https://en.wikipedia.org/wiki/Intel_8253
 * @see https://wiki.osdev.org/PIT
 */

#ifndef DRIVERS_INCLUDED_INTEL_8253_PIT
#define DRIVERS_INCLUDED_INTEL_8253_PIT

#ifdef __cplusplus
extern "C" {
#endif

void drivers_intel_8253_pit_initialize(unsigned int freq);

#ifdef __cplusplus
}
#endif

#endif
