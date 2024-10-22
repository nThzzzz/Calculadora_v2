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

  return simplificar(resultado);
}

Fracao subtrair(Fracao a, Fracao b) {

  return simplificar(resultado);
}

Fracao dividir(Fracao a, Fracao b) {
  
  return simplificar(resultado);
}

Fracao multiplicar(Fracao a, Fracao b) {

  return simplificar(resultado);
}

Fracao lerFracao() {
  
  return simplificar(f);
}

Fracao fracPadrao() {

  return simplificar(f);
}

Fracao frac_unitaria_Positiva() {

  return simplificar(f);
}

Fracao frac_unitaria_Negativa() {

  return simplificar(f);
}
