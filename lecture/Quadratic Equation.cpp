#include <utility>
#include <cmath>

/**
 * Solves the equation ax^2 + bx + c = 0
 * @param a The coefficient of x^2
 * @param b The coefficient of x
 * @param c The constant term
 * @return A pair. The first element (bool) indicates if the equation has a solution.
 *                 The second element is a pair of solutions if they exist.
 */
std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c)
{
  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0) return {false, {0, 0}};

  double solution1 = (-b + std::sqrt(discriminant)) / (2 * a);
  double solution2 = (-b - std::sqrt(discriminant)) / (2 * a);
  return {true, {solution1, solution2}};
}