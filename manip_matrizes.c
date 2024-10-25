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
  Fracao **matriz;

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
      verifica_linhas(&linhas, &colunas);
      cria_matriz(&matriz, linhas, colunas, 0, 1);
      transposta(matriz, linhas, colunas, pessoas, usuariologado);
      limpabuffer();
      espera();
      free_matriz(matriz, linhas);
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

//-------------------------------------- Funções do TXT -------------------------//

// função que le o histórico do usuário
void lerhistorico(int usuariologado, pessoa pessoas[]) {
  limpaterminal();
  char linha[300];
  FILE *file = fopen(pessoas[usuariologado].nome_hist, "r");
  while (fgets(linha, sizeof(linha), file)) {
    printf("%s", linha);
    printf("\n");
  }
  fclose(file);
  espera();
}

// Função que grava as matrizes no histórico do usuario
void gravaMatrizesEmTxt(Fracao **matriz1, Fracao **matriz2,
                        Fracao **matrizresultante, int linhas1, int colunas1,
                        int linhas2, int colunas2,
                        int usuariologado, pessoa pessoas[], char opc) {
    FILE *arquivo = fopen(pessoas[usuariologado].nome_hist, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (matriz2 != NULL) {  // Quando matriz2 é diferente de NULL
        if (opc == 'D') {  // Operação D (ex: multiplicação com 2 matrizes)
            fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                            matriz1[i][j].denominador);
                }

                fprintf(arquivo, "=\t");

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz2[i][j].numerador,
                            matriz2[i][j].denominador);
                }

                fprintf(arquivo, "*\t");

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matrizresultante[i][j].numerador,
                            matrizresultante[i][j].denominador);
                }

                fprintf(arquivo, "\n");
            }
        } else if (opc == '*') {
          if(linhas1 == linhas2 && colunas1 == colunas2){
            fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                            matriz1[i][j].denominador);
                }

                fprintf(arquivo, "%c\t", opc);  // Imprimir a operação

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz2[i][j].numerador,
                            matriz2[i][j].denominador);
                }

                fprintf(arquivo, "=\t");

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matrizresultante[i][j].numerador,
                            matrizresultante[i][j].denominador);
                }

                fprintf(arquivo, "\n");
            }
          }
           else if (colunas1 == linhas2) {
                fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");

                // Imprimir a primeira matriz
                for (int i = 0; i < linhas1; i++) {
                    for (int j = 0; j < colunas1; j++) {
                        fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                                matriz1[i][j].denominador);
                    }
                    fprintf(arquivo, "\n");
                }

                fprintf(arquivo, "\n\t\t%c\t\n", opc);  // Imprimir o operador

                // Imprimir a segunda matriz
                for (int i = 0; i < linhas2; i++) {
                    for (int j = 0; j < colunas2; j++) {
                        fprintf(arquivo, "%5d/%-5d\t", matriz2[i][j].numerador,
                                matriz2[i][j].denominador);
                    }
                    fprintf(arquivo, "\n");
                }

                fprintf(arquivo, "\n\t\t=\t\n");  // Imprimir o sinal de igual

                // Imprimir a matriz resultante
                for (int i = 0; i < linhas1; i++) {
                    for (int j = 0; j < colunas2; j++) {
                        fprintf(arquivo, "%5d/%-5d\t", matrizresultante[i][j].numerador,
                                matrizresultante[i][j].denominador);
                    }
                    fprintf(arquivo, "\n");
                }
            } else {
                fprintf(arquivo, "\n\tErro: A multiplicação não é possível!\n");
            }
        } else {  // Outras operações
            fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                            matriz1[i][j].denominador);
                }

                fprintf(arquivo, "%c\t", opc);  // Imprimir a operação

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz2[i][j].numerador,
                            matriz2[i][j].denominador);
                }

                fprintf(arquivo, "=\t");

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matrizresultante[i][j].numerador,
                            matrizresultante[i][j].denominador);
                }

                fprintf(arquivo, "\n");
            }
        }
    } else {  // Caso matriz2 seja NULL
        if (opc == 'T') {  // Operação Transposta
            fprintf(arquivo, "\n\t::VALORES DAS MATRIZES (Transposta)::\n");

            // Imprimir a matriz original
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                            matriz1[i][j].denominador);
                }
                fprintf(arquivo, "\n");
            }

            fprintf(arquivo, "=\n");

            // Imprimir a matriz transposta
            for (int j = 0; j < colunas1; j++) {
                for (int i = 0; i < linhas1; i++) {
                    fprintf(arquivo, "%5d/%-5d\t", matrizresultante[j][i].numerador,
                            matrizresultante[j][i].denominador);
                }
                fprintf(arquivo, "\n");
            }
        } else if (opc == 'D') {  // Operação Determinante
            fprintf(arquivo, "\n\t::VALOR DA DETERMINANTE::\n");
            Fracao det = determinante(matriz1, linhas1);  // Função de cálculo de determinante
            fprintf(arquivo, "Determinante: %5d/%-5d\n", det.numerador, det.denominador);
        } else {  // Outras operações
            fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                            matriz1[i][j].denominador);
                }

                fprintf(arquivo, "=\t");

                for (int j = 0; j < colunas1; j++) {
                    fprintf(arquivo, "%5d/%-5d\t", matrizresultante[i][j].numerador,
                            matrizresultante[i][j].denominador);
                }

                fprintf(arquivo, "\n");
            }
        }
    }

    fclose(arquivo);
}

