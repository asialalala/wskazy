#include "Wskaz.hh"

/*!
 * Konstruktor bezparametryczny
 */

Wskaz::Wskaz()
{
  Modol = 0;
  Faza = 0;
}

/*!
 * Konstruktor parametryczny
 */
Wskaz::Wskaz(double _modol, double _faza)
{
  Modol = _modol;
  Faza = _faza;
}

/*!
 * Konstruktor kopijacy
 */
Wskaz::Wskaz(const Wskaz &wskaz)
 {
   Modol = wskaz.modol();
   Faza = wskaz.faza();
 }

/*!
 * Zwraca wartosc modulu
 */
double  Wskaz::modol() const
{
  return Modol;
}

/*!
 * Zwraca wartosc fazy
 */
double Wskaz::faza() const
{
  return Faza;
}
