#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VSTUP "casy.txt"
#define VYSTUP "platby.txt"
#define ZDARMA 2
#define SAZBA 20

int sekundyCelkem(int h2,int m2, int s2,int h,int m, int s){
    return (h2*3600+m2*60+s2)-(h*3600+m*60+s);
}

int prevodNaHodiny(int sekundy) {
    return sekundy / 3600;
}

int prevodNaMinuty(int sekundy) {
    return sekundy % 3600 / 60;
}

int prevodNaSekundy(int sekundy) {
    return sekundy % 60;
}
int limit(int hodiny){
    return hodiny -2;
}

int platba(int hodiny, int minuty){
    if (minuty > 1){
        minuty=20;
        return minuty;
    }
    else {
        minuty = 0;
        return minuty;
    }
    return hodiny * 20 + minuty;
}


int main(int argc, char** argv){
    int hodiny,minuty,sekundy,hodiny2,minuty2,sekundy2, poradi = 0, poradiSoubor = 0,vysledek, cas,souborHodiny, nadLimit;
    
    FILE *fr,*fw;
    fr = fopen(VSTUP,"r");

    if (fr == NULL)
    {
        printf("Soubor %s nebyl otevren",VSTUP);
        return EXIT_FAILURE;
    }
        printf("P A R K O V I S T E\n");
    printf("------------------------------------------------\n");
    printf("poradi  cas       cas        doba     parkovani\n");
    printf("        vjezdu    vyjezdu    sekundy        cas\n");
    printf("------------------------------------------------\n");

    fw = fopen(VYSTUP,"w");
    if(fw == NULL){
        printf("Soubor %s nebyl otevren. Program bude ukoncen.",VYSTUP);
        return 0;
    }
    fprintf(fw,"Parkoviste - P L A T B Y\n");
    fprintf(fw,"------------------------------\n");
    fprintf(fw,"pocet hodin parkovani zdarma          : 2 \n");
    fprintf(fw,"hodinova sazba po prekroceni limitu   : 20  KC \n");
    fprintf(fw,"-----------------------------------------------------------------------\n");
    fprintf(fw,"poradi  cas vjezdu  cas vyjezdu  doba parkovani  nad limit  platba\n");
    fprintf(fw,"-----------------------------------------------------------------------\n");


    while(fscanf(fr, "%d %d %d %d %d %d", &hodiny, &minuty, &sekundy, &hodiny2, &minuty2, &sekundy2) == 6){
        poradi++;
        cas = sekundyCelkem(hodiny2,minuty2,sekundy2,hodiny,minuty,sekundy);
        printf("%2d.    %02d:%02d:%02d   %02d:%02d:%02d   %d   %02d:%02d:%d \n",poradi,hodiny,minuty,sekundy, hodiny2,minuty2,sekundy2,
        cas, prevodNaHodiny(cas), prevodNaMinuty(cas) ,  prevodNaSekundy(cas) );
        souborHodiny =prevodNaHodiny(cas);
        
        if (souborHodiny > 1)
        {
            poradiSoubor++;
            nadLimit = limit(souborHodiny);
            fprintf(fw," %2d.    %02d:%02d:%02d    %02d:%02d:%02d     %02d:%02d:%02d        %02d:%02d:%02d    %d\n",poradiSoubor,hodiny,minuty,sekundy, hodiny2,minuty2,sekundy2,
            prevodNaHodiny(cas), prevodNaMinuty(cas) ,  prevodNaSekundy(cas), nadLimit, prevodNaMinuty(cas) ,  prevodNaSekundy(cas), platba(hodiny,minuty) );
        }
        
        
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