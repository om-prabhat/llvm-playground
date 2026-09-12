#include <stdio.h>
#include <stdlib.h>
#define extern_
#include "include/data.h"
#undef extern_
#include "include/decls.h"
#include "include/defs.h"
#include <errno.h>

static void init(){
    Line = 1;
}
static void usage(char *prog){
    fprintf(stderr, "Usage %s infile.ie\n", prog);
}


int main(int argc, char *argv[])
{
    if(argc != 2){
        usage(argv[0]);
        return 1;
    }
    init();
    // printf("%d\n", Line);
    if ((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }
    // char *readwords = malloc(10 * sizeof(char));
    // fgets(readwords, 10, Infile);
    // printf("%s\n", readwords);
    // free(readwords);

    tokenStruct *t = initToken();
    while(t->returnedInt != -1){
        t->returnedInt = getToken(t);
        char *toPrint = tokenPrint(t);
        printf("%s\n", toPrint);
    }

    return 0;
}
