#include "../try.h"
#include <ctype.h>

int main(int argc, char const *argv[]) {
    char c;
    int p[2];
    try(pipe(p));
    switch (try(fork())) {
        case 0: // Child Reader
            try(close(p[1]));
            int i;
            for (i = 0; i < 10 && try(read(p[0], &c, 1)) == 1; i++) {
                try(write(STDOUT_FILENO, &c, 1));
            }
            // int counter = 0;
            // while (try(read(p[0], &c, 1)) == 1) {
            //     try(write(STDOUT_FILENO, &c, 1));
            //     counter++;
            //     if (counter == 10) {
            //         break;
            //     }
            // }
            break;
        default: // Parent Writer
            try(close(p[0]));
            while (try(read(STDIN_FILENO, &c, 1)) == 1) {
                c = toupper(c);
                try(write(p[1], &c, 1));
            }
            break;
    }

    return 0;
}
