#ifndef CDVETOR_H_INCLUDED
#define CDVETOR_H_INCLUDED

char* CompactaVetor(char *VetorDeEntrada, int *lengthVetorCompactado, int QtdDeDados);
char* DescompactaVetor(char *VetorDeEntrada, int *lengthVetorCompactado, int QtdDeDados);
void printVetorCompactado(char *VetorEntrada, int *lengthVetorCompactado);
void printVetorDescompactado(char *VetorEntrada, int largura, int altura, int QtdDeDados);
void printVetorDescompactadoBin(char *VetorDeEntrada, int qtd);  // inserido para ler o arquivo BIN
#endif // CDVETOR_H_INCLUDED
