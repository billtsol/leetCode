#include <iostream>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {

    if (x == 0 || x == 1)
      return x;

    // long int middle = (x / 2) + 1;

    // for(long int i = 0; i <= middle; i++){
    //     if (i * i == x){
    //         return i;
    //     }else if (i*i > x){
    //         return i - 1;
    //     }
    // }

    long int left = 1;
    long int right = (x / 2) + 1;
    bool flag = true;

    while (flag)
    {
      long int middle = (left + right) / 2;

      if ((middle * middle) == x)
      {
        return middle;
      }
      else if ((middle * middle) > x)
      {
        right = middle - 1;
      }
      else
      {
        left = middle + 1;
      }

      std::cout << "left: " << left << " Middle: " << middle << " Right: " << right << endl;

      std::cout << (left != right) << endl;

      if ((left != right) == 0)
      {
        flag = false;
        std::cout << "mpike" << endl;
        break;
      }
    }

    std::cout << "bgike" << endl;

    return right - 1;
  }
};