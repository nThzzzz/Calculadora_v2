#ifndef manip_matrizes
#define manip_matrizes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Fracao {
  int numerador;
  int denominador;
} Fracao;

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

#endif
