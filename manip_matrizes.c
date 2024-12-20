#include "manip_matrizes.h"

// Função para simplificar a fração
Fracao simplificar(Fracao f) {
  int divisor_comum = mdc(f.numerador, f.denominador);

  if ((f.numerador == 0 || f.denominador == 0) ||
      (f.numerador == 0 && f.denominador == 0)) {
    f.numerador = 0;
    f.denominador = 1;
  } else {
    f.numerador /= divisor_comum;
    f.denominador /= divisor_comum;
  }

  if (f.denominador < 0 && f.numerador > 0) {
    f.numerador = -1 * f.numerador;
    f.denominador = -1 * f.denominador;
  }
  return f;
}

// Função para somar duas frações
Fracao somar(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador =
      a.numerador * b.denominador + b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return simplificar(resultado);
}

// Função para subtrair duas frações
Fracao subtrair(Fracao a, Fracao b) {
  Fracao resultado;
  resultado.numerador =
      a.numerador * b.denominador - b.numerador * a.denominador;
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
  int numbarra = 0; // para contar o número de barras na entrada
  int valida = 0;   // para verificar se a entrada foi válida

  while (!valida) {
    printf("Digite uma fração (EX: 3/4) ou um número inteiro: ");
    scanf("%s", frac);

    // Verificar se há barras barras ou vírgulas
    numbarra = 0;
    for (int i = 0; i < strlen(frac); i++) {
      if (frac[i] == '/') {
        numbarra++;
      }
      if (frac[i] == '.' || frac[i] == ',' ||
          (!isdigit(frac[i]) && frac[i] != '/' && frac[i] != '-')) {
        printf("Use apenas números inteiros ou frações no formato a/b, tente "
               "novamente\n");
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
        valida = 1; // entrada válida
      } else {
        printf("Entrada de fração inválida.\n");
      }
    } else {
      // Tentar analisar como número inteiro
      if (sscanf(frac, "%d", &f.numerador) == 1) {
        f.denominador = 1;
        valida = 1; // entrada válida
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

// Fracao que vale a -1
Fracao frac_unitaria_Negativa() {
  Fracao f;

  f.numerador = -1;
  f.denominador = 1;

  return simplificar(f);
}

// ------------------------------------- Funções Principais
// -------------------------------------

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
void transposta(Fracao **matriz, int linhas, int colunas, pessoa pessoas[],
                int usuariologado) {
  Fracao **matriztra;
  cria_submatriz(&matriztra, colunas, linhas);

  // Correção na transposição
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      matriztra[j][i] = matriz[i][j]; // a pika é que ele tava salvando errado
    }
  }

  for (int i = 0; i < colunas; i++) {
    for (int j = 0; j < linhas; j++) {
      imprimirFracao(matriztra[i][j]);
    }
    printf("\n");
  }

  gravaMatrizesEmTxt(matriz, NULL, matriztra, linhas, colunas, linhas, colunas,
                     usuariologado, pessoas, 'T');

  for (int i = 0; i < colunas; i++) {
    free(matriztra[i]);
  }
  free(matriztra);

  return;
}

// Função soma de matrizes
void soma(pessoa pessoas[], int usuariologado) {
  Fracao **matriz;
  Fracao **matriz2;
  int linhas, colunas;

  verifica_linhas(&linhas, &colunas);

  cria_matriz(&matriz, linhas, colunas, 0, 1);
  cria_matriz(&matriz2, linhas, colunas, 1, 1);

  Fracao **matrizresultante = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    matrizresultante[i] = malloc(colunas * sizeof(Fracao));
  }

  // Soma
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      matrizresultante[i][j] = somar(matriz[i][j], matriz2[i][j]);
    }
  }
  gravaMatrizesEmTxt(matriz, matriz2, matrizresultante, linhas, colunas, linhas,
                     colunas, usuariologado, pessoas, '+');

  limpaterminal();
  printf("A matriz RESULTANTE da soma é: \n");
  printMatriz(matrizresultante, linhas, colunas);
  limpabuffer();
  espera();

  free_matriz(matrizresultante, linhas);
  free_matriz(matriz2, linhas);
  free_matriz(matriz, linhas);
}

