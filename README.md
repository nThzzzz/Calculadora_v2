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
        <pre><code> gcc -o matrizes main.c manip_matrizes.c</pre></code>   
      -   E logo em seguida.
        <pre><code>./matrizes</pre></code>

##  ⌈ INSTRUÇÕES DE USO DO PROJETO ⌋
  
-  Logo quando iniciar o programa, o menu inicial com as opções de cadastro, login e sair. Para começar faça o cadastro de usuário (**usuário teste: CPF: 12345678909 e SENHA: 123456**), logo após isso você sera redirecionado novamente para o menu inicial para que possa fazer o login.
-  No login, utilize as mesmas credenciais do cadastro para criar seu usuário, com isso seu histórico sera criado automaticamente e você será redirecionado para o menu de operações.
-  No menu de operações, basta escolher qual operação deseja fazer digitando a opção correspondente a cada operação, inclusive a de saida.
-  Ao digitar a opção de saida, será redirecionado para o menu inicial novamente e para fechar completamente o programa e salvar suas credenciais permanentemente, digite novamente a opção correspondente a saida.

##  ⌈ EXEMPLO DE USO DO PROJETO ⌋

### 1. Menu Inicial
![image](https://github.com/user-attachments/assets/ba3e92b0-9c3f-43d2-8b4f-f9707152f5a1)

### 2. Cadastro 
-  Usuário (CPF: 12345678909 SENHA: 123456 NOME: Fernando)
  
![image](https://github.com/user-attachments/assets/47069b66-6ca3-4a99-b923-762ddd68fe47)

### 3. Login
-  Usuário (CPF: 12345678909 SENHA: 123456 NOME: Fernando)
  
![image](https://github.com/user-attachments/assets/f0c2b3a3-d0d0-4bb0-9701-c3ac0b980239)

### 4. Menu de Operações
![image](https://github.com/user-attachments/assets/d999930c-62db-4ef5-99ff-af769da7e8c0)

### 5. Seleção de Soma
![image](https://github.com/user-attachments/assets/f2a76283-bb05-46c0-a659-273a1612737d)

### 6. Soma de matrizes 2 x 2
![image](https://github.com/user-attachments/assets/52b13be9-9079-49ca-b744-6ac1aaf136d0)

### 7. Digitando os valores das matrizes
![image](https://github.com/user-attachments/assets/d3ab1454-ec85-4e20-8ca2-8a11b0f57524)

### 8. Resultado da operação
![image](https://github.com/user-attachments/assets/8e881768-aecb-4446-9e0b-914061f1badf)

### 9. Histórico
![image](https://github.com/user-attachments/assets/a4adaa31-83ce-43eb-9cd4-c6b8d12c4554)

### 10. Visualizando Histórico
![image](https://github.com/user-attachments/assets/ca785922-4806-4fd2-9baf-9fa75879e775)

### 11. Sair do menu de operações
![image](https://github.com/user-attachments/assets/3985f128-a18b-495a-b2c9-6e7b189cab2c)

### 12. Sair do menu inicial
![image](https://github.com/user-attachments/assets/46fa8f71-376a-4e79-b51c-38d9fdefd147)





## ⌈ FUNÇÕES ⌋

### 1. Menu Inicial
-    Local onde o usuário deve se cadastrar para utilizar 100% do nosso software, tornando assim um ambiente mais controlado e seguro, abaixo seguem as opções dadas ao usuário:
-    **Cadastro**:  Caso não tenha uma conta no **Determinatrix**, crie sua conta aqui com um CPF válido, senha e um nome de usuário.
-    **Login**:  Caso já tenha uma conta e deseja acessa-la.
-    **Sair**: Sair da aplicação.

### 2. Menu de operações
-    Local que hospeda uma vasta gama de operações que o usuário pode desfrutar a vontade para resolver quaisquer problemas, as operações seguem abaixo com uma breve explicação:
     #### 2.1. Soma
     -  Soma de matrizes de mesma ordem, gerando assim uma matriz resultado que é exibida para o usuário assim que a operação é finalizada.
     #### 2.2. Subtração
     -  Subtração de matrizes de mesma ordem, gerando assim uma matriz resultado que é exibida para o usuário assim que a operação é finalizada.
     #### 2.3. Multiplicação
     -  Multiplicação de matrizes, e diferente das outras que são de mesma ordem, essa tem seu próprio sistema de verificação e exibe uma mensagem caso não seja possível a multiplicação, porém caso seja possivel termina gerando assim uma matriz resultado, que é exibida para o usuário assim que a operação é finalizada.
     #### 2.4. Inversa
     -  Gera a matriz inversa de uma matriz , somente se a mesma possuir uma inversa, caso contrário, a função retorna um recado ao usuário e finaliza a operação. 
     #### 2.5. Transposta
     -  Gera a matriz transposta de uma matriz, invertendo os valores de linha para colunas e vice versa, exibindo a matriz ao final da função.
     #### 2.6. Determinante
     -  Gera a determinante de uma matriz, sendo ela um núero que é exibido para o usuário ao final da função;
     #### 2.7. Decomposição LU
     -  Um tipo de decomposição de matrizes, que retorna duas outras matrizes que a multiplicação é a matriz original;
     #### 2.8. Sitemas Lineares
     -  Gera um sistema linear indicado pelo usuário com as váriaveis e com os termos independentes e ao final retorna se é SPD , SPI ou SI e retorna uma possível solução para o sistema;
     #### 2.9. Histórico
     -  Assim como em uma calculadora comum, suas equações não são simplesmente descartadas, mas sim salvas em seu histórico para que seja possível fazer uma consulta posteriormente;

## ⌈ INTEGRANTES ⌋

-    Arthur Barbosa Zanvetor  **R.A.**: 24.124.063-9
-    Fernando Bordin Lopes  **R.A.**: 24.124.003-5
  





  

