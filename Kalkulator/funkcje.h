/*******************************************************
* PLIK NAGLOWKOWY Z DEKLARACJAMI FUNKCJI DO POMOCY     *
*           PRZY PORUSZANIU SIE PO STOSIE              *
*******************************************************/


#ifndef FUNKCJE_H
#define FUNKCJE_H

typedef struct elem{            /* struktura z elementami na liscie */
  int liczba;                               /* przechowywana liczba */
  struct elem *nastepny;         /* wskaznik do nastepnego elementu */
} t_elem; 


/*******************************************************/

int inicjuj(t_elem**);             /* inicjowanie listy */

/*******************************************************/

void push(t_elem**, int);         /* dodawanie elementu */

/*******************************************************/

void pop(t_elem**);                /* usuwanie elementu */

/*******************************************************/

int empty(t_elem*);   /* sprawdzanie czy stos jest pusty*/

/*******************************************************/

void print(t_elem*);   /* wyswietlanie zawartosci stosu */

/*******************************************************/

#endif
