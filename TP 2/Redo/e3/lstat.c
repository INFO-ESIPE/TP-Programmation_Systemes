#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "../../../try.h"

int main(int argc, char const *argv[]) {
    struct stat sb;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>", argv[0]);
        exit(EXIT_FAILURE);
    }

    try(lstat(argv[1], &sb));
    printf("Inode number: %ld\n", sb.st_ino);
    printf("Size: %ld bytes\n", sb.st_size);
    printf("Last modification: %s", ctime(&sb.st_mtime));

    if (!S_ISLNK(sb.st_mode)) {
        printf("Type: ");
        S_ISREG(sb.st_mode) ? putchar('f') : S_ISDIR(sb.st_mode) ? putchar('d') : putchar('?');
    } else {
        char buf[BUFSIZ];
        ssize_t len = try(readlink(argv[1], buf, sizeof(buf) - 1));
        buf[len] = '\0';
        printf("Link to -> %s", buf);
    }
    putchar('\n');

    return 0;
}
