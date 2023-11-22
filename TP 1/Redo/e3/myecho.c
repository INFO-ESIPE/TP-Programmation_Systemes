#include <unistd.h>
#include "../../../try.h"

void echo(int argc, char *argv[], char* separator, char end) {
    int i;
    for (i = optind; i < argc; i++){
        printf("%s", argv[i]);
        
        if (i < argc - 1) {
            printf("%s", separator);
        }
    }

    putchar(end);
}

int main(int argc, char *argv[]){
    int opt;
    char *separator = " ";
    char endchar = '\n';

    while ((opt = getopt(argc, argv, "nsS:")) != -1) {
        switch (opt) {
        case 'n':
            endchar = '\0';
            break;
        case 's':
            separator = "";
            break;
        case 'S':
            separator = optarg;
            break;
        default:
            fprintf(stderr, "Usage: ./%s [-s] [-n] <text>", argv[0]);
            exit(EXIT_FAILURE);
            break;
        }
    }

    echo(argc, argv, separator, endchar);
    return 0;
}
