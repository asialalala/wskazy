#include <iostream>
#include <cstring>
#include "WyrazenieZesp.hh"
using namespace std;

/*!
 * konstruktor bezparametryczny
 */
WyrazenieZesp::WyrazenieZesp()
{
  
}

/*!
 * konstruktor parametryczny
 */
WyrazenieZesp::WyrazenieZesp(LZespolona _arg1, OPerator _op,LZespolona _arg2)
{
  arg1 = _arg1;
  op = _op;
  arg2 = _arg2;
}

/*!
 * konstruktor kopiujacy
 */
WyrazenieZesp::WyrazenieZesp(const WyrazenieZesp & _WZ)
{
  Arg1(_WZ.Arg1);
  Op(_WZ.Op);
  Arg2(_WZ.Arg2);
  
}

/*!
 * inicjalizuje wartosc Arg1
 */
void WyrazenieZesp::Arg1(LZespolona _arg1)
{
  arg1 = _arg1;
}
/*!
 * inicjalizuje wartosc Arg2
 */
void WyrazenieZesp::Op(Operator _op)
{
  op = _op;
}
/*!
 * inicjalizuje wartosc Arg2
 */
void WyrazenieZesp::Arg2(LZespolona _arg2)
{
  arg2 = _arg2;
}

/*!
 * zwraca wartosc arg1
 */
LZespolona & WyrazenieZesp::Arg1()
{
  return arg1;
}

/*!
 * zwraca wartosc Op
 */
Operator & WyrazenieZesp::Op()
{
  return op;
}

/*!
 * zwraca wartosc Arg2
 */
LZespolona &WyrazenieZesp::Arg2()
{
  return arg2;
}



/*!
 * zwraca wartosc arg1
 */
LZespolona WyrazenieZesp::Arg1() const
{
  return arg1;
}
/*!
 * zwraca wartosc Op
 */
Operator WyrazenieZesp::Op() const
{
  return op;
}
/*!
 * zwraca wartosc Arg2
 */
LZespolona WyrazenieZesp::Arg2() const
{
  return arg2;
}


/*!
 * Realizuje wyswietlenie wyrazenia algebraicznego liczb zespolonyc
 * Argumenty:
 *           WyrZ - wyrazenie zespolone, zawierajace dwie 
 *           liczby zespolone i oeprator. 
 *           &StrWyj - referencja do strumienia wyjsciowego,
 *           na ktory zostanie wypisany operator
 * Zwraca:
 *        referencje do strumienia wyjsciowego
 * PRE:
*       Odpowiedni operator, czyli wartosc WyrZ.Op musi wynosic 0, 1, 2, lub 3.
 */

ostream& operator << (ostream &StrWyj,WyrazenieZesp  WyrZ)
{
  cout << WyrZ.Arg1() << " ";

  switch(WyrZ.Op()){
  case 0:
    StrWyj << "+";
    break;
  case 1:
    StrWyj << "-";
    break;
  case 2:
    StrWyj << "*";
    break;
  case 3:
    StrWyj << "/";
    break;
  }
  
  cout << " " << WyrZ.Arg2() << endl;
  return StrWyj;
}

/*!
 * Interpretuje wyrazenie zespolone i w zaleznosci od operatora
 * wykonuje odpowiednie dzialanie.
 * Argumenty:
 *            WyrZ - Wyrazenie zespolone, ktore nazlezy obliczyc.
 * Zwraca:
 *         Wynik wyrazenia zespolonego.
 * PRE: 
 *     Odpowiedni operator, czyli wartosc WyrZ.Op musi wynosic 0, 1, 2 lub 3.
 */
LZespolona WyrazenieZesp::Oblicz()
{
  switch(this->Op())
    {
    case 0:
      return this->Arg1() + this->Arg2();
    case 1:
      return this->Arg1() -  this->Arg2();
    case 2:
      return this->Arg1() * this->Arg2();
    case 3:
      return this->Arg1() / this->Arg2();
    default:
      std::cerr << "Nie podano operatora dzialania.\n";
    }
  
} 

/*!
 * Wczytuje operator 
 * Argumenty:
 *           &StrWej - referencja do strumienia, z ktorego czytane sa dane
 *           &Op - referencja do operatora, ktory ma zostac wczytany
 * Zwraca:
 *         referencja do strumienia, z ktorego czyta dane lub failbit, 
 *         gdy zostanie podany zly operator
 */
istream& operator >> (istream& StrWej, Operator& Op) //Trzeba &Op, bo mamy
                                                     //pracowac na oryginalach
{
  char Znak;
  const char *TabZnakOp = "+-*/";
  Operator TabOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};
  
  StrWej >> Znak;
  if (StrWej.fail())
    return StrWej;
  const char *ptrZnakOp = strchr(TabZnakOp,Znak); // Sprawdza, czy wpisany zanak Znak zgadza sie z jednym 
  if  (ptrZnakOp == nullptr)                      // z mozliweych znakow
    {
      StrWej.setstate(ios::failbit); // ustawia strumien wejsciowy na fail, czyli ze jest blad
      return StrWej;
    }
  
  Op = TabOp[ptrZnakOp-TabZnakOp];
  return StrWej;
}

/*!
 * Wczytuje wyrazenie liczby zespolonej, skladajace
 * sie z liczby zespolonej, operatora, kolejnej
 * liczby zespolonej
 * Argumenty:
 *           &StrWej - referencja do strumienia wejsciowego, z ktorego bedzie
 *           czytane wyrarzenie zespolone
 *           &WyrZ - referencja do wyrazenia zespolonego, do ktorego maja
 *           zostac wczytane dane
 * Zwraca:
 *        referencje do strumienia wejsciowego
 * PRE: 
 *     StrWej musi nie byc pusty i zawierac poprawnie zapisane 
 *     wyrazenie zespolone: (re+/-imi) Op (re+/-imi)
 */
istream& operator >> (istream &StrWej, WyrazenieZesp &WyrZ)
{
  StrWej >>  WyrZ.Arg1() >> WyrZ.Op() >> WyrZ.Arg2() ;
  if(StrWej.fail()&&!StrWej.eof())
    {
      cerr << "Blad zwiazany z wyrazeniem zespolonym w bazie pytan." << endl;
      exit(2); // gdy zle pobrano wyrazenie zespolone  z pliku zakoncz program
    }
  return StrWej;
}
