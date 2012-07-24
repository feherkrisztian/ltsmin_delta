/*
 * spgsolver.c
 *
 *  Created on: 20 Feb 2012
 *      Author: kant
 */
#include <config.h>

#include <limits.h>

#include <../hre/user.h>
#include <../vector_set.h>
#include <../spg-solve.h>

static  struct poptOption options[] = {
    { NULL, 0 , POPT_ARG_INCLUDE_TABLE, spg_solve_options , 0, "Symbolic parity game solver options", NULL},
    { NULL, 0 , POPT_ARG_INCLUDE_TABLE, vset_options , 0 , "Vector set options",NULL},
    POPT_TABLEEND
};

int
main (int argc, char *argv[])
{
    char *files[1];
    HREinitBegin(argv[0]);
    HREaddOptions(options,"Symbolic parity game solver. Solves <game>.\n");
    HREinitStart(&argc,&argv,1,1,files,"<game>");

    vset_implementation_t vset_impl = VSET_ListDD;
    FILE *f = fopen(files[0], "r");
    if (f == NULL)
        AbortCall ("Unable to open file ``%s''", files[0]);
    parity_game* g = spg_load(f, vset_impl);
    fclose(f);
    spgsolver_options* spg_options = spg_get_solver_options();
    rt_timer_t spgsolve_timer = RTcreateTimer();
    RTstartTimer(spgsolve_timer);
    bool result = spg_solve(g, spg_options);
    Warning(info, "");
    Warning(info, "The result is: %s", result ? "true":"false");
    RTstopTimer(spgsolve_timer);
    Warning(info, "");
    RTprintTimer(info, spgsolve_timer, "solving took");

    HREexit(EXIT_SUCCESS);
}
