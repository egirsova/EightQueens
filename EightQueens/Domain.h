//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  EIGHT QUEENS USING BREADTH FIRST SEARCH
//  Domain.h
//  RouteFinding
//

#ifndef __EightQueens__Domain__
#define __EightQueens__Domain__

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Node
{
public:
    vector<int> state;
    int cost;
    Node *parent;
    template<typename T, typename S> Node(T state, S cost, Node* parent);
};

class Domain
{
public:
    // Methods that are not templated
    list<Node> successorFn(Node* currentNode, Node* dummyValue);
    void print(vector<int> state);
    int getNextColumn(vector<int> state);
    bool previousRowExists(vector<int> state, int i);
    bool topLeftDiagonalExists(vector<int> state, int i);
    bool bottomLeftDiagonalExists(vector<int> state, int i);
    int getPathCost(Node* currentNode, Node* rootNode);
    int getDepth(Node* currentNode, Node* rootNode);
    
    // Creates initial state where chessVector is empty (no queens present so filled with zeros)
    template<typename T>
    Node createInitialState(T dummyState){
        vector<int> chessVector(9); // Creates initial vector of size 8 that will represent chessboard
        for (int i = 1; i<=8; ++i){
            chessVector[i] = 0;
        }
        Node rootNode = *new Node(chessVector, 1, &rootNode);
        return rootNode;    // Returns initial state
    }
    
    // Tests for goal state
    template<typename T, typename S>
    bool goalState(T currentState, S goalState){
        if (currentState[8]!=0)
            return true;
        else
            return false;
    }
    
    // Prints the solution/goal in a user-friendly way
    template <typename T, typename S>
    void printFinal(T currentState, S dummyValue){
        int chessBoard[8][8];
        for (int row = 1; row < 9; ++row){
            for (int column = 1; column < 9; ++column){
                if (currentState.state[column] == row)
                    chessBoard[row][column] = 1;
                else
                    chessBoard[row][column] = 0;
                cout<<chessBoard[row][column]<<" ";
            }
            cout<<endl;
        }
    }
};

#endif /* defined(__EightQueens__Domain__) */
