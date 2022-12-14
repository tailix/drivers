/**
 * @brief A driver for Intel 8259-compatible programmable interrupt controller
 *
 * @details
 * This is not a driver for a random Intel 8259-compatible PIC, but only for a
 * typical configuration of it that can be found in most PCs.
 *
 * @see https://en.wikipedia.org/wiki/Intel_8259
 * @see https://wiki.osdev.org/8259_PIC
 * @see https://pdos.csail.mit.edu/6.828/2005/readings/hardware/8259A.pdf
 */

#ifndef DRIVERS_INCLUDED_INTEL_8259_PIC
#define DRIVERS_INCLUDED_INTEL_8259_PIC

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enable PIC
 */
void drivers_intel_8259_pic_enable_all();

/**
 * @brief Disable PIC
 */
void drivers_intel_8259_pic_disable_all();

/**
 * @brief Enable single IRQ line
 */
void drivers_intel_8259_pic_enable(unsigned char number);

/**
 * @brief Disable single IRQ line
 */
void drivers_intel_8259_pic_disable(unsigned char number);

/**
 * @brief Remap PIC
 */
void drivers_intel_8259_pic_remap(
    unsigned char new_master_start,
    unsigned char new_slave_start
);

/**
 * @brief Signal end of interrupt
 */
void drivers_intel_8259_pic_eoi(unsigned char number);

#ifdef __cplusplus
}
#endif

#endif
