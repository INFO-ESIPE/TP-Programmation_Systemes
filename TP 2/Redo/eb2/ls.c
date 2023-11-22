#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "../../../try.h"

void printinfo(char *dir, struct dirent *ent, struct stat sb) {
    DIR *dir = try(opendir(dir), NULL);

    while ((ent = readdir(dir)) != NULL) {
        try(lstat(ent->d_name, &sb));

        printf("%s\n", ent->d_name);
        printf("Inode number: %ld\n", sb.st_ino);
        printf("Size: %ld bytes\n", sb.st_size);
        printf("Last modification: %s", ctime(&sb.st_mtime));

        if (!S_ISLNK(sb.st_mode)) {
            printf("Type: ");
            S_ISREG(sb.st_mode) ? putchar('f') : S_ISDIR(sb.st_mode) ? putchar('d') : putchar('?');
        } else {
            char buf[BUFSIZ];
            ssize_t len = try(readlink(dir, buf, sizeof(buf) - 1));
            buf[len] = '\0';
            printf("Link to -> %s", buf);
        }
        printf("\n-------\n");
    }
    closedir(dir);
}

int main(int argc, char const *argv[]) {
    struct dirent *ent;
    struct stat sb;
    char *dirname;

    switch (argc) {
    case 1:
        dirname = ".";
        printinfo(dirname, ent, sb);
        break;
    case 2:
        
    default:
        break;
    }

    return 0;
}
