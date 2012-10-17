/*
Entrada dos nomes OK,
Entrada das coordenada OK,
Checagem de opcao menu1 e menu2 OK,
Checagem de coordenadas (linha e coluna) OK,
Checagem de jogada (posição livre ou marcada) OK;
Alernação de jogadores entre os turnos OK;
Verificação de vencedor OK;
Contagem de vítórias OK;
Reiniciar novo jogo com os mesmos jogadores OK;
Reiniciar novo jogo com jogadores diferentes OK;
Finalizar programa OK.
:) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int opcao,
    jogador=1, 
    vencedor=0, 
    turno=0,
    //A variável nomeaux é necessária para o caso de os jogadores desejarem iniciar nova partida
    //com os mesmos jogadores. É ele que permitirá que seus nomes sejam reinformados ao programa.
    nomeaux=0,
    linha, 
    coluna, 
    vitorias1=0, 
    vitorias2=0, 
    vitoriasdavelha=0, 
    i, 
    j;

char nome1[100], 
     nome2[100], 
     casa[4][4],
     //As duas variáveis abaixo armazenarão temporáriamente nome1 e nome2 para, mais tarde, serem
     //reinformados ao programa.
     nomeaux1[100],
     nomeaux2[100];

//Cria um cabeçalho
cabecalho (){
   printf ("___________________________________________________________________________\n\n");
   printf ("|\t\t\t\tJOGO DA VELHA                             |\n");
   printf ("___________________________________________________________________________\n\n");
}

//Cria o menu inicial
menu1 (){
   system ("cls");
   cabecalho();
   printf ("OPÇÕES\n\n");
   printf ("1 - Novo jogo. \n2 - Instruções.\n3 - Sair.\n\n");
   printf ("--->  ");
   scanf ("%d", &opcao);
   validaopcao ();
   switch (opcao){
      case 1:
         cabecalho();
         tabuleiro();
         informa ();
      break;
      case 2:
         system ("cls");
         cabecalho();
         printf ("\t\t\t         INSTRUÇÕES\n\n");
         printf ("1 - Informe os nomes dos jogadores. \n2 - As jogadas são alternadas. \n3 - Ganha o jogador que marcar três posições em sequencia.\n");
         getch ();
         menu1();
      break;
      case 3:
         exit (EXIT_SUCCESS);       
      break;
   }
}

//Informando os nomes dos jogadores
informa (){    
   printf ("Informe o nome do 1º jogador: ");
   fflush (stdin);
   fgets (nome1, 99, stdin);
   /* esse laço percorre a string capturada pelo fgets procurando 
     a posição marcada com \n, quando a encontra, essa posição recebe \0 */
   for (i=0; i<=strlen(nome1); i++){
      if (nome1[i] == '\n')
         nome1[i] = '\0';
   }
   printf ("Informe o nome do 2º jogador: ");
   fflush (stdin);
   fgets (nome2, 99, stdin);
   /* esse laço percorre a string capturada pelo fgets procurando 
     a posição marcada com \n, quando a encontra, essa posição recebe \0 */
   for (i=0; i<=strlen(nome2); i++){
      if (nome2[i] == '\n')
         nome2[i] = '\0';
   }
   system ("cls");
   cabecalho ();
   tabuleiro ();
   printf ("\n");
   printf ("%s joga com X.\n%s joga com O.\n\n", nome1, nome2);
   system ("pause");
   system ("cls");
   cabecalho ();
   tabuleiro ();  
}

tabuleiro (){          //tabuleiro temporário
   system ("cls");
   cabecalho ();
   printf ("\t\t\t           |     |    \n  ");
   printf ("\t\t\t        %c  |  %c  |  %c \n", casa[1][1], casa[1][2], casa[1][3]);
   printf ("\t\t\t      _____|_____|_____\n");
   printf ("\t\t\t           |     |        \n");
   printf ("\t\t\t        %c  |  %c  |  %c \n", casa[2][1], casa[2][2], casa[2][3]);
   printf ("\t\t\t      _____|_____|_____\n");
   printf ("\t\t\t           |     |    \n");
   printf ("\t\t\t        %c  |  %c  |  %c \n", casa[3][1], casa[3][2], casa[3][3]);
   printf ("\t\t\t           |     |\n\n\n");
}

