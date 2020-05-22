AM_CPPFLAGS += -I$(top_srcdir)/lib -I$(top_builddir)/lib
HRE_LIB = ../hre/libhre.la
SEQ_CPPFLAGS = $(AM_CPPFLAGS)
SEQ_CFLAGS   = $(AM_CFLAGS)

LIBS  = ../pins-lib/libpins.la
LIBS += ../vset-lib/libvset.la
LIBS += ../mc-lib/libmc.la
LIBS += $(top_builddir)/lib/libgnu.la

PROB_LIB_LIBS = ../prob-lib/libprob.la

bin_PROGRAMS = pins2jni

pins2jni_SOURCES   = pins2jni.c

pins2jni_SOURCES  += ../pins-lib/modules/pnml-pins.c ../pins-lib/modules/pnml-pins.h
pins2jni_SOURCES  += ../pins-lib/modules/etf-pins.c ../pins-lib/modules/etf-pins.h

pins2jni_LDADD  = $(LIBS)
pins2jni_LDADD  += $(PNML_LIBS) ../andl-lib/libandl.la
pins2jni_LDADD  += ../pins-lib/libmcrl2-pins.la

pins2jni_CPPFLAGS  = $(SEQ_CPPFLAGS)
pins2jni_CPPFLAGS  += -DALL_FRONTENDS
pins2jni_CPPFLAGS  += -DPNML
pins2jni_CPPFLAGS  += -DETF
pins2jni_CPPFLAGS  += -DMCRL2
pins2jni_CFLAGS   = $(SEQ_CFLAGS) $(PNML_CFLAGS)

pins2jni_LDFLAGS   = -Wl,-E
pins2jni_LDFLAGS  += $(MCRL2_LDFLAGS)
pins2jni_LDFLAGS  += $(AM_LDFLAGS)

nodist_EXTRA_pins2jni_SOURCES = automake-force-linker.cxx # req. by vset