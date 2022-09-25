#include <stdio.h>

#define VSTUP "casy.txt"
#define VYSTUP "odpoledne.txt"

int sekundyOdPulnoci(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
int prevodCasu(int h){
    if(h > 12){
        return h-12;
    }
    else if(h == 0){
        return h+12;
    }
    return h;
}

int main() {
    FILE *fr, *fw;
    int hodiny, minuty, sekundy, poradi = 0, odpoPoradi = 0;
    fr = fopen(VSTUP, "r");
    if (fr == NULL) {
        printf("Soubor %s nebyl otevren. Program bude ukoncen.", VSTUP);
        return 0;
    }
    printf("U D A J E  Z E  S O U B O R U \n");
    printf("------------------------------------------------------------------\n");
    printf("poradi casu | evropsky cas | anglicky cas | sekundy od pulnoci |\n");
    printf("------------------------------------------------------------------\n");

    fw = fopen(VYSTUP,"w");
    if(fw == NULL){
        printf("Soubor %s nebyl otevren. Program bude ukoncen.",VYSTUP);
        return 0;
    }
    fprintf(fw,"O D P O L E D N E\n");
    fprintf(fw,"-------------------------------------------------------------\n");
    fprintf(fw,"poradi casu |evropsky cas | anglicky cas | sekundy od pulnoci|\n");
    fprintf(fw,"-------------------------------------------------------------\n");

    while (fscanf(fr, "%d %d %d", &hodiny, &minuty, &sekundy) == 3) {
        poradi++;
        printf("%10d. |     %02d:%02d:%02d |  %02d:%02d:%02d %s | %19d|\n",poradi, hodiny, minuty, sekundy,
               prevodCasu(hodiny) ,minuty,sekundy, hodiny<12?"AM":"PM",
               sekundyOdPulnoci(hodiny,minuty,sekundy));
        if(hodiny >= 12){
            odpoPoradi++;
            fprintf(fw,"%10d. |    %02d:%02d:%02d |  %02d:%02d:%02d %s | %18d|\n",odpoPoradi,hodiny, minuty, sekundy,
                    prevodCasu(hodiny) ,minuty,sekundy, hodiny<12?"AM":"PM",
                    sekundyOdPulnoci(hodiny,minuty,sekundy));
        }

    }
    printf("Ze souboru %s bylo precteno %d udaju o case.\n",VSTUP,poradi);
    fprintf(fw,"-------------------------------------------------------------\n");
    fprintf(fw,"Do souboru %s bylo zapsano %d udaju o case.\n",VYSTUP,odpoPoradi);

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
