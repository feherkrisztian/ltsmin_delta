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

int main(int argc, char *argv[])
{
    const char *files[2];
    HREinitBegin(argv[0]); // the organizer thread is called after the binary
    HREaddOptions(options,"");
    lts_lib_setup();
    HREinitStart(&argc,&argv,1,2,(char**)files,"");

    model = GBcreateBase();
    GBsetChunkMap (model, simple_table_factory_create());
    GBloadFile(model,files[0],&model);

    lts_type_t ltstype=GBgetLTStype(model);
    int N=lts_type_get_state_length(ltstype);

    int src[N];
    GBgetInitialState(model,src);

    int i;
    for(i = 0; i < N; i++){
        printf("%d", src[i]);
    }
    printf("\n\n");

    return 0;
}
