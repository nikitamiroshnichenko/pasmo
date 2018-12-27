
#if MAC
//
//  main.cpp
//  PasmoMac
//
//  Created by Chrsitopher Kirby on 26/12/2018.
//  Copyright © 2018 Chrsitopher Kirby. All rights reserved.
//
//int doit (int argc, char * * argv);
//public:
//    int Pmain (int argc, char * * argv);

#include <iostream>
#include "pasmo.h"


int main(int argc, const char * argv[])
{
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //RunIt(argc, argv);

    
    return Pmain(argc, (char * *)argv);
    //doit(argc,&argv);
    return 0;
}
#endif
