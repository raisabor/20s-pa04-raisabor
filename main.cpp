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

    string array[] = { "positions7.txt", "positions25.txt", "positions100.txt"};
    for( int index = 0; index < 3; index++)
    {

                potter->Load(array[index]);
                if(index == 0){

                    for(int i = 0; i < 2; i++)
                    {
                        potter->Select(i);
                        potter->Execute();
                        potter->Display();
                    }

                }else{
                    potter->Select(1);
                    potter->Execute();
                    potter->Display();
                }

    }


}
