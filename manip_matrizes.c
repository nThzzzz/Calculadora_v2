#include "manip_matrizes.h"

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
  }
}

