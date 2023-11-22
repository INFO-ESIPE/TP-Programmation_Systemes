#include "../try.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // int fd = try(creat(argv[1], 0644));
    int fd = try(open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644));
    try(dup2(fd, STDOUT_FILENO));
    try(close(fd));

    execlp("ls", "ls", "-l", NULL);
    return 0;
}
