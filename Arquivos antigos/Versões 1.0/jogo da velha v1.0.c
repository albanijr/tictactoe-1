#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int opcao, 
    jogador=1, 
    vencedor=0, 
    turno=1, 
    linha, 
    coluna, 
    vitorias1=0, 
    vitorias2=0, 
    vitoriasdavelha=0, 
    i, 
    j;
char nome1[100], 
     nome2[100], 
     casa[4][4];

//Cria um cabeçalho
cabecalho (){
   printf ("___________________________________________________________________\n\n\n");
   printf ("|\t\t\tJOGO DA VELHA                             |\n\n");
   printf ("___________________________________________________________________\n\n");
}

//Cria o menu inicial
menu1 (){
   system ("cls");
   cabecalho();
   printf ("\t\t\tOPÇÕES\n\n");
   printf ("\t\t\t1 - Novo jogo. \n\t\t\t2 - Instruções. \n\t\t\t3 - Sair. \n\n");
   validaopcao1 ();
}   

validaopcao1 (){
   printf ("--->  ");
   scanf ("%d", &opcao);
   validaentrada ();
   switch (opcao){
      case 1:
         tabuleiro ();
         informa ();
         while (vencedor == 0 || turno < 10)
            jogada ();      
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
         printf ("Obrigado por ter jogado velha's gaming :)\n");
         system ("pause");
      break;      
      //default:
        // menu1();
      //break;
   }
}

//Informando os nomes dos jogadores
informa (){    
   printf ("Informe o nome do 1º jogador: ");
   fflush (stdin);
   //fgets (nome1, 99, stdin);
   gets (nome1);
   printf ("Informe o nome do 2º jogador: ");
   fflush (stdin);
   //fgets (nome2, 99, stdin);
   gets (nome2);
   system ("cls");
   cabecalho ();
   tabuleiro ();
   printf ("\n");
   printf ("%s joga com X.\n%s joga com O.\n", nome1, nome2);
   getch ();
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
validaentrada (){
   while (opcao < 1 || opcao > 3){
      system ("cls");
      cabecalho ();
      printf ("\n\n%d não é uma opção válida.\n", opcao);
      printf ("Por favor, escolha 1, 2 ou 3.\n\n");
      printf ("--->   ");
      scanf ("%d", &opcao);
   }
}

//Marcação das posções escolhidas, ora pelo jogador 1, ora pelo jogador 2.
jogada (){
//   while (vencedor == 0 || turno < 10){
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
       for (i=1; i<=3; i++){
          for (j=1;j<=3; j++){
             verificavencedor (i, 1, i, 2, i, 3); //verifica vencedor nas colunas
             verificavencedor (1, j, 2, j, 3, j); //verifica vencedos nas linhas
          }
       }
       verificavencedor (1, 1, 2, 2, 3, 3);       //verifica vencedor na primeira diagona
       verificavencedor (1, 3, 2, 2, 3, 1);       //verifica vencedor na segunda diagonal
       turno++;
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

/*
alternajogador (){
   if (jogador == 1){
      casa[linha][coluna] = 1;
      jogador = 2;
   }
   else {
      casa[linha][coluna] = 2;
      jogador = 1;
   }
}
*/

//Verifica se houve vencedor ou se deu velha.
verificavencedor(a, b, c, d, e, f){
   if (casa[a][b] == 'X' && casa[c][d] == 'X' && casa[e][f] == 'X'){
      jogador = 1;
      vencedor =1;
      ++vitorias1;
      printf ("Parabéns! %s, você foi o vencedor\n\n!", nome1);
      placar ();
      jogador = 2;
   }
   if (casa[a][b] == 'O' && casa[c][d] == 'O' && casa[e][f] == 'O'){
      jogador = 2;
      vencedor = 1;
      ++vitorias2;
      printf ("Parabéns!\n%s, você foi o(a) vencedor(a)!", nome2);
      placar ();
   }
   if (turno > 10) {
      printf ("Xiiiii, deu velha!\nEssa foi a %dª rodada, então acabou.\n\n", turno);
      system ("pause");
      ++vitoriasdavelha;
      placar ();
   }
}

placar (){
   system ("cls");
   cabecalho ();
   tabuleiro ();   
   printf ("___________________________________________________________________\n\n\n");
   printf ("|\t\t\t\tPLACAR                             |\n\n");
   printf ("___________________________________________________________________\n\n");
   printf ("%s venceu %d vezes.\n", nome1, vitorias1);
   printf ("%s venceu %d vezes.\n", nome2, vitorias2);
   printf ("A velha ganhou %d vezes.\n", vitoriasdavelha);
   system ("pause");
   for (i=0; i<=4; i++)             //Essse loops ZERA novamente as casas, fazendo com que seja possível reiniciar o jogo sem um vencedor.
      for (j=0;j<=4; j++)
         casa[i][j] = '\0';
   turno=0;
}

/*
============================================================================
                      PROGRAMA PRINCIPAL
============================================================================
*/

main (){
   setlocale (LC_ALL, "Portuguese");
   system ("color 07");
   
   menu1 ();

}
