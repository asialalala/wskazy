#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
private:
  LZespolona   arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     op;     // Opertor wyrazenia arytmetycznego
  LZespolona   arg2;   // Drugi argument wyrazenia arytmetycznego
public:
  WyrazenieZesp();
  WyrazenieZesp(LZespolona _arg1, OPerator _op,LZespolona _arg2);
  WyrazenieZesp(const WyrazenieZesp & _WZ);
  void Arg1(LZespolona _arg1);
  void Op(Operator _op);
  void Arg2(LZespolona _arg2);
  LZespolona & Arg1();
  Operator & Op();
  LZespolona & Arg2();
  LZespolona Arg1() const;
  Operator Op() const;
  LZespolona Arg2() const;
  LZespolona Oblicz();
  
};



std::ostream& operator << (std::ostream &StrWyj, WyrazenieZesp  WyrZ);
std::istream& operator >> (std::istream& StrWej, Operator &Op);
std::istream& operator >> (std::istream& StrWej, WyrazenieZesp &WyrZ);
#endif
