#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int opcao, jogador=1, vencedor=0, turno=1, linha, coluna, i, j;
char nome1[100], nome2[100], casa[3][3];

//Cria um cabeçalho
cabecalho (){
   printf ("__________________________________________________________________\n\n\n");
   printf ("\t\t\tJOGO DA VELHA     \n\n");
   printf ("___________________________________________________________________\n\n");
}

//Cria o menu inicial
menu1 (){
   system ("cls");
   cabecalho();
   printf ("\t\t\tOPÇÕES\n\n");
   printf ("\t\t\t1 - Novo jogo. \n\t\t\t2 - Instruções. \n\t\t\t3 - Sair. \n\n");
   entradamenu1 ();
}   

//Seleção de opções do menu inicial
entradamenu1 (){
   printf ("---->   ");
   scanf ("%d", &opcao);
   validaentrada ();
   switch (opcao){
      case 1:
         desenha ();
         informa ();
         jogada ();    
         getch ();
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
         printf ("Sair do programa.");
      break;      
      default:
         menu1();
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
   desenha ();
   printf ("\n");
   printf ("%s joga com X.\n%s joga com O.\n", nome1, nome2);
   getch ();
}

desenha (){          //tabuleiro temporário
   system ("cls");
   cabecalho ();
   printf ("\t\t\t     |     |    \n  ");
   printf ("\t\t\t  %d  |  %d  |  %d\n", casa[0][0], casa[0][1], casa[0][2]);
   printf ("\t\t\t_____|_____|_____\n");
   printf ("\t\t\t     |     |        \n");
   printf ("\t\t\t  %d  |  %d  |  %d\n", casa[1][0], casa[1][1], casa[1][2]);
   printf ("\t\t\t_____|_____|_____\n");
   printf ("\t\t\t     |     |    \n");
   printf ("\t\t\t  %d  |  %d  |  %d\n", casa[0][2], casa[1][2], casa[2][2]);
   printf ("\t\t\t     |     |\n\n");
}

//valida entrada do menu inicial, impedindo que a opção do usuário seja menor que 1 ou maior que 3. 
validaentrada (){
   while (opcao < 1 || opcao > 3){
      printf ("\n\n%d não é uma opção válida.\n", opcao);
      printf ("Por favor, escolha 1, 2 ou 3.\n\n");
      printf ("---->   ");
      scanf ("%d", &opcao);
   }
}

//Marcação das posções escolhidas, ora pelo jogador 1, ora pelo jogador 2.
jogada (){
   system ("cls");
   cabecalho ();
   desenha ();
//   do {
      if (jogador == 1){
         printf ("%s, informe as coordenadas da sua jogada.\n", nome1);
         printf ("Linha: \n");
         scanf ("%d", &linha);
         validalinha ();
         printf ("Coluna: \n");
         scanf ("%d", &coluna);
         validacoluna ();
         casa[--linha][--coluna] = 'X';
         jogador=2;
      }
      else{
         printf ("%s, informe as coordenadas da sua jogada.\n", nome2);
         printf ("Linha: \n");
         scanf ("%d", &linha);
         validalinha ();
         printf ("Coluna: \n");
         scanf ("%d", &coluna);
         validacoluna ();
         casa[--linha][--coluna] = 'O';
         jogador=1;
      }
   for (i=0; i<3; i++){
      for (j=0;j<3; j++){
         verificavencedor (i, 1, i, 2, i, 3);
         verificavencedor (j, 1, j, 2, j, 3);
      }
   }
   verificavencedor (0, 0, 1, 1, 2, 2);
   verificavencedor (0, 2, 1, 1, 2, 0); 
   desenha ();
//} while (turno <=9);
}

validalinha (){
   while (linha < 1 || linha > 3){
      system ("cls");
      cabecalho ();
      desenha ();
      printf ("O número informado é inválido.\n");
      printf ("Por favor, escolha um valor de 1 até 3 para a linha escolida: \n");
      printf ("----> ");
      scanf ("%d", &linha);
      }
}

validacoluna (){
   while (coluna < 1 || coluna > 3){
      system ("cls");
      cabecalho ();
      desenha ();
      printf ("O número informado é inválido.\n");
      printf ("Por favor, escolha um valor de 1 até 3 para a coluna escolhida: \n");
      printf ("----> ");
      scanf ("%d", &coluna);
   }
}

verificavencedor(a, b, c, d, e, f){
   while (vencedor == 0 || turno < 0) {
      if (casa[a][b] == casa[c][d] && casa[a][b] == casa[e][f] && casa[a][b] == 'X'){
         jogador = 1;
         printf ("Parabéns! %s, você foi o vencedor!", nome1);
         vencedor =1;
      }
      if (casa[a][b] == casa[c][d] && casa[a][b] == casa[e][f] && casa[a][b] == 'o'){
         jogador = 2;
         printf ("Parabéns! %s, você foi o vencedor!", nome2);
         vencedor = 1;
      }
      ++turno;
      jogada ();
   }
}

/*
============================================================================
                      PROGRAMA PRINCIPAL
============================================================================
*/

main (){
   int coordenada=0;
   setlocale (LC_ALL, "Portuguese");

   for (i=0; i<3; i++){
      for (j=0;j<3; j++){
         //++coordenada;
         casa[i][j] = '\0';
         fflush (stdin);
         //printf ("%s", %casa);
      }
   }
   
   menu1 ();
//   system ("pause");
}
