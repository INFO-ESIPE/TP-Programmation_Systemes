#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../try.h"

#define MAX 20

int main(int argc, char const *argv[]) {
    int i;
    char buf[BUFSIZ];
    pid_t child_pid;
    int wstatus;

    for (i = 1; i <= MAX; i++) {
        switch (try(fork())) {
            case 0:
                snprintf(buf, sizeof(buf), "je suis le numero %d, mon PID est %ld et mon parent est %ld\n", i, (long) getpid(), (long) getppid());
                try(write(STDOUT_FILENO, buf, strlen(buf)));
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    }

    while((child_pid = wait(&wstatus)) != -1) {
        if (WIFEXITED(wstatus)) {
            snprintf(buf, sizeof(buf), "Le processus %ld vient de se terminer.\n", (long) child_pid);
            try(write(STDOUT_FILENO, buf, strlen(buf)));
        }
    }
    return 0;
}
