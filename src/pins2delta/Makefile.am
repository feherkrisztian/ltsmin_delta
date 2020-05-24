AM_CPPFLAGS += -I$(top_srcdir)/lib -I$(top_builddir)/lib
HRE_LIB = ../hre/libhre.la
SEQ_CPPFLAGS = $(AM_CPPFLAGS)
SEQ_CFLAGS   = $(AM_CFLAGS)

LIBS  = ../pins-lib/libpins.la
LIBS += $(top_builddir)/lib/libgnu.la

noinst_LIBRARIES = pins2jni.la

pins2jni_a_SOURCES  = pins2jni.c
pins2jni_a_LDADD    = $(LIBS) $(LIBLTDL)
pins2jni_a_CPPFLAGS = $(SEQ_CPPFLAGS) $(LTDLINCL)
pins2jni_a_CFLAGS   = $(SEQ_CFLAGS)
pins2jni_a_LDFLAGS  = -Wl,-E
pins2jni_a_LDFLAGS  += $(AM_LDFLAGS)

#max 5 modules can be registred

#dlopen
#pins2jni_a_SOURCES  += ../pins-lib/modules/dlopen-pins.c ../pins-lib/modules/dlopen-pins.h
#pins2jni_a_CPPFLAGS += -DPINS_DLL

#etf
pins2jni_a_SOURCES  += ../pins-lib/modules/etf-pins.c ../pins-lib/modules/etf-pins.h
pins2jni_a_CPPFLAGS += -DETF

if HAVE_LIBMCRL2
pins2jni_a_LDADD    += ../pins-lib/libmcrl2-pins.la
pins2jni_a_CPPFLAGS += -DMCRL2
pins2jni_a_LDFLAGS  += $(MCRL2_LDFLAGS)
endif

if HAVE_SPINS
pins2jni_a_SOURCES  += ../pins-lib/modules/prom-pins.c ../pins-lib/modules/prom-pins.h
pins2jni_a_LDADD    += $(SPINS_LIBS)
pins2jni_a_CPPFLAGS += -DSPINS $(SPINS_CPPFLAGS) 
pins2jni_a_LDFLAGS  += $(SPINS_LDFLAGS)
endif

if HAVE_PNML
pins2jni_a_SOURCES  += ../pins-lib/modules/pnml-pins.c ../pins-lib/modules/pnml-pins.h
pins2jni_a_LDADD    += $(PNML_LIBS) ../andl-lib/libandl.la
pins2jni_a_CPPFLAGS += -DPNML
pins2jni_a_CFLAGS   += $(PNML_CFLAGS)
endif

if HAVE_DVE
pins2jni_a_SOURCES  += ../pins-lib/modules/dve-pins.c ../pins-lib/modules/dve-pins.h
pins2jni_a_LDADD    += $(DVEC_LIBS)
pins2jni_a_CPPFLAGS += -DDIVINE $(DIVINE_CPPFLAGS)
pins2jni_a_LDFLAGS  += $(DIVINE_LDFLAGS)
endif