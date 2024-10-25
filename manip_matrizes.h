#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char CPF[12];
  char senha[7];
  char nome[100];
  FILE *historico;
  char nome_hist[100];
} pessoa;


typedef struct Fracao {
  int numerador;
  int denominador;
} Fracao;

// ---------- Menus ---------
void menu(pessoa pessoas[], int usuariologado);
void menuinicial(pessoa pessoas[], int usuariologado);

//------ FUNÇÕES DE FRAÇÃO ------
Fracao simplificar(Fracao f);
Fracao somar(Fracao a, Fracao b);
Fracao subtrair(Fracao a, Fracao b);
Fracao dividir(Fracao a, Fracao b);
Fracao multiplicar(Fracao a, Fracao b);
Fracao lerFracao();
Fracao fracPadrao();
Fracao frac_unitaria_Positiva();
Fracao frac_unitaria_Negativa();
int mdc(int a, int b);
int comparar(Fracao a, Fracao b);
void imprimirFracao(Fracao f);

//---------- Cria matrizes ----------
void cria_matriz(Fracao ***matriz, int linhas, int colunas, int segunda_matriz, int mesma_ordem);
void free_matriz(Fracao **matriz, int linhas);

//------------Binário----------------
int arquivoexiste(const char *filename);
void escrever(pessoa pessoas[], int quantidade);
void ler(FILE *file, pessoa pessoas[], int quantidade);

//--------------TXT---------------------
void criaTXTHISTORICO(FILE **file,int usuariologado,pessoa pessoas[]);
void gravaMatrizesEmTxt(Fracao **matriz1, Fracao **matriz2, Fracao **matrizresultante, int linhas1, int colunas1, int linhas2, int colunas2, int usuariologado,pessoa pessoas[],char opc);
void lerhistorico(int usuariologado, pessoa pessoas[]);
void gravaSistemaEmTxt(Fracao **equacoes, Fracao *independentes, Fracao *solucoes,int icognitas, int eqs, int usuariologado, pessoa pessoas[]);

//---------- Funções auxiliares ----------
void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
void verifica_linhas(int *linhas_rece, int *colunas_rece);
void verifica_ordens(int *n);

//--------------- Funções Principais ----------------------
void printMatriz(Fracao **matriz, int linhas, int colunas);
void transposta(Fracao **matriz, int linhas, int colunas,pessoa pessoas[],int usuariologado);
void soma(pessoa pessoas[], int usuariologado);
void sub(pessoa pessoas[], int usuariologado);
void multi(pessoa pessoas[], int usuariologado);
void inversa(pessoa pessoas[],int usuariologado);
Fracao determinante(Fracao **matriz, int n);
void sistemalinear(pessoa pessoas[], int usuariologado);
void decomposicaoLU(pessoa pessoas[], int usuariologado);

#endif
