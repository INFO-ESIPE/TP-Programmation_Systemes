#include <stdio.h>
#include <stdlib.h>
#include "../try.h"

/*
export RUN_0=0
export RUN_1=1
export RUN_2=2
export RUN_4=4
*/
int main(int argc, char const *argv[]) {
    int i;
    char *env;
    char buf[BUFSIZ];

    for (i = 0;; i++) {
        snprintf(buf, sizeof(buf), "RUN_%d", i);
        if ((env = getenv(buf)) == NULL) {
            break;
        }
        printf("%s\n", env);
    }

    return 0;
}
