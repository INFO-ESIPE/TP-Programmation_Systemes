#include "../try.h"
#include <unistd.h>

int main(int argc, char *const argv[]) {
    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s <path>", argv[0]);
    //     exit(EXIT_FAILURE);
    // }

    try(execlp("ls", "ls", NULL));
    return 0;
}
