#include <iostream>
using namespace std;
enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

//ball class
class cBall
{
  private:
    //set coordinants and direction of ball
    int x, y;
    int originalX, originalY;
    eDir direction;
  public:
    cBall(int posX, int posY)
    {
      //stores original position of ball for game reset
      originalX = posX;
      originalY = posY;
      x = posX; y = posY;
      direction = STOP;
    }
   //Reset function
   void Reset()
   {
     x = originalX; y = originalY;
     direction = STOP;
   } 
   //Directions of the ball function
   void changeDirection(eDir d)
   {
     direction = d;
   }
   //public functions for getting x and y coordinates of ball
   void randomDirection()
   {
     direction = (eDir)((rand() % 6) + 1);
   }
   inline int getX() { return x; }
   inline int getY() { return y; }
   inline eDir getDirection() { return direction; }
   //fucntion for ball movement
   void Move()
   {
     switch (direction)
     {
      case STOP:
           break;
      case LEFT:
           x--;
           break;
      case RIGHT:
           x++; 
           break;
      case UPLEFT:
           x--; y--;
           break;
      case DOWNLEFT:
           x--; y++;
           break;
      case UPRIGHT:
           x++; y--;
           break;
      case DOWNRIGHT:
           x++; y++;
           break;
      default:
           break; 
     }
   }
   friend ostream & operator<<(ostream & o, cBall c)
   {
      o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
      return o;
   }
};

int main() {
  cBall c(0, 0);
  cout << c << endl;
  c.randomDirection();
  cout << c << endl;
  c.Move();
  cout << c << endl;
  c.randomDirection();
  c.Move();
  cout << c << endl;


  
  return 0;
}