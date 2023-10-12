#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int nflag = 0;
int sflag = 0;
char *Sflag = NULL;

void myecho(int argc, char *argv[]){
    int i;
    for(i = 0 + optind; i < argc; i++){
        if (i == argc - 1) {
            printf("%s", argv[i]);
        } else {
            if (Sflag != NULL)
                printf("%s%s", argv[i], Sflag);
            else if (sflag == 1)
                printf("%s", argv[i]);
            else
                printf("%s ", argv[i]);
        }
        
        // if (sflag == 1 || i == argc - 1)
        //     printf("%s", argv[i]);
        // else
        //     printf("%s ", argv[i]);
    }

    if (nflag == 0)
        printf("\n");
}

int main(int argc, char *argv[]){
    int opt;

    while((opt = getopt(argc, argv, "nsS:")) != -1){
        switch(opt){
            case 'n':
                nflag = 1;
                break;
            case 's':
                sflag = 1;
                break;
            case 'S':
                Sflag = optarg;
                break;
            default:
                return EXIT_FAILURE;
        }
    }

    myecho(argc, argv);
    return 0;
}
