#ifndef MACIERZ_KW_HH
#define MACIERZ_KW_HH

#include "Wektor.hh"
#include <iostream>
#include <math.h>

/**
 * @brief Klasa modeluje pojęcie macierzy kwadratowej złożonej z tablicy wektorów
 * 
 */
template <class T, int R>
class MacierzKw
{
  Wektor<T, R> m_macierz[R]; ///< Tablica wektorów

public:

/**
 * @brief Konstruktor nowego obiektu Macierz Kwadratowa
 * 
 */
  MacierzKw() = default;

/**
 * @brief Konstruktor nowego obiektu Macierz Kw inicjujący go tablicą wektorów
 * 
 * @param macierz tablica wektorów
 */
  MacierzKw(const Wektor<T, R> macierz[]);

/**
 * @brief Dodawania dwóch macierzy kwadratowych
 * 
 * @param M2 druga macierz - składnik
 * @return MacierzKw suma dwóch macierzy będąca macierzą
 */
  MacierzKw operator+(const MacierzKw &M2) const;

/**
 * @brief Odejmowanie dwóch macierzy kwadratowych
 * 
 * @param M2 druga macierz - odjemnik
 * @return MacierzKw Różnica dwóch macierzy będąca macierzą
 */
  MacierzKw operator-(const MacierzKw &M2) const;

/**
 * @brief Mnożenie dwóch macierzy kwadratowych
 * @details metodą współczynniki - wektory
 * 
 * @param M2 druga macierz - czynnik
 * @return MacierzKw iloczyn dwóch macierzy będący macierzą
 */
  MacierzKw operator*(const MacierzKw &M2) const;

/**
 * @brief Mnożenie macierzy kwadratowej i skalara
 * 
 * @param l skalar - czynnik
 * @return MacierzKw iloczyn macierzy i skalara będący macierzą
 */
  MacierzKw operator*(T l) const;

/**
 * @brief Mnożenie macierzy kwadratowej i wektora
 * 
 * @param W2 wektor - czynnik
 * @return Wektor iloczyn macierzy i wektora będący wektorem
 */
  Wektor<T, R> operator*(const Wektor<T, R> &W2) const;

/**
 * @brief Dzielenie macierzy kwadratowej przez skalar
 * 
 * @exception std::invalid_argument próba dzielenia przez 0
 * @param l skalar - dzielnik
 * @return MacierzKw iloraz macierzy i skalara będący macierzą
 */
  MacierzKw operator/(T l) const;

/**
 * @brief Dostęp do elementu tablicy w celu odczytu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return const Wektor& R-wartość elementu macierzy
 */
  const Wektor<T, R> &operator[](int index) const;

/**
 * @brief Dostęp do elementu tablicy w celu zapisu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return Wektor& L-wartość elementu macierzy
 */
  Wektor<T, R> &operator[](int index);

/**
 * @brief Transponowanie macierzy kwadratowej
 * 
 * @return const MacierzKw& transponowana macierz z wejścia
 */
  const MacierzKw &transponuj();

/**
 * @brief Wyznacznik macierzy kwadratowej obliczany metodą Gaussa
 * 
 * @exception std::runtime_error wyznacznik jest równy 0
 * @return T wyznacznik macierzy
 */
  T wyznacznik() const;

/**
 * @brief Odwracanie macierzy kwadratowej metodą Gaussa-Jordana
 * 
 * @return const MacierzKw& odwrócona macierz wejściowa
 */
  const MacierzKw &odwroc();
};

/**
 * @brief Mnożenie skalara i macierzy kwadratowej
 * 
 * @param l skalar - czynnik
 * @param M2 macierz - czynnik
 * @return const MacierzKw iloczyn skalara i macierzy będący macierzą
 */
template <class T, int R>
MacierzKw<T, R> operator*(T l, const MacierzKw<T, R> &M2);

/**
 * @brief Wczytanie wartości do macierzy
 * 
 * @param strm strumień wejściowy
 * @param M macierz do której wprowadza się wartości
 * @return std::istream& strumień podany na wejściu 
 */
template <class T, int R>
std::istream &operator>>(std::istream &strm, MacierzKw<T, R> &M);

/**
 * @brief Wypisanie wartości z macierzy
 * 
 * @param strm strumień wyjściowy
 * @param M macierz do wypisania
 * @return std::ostream& strumień podany na wejściu
 */
template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const MacierzKw<T, R> &M);

/* 

DEFINICJE METOD I FUNKCJI

*/

template <class T, int R>
MacierzKw<T, R>::MacierzKw(const Wektor<T, R> macierz[])
{
  for (int i = 0; i < R; i++)
    (*this)[i] = macierz[i];
}

template <class T, int R>
MacierzKw<T, R> MacierzKw<T, R>::operator+(const MacierzKw<T, R> &M2) const
{
  MacierzKw<T, R> Suma;

  for (int i = 0; i < R; i++)
    Suma[i] = (*this)[i] + M2[i];

  return Suma;
}

