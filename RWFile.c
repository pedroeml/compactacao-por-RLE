#include <stdio.h>
#include <stdlib.h>
/**
 *  1 - Ler o arquivo e gravar em um vetor.
 */
FILE* AbreArquivo(const char *nome, const char *tipoArquivo) {
    FILE *arq;
    arq = fopen (nome,tipoArquivo);
    if (arq == NULL) {
        printf("Problemas na abertura do arquivo %s...\n", nome);
        return NULL;
    }
    printf("Arquivo %s aberto!\n", nome);
    return arq;
}

void LeTamanhoTXT(FILE *arq, int *largura, int *altura) {
    //printf("lendo largura e altura...");
    fscanf(arq,"%d", largura);
    fscanf(arq,"%d", altura);
    printf("Largura: %4d\nAltura: %4d\n", *largura, *altura);
}

void LeDadosTXT(FILE *arq, char *V, int qtd) {
    int i, dado;
    for (i=0; i<qtd; i++) {
        fscanf(arq, "%d", &dado);
        V[i] = (char) dado; // coloca o dado no vetor, convertendo para o caracter de codigo ASCII "dado"
        printf("%2c", V[i]);
    }
    printf("\n");
}

void LeTamanhoBin(FILE *arq, int *qtdGravada) { // Recebe o arq e a quantidade de dados gravados no arquivo para depois conseguirmos montar o vetor
    int qnt;
    fread(&qnt, sizeof(int), 1, arq); // Grava a quantidade de elementos no arquivo
    *qtdGravada = qnt;
    printf("Cabeçalho: %4d\n", *qtdGravada);
}

void LeDadosBin(FILE *arq, char *V, int qtd) {
   int i, dado;
   for(i=0;i<qtd;i++) {
       fread(&dado,sizeof(int),1,arq);
       V[i] = (char) dado;
       printf("%2c", V[i]);
    }
    printf("\n");
}
