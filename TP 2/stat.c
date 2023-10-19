#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../try.h"

int main(int argc, char *argv[]){
    struct stat sb;

    if (argc == 1) {
        printf("Usage: %s <file>\n", argv[0]);
    } else {
        try(stat(argv[1], &sb));
    }

    printf("Inode number: %d\n", sb.st_ino);
    printf("File size: %d\n", sb.st_size);
    printf("Last modification: %d\n", sb.st_mtime);
    printf("Type: ");

    switch (sb.st_mode & S_IFMT){
    case S_IFDIR:
        putchar('d');
        break;
    case S_IFREG:
        putchar('f');
        break;
    default:
        putchar('?');
        break;
    }

    putchar('\n');
    return 0;
}
