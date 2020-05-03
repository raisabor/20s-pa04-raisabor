//
//  main.cpp
//  src
//
//  Created by Richmond Aisabor on 11/22/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//
#include <vector>
#include "Search.h"
#include <iostream>
#include <time.h>

int main(int argc, const char * argv[]) {

    srand ( time(NULL) );
    Algorithm* potter = new Search();

    string array[] = { "positions9.txt", "positions25.txt", "positions100.txt"};
    
    for( int index = 0; index < 3; index++)
    {

            potter->Load(array[index]);
            potter->Select(0);
            potter->Execute();
            potter->Stats();
            potter->Display();
            potter->Save("SavedSolution.txt");


    }

    //return 0;
}
