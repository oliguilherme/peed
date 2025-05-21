#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    float matriz[15][4], media_aluno[15], media_disciplina[4];
    float maior_media = 0.0, menor_media_disciplina = 10.0;

    srand(time(NULL));

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 11;
        }
    }

    printf("Media de cada aluno \n\n");
    for (int i = 0; i < 15; i++) {
        float soma_nota_disciplina = 0;
        for (int j = 0; j < 4; j++) {
            soma_nota_disciplina += matriz[i][j];
        }
        media_aluno[i] = soma_nota_disciplina / 4.0;

        if (media_aluno[i] > maior_media) maior_media = media_aluno[i];

        printf("Media do aluno %d: %.2f\n", i+1, media_aluno[i]);
    }

    printf("\nA maior media foi %.2f, do(s) aluno(s): ", maior_media);
    for (int i = 0; i < 15; i++) {
        if (media_aluno[i] == maior_media) printf("%d ", i+1);
    }

    printf("\n\nMedia de cada disciplina: \n");

    for (int i = 0; i < 4; i++) {
        float soma_nota_disciplina = 0;
        for (int j = 0; j < 15; j++) {
            soma_nota_disciplina = matriz[j][i];
        }
        media_disciplina[i] = soma_nota_disciplina / 4;

        if (media_disciplina[i] < menor_media_disciplina) menor_media_disciplina = media_disciplina[i];

        printf("Media da disciplina %d eh: %.2f\n",i+1, media_disciplina[i]);
    }

    printf("A menor media foi %.2f, da(s) disciplina(s):", menor_media_disciplina);
    for (int i = 0; i < 4; i++) {
        if (media_disciplina[i] == menor_media_disciplina) printf(" %d", i+1);
    }
    return 0;
}