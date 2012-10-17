/*
Checagem de opcao OK,
Checagem de linha OK,
Checagem de coluna OK;
Checagem de posi��o marcada OK;
Verifica��o de vencedor OK;
Contagem de v�t�rias OK;
Reiniciar novo jogo com jogadores diferentes OK;
Finalizar programa OK.

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
     nomeaux1[100],
     nomeaux2[100];

//Cria um cabe�alho
cabecalho (){
   printf ("___________________________________________________________________________\n\n");
   printf ("|\t\t\t\tJOGO DA VELHA                             |\n");
   printf ("___________________________________________________________________________\n\n");
}

//Cria o menu inicial
menu1 (){
   system ("cls");
   cabecalho();
   printf ("OP��ES\n\n");
   printf ("1 - Novo jogo. \n2 - Instru��es.\n3 - Sair.\n\n");
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
         printf ("\t\t\tINSTRU��ES\n\n");
         printf ("1 - Informe os nomes dos jogadores. \n2 - As jogadas s�o alternadas. \n3 - Ganha o jogador que marcar tr�s posi��es em sequencia.\n");
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
   printf ("Informe o nome do 1� jogador: ");
   fflush (stdin);
   fgets (nome1, 99, stdin);
   /*
     esse la�o percorre a string capturada pelo fgets procurando 
     a posi��o marcada com \n, caso entre, essa posi��o recebe \o.
   */
   for (i=0; i<=strlen(nome1); i++){
      if (nome1[i] == '\n')
         nome1[i] = '\0';
   }
   printf ("Informe o nome do 2� jogador: ");
   fflush (stdin);
   fgets (nome2, 99, stdin);
   /*
     esse la�o percorre a string capturada pelo fgets procurando 
     a posi��o marcada com \n, caso entre, essa posi��o recebe \o.
   */
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

tabuleiro (){          //tabuleiro tempor�rio
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
       turno++;
       //system ("cls");
       //cabecalho ();
       //tabuleiro ();
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
            printf ("A posi��o escolhida j� foi marcada. \n\n%s, ainda � sua vez.\n", nome1);
         if (jogador == 2)
            printf ("A posi��o escolhida j� foi marcada. \n\n%s, ainda � sua vez.\n", nome2);
            
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
      printf ("Parab�ns! %s, voc� foi o vencedor\n\n!", nome1);
   }
   else {
        if (casa[a][b] == 'O' && casa[c][d] == 'O' && casa[e][f] == 'O'){
            jogador = 2;
            vencedor = 1;
            printf ("Parab�ns! %s, voc� foi o vencedor\n\n!", nome1);
         }
         else {
            if (vencedor == 0 && turno >= 9) {
               vencedor = 0;
               printf ("Xiiiii, deu velha!\nEssa foi a %d� rodada, ent�o acabou.\n\n", turno);
            }
         }
   }
}

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
   printf ("%s venceu %d vezes\n\n", nome1, vitorias1);
   printf ("%s venceu %d vezes\n\n", nome2, vitorias2);
   printf ("A velha ganhou %d vezes.\n\n\n", vitoriasdavelha);
}

menu2(){
   system ("cls");
   cabecalho();
   printf ("E a�, querem jogar mais uma?\n\n");
   printf ("1 - Jogar com os mesmos jogadores.\n");
   printf ("2 - Jogar com jogadores diferentes.\n");
   printf ("3 - Sair.\n\n");
   printf ("--->  ");
   scanf ("%d", &opcao2);
   validaopcao2();
   switch (opcao2){
      //Para jogar com os mesmos jogadores, os nomes informados no inc�cio s�o transmitidos para
      //vari�veis auxiliare, nomeaux recebe 1, vencedor recebe e turno recebem 0.
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
      //Para jogar com jogadores diferentes, zera a quantidade de vit�rias e volta � fun��o main.
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

validaopcao2 (){
   while (opcao2 < 1 || opcao2 > 3){
      system ("cls");
      cabecalho ();
      printf ("\n\n%d n�o � uma op��o v�lida.\n", opcao);
      printf ("Por favor, escolha 1, para jogar, 2 para informa��es ou 3 para sair.\n\n");
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
   //Essse loop "ZERA" as casas do tabuleiro para qualquer novo jogo.
   for (i=0; i<=4; i++)            
      for (j=0;j<=4; j++)
         casa[i][j] = '\0';
   menu1();
   do {
      //A estrutura de decis�o abaixo s� � invocada ap�s o jogo ter rodado ao menos 1 vez. e
      //informa novamente ao programa os nomes dos jogadores 1 e 2.
      if (nomeaux == 1){
         strcpy (nome1, nomeaux1);
         strcpy (nome2, nomeaux2);
         cabecalho ();
         tabuleiro ();
      }
      //La�o de repeti��o que determina a dura��o do jogo.
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
      }
      placar ();

      system ("pause");  
      menu2();
   } while (opcao2 == 1);
}