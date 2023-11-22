#include <stdio.h>

// man vim | ./buffered
int main(int argc, char const *argv[]){
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, stdout);
    }
    
    return 0;
}
