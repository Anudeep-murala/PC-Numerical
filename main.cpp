#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

#ifdef __cplusplus
extern "C"
{
#endif

  float f1(float x, int intensity);
  float f2(float x, int intensity);
  float f3(float x, int intensity);
  float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[])
{

  if (argc < 6)
  {
    std::cerr << "usage: " << argv[0] << " <functionid> <a> <b> <n> <intensity>" << std::endl;
    return -1;
  }
  float fId = argv[1];
  float a = argv[2];
  float b = argv[3];
  int n = argv[4];
  int intensity = argv[5];
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
  float partOne = (b - a) / n;
  float finalOutput = 0;
  float partTwo = 0;
  for (int i = 0; i < n; i++)
  {
    partTwo = a + ((i + 0.5) * partOne);
    switch (fId)
    {
    case 1:
      finalOutput = finalOutput + f1(partTwo,intensity);
          break;
    case 2:
      finalOutput = finalOutput + f2(partTwo,intensity);
      break;
    case 3:
      finalOutput = finalOutput + f3(partTwo,intensity);
      break;
    case 4:
      finalOutput = finalOutput + f4(partTwo,intensity);
      break;
    default:
          std::cerr<<"Wrong Function ID."<<std::endl;
      break;
    }  
  }
finalOutput*= partOne;
std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
std::chrono::duration<double, std::milli> difference = end - start;
  std::cout<< finalOutput<<std::endl;
  std::cerr << difference.count() << std::endl;
  return 0;
}