template <class T, int R>
MacierzKw<T, R> MacierzKw<T, R>::operator-(const MacierzKw<T, R> &M2) const
{
  MacierzKw<T, R> Roznica;

  for (int i = 0; i < R; i++)
    Roznica[i] = (*this)[i] - M2[i];

  return Roznica;
}

template <class T, int R>
MacierzKw<T, R> MacierzKw<T, R>::operator*(const MacierzKw<T, R> &M2) const
{
  MacierzKw<T, R> Iloczyn;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < R; j++)
      Iloczyn[i] += (*this)[i][j] * M2[j];

  return Iloczyn;
}

template <class T, int R>
MacierzKw<T, R> MacierzKw<T, R>::operator*(T l) const
{
  MacierzKw<T, R> Iloczyn;

  for (int i = 0; i < R; i++)
    Iloczyn[i] = (*this)[i] * l;

  return Iloczyn;
}

template <class T, int R>
Wektor<T, R> MacierzKw<T, R>::operator*(const Wektor<T, R> &W2) const
{
  Wektor<T, R> Iloczyn;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < R; j++)
      Iloczyn[i] += (*this)[i][j] * W2[j];

  return Iloczyn;
}

template <class T, int R>
MacierzKw<T, R> MacierzKw<T, R>::operator/(T l) const
{
  MacierzKw<T, R> Iloraz;

  if (l == 0)
    throw(std::invalid_argument("Próba dzielenia przez 0"));

  for (int i = 0; i < R; i++)
    Iloraz[i] = (*this)[i] / l;

  return Iloraz;
}

template <class T, int R>
const Wektor<T, R> &MacierzKw<T, R>::operator[](int index) const
{
  if (index < 0 || index >= R)
    throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

  return this->m_macierz[index];
}

template <class T, int R>
Wektor<T, R> &MacierzKw<T, R>::operator[](int index)
{
  if (index < 0 || index >= R)
    throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

  return this->m_macierz[index];
}

template <class T, int R>
const MacierzKw<T, R> &MacierzKw<T, R>::transponuj()
{
  MacierzKw<T, R> Temp = (*this);

  for (int i = 0; i < R; i++)
    for (int j = 0; j < R; j++)
      (*this)[i][j] = Temp[j][i];

  return (*this);
}

template <class T, int R>
T MacierzKw<T, R>::wyznacznik() const
{
  int i, j;
  MacierzKw<T, R> Wyz = (*this);
  T temp = 1;

  for (i = 0; i < R; i++)
  { //petla kolejnych elementów z przekątnej
    if (Wyz[i][i] == 0)
    { //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
      j = i;
      while (Wyz[j][i] == 0)
      {
        if (++j == R)
          return 0; //macierz jest osobliwa
      }
      Wyz[i] = Wyz[j];
      Wyz[j] = -(*this)[i];
    }

    for (j = i + 1; j < R; j++)
    { //petla zerowania kolejnych kolumn
      Wyz[j] += (-Wyz[j][i] / Wyz[i][i]) * Wyz[i];
      if (Wyz[j].dlugosc() == 0)
        return 0;
    }
    temp *= Wyz[i][i];
  }
  return temp;
}

template <class T, int R>
const MacierzKw<T, R> &MacierzKw<T, R>::odwroc()
{
  int i, j;
  T mnoznik;
  MacierzKw<T, R> OdwA, A = (*this);

  for (i = 0; i < R; i++)
  {
    OdwA[i][i] = 1;
  }

  for (i = 0; i < R; i++)
  { //petla dla części pod przekątną
    if (A[i][i] == 0)
    { //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
      j = i;
      while (A[j][i] == 0)
      {
        if (++j == R)
          throw(std::runtime_error("Macierz jest osobliwa."));
      }
      std::swap(A[i], A[j]);
      std::swap(OdwA[i], OdwA[j]);
    }

    OdwA[i] = OdwA[i] / A[i][i];
    A[i] = A[i] / A[i][i];

    for (j = i + 1; j < R; j++)
    { //petla zerowania kolejnych kolumn
      mnoznik = -A[j][i] / A[i][i];
      A[j] += mnoznik * A[i];
      OdwA[j] += mnoznik * OdwA[i];
    }
  }

  for (i = R - 1; i > 0; i--)
  { //petla dla części nad przekątną
    for (j = i - 1; j >= 0; j--)
    { //petla zerowania kolejnych kolumn
      OdwA[j] -= A[j][i] * OdwA[i];
      A[j] -= A[j][i] * A[i];
    }
  }
  (*this) = OdwA;

  return (*this);
}

template <class T, int R>
MacierzKw<T, R> operator*(T l, const MacierzKw<T, R> &M2)
{
  return M2 * l;
}

template <class T, int R>
std::istream &operator>>(std::istream &strm, MacierzKw<T, R> &M)
{
  for (int i = 0; i < R; i++)
    strm >> M[i];

  return strm;
}

template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const MacierzKw<T, R> &M)
{

  for (int i = 0; i < R; i++)
    strm << M[i] << std::endl;

  return strm;
}

#endif
