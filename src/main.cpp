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
#include "rozmiar.hh"

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
      UkladRownanLiniowych<double, ROZMIAR> UklRow;

      cout << endl << "Układ równań liniowych o współczynikach rzeczywistych" << endl << endl;

      cin >> UklRow;
      if (!cin.good())
      {
        cout << "Błąd zapisu układu równań." << endl;
        return -1;
      }

      cout << std::fixed << std::setprecision(2);
      cout << "Macierz A^T:" << endl << UklRow.PrzekazA() << endl;
      cout << "Wektor wyrazów wolnych b:" << endl << UklRow.PrzekazB() << endl << endl;

      try
      {
        UklRow.ObliczCramer();
      }
      catch (const std::out_of_range &e) //próba dostępu poza tablice
      { 
        cout << e.what() << endl;
        cout << "Kończenie pracy programu" << endl;
        return -1;
      }
      catch (const std::invalid_argument &e) //próba dzielenia przez 0
      { 
        cout << e.what() << endl;
        cout << "Kończenie pracy programu" << endl;
        return -1;
      }
      catch (const std::runtime_error &e) //wyznacznik równy 0
      { 
        cout << e.what() << endl;
        cout << "Układ równań nie ma rozwiązań lub ma ich nieskończenie wiele." << endl;
        return 0;
      }

      cout << "Rozwiązanie x = (x1";
      for (int i = 2; i <= ROZMIAR; ++i)
        cout << ", x" << i;
      cout << "):" << endl << UklRow.PrzekazX() << endl << endl;

      cout << "Wektor błędu:"<< endl << std::scientific << UklRow.WektorBledu() << endl << endl;
      
      break;
    }
    case 'z':
    {
      UkladRownanLiniowych<LZespolona, ROZMIAR> UklRow;

      cout << endl << "Układ równań liniowych o współczynikach zespolonych"<< endl << endl;

      cin >> UklRow;
      if (!cin.good())
      {
        cout << "Błąd zapisu układu równań." << endl;
        return -1;
      }

      cout << std::fixed << std::setprecision(2);
      cout << "Macierz A^T:" << endl << UklRow.PrzekazA() << endl;
      cout << "Wektor wyrazów wolnych b:" << endl << UklRow.PrzekazB() << endl << endl;

      try
      {
        UklRow.ObliczCramer();
      }
      catch (const std::out_of_range &e) //próba dostępu poza tablice
      { 
        cout << e.what() << endl;
        cout << "Kończenie pracy programu" << endl;
        return -1;
      }
      catch (const std::invalid_argument &e) //próba dzielenia przez 0
      { 
        cout << e.what() << endl;
        cout << "Kończenie pracy programu" << endl;
        return -1;
      }
      catch (const std::runtime_error &e) //wyznacznik równy 0
      { 
        cout << e.what() << endl;
        cout << "Układ równań nie ma rozwiązań lub ma ich nieskończenie wiele." << endl;
        return 0;
      }

      cout << "Rozwiązanie x = (x1";
      for (int i = 2; i <= ROZMIAR; ++i)
        cout << ", x" << i;
      cout << "):" << endl << UklRow.PrzekazX() << endl << endl;

      cout << "Wektor błędu:"<< endl << std::scientific << UklRow.WektorBledu() << endl << endl;
      
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
