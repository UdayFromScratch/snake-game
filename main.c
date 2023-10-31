#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

int snakeX[30], snakeY[30]; //snake coordinates
int counttail = 0;

void setup()
{
    gameover = 0;

    x = height / 2;
    y = width / 2;
    label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
    label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}
void draw()
{
    system("cls");

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                    printf("O"); //snake head
                else if (i == fruitx && j == fruity)
                    printf("F"); //fruit
                else
                {
                    int ch = 0;
                    for (int k = 0; k < counttail; k++) //prints the tail
                    {
                        if (i == snakeX[k] && j == snakeY[k])
                        {
                            printf("o"); ch = 1;
                        }
                    }
                    if (ch == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");

}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void makelogic()
{
    sleep(0.01);

    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = x;
    snakeY[0] = y;

    for(int i = 1; i < counttail ; i++)
    {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
    if (x<0 || x>height || y<0 || y>width)
        gameover=1;

   for (i=0;i<counttail;i++)
       if(snakeX[i]==x && snakeY[i]==y)
           gameover=1;

   if(x==fruitx && y==fruity)
   {
       label3:
       fruitx=rand()%20;
       if(fruitx==0)
           goto label3;

       label4:
       fruity=rand()%20;
       if(fruity==0)
           goto label4;

       score+=10;
       counttail++;
   }

}

int main()
{
   int m, n;

   char c;

   label5:

   setup();

   while (!gameover)
   {
       draw();
       input();
       makelogic();
   }

   printf("\npress Y to continue again :");

   scanf("%c", &c);
   if (c == 'y' || c == 'Y')
       goto label5;

   return 0;

}
