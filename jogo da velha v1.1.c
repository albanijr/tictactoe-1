/*
Checagem de opcao OK,
Checagem de linha OK,
Checagem de coluna OK;
Checagem de posi��o marcada OK;
Verifica��o de vencedor OK;
Contagem de v�t�rias OK;
Reiniciar novo jogo com jogadores diferentes OK;

ERROS:
Reiniciar novo jogo com os mesmos jogadores - Some o nome do jogador 2).
Finalizar programa ERRO - n�o finaliza.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int opcao, 
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
     casa[4][4];

//Cria um cabe�alho
cabecalho (){
   printf ("___________________________________________________________________\n\n\n");
   printf ("|\t\t\tJOGO DA VELHA                             |\n\n");
   printf ("___________________________________________________________________\n\n");
}

//Cria o menu inicial
menu1 (){
   system ("cls");
   cabecalho();
   printf ("OP��ES\n\n");
   printf ("1 - Novo jogo. \n2 - Instru��es. \n3 - Sair. \n\n");
   printf ("--->  ");
   scanf ("%d", &opcao);
   validaopcao ();
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
         printf ("\t\t\tINSTRU��ES\n\n");
         printf ("1 - Informe os nomes dos jogadores. \n2 - As jogadas s�o alternadas. \n3 - Ganha o jogador que marcar tr�s posi��es em sequencia.\n");
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
   printf ("Informe o nome do 1� jogador: ");
   fflush (stdin);
   //fgets (nome1, 99, stdin);
   gets (nome1);
   printf ("Informe o nome do 2� jogador: ");
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

tabuleiro (){          //tabuleiro tempor�rio
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

//valida entrada do menu inicial, impedindo que a op��o do usu�rio seja menor que 1 ou maior que 3. 
validaopcao (){
   while (opcao < 1 || opcao > 3){
      system ("cls");
      cabecalho ();
      printf ("\n\n%d n�o � uma op��o v�lida.\n", opcao);
      printf ("Por favor, escolha 1, para jogar, 2 para informa��es ou 3 para sair.\n\n");
      printf ("--->   ");
      scanf ("%d", &opcao);
   }
}

//Marca��o das pos��es escolhidas, ora pelo jogador 1, ora pelo jogador 2.
jogada (){
//   while (vencedor == 0 || turno < 10){
       turno++;
       system ("cls");
       cabecalho ();
       tabuleiro ();
       printf ("\n\nEssa � a %d rodada.\n\n", turno);
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
//   }
}

//Obriga linha escolhida estar entre 1 e 3.
validalinha (){
   while (linha < 1 || linha > 3){
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("O n�mero informado � inv�lido.\n");
      printf ("Por favor, escolha um valor de 1 at� 3 para a linha escolida: \n");
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
      printf ("O n�mero informado � inv�lido.\n");
      printf ("Por favor, escolha um valor de 1 at� 3 para a coluna escolhida: \n");
      printf ("----> ");
      scanf ("%d", &coluna);
   }
}

//Valida uma jogada em posi��o livre.
validajogada (){
   if (casa[linha][coluna] == 'X' || casa[linha][coluna] == 'O'){
      system ("cls");
      cabecalho ();
      tabuleiro ();
         if (jogador == 1)
            printf ("A posi��o escolhida j� foi marcada. \n%s, ainda � sua vez.\n", nome1);
         if (jogador == 2)
            printf ("A posi��o escolhida j� foi marcada. \n%s, ainda � sua vez.\n", nome2);
            
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
      vencedor =1;
      ++vitorias1;
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("Parab�ns! %s, voc� foi o vencedor\n\n!", nome1);
      placar ();
   }
   if (casa[a][b] == 'O' && casa[c][d] == 'O' && casa[e][f] == 'O'){
      jogador = 2;
      vencedor = 1;
      ++vitorias2;
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("Parab�ns! %s, voc� foi o vencedor\n\n!", nome1);
      placar ();
   }
   if (turno >= 9) {
      ++vitoriasdavelha;
      system ("cls");
      cabecalho ();
      tabuleiro ();
      printf ("Xiiiii, deu velha!\nEssa foi a %d� rodada, ent�o acabou.\n\n", turno);
      placar ();
      system ("pause");
      
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
   for (i=0; i<=4; i++)             //Essse loops ZERA novamente as casas, fazendo com que seja poss�vel reiniciar o jogo sem um vencedor.
      for (j=0;j<=4; j++)
         casa[i][j] = '\0';
   turno=0;
   menu2();
}

menu2(){
   system ("cls");
   cabecalho();
   printf ("E a�, querem jogar mais uma?\n\n");
   printf ("1 - Jogar com os mesmos jogadores.\n");
   printf ("2 - Jogar com jogadores diferentes.\n");
   printf ("3 - Sair.\n\n");
   printf ("--->  ");
   scanf ("%d", &opcao);
   validaopcao();
   switch (opcao){
      case 1:
         printf ("Voc� escolheu 1.\n");
         //vencedor = 0;
         //vitorias1=0;
         //vitorias2=0;
         //vitoriasdavelha=0;
         printf ("Vitorias 1 %d\n", vitorias1);
         printf ("Vitorias 2 %d\n", vitorias2);
         printf ("Vitorias Velha %d\n", vitoriasdavelha);
         printf ("Nome 1 %s\n", nome1);
         printf ("Nome 2 %s\n", nome2);                  //ERRO Nome2 est� sumindo.
         system ("pause");
      break;
      case 2:
/*
         vencedor = 0;
         vitorias1=0;
         vitorias2=0;
         vitoriasdavelha=0;
         printf ("Vitorias 1 %d\n", vitorias1);
         printf ("Vitorias 2 %d\n", vitorias2);
         printf ("Vitorias Velha %d\n", vitoriasdavelha);
         printf ("Nome 1 %s\n", nome1);
         printf ("Nome 2 %s\n", nome2);                  //ERRO Nome2 est� sumindo.
         system ("pause");
*/
         menu1();
      break;
      case 3:
         vencedor = 1;                 
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
   
   menu1 ();

}
