#include "snake.h"
#include<windows.h>
#include <Food.h>
#include<vector>
#define HEIGHT 20
#define WIDTH 50

snake::snake(COORD pos)
{
    this->pos = pos;
    len =1;
    snakeGrow.push_back(pos);
}

COORD snake::getPos()
{
    return pos;
    // declaring head of snake

}

void snake::setDir(int direction){dir = direction;}

void snake::moveSnake()
{
    switch(dir)
    {
    case 'u': pos.Y--;break;
    case 'd': pos.Y++;break;
    case 'l': pos.X--;break;
    case 'r': pos.X++;break;
    }
    snakeGrow.push_back(pos);
    //Declared to delete first element to show movement
    if(snakeGrow.size() > len)
    {
        snakeGrow.erase(snakeGrow.begin());
    }
}

bool snake::collide()
{
    if(pos.X == 0 || pos.X == WIDTH+1 || pos.Y == 0 || pos.Y == HEIGHT+1)
    {
        return true;
    }
    return false;
}

bool snake::eaten(Food &food)
{
    if(pos.X == food.getFoodPos().X && pos.Y == food.getFoodPos().Y)
    {
        return true;
    }
}

void snake::grow()
{
    len++;
}

vector <COORD> snake::snakeLen()
{
    return snakeGrow;
}
