//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  EIGHT QUEENS USING BREADTH FIRST SEARCH
//  main.cpp
//  RouteFinding
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include "Domain.h"
#include "BFS.h"

using namespace std;

int main(int argc, const char * argv[])
{
    cout<<"Algorithm: Breadth-First Search"<<endl;
    cout<<"Domain: 8-Queens"<<endl<<endl;
    Domain d;
    BFS newBFS;
    newBFS.runBFS(d, NULL, NULL);

    return 0;
}



