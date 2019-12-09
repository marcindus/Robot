#ifndef IDRIVER_HPP
#define IDRIVER_HPP

#include "Types.hpp"


class IDriver 
{
public:

   virtual  ~IDriver() {};
   virtual  void forward() = 0;
   virtual  void turnLeft() = 0;
   virtual  void backward() = 0;
   virtual  void stay() = 0;
   virtual  void turnRight() = 0;
}


