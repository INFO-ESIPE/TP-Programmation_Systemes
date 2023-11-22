#include <stdio.h>
#include <unistd.h>
#include "../../../try.h"

int main(int argc, char const *argv[]) {
    int i;
    char separator = ' ';
    char newline = '\n';
    for (i = 1; i < argc; i++){
        try(write(STDOUT_FILENO, argv[i], strlen(argv[i])));

        if (i < argc - 1) {
            try(write(STDOUT_FILENO, &separator, 1));
        }
    }

    try(write(STDOUT_FILENO, &newline, 1));
    return 0;
}
