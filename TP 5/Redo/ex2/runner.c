#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../try.h"

int main(int argc, char *argv[]) {
    int wstatus;
    char *msg;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> <options>", argv[0]);
        exit(EXIT_FAILURE);
    }

    switch (try(fork())) {
        case 0:
            try(execvp(argv[1], argv + 1));
            break;
        default:
            try(wait(&wstatus));
            int success = WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 0;
            printf("%s\n", success ? "OK" : "ERREUR");
            break;
    }

    return 0;
}
