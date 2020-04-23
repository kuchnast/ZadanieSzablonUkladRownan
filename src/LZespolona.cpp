#include <iostream>
#include <math.h>

#include "LZespolona.hh"

using std::cin;
using std::cout;
using std::endl;
using std::noshowpos;
using std::showpos;

LZespolona::LZespolona(double R){
  (*this) = R;
}

LZespolona &LZespolona::operator=(double C)
{
  (*this).re = C;
  (*this).im = 0;

  return *this;
}
 
LZespolona operator+(LZespolona L1, LZespolona L2)
{
  LZespolona Wynik;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

LZespolona operator-(LZespolona L1, LZespolona L2)
{
  LZespolona Roznica;

  Roznica.re = L1.re - L2.re;
  Roznica.im = L1.im - L2.im;
  return Roznica;
}

LZespolona operator-(LZespolona L1){
  LZespolona Znak;

  Znak.re = -L1.re;
  Znak.im = -L1.im;
  return Znak;
}

LZespolona operator*(LZespolona L1, LZespolona L2)
{
  LZespolona Iloczyn;

  Iloczyn.re = L1.re * L2.re - L1.im * L2.im;
  Iloczyn.im = L1.re * L2.im + L1.im * L2.re;
  return Iloczyn;
}

LZespolona operator*(LZespolona L1, double R){
  LZespolona Temp(R);

  return L1 * Temp;
}

LZespolona operator*(double R, LZespolona L1){
  return L1 * R;
}

LZespolona operator/(LZespolona L1, double R)
{
  LZespolona Iloraz;
  if (R == 0)
    throw(std::invalid_argument("Próba dzielenia przez 0"));

  Iloraz.re = L1.re / R;
  Iloraz.im = L1.im / R;

  return Iloraz;
}

LZespolona operator/(LZespolona L1, LZespolona L2)
{
  if (L2 == 0)
    throw(std::invalid_argument("Próba dzielenia przez 0"));

  return (L1 * Sprzezenie(L2)) / pow(Modul(L2), 2);
}

LZespolona &operator+=(LZespolona &L1, LZespolona L2){
  L1.re += L2.re;
  L1.im += L2.re;

  return L1;
}

LZespolona &operator-=(LZespolona &L1, LZespolona L2){
  L1.re -= L2.re;
  L1.im -= L2.re;

  return L1;
}

bool operator==(LZespolona L1, LZespolona L2)
{
  if (abs(L1.re - L2.re) > 0.000001 || abs(L1.im - L2.im) > 0.000001)
    return false;

  return true;
}

bool operator!=(LZespolona L1, LZespolona L2)
{
  return !(L1 == L2);
}

bool operator==(LZespolona L, double R)
{
  LZespolona Temp(R);

  return L == Temp;
}

bool operator!=(LZespolona L, double R)
{
  return !(L == R);
}

double Modul(LZespolona L1)
{
  return sqrt(pow(L1.re, 2) + pow(L1.im, 2));
}

LZespolona Sprzezenie(LZespolona L1)
{
  LZespolona Temp;

  Temp.re = L1.re;
  Temp.im = -L1.im;
  return Temp;
}

LZespolona Utworz(double re, double im)
{
  LZespolona Nowa;

  Nowa.re = re;
  Nowa.im = im;
  return Nowa;
}

std::istream &operator>>(std::istream &strm, LZespolona &L)
{
  char znak;
  double liczba;

  strm >> znak;
  if (znak != '(') //sprawdzenie czy pierwszy znak to nawias
    strm.setstate(std::ios::failbit);

  znak = strm.peek(); //podejzyj nastepny znak
  if (znak == '-')
  { //(1)pierwszy znak to minus
    strm >> znak;
    znak = strm.peek();
    if (znak == 'i')
    { //(2)drugi znak to i czyli to liczba -i
      strm >> znak;
      L.re = 0;
      L.im = -1;
    }
    else if (isdigit(znak))
    { //(2)drugi znak to cyfra, wiec wczytaj liczbe
      strm >> liczba >> znak;
      if (znak == ')')
      { //(3)znak po liczbie to nawias, wiec wczytano -re
        L.re = -liczba;
        L.im = 0;
        return strm;
      }
      else if (znak == 'i')
      { //(3)znak po liczbie to i, wiec wczytano -im
        L.re = 0;
        L.im = -liczba;
      }
      else if (znak == '-')
      { //(3)znak po liczbie to -, wiec czytaj dalej
        L.re = -liczba;
        znak = strm.peek();
        if (znak == 'i')
        { //(4)dalej jest i, wiec wczytano -re-i
          strm >> znak;
          L.im = -1;
        }
        else if (isdigit(znak))
        { //(4)dalej jest cyfra, wiec wczytano -re-im
          strm >> L.im >> znak;
          L.im = -L.im;
          if (znak != 'i') //(5)jesli po liczbie nie ma i, zwroc blad
            strm.setstate(std::ios::failbit);
        }
        else
        { //(4)jesli cos innego, zwroc blad
          strm.setstate(std::ios::failbit);
        }
      }
      else if (znak == '+')
      { //(3)znak po liczbie to +, wiec czytaj dalej
        L.re = -liczba;
        znak = strm.peek();
        if (znak == 'i')
        { //(4)dalej jest i, wiec wczytano -re+i
          strm >> znak;
          L.im = 1;
        }
        else if (isdigit(znak))
        { //(4)dalej jest cyfra, wiec wczytano -re+im
          strm >> L.im >> znak;
          if (znak != 'i') //(5)jesli po liczbie nie ma i, zwroc blad
            strm.setstate(std::ios::failbit);
        }
        else
        { //(4)jesli cos innego, zwroc blad
          strm.setstate(std::ios::failbit);
        }
      }
      else
      { //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else
    { //(2)jesli cos innego, zwroc blad
      strm.setstate(std::ios::failbit);
    }
  }
  else if (znak == 'i')
  { //(1)pierwszy znak to i, wiec wczytano i
    strm >> znak;
    L.re = 0;
    L.im = 1;
  }
  else if (isdigit(znak))
  { //(1)pierwszy znak to cyfra, wiec wczytaj liczbe
    strm >> liczba >> znak;
    if (znak == ')')
    { //(2)drugi znak to ), wiec wczytano re
      L.re = liczba;
      L.im = 0;
      return strm;
    }
    else if (znak == 'i')
    { //(2)drugi znak to i, wiec wczytano im
      L.re = 0;
      L.im = liczba;
    }
    else if (znak == '-')
    { //(2)drugi znak to -, wiec czytaj dalej
      L.re = liczba;
      znak = strm.peek();
      if (znak == 'i')
      { //(3)kolejny znak to i, wiec wczytano re-i
        strm >> znak;
        L.im = -1;
      }
      else if (isdigit(znak))
      { //(3)kolejny znak to cyfra, wiec wczytano re-im
        strm >> L.im >> znak;
        L.im = -L.im;
        if (znak != 'i') //(4)jesli po liczbie nie ma i, zwroc blad
          strm.setstate(std::ios::failbit);
      }
      else
      { //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else if (znak == '+')
    { //(2)drugi znak to -, wiec czytaj dalej
      L.re = liczba;
      znak = strm.peek();
      if (znak == 'i')
      { //(3)kolejny znak to i, wiec wczytano re+i
        strm >> znak;
        L.im = 1;
      }
      else if (isdigit(znak))
      { //(3)kolejny znak to cyfra, wiec wczytano re+im
        strm >> L.im >> znak;
        if (znak != 'i') //(4)jesli po liczbie nie ma i, zwroc blad
          strm.setstate(std::ios::failbit);
      }
      else
      { //(3)jesli cos innego, zwroc blad
        strm.setstate(std::ios::failbit);
      }
    }
    else
    { //(2)jesli cos innego, zwroc blad
      strm.setstate(std::ios::failbit);
    }
  }
  else
  { //(1)jesli cos innego, zwroc blad
    strm.setstate(std::ios::failbit);
  }

  strm >> znak;    //wczytaj kolejny znak
  if (znak != ')') //jesli jest to ), znaczy ze koniec liczby
    strm.setstate(std::ios::failbit);

  return strm;
}

std::ostream &operator<<(std::ostream &strm, const LZespolona &L)
{
  strm << '(';

  if (L.re != 0)
  { //jesli czesc rzeczywista jest rozna od 0, wypisz ja
    strm << L.re;
  }

  if (L.im != 0)
  { //jesli czesc urojona jest rozna od 0, wypisz jej odpowiednia wersje
    if (L.im == 1)
    {
      if (L.re == 0) //jesli czesc urojona byla rowna 1, a rzeczywista rowna 0, wypisz i
        strm << "i";
      else //jesli czesc urojona byla rowna 1, a rzeczywista rozna od 0, wypisz +i
        strm << "+i";
    }
    else if (L.im == -1)
    { //jesli czesc urojona byla rowna -1, wypisz -i
      strm << "-i";
    }
    else
    {
      if (L.re != 0) //jesli czesc urojona byla inna liczba rozna od 0, a rzeczywista rozna od 0, wypisz ja z ew. +
        strm << showpos << L.im << noshowpos << 'i';
      else //jesli czesc urojona byla inna liczba rozna od 0, a rzeczywista rowna 0, wypisz ja bez ew. +
        strm << L.im << 'i';
    }
  }
  else
  {
    if (L.re == 0) //jesli czesc rzeczywista i zespolona sa rowne 0, wypisz 0
      strm << 0;
  }

  strm << ')';

  return strm;
}