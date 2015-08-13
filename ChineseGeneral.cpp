#include <iostream>

int main()
{
  unsigned char i = 81;
  while(i--)
  { 
    if(i/9 %3 == i % 9 %3)
      continue;
    std::cout<<"A = "<< i/9+1 <<", B = "<< i%9+1 <<std::endl;
  }
  return 0;
}