//Valida entrada do menu inicial, impedindo que a opção do usuário seja menor que 1 ou maior que 3. 
validaopcao (){
   while (opcao < 1 || opcao > 3){
      system ("cls");
      cabecalho ();
      printf ("\n\n%d não é uma opção válida.\n", opcao);
      printf ("Por favor, escolha 1, para jogar, 2 para informações ou 3 para sair.\n\n");
      printf ("--->   ");
      scanf ("%d", &opcao);
   }
}

//Função que orienta seleção das casas marcadas e vai orientar as jogadas.
jogada (){
       turno++;
       printf ("\n\nEssa é a %d rodada.\n\n", turno);
          if (jogador == 1)
             printf ("%s, informe as coordenadas da sua jogada.\n", nome1);
          else
             printf ("%s, informe as coordenadas da sua jogada.\n", nome2);
    
             printf ("Linha: ");
             scanf ("%d", &linha);
             validalinha ();
             printf ("Coluna: ");
             scanf ("%d", &coluna);
             validacoluna ();
             validajogada ();
}

//Obriga linha escolhida estar entre 1 e 3.
validalinha (){
   while (linha < 1 || linha > 3){
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("O número informado é inválido.\n");
      printf ("Por favor, escolha um valor de 1 até 3 para a linha escolida: \n");
      printf ("----> ");
      scanf ("%d", &linha);
      }
}

//Obriga coluna estar entre 1 e 3.
validacoluna (){
   while (coluna < 1 || coluna > 3){
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("O número informado é inválido.\n");
      printf ("Por favor, escolha um valor de 1 até 3 para a coluna escolhida: \n");
      printf ("----> ");
      scanf ("%d", &coluna);
   }
}

//Valida uma jogada em posição livre e, caso a posição informada não estivesse marcada, marca
//a posição informada e, após isso, alterna o jogador que jogará o próximo turno.
validajogada (){
   if (casa[linha][coluna] == 'X' || casa[linha][coluna] == 'O'){
      system ("cls");
      cabecalho ();
      tabuleiro ();
         if (jogador == 1)
            printf ("A posição escolhida já foi marcada. \n\n%s, ainda é sua vez.\n", nome1);
         if (jogador == 2)
            printf ("A posição escolhida já foi marcada. \n\n%s, ainda é sua vez.\n", nome2);
            
            printf ("Informe as novas coordenadas da sua jogada.\n");
            printf ("Linha: ");
            scanf ("%d", &linha);
            validalinha ();
            printf ("Coluna: ");
            scanf ("%d", &coluna);
            validacoluna();
            validajogada ();
   }
   else {
        if (jogador == 1){
            casa[linha][coluna] = 'X';
            jogador = 2;
        }
        else {
           casa[linha][coluna] = 'O';
           jogador = 1;
        }
   }
}

//Essa função recebe parâmetros de 1 até 3, que dizem respeto às coordenadas maracadas pelos
//jogadores, verifica e informa se houve vencedor ou se houve empate.
verificavencedor(int a, int b, int c, int d, int e, int f){
   if (casa[a][b] == 'X' && casa[c][d] == 'X' && casa[e][f] == 'X'){
      jogador = 1;
      vencedor = 1;
      printf ("Parabéns! %s, você foi o vencedor\n\n!", nome1);
   }
   else {
        if (casa[a][b] == 'O' && casa[c][d] == 'O' && casa[e][f] == 'O'){
            jogador = 2;
            vencedor = 1;
            printf ("Parabéns! %s, você foi o vencedor\n\n!", nome1);
         }
         else {
            if (vencedor == 0 && turno >= 9) {
               vencedor = 0;
               printf ("Xiiiii, deu velha!\nEssa foi a %dª rodada, então acabou.\n\n", turno);
            }
         }
   }
}

