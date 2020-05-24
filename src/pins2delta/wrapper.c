#include <stdio.h>
#include "pins2jni.h"
#include "../pins-lib/pins.h"

int main(int argc, char *argv[])
{
   // printf() displays the string inside quotation
   printf("wrapper.c......................\n");
   model_t model = getModel(argv);

   lts_type_t ltstype=GBgetLTStype(model);
   int N=lts_type_get_state_length(ltstype);
   int src[N];
   GBgetInitialState(model,src);

   for(int i = 0; i < N; i++){
   printf("%d\n", src[i]);
    }

 printf("wrapper.c-bol\n");   

   
   return 0;
}