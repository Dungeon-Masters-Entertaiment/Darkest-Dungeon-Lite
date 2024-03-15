#include "PointClass/Vector.h"

int main() {
  Vector v1(1.0, 2.0);
  Vector v2(4.0, 5.0);

  std::cout << "v1: " << v1 << ", length: " << v1.length() << std::endl;
  std::cout << "v2: " << v2 << ", length: " << v2.length() << std::endl;

  Vector sum = v1 + v2;
  Vector diff = v1 - v2;

  std::cout << "v1 + v2: " << sum << std::endl;
  std::cout << "v1 - v2: " << diff << std::endl;

  Vector scaled = v1 * 2.0;
  std::cout << "2 * v1: " << scaled << std::endl;

  double dist = distance(v1, v2);
  double dotProd = v1 * v2;
  std::cout << "Distance between v1 and v2: " << dist << std::endl;
  std::cout << "Dot product between v1 and v2: " << dotProd << std::endl;


  return 0;
}