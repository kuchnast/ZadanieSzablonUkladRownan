#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <iomanip>
#include <math.h>
#include "MacierzKw.hh"
#include "Wektor.hh"

using std::cin;
using std::cout;
using std::endl;
using std::setw;

/**
 * @brief Klasa realizuje pojęcie układu równań liniowych
 * @details Układ równań liniowych opisywany jest przy użyciu kwadratowej macierzy współczynników
 *          wektora wyrazów wolnych oraz wyliczonego wektora rozwiązań.
 */
 template <class T, int R>
class UkladRownanLiniowych {
  Wektor<T, R> m_b; ///< Wektor wyrazów wolnych
  Wektor<T, R> m_x; ///< Wektor rozwiązań
  MacierzKw<T, R> m_A; ///< Macierz współczynników

public:
/**
 * @brief Konstruktor nowego obiektu Uklad Rownan Liniowych
 * 
 */
  UkladRownanLiniowych() = default;

/**
 * @brief Konstruktor nowego obiektu Uklad Rownan Liniowych
 * 
 * @param M Macierz współczynników
 * @param W Wektor wyrazów wolnych
 */
  UkladRownanLiniowych(const MacierzKw<T, R> M, const Wektor<T, R> W);

/**
 * @brief Przekazuje wektor wyrazów wolnych
 * 
 * @return const Wektor& wektor wyrazów wolnych
 */
  const Wektor<T, R> &PrzekazB() const;

/**
 * @brief Przekazuje wektor rozwiązań
 * 
 * @return const Wektor& wektor rozwiązań
 */
  const Wektor<T, R> &PrzekazX() const;

/**
 * @brief Przekazuje macierz współczynników
 * 
 * @return const MacierzKw& macierz współczynników
 */
  const MacierzKw<T, R> &PrzekazA() const;

/**
 * @brief Oblicza wektor rozwiązań układu równań metodą macierzy odwrotnej
 * 
 */
  void ObliczMacierzOdwrotna();

/**
 * @brief Oblicza wektor rozwiązań układu równań metodą Cramera
 * 
 */
  void ObliczCramer();

  /**
 * @brief Oblicza wektor błędu 
 *        wynikający z ograniczeń przetwarzania liczb zmiennoprzecinkowych
 * 
 * @return Wektor wektor błędu
 */
  Wektor<T, R> WektorBledu() const;

/**
 * @brief Wyświetla układ równań, wektor błędu oraz długość wektora błędu z odpowiednim nagłówkiem
 * 
 * @param nazwa nazwa wyświetlana u góry wyników
 */
  void WyswietlUkladBlad(const std::string &nazwa) const;
};

/**
 * @brief Wczytuje macierz współczynników oraz wektor wyrazów wolnych w postaci transponowanej
 * 
 * @param strm strumień wejściowy
 * @param UklRown układ równań
 * @return std::istream& referencja do strumienia wejściowego
 */
template <class T, int R>
std::istream &operator>>(std::istream &strm, UkladRownanLiniowych<T, R> &UklRown);

/**
 * @brief Wyświetla układ równań 
 *        w postaci macierz, wektor rozwiązań, wektor wyrazów wolnych
 * 
 * @param strm strumień wyjściowy
 * @param UklRown układ równań
 * @return std::ostream& referencja do strumienia wyjściowego
 */
template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych<T, R> &UklRown);

/* 

DEFINICJE METOD I FUNKCJI

*/

template <class T, int R>
UkladRownanLiniowych<T, R>::UkladRownanLiniowych(const MacierzKw<T, R> M, const Wektor<T, R> W)
{
  m_A = M;
  m_b = W;
}

template <class T, int R>
const Wektor<T, R> &UkladRownanLiniowych<T, R>::PrzekazB() const
{
  return m_b;
}

template <class T, int R>
const Wektor<T, R> &UkladRownanLiniowych<T, R>::PrzekazX() const
{
  return m_x;
}

template <class T, int R>
const MacierzKw<T, R> &UkladRownanLiniowych<T, R>::PrzekazA() const
{
  return m_A;
}

template <class T, int R>
void UkladRownanLiniowych<T, R>::ObliczMacierzOdwrotna()
{
  MacierzKw<T, R> OdwA = this->m_A;
  this->m_x = OdwA.odwroc() * this->m_b;
}

template <class T, int R>
void UkladRownanLiniowych<T, R>::ObliczCramer()
{
  MacierzKw<T, R> tempA = this->m_A;
  Wektor<T, R> tempWiersz;
  double detA = tempA.wyznacznik();

  if (abs(detA) < 0.000001)
    throw(std::runtime_error("Wyznacznik jest równy 0."));

  tempA.transponuj();
  for (int i = 0; i < R; ++i)
  {
    tempWiersz = tempA[i];
    tempA[i] = this->m_b;
    this->m_x[i] = tempA.wyznacznik() / detA;
    tempA[i] = tempWiersz;
  }
}

template <class T, int R>
Wektor<T, R> UkladRownanLiniowych<T, R>::WektorBledu() const
{
  return this->m_A * this->m_x - this->m_b;
}

template <class T, int R>
void UkladRownanLiniowych<T, R>::WyswietlUkladBlad(const std::string &nazwa) const
{
  Wektor<T, R> Blad = (*this).WektorBledu();

  cout << endl
       << "====== " << nazwa << " ======" << endl;
  cout << "Rozwiązanie: " << endl
       << *this << endl;
  cout << std::scientific << std::setprecision(2);
  cout << "Wektor błędu: " << endl
       << Blad << endl;
  cout << std::defaultfloat;
  cout << "Długość wektora błędu: " << Blad.dlugosc() << endl;
}

template <class T, int R>
std::istream &operator>>(std::istream &strm, UkladRownanLiniowych<T, R> &UklRown)
{
  MacierzKw<T, R> M;
  Wektor<T, R> W;

  strm >> M >> W;
  UkladRownanLiniowych<T, R> Temp(M.transponuj(), W);
  UklRown = Temp;

  return strm;
}

template <class T, int R>
std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych<T, R> &UklRown)
{
  cout << std::setprecision(4) << std::left;
  for (int i = 0; i < R; i++)
  {
    strm << "| " << UklRown.PrzekazA()[i] << " | | " << setw(8) << UklRown.PrzekazX()[i] << " |";
    if (i == R / 2)
      strm << " = ";
    else
      strm << "   ";
    strm << "| " << setw(8) << UklRown.PrzekazB()[i] << " |" << endl;
  }

  return strm;
}

#endif
