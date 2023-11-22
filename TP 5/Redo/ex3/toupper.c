#include <ctype.h>
#include "../try.h"

int main(int argc, char const *argv[]) {
    char c;
    int p[2];
    try(pipe(p));
    switch (try(fork())) {
        case 0: // Writer
            try(close(p[0])); // Close reader as it is not used and child inherits fds
            while (try(read(STDIN_FILENO, &c, 1)) == 1) {
                c = toupper(c);
                try(write(p[1], &c, 1));
            }
            break;
        
        default: // Reader
            try(close(p[1])); // Close writer as it is not used and child inherits fds
            while (try(read(p[0], &c, 1)) == 1) {
                try(write(STDOUT_FILENO, &c, 1));
            }
            break;
    }
    return 0;
}
