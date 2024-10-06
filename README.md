#         ✖️➗➕➖🟰 ***DETERMINATRIX*** 🟰➖➕➗✖️

Bem vindo ao **DETERMINATRIX** nosso projeo de C, antes de saber mais sobre o projeto, que tal entender o porque dele existir?

<img src="https://img.freepik.com/vetores-gratis/ilustracao-de-formulas-quimicas_53876-18348.jpg?t=st=1728068074~exp=1728071674~hmac=8fc7faaf2b77d8382568cee20cc19097e85acfbc58b82ed0c34ebd3c4ec0a1a2&w=1380" alt="Texto Alternativo">

  ##  ⌈ PARADOXO DOS CÁLCULOS COMPLICADOS ⌋
 ```mermaid
flowchart TD
    A[Usuário] -->|cálculos complexos| B(Cálculos com matriz)
    B -->|busca de software| C{Opções}
    C --> D[Calculadora básica]
    C --> E[Software duvidoso]
    C --> F[Cálculos longos]
     F -->  G[ERROR]
    D --> G
   E --> G
```
Cansado de erros que sempre aparecem e estragam sua tentativa de estudo? **NÓS TAMBÉM!!!**
  - Decidimos então que criariamos um software capaz de resolver as contas mais dificeis em passos simples e com uma das mais altas taxas de acerto, para que todos possam focar mais seu tempo em estudar e menos tempo em ficar resolvendo erros por resultados duvidosos...***Um projeto ambicioso, mas necessário.***

  ##  ⌈ OBJETIVO DO PROJETO ⌋
  
  -  Com esse projeto em linguagem C juntamente dos nossos conhecimento adquiridos nas aulas de Geometria Analítica, decidimos que seria uma ótima ideia unir estes dois polos em um projeto, assim praticando cada vez mais oque nos é ensinado nas aulas. Determinatrix é um grande projeto que visa solucionar os problemas dos alunos, sendo fácil, intuitivo e o ponto princial, uma proposta de alunos para alunos.

  ##  ⌈ COMPILAÇÃO E EXECUÇÃO ⌋
  
-    Como compilar e executar nosso projeto?
### 1. Replit
-    Abrir a plataforma Replit e puxar o codigo do github pelo link desse repositorio.
      #### 1.2. Makefile 
     -    Após isso, o usuário deverá abrir o arquivo Makefile criado e colar a seguinte linha de codigo.
         <pre><code>
         
              all: main
              CC = clang
              
              override CFLAGS += -g -Wno-everything -pthread -lm
              
              SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
              HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)
              
              main: $(SRCS) $(HEADERS)
                $(CC) $(CFLAGS) $(SRCS) -o "$@"
              
              main-debug: $(SRCS) $(HEADERS)
                $(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"
              
              clean:
                rm -f main main-debug
          </pre></code>
     - Depois de colar o código, apenas clique no botão "Run". Onde o programa será compilado e executado de forma correta.
### 2. Terminal
-  Ao baixar a pasta e entrar no diretório dos arquivos pelo terminal de sua máquina, cole a seguinte linha de código.
        <pre><code> gcc -o determinatrix main.c manip_determinatrix.c</pre></code>   
      -   E logo em seguida.
        <pre><code>./determiantrix</pre></code>

## ⌈ FUNÇÕES ⌋

### 1. Exibe_Matriz
-  Assim como o nome diz, uma função para exibir sua matriz, tornando mais intuitivo uma vez que você consegue ver os números todos formatados em forma de matriz.

### 2. Soma
-  Soma de matrizes de mesma ordem, gerando assim uma matriz resultado que é exibida para o usuário assim que a operação é finalizada.

### 3. Subtração
-  Subtração de matrizes de mesma ordem, gerando assim uma matriz resultado que é exibida para o usuário assim que a operação é finalizada.

### 4. Multiplicação
-  Multiplicação de matrizes, e diferente das outras que são de mesma ordem, essa tem seu próprio sistema de verificação e exibe uma mensagem caso não seja possível a multiplicação, porém caso seja possivel termina gerando assim uma matriz resultado, que é exibida para o usuário assim que a operação é finalizada.

### 5. Inversa
-  Gera a matriz inversa de uma matriz , somente se a mesma possuir uma inversa, caso contrário, a função retorna um recado ao usuário e finaliza a operação. 

### 6. Transposta
-  Gera a matriz transposta de uma matriz, invertendo os valores de linha para colunas e vice versa, exibindo a matriz ao final da função.

### 7. Deterinante
-  Gera a determinante de uma matriz, sendo ela um núero que é exibido para o usuário ao final da função;

### 8. Decomposição
-  Em construção;

### 8. Troca de base
-  Em construção;

## ⌈ INTEGRANTES ⌋

-    Arthur Barbosa Zanvetor  **R.A.**: 24.124.063-9
-    Fernando Bordin Lopes  **R.A.**: 24.124.003-5
  





  

