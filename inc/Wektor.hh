#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <LZespolona.hh>
#include <rozmiar.hh>

/**
 * @brief Klasa modeluje pojęcie wektora o stałym rozmiarze
 * 
 */
template <class T, int R>
class Wektor 
{
private:

  T m_tab[R]; ///< Tablica współżędnych wektora

public:

/**
 * @brief Konstruktor nowego obiektu Wektor 
 * @details Wektor inicjowany jest zerami
 * 
 */
  Wektor();

/**
 * @brief Konstruktor nowego obiektu Wektor 
 * @details Wektor inicjowany jest tablicą wartości o tym samym rozmiarze
 * 
 * @param tablica tablica wartości
 */
  Wektor(T tablica[]);

/**
 * @brief Dodawania dwóch wektorów
 * 
 * @param W2 drugi wektor - składnik
 * @return Wektor suma dwóch wektorów będąca wektorem 
 */
  Wektor operator+(const Wektor &W2) const;

/**
 * @brief Odejmowanie dwóch wektorów
 * 
 * @param W2 drugi wektor - odjemnik
 * @return Wektor różnica dwóch wektorów będąca wektorem
 */
  Wektor operator-(const Wektor &W2) const;

/**
 * @brief Iloczyn skalarny dwóch wektorów
 * 
 * @param W2 drugi wektor - czynnik
 * @return T iloczyn dwóch wektorów będący skalarem
 */
  T operator*(const Wektor &W2) const;

/**
 * @brief Iloczyn wektora ze skalarem
 * 
 * @param l skalar - czynnik
 * @return Wektor iloczyn wektora i skalara będący wektorem
 */
  Wektor operator*(T l) const;

/**
 * @brief Iloraz wektora i skalara
 * 
 * @exception std::invalid_argument próba dzielenia przez 0
 * @param l skalar - dzielnik
 * @return Wektor iloraz wektora i skalara będący wektorem
 */
  Wektor operator/(T l) const;

/**
 * @brief Suma z przypisaniem dla dwóch wektorów
 * 
 * @param W2 drugi wektor - składnik
 * @return const Wektor& zmieniony wektor z wejścia
 */
  const Wektor &operator+=(const Wektor &W2);

/**
 * @brief Różnica z przypisaniem dla dwóch wektorów
 * 
 * @param W2 drugi wektor - odjemnik
 * @return const Wektor& zmieniony wektor z wejścia
 */
  const Wektor &operator-=(const Wektor &W2);

/**
 * @brief Porównanie dwóch wektorów
 * 
 * @param W2 drugi wektor
 * @return true - wektory są równe
 * @return false  - wektory są różne
 */
  bool operator==(const Wektor &W2) const;

/**
 * @brief Porównanie dwóch wektorów
 * 
 * @param W2 drugi wektor
 * @return true - wektory są różne
 * @return false  - wektory są równe
 */
  bool operator!=(const Wektor &W2) const;

/**
 * @brief Dostęp do elementu tablicy w celu odczytu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return T R-wartość elementu tablicy
 */
  T operator[](int index) const;

/**
 * @brief Dostęp do elementu tablicy w celu zapisu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return T& L-wartość elementu tablicy
 */
  T &operator[](int index);

/**
 * @brief Oblicza długość wektora
 * 
 * @return double dlugosc wektora jako liczbe zmiennoprzecinkową
 */
  double dlugosc() const;

};

/**
 * @brief Iloczyn skalara i wektora
 * 
 * @param l skalar - czynnik
 * @param W2 wektor - czynnik
 * @return Wektor iloraz skalara i wektora będący wektorem
 */
template <class T, int R>
Wektor<T, R> operator*(T l, const Wektor<T, R> &W2);

/**
 * @brief Zmiana znaków elementów wektora na przeciwne
 * 
 * @param W2 wektor
 * @return Wektor wejściowy wektor z przeciwnymi znakami
 */
template <class T, int R>
Wektor<T, R> operator-(const Wektor<T, R> &W2);

/**
 * @brief Wczytanie wartości do wektora
 * 
 * @param strm strumień wejściowy
 * @param W wektor do którego wprowadza się wartości
 * @return std::istream& strumień podany na wejściu 
 */
template <class T, int R>
std::istream &operator>>(std::istream &strm, Wektor<T, R> &W);

/**
 * @brief Wypisanie wartości z wektora
 * 
 * @param strm strumień wyjściowy
 * @param M wektor do wypisania
 * @return std::ostream& strumień podany na wejściu
 */
