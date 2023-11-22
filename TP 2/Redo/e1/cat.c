#include <unistd.h>
#include <fcntl.h>
#include "../../../try.h"

void cat(int fd) {
    int i;
    ssize_t size;
    char buff[BUFSIZ];

    while ((size = try(read(fd, buff, sizeof(buff)))) > 0) {
        try(write(STDOUT_FILENO, buff, size));
    }
}

int main(int argc, char const *argv[]){
    if (argc == 1) {
        cat(STDIN_FILENO);
    } else {
        int i, fd;
        for(i = 1; i < argc; i++) {
            fd = try(open(argv[i], O_RDONLY));
            cat(fd);
            try(close(fd));
        }
    }

    return 0;
}
