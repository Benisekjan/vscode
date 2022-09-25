#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define VSTUP "vstup.txt"
#define VYSTUP "vystup.txt"

int main(int argc, char** argv){
    int a,b,c;
    FILE * fr,* fw;
    fr = fopen(VSTUP,"r");

    if (fr == NULL)
    {
        printf("Soubor %s nebyl otevren",VSTUP);
        return EXIT_FAILURE;
    }

    printf("Menu");

    fw = fopen(VYSTUP,"w");
    if(fw == NULL){
        printf("Soubor %s nebyl otevren. Program bude ukoncen.",VYSTUP);
        return 0;
    }
    fprintf(fw,"Menu");
    while(fscanf(fr,"%d%d%d",&a,&b,&c)== 3){
        //printf("vypis");
        //fprintf("vypis do souboru");
    }
            if (fclose(fr) == EOF) {
        printf("Soubor %s nebyl zavren.\n", VSTUP);
        return 0;
    }
    if (fclose(fw) == EOF){
    printf("Soubor %s nebyl uzavren.\n",VYSTUP);
    }
    else{
    printf("Soubor %s byl vytvoren.\n",VYSTUP);
    }
    
    return 0;
}