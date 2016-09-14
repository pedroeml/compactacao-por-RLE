#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * 2 - Compactar o vetor.
 *      2.1 - Le o primeiro char e joga na posição 'i' do vetor temporário.
 *      2.2 - Conta quantos chars iguais à posição 'i' até encontrar um char diferente.
 *      2.3 - Armazena o valor inteiro na posição 'i+1'.
 */
char* CompactaVetor(char *VetorDeEntrada, int *lengthVetorCompactado, int QtdDeDados) {
    char *VetorTemp, *VetorFinal;
    int i = 0, j, index = 0, count = 0;
    unsigned char c;
    // inicialmente, pode alocar um vetor igual ao da entrada
    VetorTemp = (char*) malloc(sizeof(char)*QtdDeDados);
    // Caso em que copiamos o primeiro char apenas
    VetorTemp[index] = VetorDeEntrada[i];
    index++;
    count++;

    for(i = 1; i <= QtdDeDados; i++) {
        if(VetorTemp[index-1] == VetorDeEntrada[i])
            count++;
        else {
            if(count <= 255) {
                c = count;
                VetorTemp[index] = c;
                index += 2;
                count = 1;
                VetorTemp[index-1] = VetorDeEntrada[i];
            }
            else {
                // O algoritmo a seguir se baseia em quantas vezes devemos armazenar o caracter e 255 e em seguida imprimir o restante da divisão por 255
                c = 255;
                int multiplicador = count/255, resto = count%255;
                for(j = 1; j <= multiplicador; j++) {
                    VetorTemp[index] = c;
                    index += 2;
                    VetorTemp[index-1] = VetorDeEntrada[i-1];
                }
                c = resto;
                VetorTemp[index] = c;
                index += 2;
                count = 1;
                VetorTemp[index-1] = VetorDeEntrada[i];
            }
        }
    }

    // No final redimensiona o vetor.
    VetorFinal = (char*) malloc(sizeof(char)*(index-1));

    memcpy(VetorFinal, VetorTemp, sizeof(char)*(index-1));
    /**  é a mesma coisa que:
     *   for(i = 0; i < index-1; i += 2) {
     *       VetorFinal[i] = VetorTemp[i];
     *       VetorFinal[i+1] = VetorTemp[i+1];
     *   }
     */
    *lengthVetorCompactado = index-1;
    free(VetorTemp);
    return VetorFinal;
}

/**
 * 3 - Descompactar o vetor.
 *       3.1 - Le o primeiro char a posição 'i' e le o valor inteiro da posiço 'i+1'.
 *       3.2 - Grava em um vetor novo o char da posição 'i' a quantidade de vezes do valor inteiro da posição 'i+1'.
 */
char* DescompactaVetor(char *VetorDeEntrada, int *lengthVetorCompactado, int QtdDeDados) {
    char *VetorTemp, *VetorFinal;
    char c;
    int i = 0, posInicial = 0, rep;
    // inicialmente, pode alocar um vetor igual ao da entrada
    VetorTemp = (char*) malloc(sizeof(char)*QtdDeDados);

    for(i = 0; i < *lengthVetorCompactado; i += 2) {
        c = VetorDeEntrada[i];
        rep = (unsigned char) VetorDeEntrada[i+1];
        memset(&VetorTemp[posInicial], c, rep);
        posInicial += rep;
    }
    // No final redimensiona o vetor.
    VetorFinal = (char*) malloc(sizeof(char)*posInicial);
    memcpy(VetorFinal, VetorTemp, sizeof(char)*posInicial);
    /**  é a mesma coisa que:
     *   for(i = 0; i<QtdDeDados; i++)
     *       VetorFinal[i] = VetorTemp[i];
     */
    free(VetorTemp);
    return VetorFinal;
}

void printVetorCompactado(char *VetorDeEntrada, int *lengthVetorCompactado) {
    int i = 0;
    printf("\nVETOR COMPACTADO:\n");
    for(i = 0; i < *lengthVetorCompactado; i += 2)
        printf("%c %d ", VetorDeEntrada[i], ((unsigned char) VetorDeEntrada[i+1]));
    printf("\n");
}

void printVetorDescompactado(char *VetorDeEntrada, int largura, int altura, int QtdDeDados) {
    int i, larguraCOUNTER = 1;
    printf("\nVETOR DESCOMPACTADO:\n");
    printf("%d %d\n",largura, altura );
    for(i = 0; i<QtdDeDados; i++) {
        printf("%4d", VetorDeEntrada[i]);
        if(larguraCOUNTER < largura) //Serve para controlar a quantidade de elementos a ser impressos horizontalmente para podermos imprimir na próxima linhar
            larguraCOUNTER++;
        else {
            larguraCOUNTER = 1;
            printf("\n");
        }
    }
}

void printVetorDescompactadoBin(char *VetorDeEntrada, int qtd) { //Recebe o vetor e a quantidade de elemento gravados no arquivo binári a partir do cabeçalho
    int i;
    printf("\nVETOR DESCOMPACTADO:\n");
    printf("%4d",qtd); //Mostra quantidade de elementos gravados no arquivo binário
    for(i = 0; i<qtd; i++)
        printf("%4d", VetorDeEntrada[i]);
    printf("\n");
}