// Funcao que subtrai matrizes
void sub(pessoa pessoas[], int usuariologado) {
  Fracao **matriz;
  Fracao **matriz2;
  int linhas, colunas;

  verifica_linhas(&linhas, &colunas);

  cria_matriz(&matriz, linhas, colunas, 0, 1);
  cria_matriz(&matriz2, linhas, colunas, 1, 1);

  Fracao **matrizresultante = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    matrizresultante[i] = malloc(colunas * sizeof(Fracao));
  }

  // Soma
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      matrizresultante[i][j] = subtrair(matriz[i][j], matriz2[i][j]);
    }
  }
  gravaMatrizesEmTxt(matriz, matriz2, matrizresultante, linhas, colunas, linhas,
                     colunas, usuariologado, pessoas, '-');

  limpaterminal();
  printf("A matriz RESULTANTE da soma é: \n");
  printMatriz(matrizresultante, linhas, colunas);
  limpabuffer();
  espera();

  free_matriz(matrizresultante, linhas);
  free_matriz(matriz2, linhas);
  free_matriz(matriz, linhas);
}

// Funcao que realiza multiplicação de matrizes
void multi(pessoa pessoas[], int usuariologado) {

  int linhas, colunas;
  printf("Digite o número de linhas e colunas da PRIMEIRA matriz a seguir \n");
  verifica_linhas(&linhas, &colunas);

  int linhas2, colunas2;
  printf("Digite o número de linhas e colunas da SEGUNDA matriz a seguir \n");
  verifica_linhas(&linhas2, &colunas2);

  if (colunas != linhas2) {
    printf(
        "Multiplicação de matrizes inválida! O número de colunas da primeira "
        "matriz deve ser igual ao número de linhas da segunda matriz.\n");
    limpabuffer();
    espera();
    return;
  }

  Fracao **matriz2;
  Fracao **matriz;

  cria_matriz(&matriz, linhas, colunas, 0, 1);
  cria_matriz(&matriz2, linhas2, colunas2, 1, 1);

  Fracao **matrizresultante;
  cria_submatriz(&matrizresultante, linhas, colunas2);

  // Multiplicação
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas2; j++) {
      matrizresultante[i][j] = fracPadrao();
      for (int k = 0; k < colunas; k++) {
        matrizresultante[i][j] = somar(
            matrizresultante[i][j], multiplicar(matriz[i][k], matriz2[k][j]));
      }
    }
  }
  gravaMatrizesEmTxt(matriz, matriz2, matrizresultante, linhas, colunas,
                     linhas2, colunas2, usuariologado, pessoas, '*');

  limpaterminal();
  // Exibe a matriz resultante
  printf("A matriz resultante da multiplicação é: \n");
  printMatriz(matrizresultante, linhas, colunas2);
  limpabuffer();
  espera();

  free_matriz(matrizresultante, linhas);
  free_matriz(matriz2, linhas2);
  free_matriz(matriz, linhas);
}

// Função para calcular o determinante
Fracao determinante(Fracao **matriz, int n) {
  Fracao det = fracPadrao();       // Inicia com 0
  Fracao somatorio = fracPadrao(); // Variável para acumular o determinante

  if (n == 1) {
    return matriz[0][0];
  } else if (n == 2) {
    // Caso base, determinante de matriz 2x2
    return subtrair(multiplicar(matriz[0][0], matriz[1][1]),
                    multiplicar(matriz[1][0], matriz[0][1]));
  } else {
    for (int x = 0; x < n; x++) {
      // Alocando submatriz de tamanho (n-1)x(n-1)
      Fracao **submatriz;
      cria_submatriz(&submatriz, n - 1, n - 1);

      for (int i = 1; i < n; i++) {
        int subi = 0;
        for (int j = 0; j < n; j++) {
          if (j == x) {
            continue; // Pula a coluna que está sendo excluída
          }
          submatriz[i - 1][subi] = matriz[i][j];
          subi++;
        }
      }
      // det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * determinante(submatriz, n
      // - 1); // Vou reduzindo ate ficar 2:2

      Fracao cofactor;
      if (x % 2 == 0) {
        cofactor = multiplicar(matriz[0][x], determinante(submatriz, n - 1));
      } else {
        cofactor = multiplicar(
            frac_unitaria_Negativa(),
            multiplicar(matriz[0][x], determinante(submatriz, n - 1)));
      }

      // Somando o cofactor
      somatorio = somar(somatorio, cofactor);

      free_matriz(submatriz, n - 1);
    }
  }

  return somatorio;
}