// Função que cria o arquivo de historico
void criaTXTHISTORICO(FILE **file, int usuariologado, pessoa pessoas[]) {
  char nomeregistro[100];
  sprintf(nomeregistro, "historico_%s.txt", pessoas[usuariologado].CPF);
  strcpy(pessoas[usuariologado].nome_hist, nomeregistro);

  *file = fopen(nomeregistro, "a");
  if (*file) {
    printf("Arquivo criado com sucesso!\n");
  } else {
    printf("Erro ao criar o arquivo!\n");
  }

  fclose(*file); // Fecha o arquivo apontado pelo ponteiro.
}

//Função especifica para gravar os sistemas lineares
void gravaSistemaEmTxt(Fracao **equacoes, Fracao *independentes,
                       Fracao *solucoes, int icognitas, int eqs,
                       int usuariologado, pessoa pessoas[]) {

  FILE *arquivo = fopen(pessoas[usuariologado].nome_hist, "a");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  fprintf(arquivo, "\n\t::SISTEMA LINEAR RESOLVIDO::\n");

  char letras[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  // Gravando as equações
  for (int i = 0; i < eqs; i++) {
    for (int j = 0; j < icognitas; j++) {
      fprintf(arquivo, "%d/%d * %c", equacoes[i][j].numerador,
              equacoes[i][j].denominador, letras[j]);
      if (j < icognitas - 1) {
        fprintf(arquivo, " + ");
      }
    }
    fprintf(arquivo, " = %d/%d\n", independentes[i].numerador,
            independentes[i].denominador);
  }

  // Gravando as soluções
  fprintf(arquivo, "\n::SOLUÇÕES::\n");
  for (int i = 0; i < icognitas; i++) {
    fprintf(arquivo, "%c = %d/%d\n", letras[i], solucoes[i].numerador,
            solucoes[i].denominador);
  }

  fclose(arquivo);
}


// ------------------- Funções principais -----------------------

// Funçao responsavel pelo login do usuario
void login(pessoa pessoas[], int usuariologado) {
  limpaterminal();
  char cpflogin[12];
  char senhalogin[7];

  printf("|------------------------------[Login]------------------------------|"
         "\n");
  printf("Digite o CPF: ");
  scanf("%s", cpflogin);

  if (strlen(cpflogin) != 11) {
    printf("CPF inválido!\n");
    limpabuffer();
    espera();
    limpaterminal();
    menuinicial(pessoas, usuariologado);
  }
  limpabuffer();

  for (int i = 0; i < 10; i++) {
    if (strcmp(cpflogin, pessoas[i].CPF) == 0) {
      printf("Digite sua senha: ");
      scanf("%s", senhalogin);
      if (strlen(senhalogin) != 6) {
        printf("Senha inválida!\n");
        limpabuffer();
        espera();
        menuinicial(pessoas, usuariologado);
      }
      limpabuffer();
      if (strcmp(senhalogin, pessoas[i].senha) == 0) {
        printf("Logado com sucesso\n");
        usuariologado = i;
        espera();
        criaTXTHISTORICO(&pessoas[usuariologado].historico, usuariologado,
                         pessoas);
        menu(pessoas, usuariologado);
        return;
      } else {
        printf("Senha incorreta\n");
        espera();
        menuinicial(pessoas, usuariologado);
        return;
      }
    }
  }
  printf("CPF não cadastrado!\n");
  espera();
  menuinicial(pessoas, usuariologado);
}

// Funcao que cadastra os usuários
void cadastrar(pessoa pessoas[], int usuariologado) {
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];
  int cadastrados = 0;

  printf("|------------------------------[Cadastro]----------------------------"
         "|\n");
  if (cadastrados == 9) {
    printf("Limite de cadastro atingido!\n");
    espera();
    menuinicial(pessoas, usuariologado); // Chamando o novo menu
    return;
  } else {
    printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
    scanf("%s", cpfcadastro);
    if (strlen(cpfcadastro) != 11) {
      printf("CPF inválido\n");
      limpabuffer();
      espera();
      menuinicial(pessoas, usuariologado); // Chamando o novo menu
      return;
    }
    limpabuffer();
    for (int i = 0; i < 10; i++) {
      if ((strcmp(cpfcadastro, pessoas[i].CPF) == 0)) {
        printf("CPF já cadastrado\n");
        espera();
        menuinicial(pessoas, usuariologado); // Chamando o novo menu
        return;
      } else if ((strlen(cpfcadastro) != 11) ||
                 (verificaCPF(cpfcadastro) == 0)) {
        printf("CPF inválido!\n");
        espera();
        menuinicial(pessoas, usuariologado); // Chamando o novo menu
        return;
      } else if (pessoas[i].CPF[0] == '\0') {
        printf("Digite sua senha (numérica com 6 dígitos): ");
        scanf("%s", senhacadastro);
        if (strlen(senhacadastro) != 6) {
          limpabuffer();
          printf("Senha inválida\n");
          espera();
          menuinicial(pessoas, usuariologado); // Chamando o novo menu
          return;
        }
        limpabuffer();
        if (strlen(senhacadastro) == 6) {
          strcpy(pessoas[i].CPF, cpfcadastro);
          strcpy(pessoas[i].senha, senhacadastro);
          while (1) {
            printf("Digite seu nome: ");
            fgets(pessoas[i].nome, 100, stdin);
            size_t len = strlen(pessoas[i].nome);
            if (len > 0 && pessoas[i].nome[len - 1] == '\n') {
              pessoas[i].nome[len - 1] = '\0';
            }

            if (strlen(pessoas[i].nome) < 5) {
              printf(
                  "Nome inválido (DEVE POSSUIR 5 LETRAS), tente novamente!\n");
            } else {
              break;
            }
          }
          cadastrados += 1;
          printf("Cadastro realizado com sucesso!\n");
          espera();
          menuinicial(pessoas, usuariologado); // Chamando o novo menu
          return;
        } else {
          printf("Senha inválida. Deve ter 6 dígitos.\n");
          espera();
          menuinicial(pessoas, usuariologado); // Chamando o novo menu
          return;
        }
      }
    }
  }
}


