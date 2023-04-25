Solve hello-remember.c

    * Compile using gcc -Wall -g -o hello-remember hello-remember.c
    * Edit the source code and recompile until you fix all compilation errors and warnings
    * Run the program using command valgrind ./hello-remember < names.txt
    * Edit the source code, recompile and run, until valgrind reports that no leaks are possible and the program output is

    Hello Joe
    Hello Ann
    Hello John
    Hello Mary
    Hello Mike
    Hello Pam
    Still around Joe, eh?
    Still around Pam, eh?
    Still around Mike, eh?


Solve matrix-to-binary.c

    Compile using gcc -Wall -g -o matrix-to-binary matrix-to-binary.c
    * Edit the source code and recompile until you fix all compilation errors and warnings
    * Run the program using command valgrind ./matrix-to-binary matrix.txt matrix.bin
    * Edit the source code, recompile and run, until valgrind reports that no leaks are possible
    * Check the content of file matrix.bin using command xxd matrix.bin and repeat the steps above until the output of the command is as below.

    0000000: 0700 0000 0300 0000 0100 0000 0200 0000  ................
    0000010: 0300 0000 0400 0000 0500 0000 0600 0000  ................
    0000020: 0700 0000 0800 0000 0900 0000 0a00 0000  ................
    0000030: 0b00 0000 0c00 0000 0d00 0000 0e00 0000  ................
    0000040: 0f00 0000 1000 0000 1100 0000 1200 0000  ................
    0000050: 1300 0000 1400 0000 1500 0000            ............

