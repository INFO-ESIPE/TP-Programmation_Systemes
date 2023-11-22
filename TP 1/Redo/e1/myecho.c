#include <stdio.h> 

int main(int argc, char const *argv[]) {
    int i;
    char *separator = "";
    for (i = 1; i < argc; i++){
        printf("%s%s", separator, argv[i]);
        separator = " ";
    }

    putchar('\n');
    return 0;
}
