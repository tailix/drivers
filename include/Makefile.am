nobase_include_HEADERS = \
	drivers.h \
	drivers/console.h \
	drivers/shutdown.h

# Intel 8253-compatible programmable interval timer

if ASM_I386
nobase_include_HEADERS += drivers/intel_8253_pit.h
endif

# Intel 8259-compatible programmable interrupt controller

if ASM_I386
nobase_include_HEADERS += drivers/intel_8259_pic.h
endif
