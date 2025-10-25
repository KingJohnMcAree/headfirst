#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
/*
Note the getopt.h file is only needed to clear the erros in the editor
The programme still runs without it. See ChatGPT for an explanation on POSIX C)
*/
int main(int argc, char *argv[]) {
    char *delivery = "";
    int thick = 0;
    int count = 0;
    int ch;  // getopt returns int

    // Parse options: -d <arg> and -t
    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            case '?':  // unknown option
            default:
                fprintf(stderr, "unknown option: '-%c'\n", ch == '?' ? optopt : ch);
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
