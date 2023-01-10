#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double **aloca(int linhas, int colunas, double **matriz){
    matriz = malloc(linhas * sizeof(double *));
    for (int i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(double));
    return matriz;
}


double** popula(int linhas, int c, double **matriz)
{
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < c; j++)
            matriz[i][j] = rand() % 101;
    return matriz;
}


double** multClassica(int linhas1, int colunas1, int colunas2, double **MAT_1, double **MAT_2, double **MAT_MULT) {
    
    
    for (int i = 0; i < linhas1; i++)
        for (int j = 0; j < colunas2; j++)
        {
            double sum = 0;
            for (int k = 0; k < colunas1; k++)
                sum = sum + MAT_1[i][k] * MAT_2[k][j];
            MAT_MULT[i][j] = sum;
        }
    return MAT_MULT;
}


double** multClassicaComTransposta(int linhas1, int colunas1, int linhas2, double **MAT_1, double **MAT_2, double **MAT_MULT) {
    for (int i = 0; i < linhas1; i++)
        for (int j = 0; j < linhas2; j++)
        {
            double sum = 0;
            for (int k = 0; k < colunas1; k++)
                sum = sum + MAT_1[j][k] * MAT_2[i][k];
            MAT_MULT[j][i] = sum;
        }

    return MAT_MULT;
}


double** transposta(int linhas,int colunas, double **matriz){
    for(int i = 0; i< linhas ; i++)
        for(int j = i + 1; j < colunas; j++){
            double aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    return matriz;
}


int main(int argc, char *argv[6])
{

    int linhas1 = atoi(argv[1]);
    int colunas1 = atoi(argv[2]);
    int linhas2 = atoi(argv[3]);
    int colunas2 = atoi(argv[4]);
    char mode = argv[5];

    float tempo = 0.0;
    clock_t inicio, fim;


    srand(time(NULL));

    double **MAT_1, **MAT_2, **MAT_MULT;

    MAT_1     =  aloca(linhas1, colunas1, MAT_1);
    MAT_2     =  aloca(linhas2, colunas2, MAT_2);
    MAT_MULT  =  aloca(linhas1, colunas2, MAT_MULT);



    MAT_1 = popula(linhas1, colunas1, MAT_1);
    MAT_2 = popula(linhas2, colunas2, MAT_2);

    if(mode == 'o'){
        
    
    inicio = clock();
    MAT_MULT =  multClassica(linhas1, colunas1, colunas2, MAT_1, MAT_2, MAT_MULT);
    fim = clock();

    tempo = (float) (((fim - inicio ) + 0.0) / CLOCKS_PER_SEC);
    }else if(mode == 't') {

        MAT_2 = transposta(linhas2, colunas2, MAT_2);


        inicio = clock();
        MAT_MULT =  multClassicaComTransposta(linhas1, colunas1, linhas2, MAT_1, MAT_2, MAT_MULT);

        fim = clock();

        tempo = (float) (((fim - inicio ) + 0.0) / CLOCKS_PER_SEC);
    } else {
        printf("Entrada Invalida\n");
    }

    return 0;
}