// Função para calcular a inversa
void inversa(pessoa pessoas[], int usuariologado) {
  Fracao **matriz;
  int n;

  printf("Digite a ordem da matriz a seguir: \n");
  verifica_ordens(&n);
  cria_matriz(&matriz, n, n, 0, 1);

  Fracao det = determinante(matriz, n);
  if (comparar(determinante(matriz, n), fracPadrao()) == 0) {
    printf("Matriz não tem inversa (determinante é zero).\n");
    limpabuffer();
    espera();
    return;
  }

  Fracao **inversa;
  Fracao **cofatores;

  cria_submatriz(&inversa, n, n);
  cria_submatriz(&cofatores, n, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      Fracao **submatriz;
      cria_submatriz(&submatriz, n - 1, n - 1);

      int subi = 0;
      for (int a = 0; a < n; a++) {
        if (a == i)
          continue;
        int subj = 0;
        for (int b = 0; b < n; b++) {
          if (b == j) {
            continue;
          }
          submatriz[subi][subj] = matriz[a][b];
          subj++;
        }
        subi++;
      }

      if ((i + j) % 2 == 0) {
        cofatores[i][j] = multiplicar(frac_unitaria_Positiva(),
                                      determinante(submatriz, n - 1));
      } else {
        cofatores[i][j] = multiplicar(frac_unitaria_Negativa(),
                                      determinante(submatriz, n - 1));
      }
      // cofatores[i][j] = (float)((i + j) % 2 == 0 ? 1 : -1) *
      // determinante(submatriz, n - 1);

      free_matriz(submatriz, n - 1);
    }
  }

  // Transposta da matriz de cofatores
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      inversa[i][j] = dividir(cofatores[j][i], det);
    }
  }
  gravaMatrizesEmTxt(matriz, NULL, inversa, n, n, n, n, usuariologado, pessoas,
                     'I');

  limpaterminal();
  printf("A matriz inversa é:\n");
  printMatriz(inversa, n, n);
  limpabuffer();
  espera();

  free_matriz(cofatores, n);
  free_matriz(inversa, n);
  free_matriz(matriz, n);
}

// Funcao que decompoe uma matriz no modelo L e U
void decomposicaoLU(pessoa pessoas[], int usuariologado) {
  Fracao **matriz;
  int n;
  printf("Digite a ordem da matriz a seguir \n");
  verifica_ordens(&n);
  cria_matriz(&matriz, n, n, 0, 1);

  Fracao **matrizL;
  Fracao **matrizU;

  cria_submatriz(&matrizL, n, n);
  cria_submatriz(&matrizU, n, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j)
        matrizU[i][j] = matriz[i][j]; // Copia elementos de A para U
      else
        matrizU[i][j] = fracPadrao();

      if (i == j)
        matrizL[i][j] =
            frac_unitaria_Positiva(); // Elementos da diagonal de L são 1
      else if (i > j)
        matrizL[i][j] = fracPadrao();
    }
  }

  limpaterminal();
  // Fatoração LU
  for (int k = 0; k < n - 1; k++) {
    for (int i = k + 1; i < n; i++) {
      matrizL[i][k] =
          dividir(matriz[i][k], matriz[k][k]); // Calcula o multiplicador
      for (int j = k; j < n; j++) {
        matriz[i][j] =
            subtrair(matriz[i][j], multiplicar(matrizL[i][k], matriz[k][j]));
        matrizU[i][j] = matriz[i][j];
        // matriz[i][j] = matriz[i][j] - matrizL[i][k] * matriz[k][j];  //
        // Eliminação matrizU[i][j] = matriz[i][j];   //Atualiza U com os
        // valores resultantes
      }
    }
  }
  printf("Matriz U: \n");
  printMatriz(matrizU, n, n);
  printf("Matriz L: \n");
  printMatriz(matrizL, n, n);
  gravaMatrizesEmTxt(matriz, matrizU, matrizL, n, n, n, n, usuariologado,
                     pessoas, 'D');
  limpabuffer();
  espera();

  free_matriz(matrizU, n);
  free_matriz(matrizL, n);
  free_matriz(matriz, n);
}

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

