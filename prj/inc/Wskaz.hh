#ifndef WSKAZ_HH
#define WSKAZ_HH

#include <iostream>
#include "Lzespolona.hh"


class Wskaz {
private:
  double Modol;
  double Faza;
public:
  Wskaz();
  Wskaz(double _modol, double _faza);
  Wskaz(const Wskaz &wskaz);
  
  // double oblicz_modol();
  // double oblicz_faze();
  double modol() const;
  double faza() const;
};

#endif
