// ...existing code...
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
/*
Note the getopt.h file is only needed to clear the erros in the editor
The programme still runs without it. (See ChatGPT for an explanation on POSIX C)
run the debugger: gdb --args ./options -t -d home cheese olives

*/

static void usage(const char *prog) {
    fprintf(stderr, "Usage: %s [-t] [-d delivery] [ingredients...]\n", prog);
}

// ...existing code...
int main(int argc, char *argv[]) {
    char *delivery = "";
    int thick = 0;
    int count = 0;
    int ch;  // getopt returns int

    // Parse options: -d <arg> and -t
    while ((ch = getopt(argc, argv, ":d:t")) != -1) {
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            case ':': // missing option argument
                fprintf(stderr, "option -%c requires an argument\n", optopt);
                usage(argv[0]);
                return 1;
            case '?':  // unknown option
            default:
                fprintf(stderr, "unknown option: '-%c'\n", optopt);
                usage(argv[0]);
                return 1;
        }
    }

    // Shift past the options
    argc -= optind;
    argv += optind;

    if (thick)
        puts("Thick Crust.");

    if (delivery[0])
        printf("To be delivered %s.\n", delivery);
    
    puts("Ingredients:");

    for (count = 0; count < argc; count++)
        puts(argv[count]);

    return 0;
}
