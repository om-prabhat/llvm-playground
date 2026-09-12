# llvm-playground
This project exists just because I wanted to learn a little about compilers and LLVM too.

## Whats done...
Currently only lexer has been written.
Lexer - converts the code/texts (at that moment) to some meaningful chunks called tokens.

More specifically this has currently capability of converting some symbols, some arithmetic operators, some data types, return and numbers into tokens. And removing spaces and comments (starting with: "#").

## Build steps

```sh
cmake -B build #using cmake i felt its easier
cd build #cmake will make Makefiles here
make #build it
```
- and test input files are in `tests/*.ie`

References taken from (read some other blogs too but forgot to note them down - will add if i came across them again) :

https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl01.html

https://github.com/DoctorWkt/acwj/tree/master/01_Scanner

https://youtu.be/PRcMPwaWj1Y?si=rZEkthtud4rzQ503
