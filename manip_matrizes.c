#include "manip_matrizes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------- FUNÇÕES DAS FRAÇÕES ---------

// Função para simplificar a fração
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

// Função para somar duas frações
Fracao somar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Função para subtrair duas frações
Fracao subtrair(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Funcao que dividi frações
Fracao dividir(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.denominador;
  resultado.denominador = a.denominador * b.numerador;
  return simplificar(resultado);
}

// Função que multiplica frações
Fracao multiplicar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador = a.numerador * b.numerador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Função para ler um número inteiro ou uma fração
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

// Pra usar em casos que se inicia como 0;
Fracao fracPadrao() {
  Fracao f;
  f.numerador = 0;
  f.denominador = 1;
  return simplificar(f);
}

// Fracao que equivale a 1
Fracao frac_unitaria_Positiva() {
  Fracao f;
  f.numerador = 1;
  f.denominador = 1;
  return simplificar(f);
}

// Fracao que equivale a -1
Fracao frac_unitaria_Negativa() {
  Fracao f;
  f.numerador = -1;
  f.denominador = 1;
  return simplificar(f);
}
