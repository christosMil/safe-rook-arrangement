#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Position
{
    int positionX;
    int positionY;
} Position;

void runProgram ();
int randomPosition (int *availablePositions, int freeSpots);
void displayBoard (Position *position, int rooksOnBoard);

int main (int argc, char **argv)
{
    runProgram();
    return 0;
}

void runProgram ()
{
    Position position[8];
    int availablePositionsX[8] = {1, 2, 3, 4, 5, 6, 7, 8}, availablePositionsY[8] = {1, 2, 3, 4, 5, 6, 7, 8}, i, j, arrayPositionX, arrayPositionY, freeSpotsX = 8, freeSpotsY = 8, rooksOnBoard = 0;
    srand(time(0));

    for (i = 0; i < 8; ++i)
    {
        printf("%d free row(s): ", freeSpotsX);
        for (int k = 0; k < 8 - i; k++)
        {
            printf("%d ", availablePositionsX[k]);
        }
        printf("\n%d free column(s): ", freeSpotsY);
        for (int k = 0; k < 8 - i; k++)
        {
            printf("%d ", availablePositionsY[k]);
        }
        printf("\n");
        arrayPositionX = randomPosition(availablePositionsX, freeSpotsX);
        arrayPositionY = randomPosition(availablePositionsY, freeSpotsY);
        position[i].positionX = availablePositionsX[arrayPositionX];
        position[i].positionY = availablePositionsY[arrayPositionY];
        ++rooksOnBoard;
        displayBoard(position, rooksOnBoard);
        --freeSpotsX;
        --freeSpotsY;
        for (j = arrayPositionX; j < freeSpotsX; ++j)
        {
            availablePositionsX[j] = availablePositionsX[j+1];
        }
        for (j = arrayPositionY; j < freeSpotsY; ++j)
        {
            availablePositionsY[j] = availablePositionsY[j+1];
        }
    }
    printf("\nFinal board\n");
    displayBoard(position, 8);

}

int randomPosition (int *availablePositions, int freeSpots)
{
    int position;

    position = random() % freeSpots;

    return position;
}

void displayBoard (Position *position, int rooksOnBoard)
{
    int i, j, k, l, gapBetweenSquares = 3, place = 0;

    for (i = 0; i < 8; ++i)
    {
        printf(" ");
        for (j = 1; j <= gapBetweenSquares; ++j)
        {
            printf("-");
        }        
    }
    printf("\n");
    for (i = 0; i < 8; ++i)
    {
        for (l = 0; l < rooksOnBoard; ++l)
        {
            if ((i+1) == position[l].positionX) place = l;
        }
        for (j = 0; j < 8; ++j)
        {
            printf("|");
            for (k = 1; k <= gapBetweenSquares; ++k)
            {
                if (k == 2 && position[place].positionX == i+1 && position[place].positionY == j+1) printf("*");
                else printf(" ");
            }
        }
        printf("|\n");
        for (j = 0; j < 8; ++j)
        {
            printf(" ");
            for (k = 0; k < gapBetweenSquares; ++k)
            {
                printf("-");
            }        
        }
        printf("\n");
    }
    
    return;
}
