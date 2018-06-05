#include <stdio.h>
#include <stdlib.h>
#include "dzialania.h"

#define B_LICZB -1  /* gdy na stosie jest za malo liczb do wykonania funkcji */
#define ZERO -2  /* gdy dzielimy przez zero */

/**************************************************/
/** DODAWANIE ELEMENTOW **/

int dodaj(t_elem **wsk_lista)
{
  int suma;

  /* sprawdzamy czy na stosie sa conajmniej 2 liczby*/
  if( empty(*wsk_lista) >= 2){ 
    suma = (*wsk_lista)->liczba;
    pop(wsk_lista);
    suma += (*wsk_lista)->liczba;    /* dodajemy liczbe ze stosu */
    pop(wsk_lista);                  /* usuwamy liczbe ze stostu */
    /* dodajemy liczbe na szczycie stosu */
    push(wsk_lista, suma);
    return 0;  
  }
  else
    return B_LICZB;
    
}

/**************************************************/
/** ODEJMOWANIE ELEMENTOW **/

int odejmij(t_elem **wsk_lista)
{
  int liczba, liczba2;

  /* sprawdzamy czy na stosie sa liczby do wykonania dzialania */
  if( empty(*wsk_lista) >= 2){
    liczba = (*wsk_lista)->liczba;   /* przypisujemy wartosc liczbie */
    pop(wsk_lista);                /* mozemy usunac ja ze stosu */
    liczba2 = (*wsk_lista)->liczba;/* przypisujemy wartosc 2 liczbie */
    pop(wsk_lista);                        /* i usuwamy kolejna */
    liczba2 -= liczba;                          /* odejmujemy liczby */
    push(wsk_lista, liczba2);        /* dodajemy liczbe na stos */
    return 0;
  }
  else 
    return B_LICZB;
}

/**************************************************/
/** MNOZENIE ELEMENTOW **/

int pomnoz(t_elem **wsk_lista)
{
  int iloczyn;

  /* sprawdzamy czy na stosie sa conajmniej dwie liczby */
  if( empty(*wsk_lista) >= 2 ){
    iloczyn = (*wsk_lista)->liczba; /* przepisujemy pierwsza liczbe */
    pop(wsk_lista);                   /* i usuwamy ja ze stosu */
    iloczyn *= (*wsk_lista)->liczba;         /* mnozymy przez druga */
    pop(wsk_lista);                  /* i tez usuwamy ze stosu */ 
    push(wsk_lista, iloczyn);        /* dodajemy wynik na stos */
    return 0;
  }
  else
    return B_LICZB;
}

/**************************************************/
/**  DZIELENIE ELEMENTOW  **/

int podziel(t_elem **wsk_lista)
{
  int liczba, liczba2;

  /* sprawdzamy czy na stosie sa conajmniej 2 liczby */
  if( empty(*wsk_lista) >= 2){
    liczba = (*wsk_lista)->liczba;    /* nadajemy wartosc liczbie 1 */   
    if( liczba == 0 )           /* jesli mamy podzielic przez zero */
      return ZERO;
    else{
      pop(wsk_lista);                /* usuwamy liczbe ze stostu */
      liczba2 = (*wsk_lista)->liczba;       /* pobieramy druga liczbe */
      pop(wsk_lista);                      /* i usuwamy ze stosu */
      liczba2 /= liczba;                      /* wykonujemy dzielenie */
      push(wsk_lista, liczba2);    /* i dopisujemy na stos wynik */
      return 0;
    }
  }
  else 
    return B_LICZB;
}

/**************************************************/
/** DUPLIKUJ ELEMENT **/

int duplikuj(t_elem **wsk_lista)
{
  if( empty(*wsk_lista) > 0 ){  /* sprawdzamy czy stos nie jest pusty */
    push(wsk_lista, (*wsk_lista)->liczba);    /* dodajemy element */
    return 0;
  }
  else
    return B_LICZB;
  
}

/**************************************************/
/**  ZAMIEN ELEMENTY  **/

int zamien(t_elem **wsk_lista)
{
  int liczba, liczba2;

  /* sprawdzamy czy na stosie sa conajmniej dwie liczby */
  if( empty(*wsk_lista) >= 2 ){
    liczba = (*wsk_lista)->liczba; /* przekazujemy wartosc zmiennej statycznej */
    pop(wsk_lista);              /* usuwamy ta liczbe ze stosu */
    liczba2 = (*wsk_lista)->liczba;    /* znow przekazujemy wartosc */
    (*wsk_lista)->liczba = liczba;   /* zamieniamy wartosc liczby 2 */
    push(wsk_lista, liczba2);        /* i dodajemy nowa liczbe */
    return 0;
  }
  else
    return B_LICZB;

}
