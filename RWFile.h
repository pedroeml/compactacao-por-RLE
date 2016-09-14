#ifndef RWFILE_H_INCLUDED
#define RWFILE_H_INCLUDED

FILE* AbreArquivo(const char *nome, const char *tipoArquivo);
void LeTamanhoTXT(FILE *arq, int *largura, int *altura);
void LeDadosTXT(FILE *arq, char *V, int qtd);
void LeTamanhoBin(FILE *arq, int *qtdGravada); //// inserido para ler o arquivo BIN
void LeDadosBin(FILE *arq, char *V, int qtd);  // ler arquivo bin
#endif // RWFILE_H_INCLUDED
