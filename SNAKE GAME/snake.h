#ifndef SNAKE_H
#define SNAKE_H
#include <Food.h>
#include<windows.h>
#include <vector>
using namespace std;
class snake
{
private:
    COORD pos;
    int len;
    int dir;
    vector <COORD> snakeGrow;

public:
    snake(COORD pos);
    COORD getPos();
    void setDir(int direction);
    void moveSnake();
    bool collide();
    // Getting food object as parameters
    bool eaten(Food &food);
    void grow();
    vector <COORD> snakeLen();
};

#endif // SNAKE_H
