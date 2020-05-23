#ifndef SPEC_GREYBOX_H
#define SPEC_GREYBOX_H

#define SPEC_POPT_OPTIONS_MCRL2
#define SPEC_POPT_OPTIONS_ETF
#define SPEC_POPT_OPTIONS_DIVINE
#define SPEC_POPT_OPTIONS_SPINS
#define SPEC_POPT_OPTIONS_PNML
#define SPEC_POPT_OPTIONS_PINS_DLL

#if defined(MCRL2)
#include <pins-lib/modules/mcrl2-pins.h>
#define SPEC_POPT_OPTIONS_MCRL2 { NULL, 0, POPT_ARG_INCLUDE_TABLE, mcrl2_options, 0, "mCRL2 options", NULL },
#endif
#if defined(ETF)
#include <pins-lib/modules/etf-pins.h>
#define SPEC_POPT_OPTIONS_ETF { NULL, 0, POPT_ARG_INCLUDE_TABLE, etf_options, 0, "ETF options", NULL },
#endif
#if defined(DIVINE)
#include <pins-lib/modules/dve-pins.h>
#define SPEC_POPT_OPTIONS_DIVINE { NULL, 0, POPT_ARG_INCLUDE_TABLE, dve_options, 0, "DiVinE options", NULL },
#endif
#if defined(SPINS)
#include <pins-lib/modules/prom-pins.h>
#define SPEC_POPT_OPTIONS_SPINS { NULL, 0, POPT_ARG_INCLUDE_TABLE, prom_options, 0, "Promela options", NULL },
#endif
#if defined(PNML)
#include <pins-lib/modules/pnml-pins.h>
#define SPEC_POPT_OPTIONS_PNML { NULL, 0, POPT_ARG_INCLUDE_TABLE, pnml_options, 0, "PNML options", NULL },
#endif
#if defined(PINS_DLL)
#include <pins-lib/modules/dlopen-pins.h>
#define SPEC_POPT_OPTIONS_PINS_DLL { NULL, 0, POPT_ARG_INCLUDE_TABLE, pins_plugin_options, 0, "PINS plugin options", NULL },
#endif

#define SPEC_POPT_OPTIONS SPEC_POPT_OPTIONS_MCRL2 \
 SPEC_POPT_OPTIONS_ETF \
 SPEC_POPT_OPTIONS_DIVINE \
 SPEC_POPT_OPTIONS_SPINS \
 SPEC_POPT_OPTIONS_PNML \
 SPEC_POPT_OPTIONS_PINS_DLL

#endif