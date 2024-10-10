#include<stdio.h>
#include<conio.h>

int printgrid(char grid[11][11]);
int isvalid(int a);
int printgrid_bomb(char grid[11][11]);

int main()
{
    int age;

    printf("WELCOME!\n Please enter your age:");
    scanf("%d", &age);
    int i,j;

    char grid[11][11];
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {

            grid[i][j]='*';
        }
    }

    grid[0][0]='s';
    grid[6][6]='c';
    grid[1][2]='b';
    grid[1][3]='b';
    grid[1][5]='b';
    grid[1][6]='b';
    grid[1][7]='b';
    grid[1][9]='b';

    grid[2][0]='b';
    grid[2][2]='b';
    grid[2][3]='b';
    grid[2][5]='b';
    grid[2][6]='b';
    grid[2][7]='b';
    grid[2][9]='b';

    grid[3][0]='b';
    grid[3][2]='b';
    grid[3][3]='b';
    grid[3][9]='b';

    grid[4][0]='b';
    grid[4][2]='b';
    grid[4][3]='b';
    grid[4][4]='b';
    grid[4][6]='b';
    grid[4][8]='b';
    grid[4][9]='b';

    grid[5][0]='b';
    grid[5][2]='b';
    grid[5][3]='b';
    grid[5][4]='b';
    grid[5][6]='b';
    grid[5][8]='b';
    grid[5][9]='b';

    grid[6][0]='b';
    grid[6][8]='b';
    grid[6][9]='b';

    grid[7][0]='b';
    grid[7][1]='b';
    grid[7][3]='b';
    grid[7][4]='b';
    grid[7][5]='b';

    grid[8][0]='b';
    grid[8][1]='b';
    grid[8][3]='b';
    grid[8][4]='b';
    grid[8][5]='b';
    grid[8][7]='b';
    grid[8][8]='b';
    grid[8][9]='b';
    grid[8][10]='b';

    grid[9][0]='b';
    grid[9][1]='b';
    grid[9][7]='b';
    grid[9][8]='b';
    grid[9][9]='b';
    grid[9][10]='b';


    grid[10][0]='b';
    grid[10][1]='b';
    grid[10][2]='b';
    grid[10][3]='b';
    grid[10][4]='b';
    grid[10][5]='b';
    grid[10][6]='b';
    grid[10][7]='b';
    grid[10][8]='b';
    grid[10][9]='b';
    grid[10][10]='b';
    int c_row=0;
    int c_col=0;

    printf("Here, it is the initial phase of a robot. You are starting from s. If you want to win, you have to take the robot to the position c.\n");

    printgrid(grid);

    printf("X WARNING X\n");

    printf("There are some bombs in some positions.\n WHICH CAN TAKE YOUR LIFE AWAY!!!!!\n");

    printf("INSTRUCTIONS:\n 1. If you want to go right enter: r .\n 2. If you want to go left enter l.\n 3. If you want to go up enter u.\n 4. If you want to go down enter d.\n");


    int game_over=0;


    while(game_over==0)
    {
        printf("Enter your action:");

        char entry;
        scanf("%s", &entry);
        //entry='r';

        switch(entry)
        {
        case 'r':

            c_col=c_col+1;

            printf("You entered: %s\n", &entry);

            Beep(300, 300);

            printf("You are in position:\n");



            printf("%d %d\n", c_col,isvalid(c_col));



            if(isvalid(c_col)==0)
            {
                printf("error");
                game_over=1;
            }
            break;

        case 'l':
            c_col=c_col-1;
            printf("You entered: %s\n", &entry);
            Beep(300, 300);

            printf("You are in position:\n");
            printf("%d %d\n", c_col,isvalid(c_col));

            if(isvalid(c_col)==0)
            {
                printf("error");
                game_over=1;
            }
            break;
        case 'u':
            c_row=c_row-1;
            printf("You entered: %s\n", &entry);
            Beep(300, 300);

            printf("You are in position:\n");
            printf("%d %d\n", c_row,isvalid(c_row));

            if(isvalid(c_row)==0)
            {
                printf("error");
                game_over=1;
            }
            break;

        case 'd':
            c_row=c_row+1;
            printf("You entered: %s\n", &entry);
            Beep(300, 300);

            printf("You are in position:\n");

            printf("%d %d\n", c_row,isvalid(c_row));



            if(isvalid(c_row)==0)
            {
                printf("error");
                game_over=1;

            }
            break;
        }
        if(grid[c_row][c_col]=='b')
        {
            printf("OH NO!!!!!!\n You died.\n 0~0");
            printf("Game over.Better luck next time!.\n");
            printf("Just in case you are curious, this is the phase with bombs:\n");
            printgrid_bomb(grid);
            game_over=1;
            continue;

        }
        else if(grid[c_row][c_col]=='c')
        {

            printf("CONGRATULATIONSSSSS!!!!!!!! YOU MADE IT! You win!!\n");
            Beep(700, 700);
            printf("Just in case you are curious, this is the phase with bombs:\n");
            printgrid_bomb(grid);
            game_over=1;

            continue;
        }


        grid[c_row][c_col]='o';

        grid[0][0]='s';

        printgrid(grid);


    }


}
int printgrid(char grid[11][11])
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {
            if(grid[i][j]=='b')
            {

                printf("* ");

            }
            else
            {
                printf("%c ", grid[i][j]);
            }

        }
        printf("\n");
    }

}


int printgrid_bomb(char grid[11][11])
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<11; j++)
        {

            printf("%c ", grid[i][j]);

        }
        printf("\n");
    }

}
isvalid(int a)
{
    if(a>=0 && a<11)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




