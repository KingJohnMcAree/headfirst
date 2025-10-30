/*
Note the getopt.h file is only needed to clear the erros in the editor
The programme still runs without it. (See ChatGPT for an explanation on POSIX C)
compile:gcc -g -O0 -Wall -Wextra -o options option.c
debug: gdb --args ./options -m monday tuesday wednesday.

*/
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>


static void usage(const char *prog) {
    fprintf(stderr, "Usage: %s [-s] [-m] [daysWorked...]\n", prog);
}

int main(int argc, char *argv[]) {
    int count=0;
    int single = 0;
    int married = 0;
    int ch;  // getopt returns int

    // Parse options: -d <arg> and -t
    while ((ch = getopt(argc, argv, ":d:s:m")) != -1) {
        switch (ch) {
            
            case 's':
                single = 1;
                break;
            case 'm':
                married = 1;
                break;
            
            default:
                fprintf(stderr, "unknown option: '-%c'\n", optopt);
                usage(argv[0]);
                return 1;
        }
    }

    // Shift past the options
    argc -= optind;
    argv += optind;

    if (single) {
        puts("As a single person, your UC rate is £344.00 per month.");
    }
    if (married) {
        puts("As a married couple, your UC rate is £488.00 per month.");
    }

   puts("Days worked this week:");

    for (count = 0; count < argc; count++)
        puts(argv[count]);

    return 0;
}