void sistemalinear(pessoa pessoas[], int usuariologado) {
  int icognitas, eqs;

  char letras[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  printf("Digite o número de incógnitas do sistema: ");
  scanf("%d", &icognitas);
  printf("Digite o número de equações do sistema: ");
  scanf("%d", &eqs);

  // Alocação das equações e termos independentes
  Fracao **equacoes = (Fracao **)malloc(eqs * sizeof(Fracao *));
  for (int i = 0; i < eqs; i++) {
    equacoes[i] = (Fracao *)malloc(icognitas * sizeof(Fracao));
  }

  Fracao *independentes = (Fracao *)malloc(eqs * sizeof(Fracao));

  // Leitura dos coeficientes
  printf("Digite os coeficientes das equações:\n");
  for (int i = 0; i < eqs; i++) {
    for (int j = 0; j < icognitas; j++) {
      printf("Coeficiente de %c da %dºEquação: \n", letras[j], i + 1);
      equacoes[i][j] = lerFracao();
    }
    printf("Termo independente da %dºEquação: \n", i + 1);
    independentes[i] = lerFracao();
  }

  // Eliminação de Gauss
  int posto =
      0; // num de linhas que contem um pivo != de 0 depois de escalonado
  // Posto = num de incógnitas: O sistema é determinado e tem uma solução única.
  // Posto < num de incógnitas e Posto = num de eqs: O sistema é indeterminado e
  // tem infinitas soluções. Posto < num de equações: O sistema é impossível, ou
  // seja, não tem solução.
  for (int i = 0; i < icognitas; i++) {
    int linha_pivo = -1;
    for (int k = i; k < eqs; k++) {
      if (comparar(equacoes[k][i], fracPadrao()) == 1) { // Digerente de 0
        linha_pivo = k;
        break;
      }
    }

    if (linha_pivo == -1) {
      // Se não encontramos um pivô pula
      continue;
    }

    // Troca a linha atual com a linha pivô
    if (linha_pivo != i) {
      Fracao *temp = equacoes[i];
      equacoes[i] = equacoes[linha_pivo];
      equacoes[linha_pivo] = temp;

      Fracao temp_indep = independentes[i];
      independentes[i] = independentes[linha_pivo];
      independentes[linha_pivo] = temp_indep;
    }

    // Pivô
    Fracao piv = equacoes[i][i];
    for (int j = i; j < icognitas; j++) {
      equacoes[i][j] = dividir(equacoes[i][j], piv);
    }
    independentes[i] = dividir(independentes[i], piv);

    // Eliminação abaixo da diagonal
    for (int k = i + 1; k < eqs; k++) {
      Fracao fator = equacoes[k][i];
      for (int j = i; j < icognitas; j++) {
        equacoes[k][j] =
            subtrair(equacoes[k][j], multiplicar(fator, equacoes[i][j]));
      }
      independentes[k] =
          subtrair(independentes[k], multiplicar(fator, independentes[i]));
    }

    posto++;
  }

  // Verificação do tipo de sistema
  if (posto < icognitas) {
    if (posto == eqs) {
      printf("O sistema é SPI (Sistema Possível Indeterminado)\n");
      limpabuffer();
      espera();
      return;
    } else {
      printf("O sistema é SI (Sistema Impossível) OU SPI (Sistema Possível "
             "Indeterminado)\n");
      limpabuffer();
      espera();
      return;
    }
  }

  // Substituição retroativa
  Fracao *solucoes = (Fracao *)malloc(icognitas * sizeof(Fracao));

  for (int i = icognitas - 1; i >= 0; i--) {
    solucoes[i] = independentes[i];
    for (int j = i + 1; j < icognitas; j++) {
      solucoes[i] =
          subtrair(solucoes[i], multiplicar(equacoes[i][j], solucoes[j]));
    }
  }

  limpaterminal();
  printf("Soluções do sistema:\n");
  for (int i = 0; i < icognitas; i++) {
    printf("%c =", letras[i]);
    imprimirFracao(solucoes[i]);
    printf("\n");
  }
  gravaSistemaEmTxt(equacoes, independentes, solucoes, icognitas, eqs,
                    usuariologado, pessoas);
  limpabuffer();
  espera();

  // Liberação da memória
  free_matriz(equacoes, eqs);
  free(independentes);
  free(solucoes);
}

// ------------------------------------- Funções Menus
// -------------------------------------

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

  Fracao **matriz;
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
      verifica_linhas(&linhas, &colunas);
      cria_matriz(&matriz, linhas, colunas, 0, 1);
      transposta(matriz, linhas, colunas, pessoas, usuariologado);
      limpabuffer();
      espera();
      free_matriz(matriz, linhas);
      menu(pessoas, usuariologado);
      break;
    case 6:
      verifica_ordens(&n);
      cria_matriz(&matriz, n, n, 0, 1);
      Fracao det = determinante(matriz, n);
      gravaMatrizesEmTxt(matriz, NULL, NULL, n, n, n, n, usuariologado, pessoas,
                         'D');
      printf("O determinante da matriz digitada é: \n");
      imprimirFracao(det);
      printf("\n");
      limpabuffer();
      espera();
      free_matriz(matriz, n);
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

// ---------------------------------------- Funções de criação de Matrizes
// ----------------------------------------

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

// funcao que armazena na memoria a submatriz
void cria_submatriz(Fracao ***matriz, int linhas, int colunas) {
  *matriz = (Fracao **)malloc(linhas * sizeof(Fracao *));
  for (int i = 0; i < linhas; i++) {
    (*matriz)[i] = (Fracao *)malloc(colunas * sizeof(Fracao));
  }
}

// ---------------------------------------- Funções Auxiliares
// ----------------------------------------

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

void verifica_linhas(int *linhas_rece, int *colunas_rece) {
  while (1) {
    int linhas, colunas;
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);
    if (linhas <= 0 || colunas <= 0) {
      printf("Numeros inválidos, devem ser maiores que zero\n");
      limpabuffer();
      espera();
    } else {
      (*linhas_rece) = linhas;
      (*colunas_rece) = colunas;
      break;
    }
  }
  return;
}

