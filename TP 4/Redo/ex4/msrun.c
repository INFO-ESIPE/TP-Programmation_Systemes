#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../try.h"

/*
export RUN_0=ls
export RUN_1=ps
export RUN_2=free
export RUN_4=pwd
*/
int main(int argc, char *const *argv) {
    int i;
    char *env;
    char buf[BUFSIZ];

    for (i = 0;; i++) {
        snprintf(buf, sizeof(buf), "RUN_%d", i);
        if ((env = getenv(buf)) == NULL) {
            break;
        }

        switch (try(fork())) {
            case 0:
                try(execvp(env, argv));
                break;
            default:
                try(wait(NULL));
                break;
        }
    }

    return 0;
}
