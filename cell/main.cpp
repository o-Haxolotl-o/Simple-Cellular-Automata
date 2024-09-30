#include <iostream>
#include <unistd.h>

[[noreturn]] int main()
{
    //variables
    int height = 32; //essentially the steps
    int width = height*2-3;

    int screen[width*height];
    int parents = 0;

    //initialize board
    for (int i = 0; i < width*height; i++)
    {
        screen[i] = 0;
    }
    for (int i = 0; i < width; i++)
    {
        screen[i] = 0;
        screen[width/2] = 1;
    }

    //update rows
        for (int i = width; i < width*height; i++)
        {
            //check parents
            parents = 0;
            if(i%width != 0 && i%width != width-1)
            {
                if(screen[i-width-1] == 1)
                {
                    parents++;
                }
                if(screen[i-width] == 1)
                {
                    parents++;
                }
                if(screen[i-width+1] == 1)
                {
                    parents++;
                }

                //update cell
                if(parents==1)
                {
                    screen[i] = 1;
                }
                if(parents==3)
                {
                    screen[i] = 1;
                }
            }
            else if(i%width == 0)
            {
                if(screen[i-width] == 1)
                {
                    parents++;
                }
                if(screen[i-width+1] == 1)
                {
                    parents++;
                }

                //update cell
                if(parents==1)
                {
                    screen[i] = 1;
                }
                if(parents==2)
                {
                    screen[i] = 1;
                }
            }
            else if(i%width == width-1)
            {
                if(screen[i-width-1] == 1)
                {
                    parents++;
                }
                if(screen[i-width] == 1)
                {
                    parents++;
                }

                //update cell
                if(parents==1)
                {
                    screen[i] = 1;
                }
                if(parents==2)
                {
                    screen[i] = 1;
                }
            }

        }

    //draw screen
    for (int i = 0; i < width*height; i++)
    {
        if (i%width == 0)
        {
            std::cout << std::endl;
        }

        if(screen[i] == 1)
        {
            std::cout << "██";
        }
        if(screen[i] == 0)
        {
            std::cout << "░░";
        }
    }


}
