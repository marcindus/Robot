#ifndef  DRIVER_HPP
#define  DRIVER_HPP


class Driver : public IDriver 
{
public:

     Driver(std::unique_ptr<IMotor> p_leftMotor, std::unique_ptr<IMotor> p_rightMotor,);

     void forward(unsigned int speed);
     void turnLeft();
     void backward(unsigned int speed);
     void stay();
     void turnRight();

private:
    std::unique_ptr<IMotor>  leftMotor;
    std::unique_ptr<IMotor>  rightMotor;
}

#endif // DRIVER_HPP