template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const Wektor<T, R> &W);


/* 

DEFINICJE METOD I FUNKCJI

*/

template <class T, int R>
Wektor<T, R>::Wektor()
{
  for (int i = 0; i < R; i++)
    (*this)[i] = 0;
}

template <class T, int R>
Wektor<T, R>::Wektor(T tablica[])
{
  for (int i = 0; i < R; i++)
    (*this)[i] = tablica[i];
}

template <class T, int R>
Wektor<T, R> Wektor<T, R>::operator+(const Wektor<T, R> &W2) const
{
  Wektor<T, R> Suma;

  for (int i = 0; i < R; i++)
    Suma[i] = (*this)[i] + W2[i];

  return Suma;
}

template <class T, int R>
Wektor<T, R> Wektor<T, R>::operator-(const Wektor<T, R> &W2) const
{
  Wektor<T, R> Roznica;
  for (int i = 0; i < R; i++)
    Roznica[i] = (*this)[i] - W2[i];

  return Roznica;
}

template <class T, int R>
T Wektor<T, R>::operator*(const Wektor<T, R> &W2) const
{
  T iloczyn = 0;

  for (int i = 0; i < R; i++)
    iloczyn += (*this)[i] * W2[i];

  return iloczyn;
}

template <class T, int R>
Wektor<T, R> Wektor<T, R>::operator*(T l) const
{
  Wektor<T, R> Iloczyn;

  for (int i = 0; i < R; i++)
    Iloczyn[i] = (*this)[i] * l;

  return Iloczyn;
}

template <class T, int R>
Wektor<T, R> Wektor<T, R>::operator/(T l) const
{
  Wektor<T, R> Iloraz;

  if (l == 0)
    throw(std::invalid_argument("Próba dzielenia przez 0"));

  for (int i = 0; i < R; i++)
    Iloraz[i] = (*this)[i] / l;

  return Iloraz;
}

template <class T, int R>
const Wektor<T, R> &Wektor<T, R>::operator+=(const Wektor<T, R> &W2)
{
  for (int i = 0; i < R; i++)
    (*this)[i] += W2[i];

  return *this;
}

template <class T, int R>
const Wektor<T, R> &Wektor<T, R>::operator-=(const Wektor<T, R> &W2)
{
  for (int i = 0; i < R; i++)
    (*this)[i] -= W2[i];

  return *this;
}

template <class T, int R>
bool Wektor<T, R>::operator==(const Wektor<T, R> &W2) const
{
  for (int i = 0; i < R; i++)
  {
    if (abs((*this)[i] - W2[i]) > 0.000001)
      return false;
  }

  return true;
}

template <class T, int R>
bool Wektor<T, R>::operator!=(const Wektor<T, R> &W2) const
{
  return !(*this == W2);
}

template <class T, int R>
T Wektor<T, R>::operator[](int index) const
{
  if (index < 0 || index >= R)
    throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

  return this->m_tab[index];
}

template <class T, int R>
T &Wektor<T, R>::operator[](int index)
{
  if (index < 0 || index >= R)
    throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

  return this->m_tab[index];
}

template <class T, int R>
double Wektor<T, R>::dlugosc() const
{
  double dl = 0;

  for (int i = 0; i < R; i++)
    dl += pow((*this)[i], 2);
  return sqrt(dl);
}

template<>
double Wektor<LZespolona, ROZMIAR>::dlugosc() const
{
  LZespolona dl;

  for (int i = 0; i < ROZMIAR; i++)
    dl += (*this)[i] * Sprzezenie((*this)[i]);
  return sqrt(Modul(dl));
}


template <class T, int R>
Wektor<T, R> operator*(T l, const Wektor<T, R> &W2)
{
  return W2 * l;
}

template <class T, int R>
Wektor<T, R> operator-(const Wektor<T, R> &W2)
{
  Wektor<T, R> Zmiana;

  for (int i = 0; i < R; i++)
    Zmiana[i] = -W2[i];

  return Zmiana;
}

template <class T, int R>
std::istream &operator>>(std::istream &strm, Wektor<T, R> &W)
{
  for (int i = 0; i < R; i++)
    strm >> W[i];

  return strm;
}

template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const Wektor<T, R> &W)
{
  for (int i = 0; i < R; i++)
    strm << W[i] << " ";

  return strm;
}

#endif