#include <iostream>
#include <cmath>
#include <iostream>
#include <assert.h> 
#include "LZespolona.hh"

#define MIN_WART  1e-12 // Na potrzeby sprawdzenia mozliwosci dzielenia przez 0

using namespace std;

/*!
 * Konstruktor bezparametryczny
 */
LZespolona::LZespolona()
{
  Re(0);
  Im(0);
}

/*!
 * Konstruktor parametryczny
 */
LZespolona::LZespolona(double _re, double _im)
{
  Re(_re);
  Im(_im);
}

/*!
 * Konstruktor kopiujacy
 */
LZespolona::LZespolona( const LZespolona & _LZesp)
{
  Re(_LZesp.Re());
  Im(_LZesp.Im());
}


/*!
 * inicjalizuje wartosc re
 */
void LZespolona::Re(double _re)
{
  re = _re;
}

/*!
 * inicjalizuje wartosc im
 */
void LZespolona::Im(double _im)
{
  im = _im;
}


/*!
 * zwraca wartosc re
 */
double LZespolona::Re()const
{
  return re;
}

/*!
 * zwraca wartosc im
 */
double LZespolona::Im() const
{
  return im;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *           Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *        Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator +  (const LZespolona&  Skl2)const
{
  LZespolona  Wynik;

  Wynik.Re(this->Re() + Skl2.Re());
  Wynik.Im(this->Im() + Skl2.Im());
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *           Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *        Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (const LZespolona&  Skl2)const
{
  LZespolona  Wynik;

  Wynik.Re(this->Re() - Skl2.Re());
  Wynik.Im(this->Im() - Skl2.Im());
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *           Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *        Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * (const LZespolona&  Skl2)const
{
  LZespolona  Wynik;

  Wynik.Re(this->Re()*Skl2.Re() - this->Im()*Skl2.Im());
  Wynik.Im(this->Re()*Skl2.Im() + this->Im()*Skl2.Re());
  return Wynik;
}

/*!
 * Realizuje sprzezenie liczby zespolonej
 * Argumenty:
 *            brak
 * Zwraca:
 *        Sprzezenie liczby zespolonej.
 */

LZespolona LZespolona::Sprzezenie()
{
  this->Im(-this->Im());
  return *this;
}

/*!
 * Realizuje modul liczby zespolonej podniesiony do kwadratu
 * Argumenty:
 *           brak
 * Zwraca:
 *        Modul tej liczby podniesiony do kwadratu.
 */

double LZespolona::Modul2()const
{
  return pow(this->Re(),2)+pow(this->Im(),2);
}

/*!
 * Realizuje dzielenie  dwoch liczb zespolonych.
 * Argumenty:
 *           Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *        Iloraz dwoch skladnikow przekazanych jako parametry.
 * PRE: 
 *     modul2 liczby zespolonej Skl2 musi byc rozny od 0. 
 */

LZespolona LZespolona::operator / (LZespolona  Skl2)const
{
  
  LZespolona zespolona;
  double modul2 = Skl2.Modul2();
  zespolona = Skl2.Sprzezenie();
  
  if(modul2 < MIN_WART){
    throw runtime_error("Nie wolno dzielic przez 0.");
  }
  
    zespolona = *this * zespolona;
    zespolona.Re(zespolona.Re()/modul2);
    zespolona.Im(zespolona.Im()/modul2);
    return zespolona;

}

/*!
 * Wyswietla liczbe zespolona na strumien, ktory zostanie podany jako argument.
 * Argumenty:
 *           Zesp - liczba zespolona.
 *           &StreWej - referencja do strumienia, na jaki ma zostac 
 *           wyswietlona liczba
 * Zwraca:
 *        Nic.
 */

ostream& operator << (ostream &StrWej, LZespolona Zesp)
{
  StrWej << "(" << noshowpos << Zesp.Re() << showpos << Zesp.Im() << "i)";
  return StrWej;
}

/*!
 * Realizuje wczytanie liczby zespolonej
 * Argumenty:
 *           &rZesp - referencja do liczby zespolonej.
 * Zwraca:
 *         true, gdy podana liczba jest prawidlowo zapisana,
 *         false, gdy podana liczba jest blednie zapisana.
 */
 
istream& operator >> (istream& StrWej, LZespolona &rZesp)
{
  double _re, _im;
  if(!SprawdzZnak(StrWej, '(')) // sprawdzenie lewego nawiasu
    {
      if(StrWej.eof())
	{
	  StrWej.setstate(ios::failbit);
	  return StrWej; // to znaczy ze w kolejnej linijce testu nic juz nie bylo
	}
      return StrWej; // strumien jest juz ustawiony na fail
    }
  StrWej >> _re; //pobranie czesci rzeczywistej
  if(StrWej.fail())
    {
      return StrWej;
    }
  StrWej >> _im; // pobranie czesci urojonej
  if(StrWej.fail())
    {
      return StrWej;
    }
  if(!SprawdzZnak(StrWej, 'i')) // sprawdzenie literki i 
    {
      return StrWej; //strumien jest juz ustawiony na fail
    }
  if(!SprawdzZnak(StrWej, ')')) // sprawdzenie prawego nawiasu
    {
      return StrWej; // strumien jest juz ustawiony na fail
    }
  rZesp.Re(_re);
  rZesp.Im(_im);
  return StrWej;
}

/*!
 * Porownuje wczytany znak NowyZnak z wskazanym znakiem Znak
 * Argumenty: 
 *           &StrWej - referencja do strumienia, z ktorego czytane sa znaki,
 *           Znak - podany znak, z ktorym zostanie porownany ten wczytany
 * Zwraca: 
 *        wartosc false, gdy czytanie sie niepowiedzie lub wczytany znak 
 *        bedzie rozny od tego podaneg, wartosc true, gdy uda sie pobrac znak 
 *        i oba znaki beda takie same.
 */
bool SprawdzZnak(istream& StrWej, char Znak)
{
  char NowyZnak;
  StrWej >> NowyZnak;
  if(StrWej.fail()){
    return false;
  }
  if(NowyZnak != Znak)
    {
      StrWej.setstate(ios::failbit); // ustawienie strumienia, z ktorego
      return false;                    // czytane sa dane na bledny
    }
  return true;
}

/*!
 * Porownuje dwie liczby zespolone z precyzja do trzech miejsc po przecinku
 * Argument:
 *           Odpowiedz, Poprawna - liczby zespolone
 * Zwraca:
 *        true, gdy liczby sa sobie rowne
 *        false, gdy liczby sie roznia
 */
bool LZespolona::operator == (const LZespolona& Poprawna)const
{
  LZespolona OdpZaok;
  OdpZaok.Re(this->Re());
  OdpZaok.Im(this->Im());
  LZespolona PopZaok;
  PopZaok.Re(Poprawna.Re());
  PopZaok.Im(Poprawna.Im());
  
  OdpZaok.Re(round(1000*OdpZaok.Re()));
  OdpZaok.Im(round(1000*OdpZaok.Im()));
  PopZaok.Re(round(1000*PopZaok.Re()));
  PopZaok.Im(round(1000*PopZaok.Im()));
  if(abs(OdpZaok.Re() -  PopZaok.Re()) < MIN_WART && abs(OdpZaok.Im() - PopZaok.Im()) < MIN_WART)
    return true;
  else
    return false;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *           razy - drugi skladnik mnozenia.
 * Zwraca:
 *        Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator *=(LZespolona razy)
 {
   *this = *this*razy;
   return *this;
 }

/*!
 * Realizuje dodawanie dwoch liczb zespolonych.
 * Argumenty:
 *           dodaj - drugi skladnik mnozenia.
 * Zwraca:
 *        Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator +=(LZespolona dodaj)
{
   *this = *this+dodaj;
   return *this;
}
/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *           odejmij - drugi skladnik mnozenia.
 * Zwraca:
 *        Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator -=(LZespolona odejmij)
{
  *this = *this-odejmij;
  return *this;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *           dzielnik - drugi skladnik mnozenia.
 * Zwraca:
 *        Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator /=(LZespolona dzielnik)
{
   *this = *this/dzielnik;
   return *this;
}

