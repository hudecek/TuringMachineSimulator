#ifndef STATE_H
#define STATE_H

#include <iostream>


class state;

typedef struct transition {
    state* toState;
    char onTape;
    char newSymbol;
    char direction;
} transition;

class state
{
public:
    state();
    state* addTransition(char onSymbol, state* toState, char newSymbol, char direction);

    transition a[11];
    int noA;
    transition b[11];
    int noB;
    transition _[11];
    int no_;

    int id;
};

#endif // STATE_H
