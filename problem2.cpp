/* 
 * File:   problem2.cpp
 * Author: student
 *
 * Created on January 12, 2012, 10:44 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() 
{
    int fino = 0;
    
    for (int i = 0; i < 10; i++)
    {
        cout << fino;
        fino = fino + i;
    }
    
    return 0;
}

