#include "ExtraFunctions.h"
#include "MooseError.h"
#include <iostream>

/* extra function for computing factorials for Zernike polynomials,
   courtesy of cplusplus.com. */
int
factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

/* compute the number of Zernike polynomials given the expansion order
   N (not so simple as multiplying n * m because m can only have values
   m = -n, -n + 2, -n + 4, ..., n. */
int
num_zernike(int N)
{
  int number = 0;

  for (int i = 1; i <= N + 1; ++i)
    number += i;

  return number;
}

/* compute the order of the Zernike expansion given the number of
   expansion coefficients. */
int
zernike_order_from_coeffs(int N)
{
  int order = 0;
  int remaining = N;

  while (remaining > 0)
  {
    order += 1;
    remaining = remaining - order;
  }

  return order - 1;
}

// compute water density at 15 MPa given a temperature - for quick results
// for PHYSOR paper. To be made more modular in the future!
double
water_density(double temperature)
{
  if (temperature > 615)
    mooseWarning("Boiling water detected! Temperatures too high for density correlation");

  return -0.0097 * temperature * temperature + 8.8796 * temperature - 1167.1;
}
