#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define VSTUP "vysky_vahy.txt"
#define VYSTUP "obezita.txt"

float metr(float cm){
    return cm/100;
}

float BMI(float kg,float m){
    float hodnota;
    m=metr(m);
    hodnota=kg/(m*m);
    return hodnota;
}

float prumer(float m,float pocet){
    return m/pocet;
}


int main(){
    float kg,m,bmi,pr,ms=0,poradi=0;
    int poradiSoubor=0;
    FILE *fw,*fr;
    fr= fopen(VSTUP,"r");
    if(fr==NULL){
        printf("Soubor %s se nepodarilo uspesne otevrit.\n",VSTUP);
        return EXIT_FAILURE;
    }
    fw= fopen(VYSTUP,"w");
    if(fw==NULL){
        printf("Soubor %s se nepodarilo uspesne otevrit.\n",VYSTUP);
        return EXIT_FAILURE;
    }

    printf("U D A J E  Z E  S O U B O R U\n");
    printf("---------------------------------\n");
    printf("poradi|vyska(cm)|vaha(kg)|  BMI |\n");
    printf("---------------------------------\n");
    fprintf(fw,"O B E Z N I  J E D I N C I\n");
    fprintf(fw,"---------------------------------\n");
    fprintf(fw,"poradi|vyska(cm)|vaha(kg)|  BMI |\n");
    fprintf(fw,"---------------------------------\n");

    while (fscanf(fr,"%f%f",&m,&kg)==2) {
        poradi++;
        ms+=m;
        bmi=BMI(kg,m);
        if(bmi >= 30){
            poradiSoubor++;
            fprintf(fw,"%5d.|%9.0f|% 8.0f| %.2f|\n",poradiSoubor, m,kg,bmi);
        }
        printf("% 5.0f.|%9.0f|% 8.0f| %.2f|\n",poradi, m,kg,bmi);
    }
    fprintf(fw,"Do souboru %s byly zapsany udaje o %d obeznich osobach.",VYSTUP,poradiSoubor);
    printf("---------------------------------\n");
    pr=prumer(ms,poradi);
    printf("Ze souboru %s byly precteny udajo o %.0f osobach.\n",VSTUP,poradi);
    printf("Prumerna vyska %.0f osob je %.2f cm.\n\n",poradi,pr);

    if(fclose(fr)==EOF){
        printf("Soubor %s se nepodarilo uspesne zavrit.\n",VSTUP);
        return EXIT_FAILURE;
    }
    if(fclose(fw)==EOF){
        printf("Soubor %s se nepodarilo uspesne zavrit.\n",VYSTUP);
        return EXIT_FAILURE;
    } else{
        printf("Byl vytvoren soubor %s.\n",VYSTUP);
    }
    return 0;
}