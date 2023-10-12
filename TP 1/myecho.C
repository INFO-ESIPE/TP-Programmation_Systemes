#include <stdio.h>

void myecho(int argc, char *argv[]){
    int i;
    for(i = 1; i < argc; i++){
        if (i == argc - 1)
            printf("%s", argv[i]);
        else
            printf("%s ", argv[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[]){
    myecho(argc, argv);
    return 0;
}
