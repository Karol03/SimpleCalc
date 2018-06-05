#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

/***************************************************************************/
/* FUNKCJA DODAWANIA ELEMENTU NA SZCZYT STOSU */
void push(t_elem **wsk_lista, int liczba)
{
  t_elem *elem;                                      /* wskaznik pomocniczy */
  elem = malloc(sizeof(t_elem));                   /* tworzymy nowy element */
  elem->liczba = liczba;                 /* dajemy wartosc liczbie na stosie*/
  elem->nastepny = *wsk_lista;        /* nowy element wskazuje na poprzedni */
  *wsk_lista = elem;          /* wskaznik na liste wskazuje na nowy element */
}

/***************************************************************************/
/* FUNKCJA USUWANIA ELEMENTU ZE SZCZYTU STOSU */

void pop(t_elem **wsk_lista)
{
  t_elem *elem;                                      /* wskaznik pomocniczy */
  if( *wsk_lista != NULL )             /* usun element tylko jesli istnieje */
    {
      elem = *wsk_lista;             /* wsk. pom. ustawiamy na koniec lsity */
      /* wskaznik na liste ustawiamy na kolejny element */
      *wsk_lista = (*wsk_lista)->nastepny;
      free(elem);       /* zwalniamy pamiec zajmowana przez ostatni element*/
    }
  
}

/***************************************************************************/
/* SPRAWDZANIE CZY STOS JEST PUSTY */

int empty(t_elem *elem)
{
  int elementy = 0;    /* zmienna pomocnicza do liczenia elementow w stosie*/
   while( elem )              /* przesuwamy wskaznik dopoki na cos pokazuje */
    {
      ++elementy;                                   /* dodaj do licznika i */
      elem = elem->nastepny;                              /* przejdz dalej */
    }
  return elementy;                 /* i zwracamy liczbe elementow w liscie */
}

/***************************************************************************/
/* WYPISYWANIE ELEMENTOW STOSTU */

void print(t_elem *elem)
{
  if( !elem ) 
    printf("Brak elementow na stosie\n");
  while( elem ){            /* poruszamy sie dopoki lista na cos wskazuje */
      printf("%d \n", elem->liczba );                /* wypisujemy liczbe */
      elem = elem->nastepny;               /* przechodzimy dalej w liscie */
    }
}

