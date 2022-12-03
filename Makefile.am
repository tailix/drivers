include $(top_srcdir)/make/shared.am

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh

SUBDIRS = include

lib_LTLIBRARIES = libdrivers.la

libdrivers_la_SOURCES = \
	src/console.c \
	src/shutdown.c

# Intel 8253-compatible programmable interval timer

if ASM_I386
libdrivers_la_SOURCES += src/intel_8253_pit.c
endif

# Intel 8259-compatible programmable interrupt controller

if ASM_I386
libdrivers_la_SOURCES += src/intel_8259_pic.c
endif
