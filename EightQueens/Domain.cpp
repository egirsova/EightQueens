//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  EIGHT QUEENS USING BREADTH FIRST SEARCH
//  Domain.cpp
//  RouteFinding
//

#include "Domain.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>

using namespace std;

// Templated constructor for Node
template<typename T, typename S> Node::Node(T state, S cost, Node* parent){
    Node::state = state;
    Node::cost = cost;
    Node::parent = parent;
}

// Takes in current state (chessVector) and column we need to check. Outputs list of possible states.
list<Node> Domain::successorFn(Node* currentNode, Node* dummyValue){
    vector<int> tempVector(9);  // Creates temporary vector that will try different row options
    tempVector = currentNode->state;
    list<Node> possibleStates;
    int column = getNextColumn(currentNode->state);
    
    // Loops through all possibilities of rows
    for (int row = 1; row<9; row++){
        tempVector[column] = row; // First inserts potential queen into the column of temp. vector
        
        // If the potential queen does not match requirements, this is not added to possibilities
        if(!previousRowExists(tempVector, column) && !topLeftDiagonalExists(tempVector, column) && !bottomLeftDiagonalExists(tempVector, column)){
            
            // Adds tempNode to the list
            Node tempNode(tempVector, 1, currentNode);
            possibleStates.push_back(tempNode);
        }
    }
    return possibleStates;
}

// Prints out the array
void Domain::print(vector<int> state){
    for (int i = 1; i<9; ++i){
        printf("%d ",state[i]);
    }
    cout<<endl;
}


// Determines which column needs to be calculated to find the queen (for the successorFN)
int Domain::getNextColumn(vector<int> state) {
    int i = 1;
    while(state[i] != 0)
        i++;
    return i;
}

// Takes in array index and checks if the value in the index corresponds with a row already in array
bool Domain::previousRowExists(vector<int> state, int arrayIndex){
    int arrayCheck = arrayIndex-1;
    while(arrayCheck != 0)
    {
        // Returns true if row number at current column matches a row number at a previous column
        if(state[arrayIndex]==state[arrayCheck]){
            return true;
        } else
            arrayCheck--;
    }
    return false;
}

// Takes in array index and checks to see if queens in previous rows have a diagonal from top left
bool Domain::topLeftDiagonalExists(vector<int> state, int arrayIndex){
    int column = arrayIndex-1;
    int row = state[arrayIndex]-1;
    while (!((column==0) || (row ==0))){
        if(state[column] == row)
            return true;
        else{
            column--;
            row--;
        }
    }
    return false;
}

// Takes in array index and checks to see if queens in previous rows have a diagonal from bottom left
bool Domain::bottomLeftDiagonalExists(vector<int> state, int arrayIndex){
    int column = arrayIndex-1;
    int row = state[arrayIndex]+1;
    while (!((column==0) || (row==9))){
        if(state[column] == row)
            return true;
        else{
            column--;
            row++;
        }
    }
    return false;
}

// Returns cost. Since all paths cost 1, the cost is 8.
int Domain::getPathCost(Node* currentNode, Node* rootNode){
    return 8;
}

// Returns depth. We know the depth will always be 8.
int Domain::getDepth(Node* currentNode, Node* rootNode){
    return 8;
}
