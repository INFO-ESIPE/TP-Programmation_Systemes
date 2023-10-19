#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../try.h"

#define BUFFER_SIZE 1024

void cat(int fd) {
    char buffer[BUFFER_SIZE];
    int nb_read = 0;
    int nb_written = 0;

    while ((nb_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        while (nb_read > 0) {
            nb_written = write(1, buffer, nb_read);
            nb_read -= nb_written;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc == 1) {
        cat(0);
    } else {
        int fd = try(open(argv[1], O_RDONLY));
        cat(fd);
        try(close(fd));
    }

    return 0;
}