// Função para imprimir a matriz de frações
void printMatriz(Fracao **matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      imprimirFracao(matriz[i][j]);
    }
    printf("\n");
  }
}

// Funçao que mostra a da matriz
void transposta(Fracao **matriz, int linhas, int colunas, pessoa pessoas[], int usuariologado) {
    Fracao **matriztra;
    cria_submatriz(&matriztra, colunas, linhas); 
    
    // Correção na transposição
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriztra[j][i] = matriz[i][j]; //a pika é que ele tava salvando errado
        }
    }

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            imprimirFracao(matriztra[i][j]);
        }
        printf("\n");
    }

    gravaMatrizesEmTxt(matriz, NULL, matriztra, linhas, colunas,linhas,colunas, usuariologado, pessoas, 'T');
    
    for (int i = 0; i < colunas; i++) {
        free(matriztra[i]);
    }
    free(matriztra);
    
    return;
}


//------------------------- Funções Auxiliares --------------------------

// Funcao que limpa o terminal pro usuario
void limpaterminal() {
  system("cls || clear")
      /*printf("teste")*/;
}

// Função que espera a ação do usuário para dar prosseguimento
void espera() {
  printf("Aperte ENTER para SAIR!\n");
  limpabuffer();
}

// Funcao que limpa o buffer de entrada
void limpabuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  return;
}

// Funcao que verifica se o CPF é válido
int verificaCPF(char *cpf) {
  int numeros_cpf[11];
  int soma = 0;
  int maxv1 = 10;
  int maxv2 = 11;
  int resto = 0;
  int veri = 0;
  int verificador1 = 0, verificador2 = 0;
  for (int i = 0; i < 11; i++) {
    numeros_cpf[i] = cpf[i] - 48;
  }
  for (int i = 0; i < 11; i++) {
    // implementação da verificação de cpfs com todos os digitos iguais
    if (numeros_cpf[i] == numeros_cpf[0]) {
      veri += 1;
    }
  }
  if (veri == 11) {
    return 0;
  } else {

    for (int i = 0; i < 9; i++) {
      soma += numeros_cpf[i] * maxv1;
      maxv1--;
    }

    resto = soma % 11;

    if (resto == 1 || resto == 0) {
      verificador1 = 0;
    } else {
      verificador1 = 11 - resto;
    }
    soma = 0;

    for (int i = 0; i < 10; i++) {
      soma += numeros_cpf[i] * maxv2;
      maxv2--;
    }

    resto = soma % 11;
    if (resto == 1 || resto == 0) {
      verificador2 = 0;
    } else {
      verificador2 = 11 - resto;
    }

    if (verificador1 == numeros_cpf[9] && verificador2 == numeros_cpf[10]) {
      return 1;
    } else {
      return 0;
    }
  }
}

//Função que verifica as linhas e as colunas da matriz para serem maiores que zero
void verifica_linhas(int *linhas_rece, int *colunas_rece){
  while (1){
    int linhas, colunas;
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);
    if(linhas <= 0 || colunas <= 0){
      printf("Numeros inválidos, devem ser maiores que zero\n");
      limpabuffer();
      espera();
    }else{
      (*linhas_rece) = linhas;
      (*colunas_rece) = colunas;
      break;
    }
  }
  return;
}

//Função que verifica a ordem da matriz para números maiores que zero
void verifica_ordens(int *n){
  while (1){
    int ordem;
    printf("Digite o número da ordem: ");
    scanf("%d", &ordem);
    if(ordem <= 0){
      printf("Numero inválido, deve ser maior que zero\n");
      limpabuffer();
      espera();
    }else{
      (*n) = ordem;
      break;
    }
  }
  return;
}
