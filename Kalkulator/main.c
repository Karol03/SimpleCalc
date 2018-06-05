/**********************************************************/
/*      KAROL DUDZIC    KALKULATOR RPN     17.01.2017r.   */
/*                                                        */
/*  OPIS: Prosty kalkulator w odwroconej notacji polskiej */
/*  Zawiera opcje takie jak dodaj (+), odejmij (-),       */
/*  pomnnoz (*), podziel (/), duplikuj (&),               */
/*  usun ostatnia (#), zamien miejscami ($),              */
/*  a takze wyswietl zawartosc stosu (?)                  */
/*                                                        */
/*  DZIALANIE: Po uruchomieniu wprowadzamy dowolne liczby */
/*  aby wykonac dzialanie nalezy wprowadzic odpowiedni    */
/*  znak (sposrod widocznych powyzej).                    */
/*  Znak 'q' konczy prace programu.                       */
/*                                                        */
/*  TESTY: Wykonanie ponzszych dzialan zapisanych w RPN   */
/*  (2+4*5)/(1-7) ; (-4-8)/(3*4) ;  2+2*2/(2-2)           */ 
/*  dzialania sprawdzaja czy program dobrze               */
/*  wykonuje podstawowe dzialania na liczbach             */
/*  (Wynik sprawdzamy poprzez przejrzenie stostu (?) )    */
/*  Zapis dla programu:                                   */
/*  (1). 2 4 5 * + 1 7 - / - zworcony wynik -3 - popr.    */
/*  (2). -4 8 - 3 4 * / - zwrocony wynik -1 - popr.       */
/*  (3). 2 2 2 * 2 2 - / - zwrocony wnik: liczby 2, 4, 0  */
/*   na stosie oraz blad o dzieleniu przez 0 - poprawnie  */
/*  Na pozostalosciach po ostatnim dzialaniu sprawdzamy   */
/*  pozostale opcje programu.                             */
/*  Ciag znakow: # $ # & zostawia na stosie dwie cyfry 4  */
/*  - opcje dzialaja poprawnie                            */
/*                                                        */
/*  WNIOSKI: Program spelnia swoje zadanie - poprawnie    */
/*  oblicza wartosc podanych dzialan                      */ 
/**********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"
#include "dzialania.h"

/**********************************************************/
/*                     FUNKCJA MAIN                       */
/*  Funkcja okreslona w petli while, dopoki wprowadzony   */
/*              wyraz jest rozny od 'q'.                  */ 
/*                                                        */
/*  PRE:                                                  */
/*     brak                                               */
/*  POST:                                                 */
/*     funkcja pobiera kolejne wyrazy od uzytkownika      */
/*     i dodaje do stosu liczbe lub przysyla argument     */
/*     wraz ze wskaznikiem do stosu do odpowiedniej       */
/*     funkcji aby ta wykonala dzialanie                  */
/*     w przypadku gdy nie udalo sie wykonac dzialania    */
/*     funkcja wypisuje ktorego dzialania nie udalo       */
/*     sie wykonac                                        */
/**********************************************************/

int main()
{
  char txt[255];                       /*ciag znakow*/
  char *wyraz;                 /* wskaznik na wyraz */
  int i;              /* zmienna do tablicy wyrazow */
  int liczba, x, j;/* zmienna do liczby i pomocnicze*/
  int wyrazy;                     /* liczba wyrazow */
  char *tablica[255];            /* tablica wyrazow */
  t_elem *lista = NULL;        /* wskaznik do listy */

  do{
    /* pobieramy kolejne wyrazy i zapisujemy je do naszej tablicy wyrazow */
    fgets(txt, 100, stdin);        
    wyraz = strtok(txt, " ");
    i = 0;
    while(wyraz){
      tablica[i] = wyraz;
      wyraz = strtok(NULL, " ");
      ++i;
    }
    wyrazy=i;

    /* nastepnie poruszamy sie po tablicy wyrazow */
    for(i=0; i<wyrazy; i++){
      x = 0;
      if( sscanf(tablica[i],"%d" ,&liczba) == 1 ){
	push(&lista, liczba);
	x = 1;             /* zmienna posluzy w przypadku liczb ujemnych */
      }

      switch(*tablica[i]){
      case '+':
	if( dodaj(&lista) )
	  printf("Blad: Nie udalo sie dodac.\n");
	break;	
      case '-':
	if(x == 0)
	  if( odejmij(&lista) )
	    printf("Blad: Nie udalo sie odjac.\n");
	break;
      case '*':
	if( pomnoz(&lista) )
	  printf("Blad: Nie udalo sie pomnozyc.\n");
	break;
      case '/':
	if( (j = podziel(&lista)) == -2 )
	  printf("Blad: Nie mozna dzielic przez 0.\n");
	else if( j == -1 )
	  printf("Blad: Nie udalo sie podzielic.\n");
	break;
      case '$':
	if( zamien(&lista) )
	  printf("Blad: Nie udalo sie zamienic miejscami.\n");
	break;
      case '#':    
	pop(&lista);
	break;
      case '&':
	if( duplikuj(&lista) )
	  printf("Blad: Nie udalo sie zduplikowac liczby.\n");
	break;
      case '?':
	print(lista);
	break;
      default:
	break;
      } /* koniec switch */
    } /* koniec for */
  }while( *tablica[--i] != 'q' );

  return 0;
}

