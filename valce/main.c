#include <stdio.h>
#include <math.h>

#define VSTUP "cisla.txt"
#define VYSTUP "hladiny.txt"

/*parametry r a v jsou v cm*/
float obsahPodstavy(int r) {
    return (M_PI * r * r);
}

float objem(int r, int v) {
    return (obsahPodstavy(r) * v / 1000);
}

/*"V" tam prijde v dm krychlovych*/
float hladina(float V, float Sp) {
    return (V * 1000 / Sp);
}

int main() {
    FILE *fr, *fw;
    int polomer, vyska, mnozstviVody, poradi = 0, poradis = 0;
    float objemValce;
    fr = fopen(VSTUP, "r");
    if (fr == NULL) {
        printf("%s nebyl uspesne otevren", VSTUP);

    }

    fw = fopen(VYSTUP, "w");
    if (fw == NULL) {
        printf("%s nebyl uspesne otevren", VYSTUP);

    }

    fprintf(fw, "V A L C E  S  V Y H O V U J I C I M  O B J E M E M\n");
    fprintf(fw, "--------------------------------------------------\n");
    fprintf(fw, "   polomer     vyska   objem valce    mnozstvi vody  vyska hladiny\n");
    fprintf(fw, "   (cm)        (cm)  (dm krychlove)         (litry)           (cm)\n");
    fprintf(fw, "------------------------------------------------------------------\n");
    printf("V A L C E\n");
    printf("---------\n");
    printf("   polomer     vyska   objem valce    mnozstvi vody\n");
    printf("   (cm)        (cm)  (dm krychlove)         (litry)\n");
    printf("---------------------------------------------------\n");
    while (fscanf(fr, "%d%d%d", &polomer, &vyska, &mnozstviVody) != EOF) {
        poradi++;
        objemValce = objem(polomer, vyska);
        printf("%2d. %3d cm %6d cm %10.2f dm %9d l\n", poradi, polomer, vyska, objemValce, mnozstviVody);
        if (objemValce > mnozstviVody) {
            poradis++;
            fprintf(fw,"%2d. %3d cm %6d cm %10.2f dm %14d l %11.2f cm\n", poradis, polomer, vyska,
                    objemValce, mnozstviVody,hladina(mnozstviVody,obsahPodstavy(polomer)));
        }
    }
    printf("---------------------------------------------------\n");
    fprintf(fw,"------------------------------------------------------------------\n");
    if (fclose(fr) == EOF) {
        printf("%s nebyl uzavren\n", VSTUP);
    }
    if (fclose(fw) == EOF) {
        printf("%s nebyl uzavren\n", VYSTUP);
    } else {
        printf("soubor %s byl vytvoren\n", VYSTUP);
    }
    return 0;
}
