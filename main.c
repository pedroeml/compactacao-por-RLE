#include <stdio.h>
#include <stdlib.h>
#include "RWFile.h"
#include "CDVetor.h"

/**
 *   1 - Ler o arquivo e gravar em um vetor.
 *   2 - Compactar o vetor.
 *   3 - Descompactar o vetor.
 *   4 - Gravar o vetor descompactado num arquivo.
 *   5 - Realizar testes com o GeraSequenciaParaRLE.
 */

int main() {
    FILE *Arquivo;
    char nomeArquivo[] = "files/vetor.bin",/*ComUmZeroNosDados.txt vetor.bin*/ tipoArquivo[] = "rb"; // "rt" p/ texto ou "rb" p/ binário
    int largura, altura, QtdDeDados, lengthVetorCompactado;
    char *VetorDeEntrada, *VetorCompactado, *VetorDescompactado;

    Arquivo = AbreArquivo(nomeArquivo, tipoArquivo);
    if (!Arquivo)
        return 1;

    if(tipoArquivo[1]=='t') {
        LeTamanhoTXT(Arquivo, &largura, &altura);
        QtdDeDados = largura*altura;
    }
    else
        LeTamanhoBin(Arquivo, &QtdDeDados);

    // Aloca um vetor com o tamanho necessario
    VetorDeEntrada = (char*) malloc(sizeof(char)*QtdDeDados); // Tenta alocar memória para a quantidade de chars que precisamos.
    if (VetorDeEntrada == NULL) { // Se malloc retornar null, então ele não conseguiu alocar.
        printf("Faltou memória!");
        return 2;
    }
    if(tipoArquivo[1]=='t')
        LeDadosTXT(Arquivo, VetorDeEntrada, QtdDeDados);
    else
        LeDadosBin(Arquivo, VetorDeEntrada, QtdDeDados);

    // Neste ponto do codigo, o VetorDeEntrada tem os dados lidos do arquivo

    VetorCompactado = CompactaVetor(VetorDeEntrada, &lengthVetorCompactado, QtdDeDados);
    printVetorCompactado(VetorCompactado, &lengthVetorCompactado);
    VetorDescompactado = DescompactaVetor(VetorCompactado, &lengthVetorCompactado, QtdDeDados);

    if(tipoArquivo[1]=='t')
        printVetorDescompactado(VetorDescompactado, largura, altura, QtdDeDados);
    else
        printVetorDescompactadoBin(VetorDescompactado, QtdDeDados);

    printf("\n\nEXECUÇÃO CONCLUÍDA\n");
    free(VetorDeEntrada);
    return 0;
}

/**
 * dec %d: 64 hex %x: 40 bin: 01000000 = @
 * unsigned char c = 4;
 * 0 = FALSE; Qualquer outra coisa = TRUE;
 * !0 = TRUE; !1 = FALSE;
 * NULL = 0 = FALSE; !NULL = TRUE
 */
