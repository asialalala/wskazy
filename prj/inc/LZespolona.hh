#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
private:
  double   re;    /* Pole repezentuje czesc rzeczywista. */
  double   im;    /* Pole repezentuje czesc urojona. */
public:
  void Re (double _re);
  void Im (double _im);
  LZespolona();
  LZespolona(double _re, double _im);
  LZespolona(const LZespolona & _LZesp);
  double Re()const;
  double Im() const;
  LZespolona operator + ( const LZespolona&  Skl2)const;
  LZespolona operator - (const LZespolona&  Skl2)const;
  LZespolona operator * ( const LZespolona&  Skl2)const;
  LZespolona Sprzezenie();
  double Modul2()const;
  LZespolona operator / (LZespolona  Skl2)const;
  bool operator == (const LZespolona& Poprawna)const;
  LZespolona operator *=(LZespolona razy);
  LZespolona operator +=(LZespolona dodaj);
  LZespolona operator -=(LZespolona odejmij);
  LZespolona operator /=(LZespolona dzielnik);

};


std::ostream& operator << (std::ostream &StrWej, LZespolona Zesp); 
std::istream& operator >> (std::istream& StrWej, LZespolona &rZesp);
bool SprawdzZnak(std::istream& StrWej, char Znak);


#endif
