#include <iostream>
#include <windows.h>
#include <snake.h>
#include <Food.h>
#include <conio.h>
using namespace std;

#define HEIGHT 20
#define WIDTH 50

//ASCII
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

//creating objects
snake Snake({WIDTH/2,HEIGHT/2});
Food food;

board()
{

    vector<COORD> getSnakeLen = Snake.snakeLen();
    for(int i=0;i<=HEIGHT+1;i++)
    {
        cout<<"\n\t\t\t";
        for(int j=0;j<=WIDTH+1;j++)
        {
            if( i==0 || i==HEIGHT+1 || j==0 || j==WIDTH+1)
            {
                cout<<"#";
            }
            else if(i==food.getFoodPos().Y && j==food.getFoodPos().X)
            {
                cout<<"*";
            }
            else{
                    //updates snakes position
                    bool snakePos = false;
                    for(int k=0;k<getSnakeLen.size();k++)
                    {
                        if(i == getSnakeLen[k].Y && j == getSnakeLen[k].X)
                        {
                            cout<<"O";
                            snakePos = true;
                        }
                    }
                    if(!snakePos)
                    {
                        cout<<" ";
                    }
            }
        }
        cout<<endl;
    }
}

int main()
{
    while(true)
    {
        //must be declared in milliseconds
        Sleep(100);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        board();

        //kbhit -> KEYBOARD HIT
        if(kbhit())
        {
            //getch -> returns the character pressed.
            switch(getch())
            {
            case UP_ARROW: Snake.setDir('u');break;
            case DOWN_ARROW: Snake.setDir('d');break;
            case LEFT_ARROW: Snake.setDir('l');break;
            case RIGHT_ARROW: Snake.setDir('r');break;
            }

        }
        Snake.moveSnake();

        if(Snake.collide())
        {
            cout<<"GAME OVER!!"<<endl;
        }

        //passing objects
        if(Snake.eaten(food))
        {
            Snake.grow();
            food.genFood();
        }
    }
    return 0;
}
