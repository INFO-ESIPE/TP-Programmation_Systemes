#include "../try.h"
#include <unistd.h>

int main(int argc, char const *argv[]) {
    switch (try(fork())) {
        case 0: // Child
            try(execlp("ls", "ls", NULL));
            break;
        default: // Parent
            switch (try(fork())) {
                case 0: // Child
                    try(execlp("ps", "ps", NULL));
                    break;
                default: // Parent
                    try(execlp("free", "free", NULL));
                    break;
            }
            break;
    }
    return 0;
}
