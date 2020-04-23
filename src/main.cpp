/** \mainpage Strona główna
 *
 * \section intro_sec Informacje
 *
 * Program po wprowadzeniu macierzy współczynników oraz wektora wyrazów wolnych 
 * oblicza wektor rozwiązań oraz błąd wynikający z niedokładności obliczeń.
 */

#include <iostream>
#include <iomanip>
#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
  char rodzaj;

  cin >> rodzaj;
  switch (rodzaj)
  {
  case 'r':
  {
    UkladRownanLiniowych<double, 3> UklRow[2];

    cout << endl << "Układ równań liniowych o współczynikach rzeczywistych" << endl;

    cout << endl
         << " Start programu " << endl
         << endl;
    cin >> UklRow[0];
    if (!cin.good())
    {
      cout << "Błąd zapisu układu równań." << endl;
      return -1;
    }
    cout << std::setprecision(4) << std::left;
    cout << "Macierz A^T:" << endl
         << UklRow[0].PrzekazA() << endl;
    cout << "Wektor wyrazów wolnych b:" << endl
         << UklRow[0].PrzekazB() << endl;
    UklRow[1] = UklRow[0];

    try
    {
      UklRow[0].ObliczCramer();
      UklRow[1].ObliczMacierzOdwrotna();
    }
    catch (const std::out_of_range &e)
    { //próba dostępu poza tablice
      cout << e.what() << endl;
      cout << "Kończenie pracy programu" << endl;
      return -1;
    }
    catch (const std::invalid_argument &e)
    { //próba dzielenia przez 0
      cout << e.what() << endl;
      cout << "Kończenie pracy programu" << endl;
      return -1;
    }
    catch (const std::runtime_error &e)
    { //wyznacznik równy 0
      cout << e.what() << endl;
      cout << "Układ równań nie ma rozwiązań lub ma ich nieskończenie wiele." << endl;
      return 0;
    }

    UklRow[0].WyswietlUkladBlad("Metoda Cramera");
    UklRow[1].WyswietlUkladBlad("Metoda macierzy odwrotnej");

    break;
  }
  case 'z':
  {
    UkladRownanLiniowych<LZespolona, 3> UklRow[2];

    cout << endl << "Układ równań liniowych o współczynikach zespolonych"<< endl;

    cout << endl
         << " Start programu " << endl
         << endl;
    cin >> UklRow[0];
    if (!cin.good())
    {
      cout << "Błąd zapisu układu równań." << endl;
      return -1;
    }
    cout << std::setprecision(4) << std::left;
    cout << "Macierz A^T:" << endl
         << UklRow[0].PrzekazA() << endl;
    cout << "Wektor wyrazów wolnych b:" << endl
         << UklRow[0].PrzekazB() << endl;
    UklRow[1] = UklRow[0];

    try
    {
      UklRow[0].ObliczCramer();
      UklRow[1].ObliczMacierzOdwrotna();
    }
    catch (const std::out_of_range &e)
    { //próba dostępu poza tablice
      cout << e.what() << endl;
      cout << "Kończenie pracy programu" << endl;
      return -1;
    }
    catch (const std::invalid_argument &e)
    { //próba dzielenia przez 0
      cout << e.what() << endl;
      cout << "Kończenie pracy programu" << endl;
      return -1;
    }
    catch (const std::runtime_error &e)
    { //wyznacznik równy 0
      cout << e.what() << endl;
      cout << "Układ równań nie ma rozwiązań lub ma ich nieskończenie wiele." << endl;
      return 0;
    }

    UklRow[0].WyswietlUkladBlad("Metoda Cramera");
    UklRow[1].WyswietlUkladBlad("Metoda macierzy odwrotnej");
    break;
  }
  default:
  {
    cout << "Podano niewłaściwą opcje." << endl;
    break;
  }
  }

  return 0;
}
