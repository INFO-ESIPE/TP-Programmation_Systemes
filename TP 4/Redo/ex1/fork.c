#include <stdio.h>
#include <unistd.h>
#include "../try.h"

int main(int argc, char const *argv[]) {
    write(STDOUT_FILENO, "Bonjour\n", 8);
    try(fork());
    write(STDOUT_FILENO, "Au revoir\n", 10);
    return 0;
}
