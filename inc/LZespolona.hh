#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/**
  * @brief Struktura modeluje pojecie liczby zespolonej
  * 
  */
struct LZespolona
{
  double re; ///< Część rzeczywista liczby zespolonej
  double im; ///< Część urojona liczby zespolonej

/**
 * @brief Domyślny konstruktor nowego obiektu LZespolona
 * 
 */
  LZespolona();

/**
 * @brief Konstruktor nowego obiektu LZespolona z przypisaniem do niego liczby rzeczywistej
 * 
 * @param R liczba rzeczywista
 */
  LZespolona(double R);

/**
 * @brief Przypisanie liczby rzeczywistej do zespolonej
 * 
 * @param R liczba rzeczywista
 * @return LZespolona& zmieniona liczba zespolona
 */
  LZespolona &operator=(double R);
};

/**
  * @brief Dodawanie dwóch liczb zespolonych
  * 
  * @param L1 pierwszy składnik
  * @param L2 drugi skłądnik
  * @return LZespolona suma liczb zespolonych będąca liczbą zespoloną
  */
LZespolona operator+(LZespolona L1, LZespolona L2);

/**
 * @brief Odejmowanie dwóch liczb zespolonych
 * 
 * @param L1 odjemna
 * @param L2 odjemnik
 * @return LZespolona różnica dwóch liczb zespolonych będąca liczbą zespoloną
 */
LZespolona operator-(LZespolona L1, LZespolona L2);

/**
 * @brief Zmiana znaku liczby zespolonej na przeciwny
 * 
 * @param L1 liczba zespolona
 * @return LZespolona liczbę zespoloną z przeciwnymi znakami obu składowych
 */
LZespolona operator-(LZespolona L1);

/**
 * @brief Mnożenie dwóch liczb zespolonych
 * 
 * @param L1 pierwszy czynnik
 * @param L2 drugi czynnik 
 * @return LZespolona iloczyn dwóch liczb zespolonych będący liczbą zespoloną
 */
LZespolona operator*(LZespolona L1, LZespolona L2);

/**
 * @brief Mnożenie liczby zespolonej i rzeczywistej
 * 
 * @param L1 pierwszy czynnik
 * @param R drugi czynnik
 * @return LZespolona iloczyn liczby zespolonej i rzeczywistej będący liczbą zespoloną
 */
LZespolona operator*(LZespolona L1, double R);

/**
 * @brief Mnożenie liczby rzeczywistej i zespolonej
 * 
 * @param L1 pierwszy czynnik
 * @param R drugi czynnik
 * @return LZespolona iloczyn liczby rzeczywistej i zespolonej będący liczbą zespoloną
 */
LZespolona operator*(double R, LZespolona L1);

/**
 * @brief Dzielenie liczby zespolonej przez rzeczywistą
 * 
 * @exception std::invalid_argument w przypadku próby dzielenia przez 0
 * @param L1 dzielna
 * @param R  dielnik
 * @return LZespolona iloraz liczby zespolonej przez rzeczywistą będący liczbą zespoloną
 */
LZespolona operator/(LZespolona L1, double R);

/**
 * @brief Dzielenie dwóch liczb zespolonych
 * 
 * @exception std::invalid_argument w przypadku próby dzielenia przez 0
 * @param L1 dielna
 * @param L2 dzielnik
 * @return LZespolona iloraz dwóch liczb zespolonych będący liczbą zespoloną
 */
LZespolona operator/(LZespolona L1, LZespolona L2);

/**
 * @brief Dodawanie z przypisaniem dwóch liczb zespolonych
 * 
 * @param L1 pierwszy składnik
 * @param L2 drugi skłądnik
 * @return LZespolona& suma dwóch liczb zespolonych jako zmieniony pierwszy składnik
 */
LZespolona &operator+=(LZespolona &L1, LZespolona L2);

/**
 * @brief Odejmowanie z przypisaniem dwóch liczb zespolonych
 * 
 * @param L1 odjemna
 * @param L2 odjemnik
 * @return LZespolona& różnica dwóch liczb zespolonych jako zmieniona odmienna
 */
LZespolona &operator-=(LZespolona &L1, LZespolona L2);

/**
 * @brief Mnożenie z przypisaniem dwóch liczb zespolonych
 * 
 * @param L1 pierwszy czynnik
 * @param L2 drugi czynnik
 * @return LZespolona& iloczyn dwóch liczb zespolonych jako zmieniona odmienna
 */
LZespolona &operator*=(LZespolona &L1, LZespolona L2);

/**
 * @brief Porównanie dwóch liczb zespolonych
 * 
 * @param L1 pierwsza liczba
 * @param L2 druga liczba
 * @return true jeżeli liczby są równe
 * @return false jeżeli liczby są różne
 */
bool operator==(LZespolona L1, LZespolona L2);

/**
 * @brief Porównanie dwóch liczb zespolonych
 * 
 * @param L1 pierwsza liczba
 * @param L2 druga liczba
 * @return true jeżeli liczby są różne
 * @return false jeżeli liczby są równe
 */
bool operator!=(LZespolona L1, LZespolona L2);

/**
 * @brief Porównanie liczby zespolonej i rzeczywistej
 * 
 * @param L1 pierwsza liczba
 * @param R druga liczba
 * @return true jeżeli liczby są równe
 * @return false jeżeli liczby są różne
 */
bool operator==(LZespolona L, double R);

/**
 * @brief Porównanie liczby zespolonej i rzeczywistej
 * 
 * @param L1 pierwsza liczba
 * @param R druga liczba
 * @return true jeżeli liczby są różne
 * @return false jeżeli liczby są równe
 */
bool operator!=(LZespolona L, double R);

/**
 * @brief Moduł z liczby zespolonej
 * 
 * @param L1 liczba zespolona
 * @return double moduł liczby zespolonej będący liczbą rzeczywistą
 */
double Modul(LZespolona L1);

/**
 * @brief Sprzężenie liczby zespolonej
 * 
 * @param L1 liczba zespolona
 * @return LZespolona sprzężenie liczby zespolonej będące liczbą zespoloną
 */
LZespolona Sprzezenie(LZespolona L1);

/**
 * @brief Tworzy nową liczbę zespoloną z dwóch części
 * 
 * @param re część rzeczywista
 * @param im część urojona
 * @return LZespolona liczbę zespoloną powstałą z części z wejścia
 */
LZespolona Utworz(double re, double im);

/**
 * @brief Wczytywanie liczby zespolonej w skróconej formie z nawiasami
 * 
 * @param strm strumień wejściowy
 * @param L liczba na wczytywanie
 * @return std::istream& strumień z wejścia
 */
std::istream &operator>>(std::istream &strm, LZespolona &L);

/**
 * @brief Wypoisanie liczby zespolonej w skróconej formie z nawiasami
 * 
 * @param strm strumień wyjściowy
 * @param L liczba do wypisania
 * @return std::ostream& strumień z wejścia
 */
std::ostream &operator<<(std::ostream &strm, const LZespolona &L);

#endif
