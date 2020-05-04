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
    int k = 1;
    for( int index = 0; index < 3; index++)
    {

            potter->Load(array[index]);
            potter->Select(k);
            potter->Execute();
            potter->Stats();
            potter->Display();
            potter->Save("SavedSolution.txt");

        if(index >= 0)
            k = 0;



    }

    //return 0;
}
