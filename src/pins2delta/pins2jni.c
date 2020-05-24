#include <hre/config.h>

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <hre/stringindex.h>
#include <hre/user.h>
#include <lts-io/user.h>
#include <ltsmin-lib/ltsmin-standard.h>
#include <ltsmin-lib/ltsmin-tl.h>
#include <pins-lib/pins.h>
#include <pins-lib/pins-impl.h>
#include <pins-lib/pins-util.h>
#include <pins-lib/property-semantics.h>

model_t model;

/*ez miatt lehet modult regisztrálni,
 pins-impl.v-be van definiálva, minden
 language modulra külön-külön*/
static struct poptOption options[] = {
    SPEC_POPT_OPTIONS 
};

model_t getModel(char *argv[])
{
    int argc = 2;
    const char *files[2];
    HREinitBegin(argv[0]); // the organizer thread is called after the binary
    HREaddOptions(options,"");
    lts_lib_setup();
    HREinitStart(&argc,&argv,1,2,(char**)files,"");

    model = GBcreateBase();
    GBsetChunkMap (model, simple_table_factory_create());
    GBloadFile(model,files[0],&model);

    return model;
}
