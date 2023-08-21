#include "Food.h"
#include<ctime>
#include<stdlib.h>
#define HEIGHT 20
#define WIDTH 50

Food::Food()
{
    srand(time(NULL));
    genFood();
}

void Food::genFood()
{
    food_pos.X = rand() % WIDTH+1; // 1-width
    food_pos.Y = rand() % HEIGHT+1; // 1-height
}

COORD Food::getFoodPos()
{
    return food_pos;
}


