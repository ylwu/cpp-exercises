//
//  main.cpp
//  EightQueens
//
//  Created by Jason Wu on 2/8/13.
//  Copyright (c) 2013 Jason Wu. All rights reserved.
//

#include <iostream>
using namespace std;
int Row = 0;
int Path[13] = {0};
int Count = 0;
int num = 13;


bool Detect(int x[], int row, int target)
{
    if (row == 0) return false;
    for (int i =1; i<= row; i++)
    {
        if (target == x[i-1] - (row - i +1) || target == x[i-1] + (row - i + 1)|| target == x[i-1])
        {
            return true;
        }
    }
    return false;
}

void findPath()
{
    for (int i =1; i <= num; i++)
    {
        if (Detect(Path, Row, i)) continue;
        Row ++;
        Path[Row -1] = i;
        if (Row == num)
        {
            Count ++;
            Row --;
            continue;
        }
        findPath();
        Row --;
    }
}



int main(int argc, const char * argv[])
{
    findPath();
    cout << "Number of solutions for 15 queens is " << Count << endl;
    return 0;
}


