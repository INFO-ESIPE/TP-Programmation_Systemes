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

    try(stat(argv[1], &sb));

    printf("Inode number: %ld\n", sb.st_ino);
    printf("Size: %ld bytes\n", sb.st_size);
    // printf("Last modification: %ld seconds", sb.st_mtime);
    printf("Last modification: %s", ctime(&sb.st_mtime));

    printf("Type: ");
    S_ISREG(sb.st_mode) ? putchar('f') : S_ISDIR(sb.st_mode) ? putchar('d') : putchar('?');
    putchar('\n');

    return 0;
}
