############################
# Specify program versions #
############################

AC_PREREQ([2.68])
LT_PREREQ([2.4.6])



##################################
# Initialize Autoconf & Automake #
##################################

AC_INIT([drivers],
  m4_normalize(m4_include([VERSION])),
  [https://github.com/tailix/drivers/issues],
  [drivers],
  [https://github.com/tailix/drivers])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/shutdown.c])
AC_CONFIG_FILES([
  Makefile
  include/Makefile
])

AM_INIT_AUTOMAKE([1.16 subdir-objects])



#########################
# Automake conditionals #
#########################

dnl Architecture
AM_CONDITIONAL([ASM_I386],    [test "$host_cpu" = i386])
AM_CONDITIONAL([ASM_RISCV64], [test "$host_cpu" = riscv64])
AM_CONDITIONAL([ASM_X86_64],  [test "$host_cpu" = x86_64])

dnl Architecture (additional)
AM_CONDITIONAL([ASM_RISCV],   [test "$host_cpu" = riscv64])
AM_CONDITIONAL([ASM_X86],     [test "$host_cpu" = i386 -o "$host_cpu" = x86_64])



####################
# Autoconf defines #
####################

dnl Architecture
AS_IF([test "$host_cpu" = i386],    [AC_DEFINE([ASM_I386],    [1], [architecture is i386])])
AS_IF([test "$host_cpu" = riscv64], [AC_DEFINE([ASM_RISCV64], [1], [architecture is RISC-V 64-bit])])
AS_IF([test "$host_cpu" = x86_64],  [AC_DEFINE([ASM_X86_64],  [1], [architecture is x86_64])])

dnl Architecture (additional)
AS_IF([test "$host_cpu" = riscv64], [AC_DEFINE([ASM_RISCV],   [1], [architecture is RISC-V])])
AS_IF([test "$host_cpu" = i386],    [AC_DEFINE([ASM_X86],     [1], [architecture is x86])])
AS_IF([test "$host_cpu" = x86_64],  [AC_DEFINE([ASM_X86],     [1], [architecture is x86])])



##############
# Run checks #
##############

AC_LANG([C])

AM_PROG_AR
AM_PROG_AS
AC_PROG_CC
AC_PROG_CC_C99
AC_C_INLINE
AC_CHECK_HEADER_STDBOOL
AC_CHECK_HEADERS([stdarg.h stddef.h stdint.h])



######################
# Initialize Libtool #
######################

LT_INIT([disable-shared])



##########
# Finish #
##########

AC_OUTPUT
