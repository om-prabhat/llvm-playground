#pragma once
#include <stdio.h>
#ifndef extern_
    #define extern_ extern
#endif


// these variable will be used across many files but dont need to be re-defined in every file. So in other files these will resolve to "extern" i.e. defined elsewhere. and in the main.c this will be defined as blank making these vars belong to main.c
extern_ int Line;
extern_ FILE *Infile;
extern_ int Putback;
