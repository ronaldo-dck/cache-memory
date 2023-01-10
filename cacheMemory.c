#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[6])
{

    int linhas1 = atoi(argv[1]);
    int colunas1 = atoi(argv[2]);

    int linhas2 = atoi(argv[3]);
    int colunas2 = atoi(argv[4]);

    srand(time(NULL));

    double **MAT_1, **MAT_2, **MAT_MULT;

    // Alocação da MAT_1
    MAT_1 = malloc(linhas1 * sizeof(double *));
    for (int i = 0; i < linhas1; i++)
        MAT_1[i] = malloc(colunas1 * sizeof(double));

    // Alocação da MAT_2
    MAT_2 = malloc(linhas2 * sizeof(double *));
    for (int i = 0; i < linhas2; i++)
        MAT_2[i] = malloc(colunas2 * sizeof(double));

    // Alocação da MAT_MULT
    MAT_MULT = malloc(linhas1 * sizeof(double *));
    for (int i = 0; i < linhas1; i++)
        MAT_MULT[i] = malloc(colunas2 * sizeof(double));

    for (int i = 0; i < linhas1; i++)
        for (int j = 0; j < colunas1; j++)
            MAT_1[i][j] = rand() % 101;

    for (int i = 0; i < linhas2; i++)
        for (int j = 0; j < colunas2; j++)
            MAT_2[i][j] = rand() % 101;

    // Multiplicação classica das matrizes
    for (int i = 0; i < linhas1; i++)
        for (int j = 0; j < colunas2; j++)
        {
            double sum = 0;
            for (int k = 0; k < colunas1; k++)
                sum = sum + MAT_1[i][k] * MAT_2[k][j];
            MAT_MULT[i][j] = sum;
        }


    printf("MAT_2 antes da transposição\n");
    for (int i = 0; i < linhas2; i++)
    {
        for (int j = 0; j < colunas2; j++)
            printf("%3.0lf", MAT_2[i][j]);;

        printf("\n");
    }

    printf("Resultado classico\n");
    for (int i = 0; i < linhas1; i++)
    {
        for (int j = 0; j < colunas2; j++)
            printf("%10.0lf", MAT_MULT[i][j]);

        printf("\n");
    }

  //Multiplicação classica das matrizes com transposição
    for (int i = 0; i < linhas1; i++)
        for (int j = 0; j < colunas2; j++)
        {
            double sum = 0;
            for (int k = 0; k < colunas1; k++)
                sum = sum + MAT_1[j][k] * MAT_2[k][i];
            MAT_MULT[j][i] = sum;
        }

    for(int i = 0; i< linhas2; i++)
        for(int j = i + 1; j <colunas2; j++){
            double aux = MAT_2[i][j];
            MAT_2[i][j] = MAT_2[j][i];
            MAT_2[j][i] = aux;
        }
    
//////////////////////////////////
    printf("MAT_1\n");
    for (int i = 0; i < linhas1; i++)
    {
        for (int j = 0; j < colunas1; j++)
            printf("%3.0lf", MAT_1[i][j]);

        printf("\n");
    }

    printf("MAT_2 depois da transposição\n");
    for (int i = 0; i < linhas2; i++)
    {
        for (int j = 0; j < colunas2; j++)
            printf("%3.0lf", MAT_2[i][j]);;

        printf("\n");
    }

    printf("Resultado usando o metodo com transposição  \n");
    for (int i = 0; i < linhas1; i++)
    {
        for (int j = 0; j < colunas2; j++)
            printf("%10.0lf", MAT_MULT[i][j]);

        printf("\n");
    }
////////////////////////////////////////
    return 0;
}
