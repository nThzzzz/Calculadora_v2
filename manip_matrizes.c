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
  int numbarra = 0;  // para contar o número de barras na entrada
  int valida = 0;  // para verificar se a entrada foi válida

  while (!valida) {
    printf("Digite uma fração (EX: 3/4) ou um número inteiro: ");
    scanf("%s", frac);

    // Verificar se há barras barras ou vírgulas
    numbarra = 0;
    for (int i = 0; i < strlen(frac); i++) {
      if (frac[i] == '/') {
        numbarra++;
      }
      if (frac[i] == ',' || (!isdigit(frac[i]) && frac[i] != '/' && frac[i] != '-')) {
        printf("Use apenas números inteiros ou frações no formato a/b, tente novamente\n");
        numbarra = 2; 
        break;
      }
    }

    if (numbarra > 1) {
      printf("Digite a fração no formato a/b, tente novamente\n");
      continue;
    }

    // Tentar analisar como fração
    if (numbarra == 1) {
      if (sscanf(frac, "%d/%d", &f.numerador, &f.denominador) == 2) {
        if (f.denominador == 0) {
          printf("O denominador não pode ser zero.\n");
          continue;
        }
        valida = 1;  // entrada válida
      } else {
        printf("Entrada de fração inválida.\n");
      }
    } else {
      // Tentar analisar como número inteiro
      if (sscanf(frac, "%d", &f.numerador) == 1) {
        f.denominador = 1;
        valida = 1;  // entrada válida
      } else {
        printf("Entrada de número inválida.\n");
      }
    }
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
  }
}

// ---------------------------------------- Funções de criação de Matrizes ----------------------------------------

// Funcao que cria e armazena na memoria a uma matriz
void cria_matriz(Fracao ***matriz, int linhas, int colunas, int segunda_matriz,
                 int mesma_ordem) {
  *matriz = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    (*matriz)[i] = (Fracao *)malloc(colunas * sizeof(Fracao));
  }

  switch (mesma_ordem) {
  case 1:
    break;
  case 0:
    printf("Digite o número de linhas da Matriz: \n");
    scanf("%d", &linhas);
    printf("Digite o número de linhas da Matriz: \n");
    scanf("%d", &colunas);
  default:
    break;
  }

  switch (segunda_matriz) {
  case 0:
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("Digite o número da posição %d x %d da PRIMEIRA matriz: \n",
               i + 1, j + 1);
        (*matriz)[i][j] = lerFracao();
      }
    }
    break;
  case 1:
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("Digite o número da posição %d x %d da SEGUNDA matriz: \n",
               i + 1, j + 1);
        (*matriz)[i][j] = lerFracao();
      }
    }
    break;
  default:
    break;
  }
}

// Função para liberar a matriz
void free_matriz(Fracao **matriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

// ---------------------------------- Funções do Binário ----------------------- //

// Funcao que verifia de o binario ja foi criado ou nao
int arquivoexiste(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    fclose(file);
    return 1; // Arquivo existe
  }
  return 0; // Arquivo não existe
}

// Funcao que escreve no binario
void escrever(pessoa pessoas[], int quantidade) {
  FILE *file = fopen("dados.bin", "wb");

  fwrite(pessoas, sizeof(pessoa), 10, file);
  fclose(file);
}

// Lê as informações e as atribui a variáveis
void ler(FILE *file, pessoa pessoas[], int quantidade) {
  file = fopen("dados.bin", "rb");

  fread(pessoas, sizeof(pessoa), 10, file);

  fclose(file);
}
