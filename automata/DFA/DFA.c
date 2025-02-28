//
// 2021 Spring - Automata and Formal Languages (03)
// Homework #1: Building a DFA simulator that accepts strings with prefix bbab
//
// Copyright (c) Prof. Jaehyeong Sim
// Department of Computer Science and Engineering, Ewha Womans University
//

#include <stdio.h>

#define MAX_NUM_STATES 10
#define MAX_NUM_INPUTS 16
#define NUM_SYMBOLS 2

// Definition of DFA
struct DFA {
    int num_states;                         // the number of DFA states
    char symbols[NUM_SYMBOLS];              // symbols 
    int trans[MAX_NUM_STATES][NUM_SYMBOLS]; // transitions
    int idx_init;                           // an initial state
    int idx_isFinal[MAX_NUM_STATES];        // final states
};

int main(int argc, char *argv[])
{
    // declare struct DFA
    struct DFA u1;

    // assign values to member variables
    u1.num_states = 5;
    u1.symbols[0] = 'a';
    u1.symbols[1] = 'b';
    u1.idx_init = 1;
    u1.idx_isFinal[5] = 1;

    // do transitions according to input characters
    int currentState = u1.idx_init;
    for (int i = 0; i < MAX_NUM_INPUTS; i++) {
        char inchar = argv[1][i];
        if (inchar== '\0') {
            break;
        }
        if ((inchar != u1.symbols[0]) && (inchar != u1.symbols[1])) {
            currentState += 5;
            break;
        }
        else if ((currentState == 1) || (currentState == 2) || (currentState == 4)) {
            if (inchar == u1.symbols[1]) {
                currentState += 1;
            }
            else {
                break;
            }
        }
        else if (currentState == 3) {
            if (inchar == u1.symbols[0]) {
                currentState += 1;
            }
            else {
                break;
            }
        }
    }

    // print the output
    if (u1.idx_isFinal[currentState] == 1) 
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}