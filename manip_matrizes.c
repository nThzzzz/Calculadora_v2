#include "manip_matrizes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------- FUNÇÕES DAS FRAÇÕES ---------
Fracao simplificar(Fracao f) {
  int divisor_comum = mdc(f.numerador, f.denominador);

  if (f.numerador == 0 || f.denominador == 0) {
    f.numerador = 0;
    f.denominador = 1;
  } else {
    f.numerador /= divisor_comum;
    f.denominador /= divisor_comum;
    if (f.denominador < 0) {
      f.numerador = -1 * f.numerador;
    }
  }
  return f;
}

Fracao somar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

Fracao subtrair(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

Fracao dividir(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador;
  resultado.denominador = a.denominador * b.numerador;
  return simplificar(resultado);
}

Fracao multiplicar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.numerador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

Fracao lerFracao() {
  Fracao f;
  char frac[20];

  // Tenta ler a fração (numerador/denominador) ou inteiro
  scanf("%s", frac);

  // Tenta analisar a entrada como uma fração
  if (sscanf(frac, "%d/%d", &f.numerador, &f.denominador) == 2) { // Genial
    // Se a fração for válida
    if (f.denominador == 0) {
      printf("Denominador não pode ser zero.\n");
      f.denominador = 1;
    }
  } else {
    // Se não for uma fração, leia como número inteiro
    f.numerador = atoi(frac); // Converte de string pra numero
    f.denominador = 1;
  }
  return simplificar(f);
}

Fracao fracPadrao() {
  Fracao f;

  f.numerador = 0;
  f.denominador = 1;

  return simplificar(f);
}

Fracao frac_unitaria_Positiva() {

  return simplificar(f);
}

Fracao frac_unitaria_Negativa() {

  return simplificar(f);
}
