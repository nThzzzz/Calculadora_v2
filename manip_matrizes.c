#include "manip_matrizes.h"


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

// Função para calcular o MDC (Máximo Divisor Comum)
int mdc(int a, int b) {
  if (b == 0)
    return a;
  return mdc(b, a % b);
}

// Compara 2 fracoes
int comparar(Fracao a, Fracao b) {
  if (a.numerador == b.numerador && a.denominador == b.denominador) {
    return 0;
  } else {
    return 1;
  }
}

// Função para imprimir a fração
void imprimirFracao(Fracao f) {
  f = simplificar(f);
  if (f.denominador == 1) {
    printf("%5d    ", f.numerador); // Se denominador for 1, é um número inteiro
  } else {
    printf("%5d/%-5d", f.numerador,
           f.denominador); // Caso contrário, imprime a fração
  }
}

// ---------------------------------- Menus ----------------------- //

// Funcao que apresenta o menu ao usuario
void menu(pessoa pessoas[], int usuariologado) {
  int condicao = 1;
  limpaterminal();
  printf("--------------------------------------|+| CALCULADORA 2 "
         "|+|--------------------------------------\n");
  printf("Qual operação deseja realizar: \n\n");
  printf("Soma\t\t\t\t\t-\t(1)\n");
  printf("Subtração\t\t\t\t-\t(2)\n");
  printf("Multiplicação\t\t\t-\t(3)\n");
  printf("Inversa\t\t\t\t\t-\t(4)\n");
  printf("Transposta\t\t\t\t-\t(5)\n");
  printf("Determinante\t\t\t-\t(6)\n");
  printf("Decomposição LU\t\t\t-\t(7)\n");
  printf("Resolução de Sistemas\t-\t(8)\n");
  printf("Ver histórico\t\t\t-\t(9)\n");
  printf("Sair\t\t\t\t\t-\t(0)\n");
  printf("--------------------------------------|+| CALCULADORA 2 "
         "|+|--------------------------------------\n");

  int linhas, colunas, n;

  while (condicao) {
    int opc;
    scanf(" %d", &opc);
    limpabuffer();

    switch (opc) {
    case 1:
      soma(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 2:
      sub(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 3:
      multi(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 4:
      inversa(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 5:
      menu(pessoas, usuariologado);
      break;
    case 6:
      menu(pessoas, usuariologado);
      break;
    case 7:
      decomposicaoLU(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 8:
      sistemalinear(pessoas, usuariologado);
      menu(pessoas, usuariologado);
      break;
    case 9:
      lerhistorico(usuariologado, pessoas);
      menu(pessoas, usuariologado);
      break;
    case 0:
      condicao = 0;
      menuinicial(pessoas, usuariologado);
      break;
    default:
      printf("Opçao inválida, tente novamente\n");
      break;
    }
  }
}

// Funcao que mostra o menu inicial ao usuario
void menuinicial(pessoa pessoas[], int usuariologado) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |---------------[Menu Inicial]---------------| \n");
    printf(" | [1] Cadastro                               | \n");
    printf(" | [2] Login                                  | \n");
    printf(" | [3] Sair                                   | \n");
    printf(" |--------------------------------------------| \n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();

    switch (opc) {
    case '1':
      cadastrar(pessoas, usuariologado);
      return;
    case '2':
      login(pessoas, usuariologado);
      return;
    case '3':
      escrever(pessoas, 10);
      exit(0);
      return;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
    }
