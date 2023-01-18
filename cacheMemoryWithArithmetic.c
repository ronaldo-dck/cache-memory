#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    unsigned linhas;
    unsigned colunas;
    double *matriz;
} mat;

mat aloca(mat matriz)
{
    matriz.matriz = malloc(matriz.linhas * matriz.colunas * sizeof(double *));
     return matriz;
}

mat popula(mat matriz)
{
    for (int i = 0; i < (matriz.linhas*matriz.colunas); i++)
            matriz.matriz[i] = rand();
    return matriz;
}


mat multClassica(mat MAT_1, mat MAT_2, mat MAT_MULT)
{
    for (int i = 0; i < MAT_1.linhas; i++)
        for (int j = 0; j < MAT_2.colunas; j++)
        {
            double sum = 0;
            for (int k = 0; k < MAT_1.colunas; k++)
                sum = sum + MAT_1.matriz[i*MAT_1.linhas+k] * MAT_2.matriz[k*MAT_2.linhas + j];
            MAT_MULT.matriz[i* MAT_MULT.linhas + j] = sum;
        }
    return MAT_MULT;
}

mat multClassicaComTransposta(mat MAT_1, mat MAT_2, mat MAT_MULT)
{
    for (int i = 0; i < MAT_1.linhas; i++)
        for (int j = 0; j < MAT_2.linhas; j++)
        {
            double sum = 0;
            for (int k = 0; k < MAT_1.colunas; k++)
                sum = sum + MAT_1.matriz[j*MAT_1.linhas + k] * MAT_2.matriz[i*MAT_2.linhas + k];
            MAT_MULT.matriz[j*MAT_MULT.linhas + i] = sum;
        }

    return MAT_MULT;
}

mat transposta(mat matriz)
{
    for (int i = 0; i < matriz.linhas; i++)
        for (int j = i + 1; j < matriz.colunas; j++)
        {
            double aux = matriz.matriz[i*matriz.linhas + j];
            matriz.matriz[i*matriz.linhas + j] = matriz.matriz[j*matriz.linhas + i];
            matriz.matriz[j*matriz.linhas + i] = aux;
        }
    return matriz;
}


int main(int argc, char *argv[6])
{
    mat MAT_1, MAT_2, MAT_MULT;

    MAT_1.linhas = atoi(argv[1]);
    MAT_1.colunas = atoi(argv[2]);
    MAT_2.linhas = atoi(argv[3]);
    MAT_2.colunas = atoi(argv[4]);
    char mode = *argv[5];

    MAT_MULT.linhas = MAT_1.linhas;
    MAT_MULT.colunas = MAT_2.colunas;

    float tMult = 0.0, tTrans = 0.0, tCria = 0.0;
    clock_t inicio, fim;
    FILE *tempos;

    srand(time(NULL));

    inicio = clock();
    MAT_1 = aloca(MAT_1);
    MAT_2 = aloca(MAT_2);
    MAT_MULT = aloca(MAT_MULT);

    MAT_1 = popula(MAT_1);
    MAT_2 = popula(MAT_2);
    fim = clock();
    tCria = (float)(((fim - inicio) + 0.0) / CLOCKS_PER_SEC);


    

    if (mode == 'o')
    {
        inicio = clock();
        MAT_MULT = multClassica(MAT_1, MAT_2, MAT_MULT);
        fim = clock();

        tMult = (float)(((fim - inicio) + 0.0) / CLOCKS_PER_SEC);
    }
    else if (mode == 't')
    {
        inicio = clock();
        MAT_2 = transposta(MAT_2);
        fim = clock();
        tTrans = (float)(((fim - inicio) + 0.0) / CLOCKS_PER_SEC);

        inicio = clock();
        MAT_MULT = multClassicaComTransposta(MAT_1, MAT_2, MAT_MULT);
        fim = clock();

        tMult = (float)(((fim - inicio) + 0.0) / CLOCKS_PER_SEC);
    }
    else
        printf("Entrada Invalida\n");

    tempos = fopen("temposWithArithmetic.txt", "a");
    fprintf(tempos, "%d, %c, %f, %f, %f, %f\n", MAT_2.colunas, mode, tCria, tTrans, tMult, tTrans + tMult);
    fclose(tempos);
    return 0;
}
