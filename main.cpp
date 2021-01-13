#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool UsedInBox(int sdk[9][9], int startRow, int startCol, int n)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(sdk[i+startRow][j+startCol]==n)
                return true;
        }
    }
    return false;
}

bool UsedInCol(int sdk[9][9], int c, int n)
{
    for(int i=0;i<9;i++)
    {
        if(sdk[i][c]==n)
            return true;
    }
    return false;
}

bool UsedInRow(int sdk[9][9], int r, int n)
{
    for(int i=0;i<9;i++)
    {
        if(sdk[r][i]==n)
            return true;
    }
    return false;
}

bool unassignedLocation(int sdk[9][9], int &r, int &c)
{
    for(r=0;r<9;r++)
    {
        for (c=0;c<9;c++)
        {
            if (sdk[r][c]==0)
                return true;
        }
    }
    return false;
}

bool isSafe(int sdk[9][9], int r, int c, int n)
{
    return (!UsedInRow(sdk,r,n) && !UsedInCol(sdk,c,n) && !UsedInBox(sdk,r-r%3,c-c%3,n));
}

bool sudoku(int sdk[9][9])
{
    int num,r,c;
    if(!(unassignedLocation(sdk,r,c)))
       return true;
    else
    {
        for(num=1;num<=9;num++)
        {
            if(isSafe(sdk,r,c,num))
            {
                sdk[r][c]=num;
                if(sudoku(sdk))
                    return true;
                sdk[r][c]=0;
            }
        }
    }
    return false;
}

int main()
{
    int sdk[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    if(sudoku(sdk))
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<sdk[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"Sudoku does not have a solution"<<endl;
    return 0;
}
