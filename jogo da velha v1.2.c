/*
Checagem de opcao OK,
Checagem de linha OK,
Checagem de coluna OK;
Checagem de posição marcada OK;
Verificação de vencedor OK;
Contagem de vítórias OK;
Reiniciar novo jogo com jogadores diferentes OK;
Finalizar programa ERRO OK.

ERROS:
Reiniciar novo jogo com os mesmos jogadores - Some o nome do jogador 2).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int opcao,
    opcao2,
    jogador=1, 
    vencedor=0, 
    turno=0, 
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
     nomeaux[100];

//Cria um cabeçalho
cabecalho (){
   printf ("___________________________________________________________________\n\n");
   printf ("|\t\t\tJOGO DA VELHA                             |\n");
   printf ("___________________________________________________________________\n\n");
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
         printf ("\t\t\tINSTRUÇÕES\n\n");
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
   //gets (nome1);
   printf ("Informe o nome do 2º jogador: ");
   fflush (stdin);
   fgets (nome2, 99, stdin);
   //gets (nome2);
   system ("cls");
   cabecalho ();
   tabuleiro ();
   printf ("\n");
   printf ("%s joga com X.\n%s joga com O.\n\n", nome1, nome2);
   system ("pause");
}

tabuleiro (){          //tabuleiro temporário
   system ("cls");
   cabecalho ();
   printf ("\t\t\t     |     |    \n  ");
   printf ("\t\t\t  %c  |  %c  |  %c \n", casa[1][1], casa[1][2], casa[1][3]);
   printf ("\t\t\t_____|_____|_____\n");
   printf ("\t\t\t     |     |        \n");
   printf ("\t\t\t  %c  |  %c  |  %c \n", casa[2][1], casa[2][2], casa[2][3]);
   printf ("\t\t\t_____|_____|_____\n");
   printf ("\t\t\t     |     |    \n");
   printf ("\t\t\t  %c  |  %c  |  %c \n", casa[3][1], casa[3][2], casa[3][3]);
   printf ("\t\t\t     |     |\n\n\n");
}

//valida entrada do menu inicial, impedindo que a opção do usuário seja menor que 1 ou maior que 3. 
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

//Marcação das posções escolhidas, ora pelo jogador 1, ora pelo jogador 2.
jogada (){
       turno++;
       system ("cls");
       cabecalho ();
       tabuleiro ();
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

//Valida uma jogada em posição livre.
validajogada (){
   if (casa[linha][coluna] == 'X' || casa[linha][coluna] == 'O'){
      system ("cls");
      cabecalho ();
      tabuleiro ();
         if (jogador == 1)
            printf ("A posição escolhida já foi marcada. \n%s, ainda é sua vez.\n", nome1);
         if (jogador == 2)
            printf ("A posição escolhida já foi marcada. \n%s, ainda é sua vez.\n", nome2);
            
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

//Verifica se houve vencedor ou se deu velha.
verificavencedor(a, b, c, d, e, f){
   if (casa[a][b] == 'X' && casa[c][d] == 'X' && casa[e][f] == 'X'){
      jogador = 1;
      vencedor = 1;
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("Parabéns! %s, você foi o vencedor\n\n!", nome1);
   }
   else {
        if (casa[a][b] == 'O' && casa[c][d] == 'O' && casa[e][f] == 'O'){
            jogador = 2;
            vencedor = 1;
            system ("cls");
            cabecalho ();
            tabuleiro ();
            printf ("Parabéns! %s, você foi o vencedor\n\n!", nome1);
         }
         else {
            if (turno >= 9) {
               system ("cls");
               cabecalho ();
               tabuleiro ();
               printf ("Xiiiii, deu velha!\nEssa foi a %dª rodada, então acabou.\n\n", turno);
            }
         }
   }
}

placar (){
   if (jogador == 1 && vencedor == 1)
      ++vitorias1;
   if (jogador == 2 && vencedor == 1)
      ++vitorias2;
   if (turno >= 9)
      ++vitoriasdavelha;
   system ("cls");
   cabecalho ();
   tabuleiro ();   
   printf ("___________________________________________________________________\n\n");
   printf ("|\t\t\t\tPLACAR                             |\n");
   printf ("___________________________________________________________________\n\n");
   printf ("%s venceu %d vezes\n", nome1, vitorias1);
   printf ("%s venceu %d vezes\n", nome2, vitorias2);
   printf ("A velha ganhou %d vezes.\n", vitoriasdavelha);
   turno=0;
}

menu2(){
   system ("cls");
   cabecalho();
   printf ("E aí, querem jogar mais uma?\n\n");
   printf ("1 - Jogar com os mesmos jogadores.\n");
   printf ("2 - Jogar com jogadores diferentes.\n");
   printf ("3 - Sair.\n\n");
   printf ("--->  ");
   scanf ("%d", &opcao2);
   validaopcao2();
   switch (opcao2){
      case 1:                                       //Para jogar com os mesmos jogadores.
         printf ("Você escolheu 1.\n");
         vencedor = 0;
         turno = 0;
      break;
      case 2:                                       //Para jogar com jogadores diferentes
         vencedor = 0;
         turno = 0;
         vitorias1=0;
         vitorias2=0;
         vitoriasdavelha=0;
         system ("cls");
         main ();
      break;
      case 3:
         exit (EXIT_SUCCESS);                 
      break;
   }
}

validaopcao2 (){
   while (opcao2 < 1 || opcao2 > 3){
      system ("cls");
      cabecalho ();
      printf ("\n\n%d não é uma opção válida.\n", opcao);
      printf ("Por favor, escolha 1, para jogar, 2 para informações ou 3 para sair.\n\n");
      printf ("--->   ");
      scanf ("%d", &opcao2);
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
   for (i=0; i<=4; i++)             //Essse loops ZERA novamente as casas, fazendo com que seja possível reiniciar o jogo sem um vencedor.
      for (j=0;j<=4; j++)
         casa[i][j] = '\0';
   menu1();
   do {
      while (vencedor == 0 && turno < 9) {
         jogada ();
            for (i=1; i<=3; i++)
               verificavencedor (i, 1, i, 2, i, 3);     //verifica vencedor nas colunas
            for (j=1;j<=3; j++)
                verificavencedor (1, j, 2, j, 3, j);    //verifica vencedos nas linhas
             verificavencedor (1, 1, 2, 2, 3, 3);       //verifica vencedor na primeira diagona
             verificavencedor (1, 3, 2, 2, 3, 1);       //verifica vencedor na segunda diagonal
      }
      placar (); 
      system ("pause");  
      menu2();
   for (i=0; i<=4; i++)             //Essse loops ZERA novamente as casas, fazendo com que seja possível reiniciar o jogo sem um vencedor.
      for (j=0;j<=4; j++)
         casa[i][j] = '\0'; 
   } while (opcao2 == 1);
}
