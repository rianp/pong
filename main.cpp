#include <iostream>
#include <time.h>
#include <ncurses.h>

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

//paddle object
class cPaddle
{
private:
    int x, y;
    int originalX, originalY;
public:
    cPaddle()
    {
        x = y = 0;
    }
    cPaddle(int posX, int posY) : cPaddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset() { x = originalX; y = originalY; }
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline void moveUp() { y--; }
    inline void moveDown() { y++; }
    friend ostream & operator<<(ostream & o, cPaddle c)
    {
        o << "Paddle [" << c.x << "," << c.y << "]";
        return o;
    }
};

class cGameManager
{
  private:  
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall * ball;
    cPaddle *player1;
    cPaddle *player2;

  public:  
    cGameManager (int w, int h)
    {
      srand(time (NULL));
      quit = false;
      up1 = 'w'; up2 ='i';
      down1 = 's'; down2 = 'k';
      score1 = score2 = 0;
      width = w; height = h;
      ball = new cBall(w/2, h/2);
      player1 = new cPaddle(1, h/2 - 3);
      player2 = new cPaddle(w - 2, h/2 - 3);
    }

    //free game set of data
    ~cGameManager()
    {
      delete ball, player1, player2;
    }

    //keep score by pointing paddle to player
    void ScoreUp(cPaddle * player)
    {
      if(player == player1)
        score1++;
      else if (player == player2)
        score2++;
      
      ball->Reset();
      player1->Reset();
      player2->Reset();
    }
};

int main() 
{
  
  
  return 0;
}