void verifica_ordens(int *n) {
  while (1) {
    int ordem;
    printf("Digite o número da ordem: ");
    scanf("%d", &ordem);
    if (ordem <= 0) {
      printf("Numero inválido, deve ser maior que zero\n");
      limpabuffer();
      espera();
    } else {
      (*n) = ordem;
      break;
    }
  }
  return;
}

// ---------------------------------------- Funções Relacionadas a Frações
// ----------------------------------------

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

// ---------------------------------------- Funções do Binário e do TXT
// ----------------------------------------

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
                        int linhas2, int colunas2, int usuariologado,
                        pessoa pessoas[], char opc) {
  FILE *arquivo = fopen(pessoas[usuariologado].nome_hist, "a");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  if (matriz2 != NULL) { // Quando matriz2 é diferente de NULL
    if (opc == 'D') {    // Operação D (ex: multiplicação com 2 matrizes)
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
      if (linhas1 == linhas2 && colunas1 == colunas2) {
        fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
        for (int i = 0; i < linhas1; i++) {
          for (int j = 0; j < colunas1; j++) {
            fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                    matriz1[i][j].denominador);
          }

          fprintf(arquivo, "%c\t", opc); // Imprimir a operação

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
      } else if (colunas1 == linhas2) {
        fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");

        // Imprimir a primeira matriz
        for (int i = 0; i < linhas1; i++) {
          for (int j = 0; j < colunas1; j++) {
            fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                    matriz1[i][j].denominador);
          }
          fprintf(arquivo, "\n");
        }

        fprintf(arquivo, "\n\t\t%c\t\n", opc); // Imprimir o operador

        // Imprimir a segunda matriz
        for (int i = 0; i < linhas2; i++) {
          for (int j = 0; j < colunas2; j++) {
            fprintf(arquivo, "%5d/%-5d\t", matriz2[i][j].numerador,
                    matriz2[i][j].denominador);
          }
          fprintf(arquivo, "\n");
        }

        fprintf(arquivo, "\n\t\t=\t\n"); // Imprimir o sinal de igual

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
    } else { // Outras operações
      fprintf(arquivo, "\n\t::VALORES DAS MATRIZES::\n");
      for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
          fprintf(arquivo, "%5d/%-5d\t", matriz1[i][j].numerador,
                  matriz1[i][j].denominador);
        }

        fprintf(arquivo, "%c\t", opc); // Imprimir a operação

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
  } else {            // Caso matriz2 seja NULL
    if (opc == 'T') { // Operação Transposta
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
    } else if (opc == 'D') { // Operação Determinante
      fprintf(arquivo, "\n\t::VALOR DA DETERMINANTE::\n");
      Fracao det =
          determinante(matriz1, linhas1); // Função de cálculo de determinante
      fprintf(arquivo, "Determinante: %5d/%-5d\n", det.numerador,
              det.denominador);
    } else { // Outras operações
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
