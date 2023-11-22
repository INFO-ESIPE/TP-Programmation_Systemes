#include "../try.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    pid_t pid_parent = getpid();
    pid_t pid_child;
    char buf[BUFSIZ];

    printf("mon PID est %d", pid_parent);

    snprintf(buf, sizeof(buf), "my PID is %d", pid_parent);
    write(STDOUT_FILENO, buf, strlen(buf));

    switch (try(fork())) {
        case 0: // Executed by child
            pid_child = getpid();
            printf("je suis l'enfant et mon PID est %d", pid_child);
            snprintf(buf, sizeof(buf), "I am the child and my PID is %d", pid_child);
            write(STDOUT_FILENO, buf, strlen(buf));
            break;
        default: // Executed by parent
            printf("je suis le parent et mon PID est %d", pid_parent);
            snprintf(buf, sizeof(buf), "I am the parent and my PID is %d", pid_parent);
            write(STDOUT_FILENO, buf, strlen(buf));
            break;
    }
    puts("");

    return 0;
}