/*
A função PLACAR conta as vitórias de cada um dos jogadores, bem como os empates, 
e imprime na tela o resultado.
*/
placar (){
   if (jogador == 1 && vencedor == 1)
      ++vitorias1;
   if (jogador == 2 && vencedor == 1)
      ++vitorias2;
   if (vencedor == 0 && turno >= 9)
      ++vitoriasdavelha;
   system ("cls");
   cabecalho ();
   tabuleiro ();   
   printf ("___________________________________________________________________________\n\n");
   printf ("|\t\t\t\t   PLACAR                                 |\n");
   printf ("___________________________________________________________________________\n\n");
   printf ("%s venceu %d vez(es)\n\n", nome1, vitorias1);
   printf ("%s venceu %d vez(es)\n\n", nome2, vitorias2);
   printf ("A velha ganhou %d vez(es).\n\n\n", vitoriasdavelha);
}

menu2(){
   system ("cls");
   cabecalho();
   printf ("E aí, querem jogar mais uma?\n\n");
   printf ("1 - Jogar com os mesmos jogadores.\n");
   printf ("2 - Jogar com jogadores diferentes.\n");
   printf ("3 - Sair.\n\n");
   printf ("--->  ");
   scanf ("%d", &opcao);
   validaopcao();
   switch (opcao){
      
      /*
        Para jogar com os mesmos jogadores, os nomes informados no incício são transmitidos para
        variáveis auxiliares, ativa-se nomeaux, vencedor e turno recebem 0 e as casas são zeradas.
      */
      case 1:
         strcpy (nomeaux1,nome1);
         strcpy (nomeaux2,nome2);
         nomeaux = 1;
         vencedor = 0;
         turno = 0;
         //Zera as casas do tabuleiro, para reiniciar o jogo com os mesmos jogadores. 
         for (i=0; i<=4; i++)
            for (j=0;j<=4; j++)
               casa[i][j] = '\0'; 
      break;
      /*
         Para jogar com jogadores diferentes, zera-se a quantidade de vitórias, anulam-se vencedor,
         turno e variável nomeaux e invoca-se a função main desde o seu início.
      */         
      case 2:
         vitorias1=0;
         vitorias2=0;
         vitoriasdavelha=0;
         vencedor = 0;
         turno = 0;
         nomeaux = 0;
         system ("cls");
         main ();
      break;
      case 3:
         exit (EXIT_SUCCESS);                 
      break;
   }
}

/*
============================================================================
                      PROGRAMA PRINCIPAL
============================================================================
*/

main (){
   setlocale (LC_ALL, "Portuguese");
   system ("color 07");

   //Essse loop "ZERA" as casas do tabuleiro para qualquer novo jogo.
   for (i=0; i<=4; i++)            
      for (j=0;j<=4; j++)
         casa[i][j] = '\0';
   menu1();
   opcao=0;

   //O loop seguinte repete o jogo enquanto se iniciarem novos jogos com os mesmos jogadores. 
   do {
      //A função da estrutura de decisão abaixo é informa novamente ao programa os nomes dos 
      //jogadores 1 e 2. O programa só passará por ela, em caso de novo jogo com jogadores iguais aos da partida anterior.
      if (nomeaux == 1){
         strcpy (nome1, nomeaux1);
         strcpy (nome2, nomeaux2);
         cabecalho ();
         tabuleiro ();
      }
      //Laço de repetição que determina a duração do jogo.
      while (vencedor == 0 && turno < 9) {
         jogada ();
         system ("cls");
         cabecalho ();
         tabuleiro ();  
            for (i=1; i<=3; i++)
               verificavencedor (i, 1, i, 2, i, 3);     //verifica vencedor nas colunas
            for (j=1;j<=3; j++)
                verificavencedor (1, j, 2, j, 3, j);    //verifica vencedos nas linhas
             verificavencedor (1, 1, 2, 2, 3, 3);       //verifica vencedor na primeira diagona
             verificavencedor (1, 3, 2, 2, 3, 1);       //verifica vencedor na segunda diagonal
      } //fecha o while da linha 334.
      
      placar ();

      system ("pause");  

      menu2();

   } while (opcao == 1); //estabelece a condição do DO iniciado na linha 324.
}  //encerra a função main ().
