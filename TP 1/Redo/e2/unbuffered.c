#include <stdio.h>

// man vim | ./unbuffered
int main(int argc, char const *argv[]){
    int c;
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, stdout);
    }
    return 0;
}
