#include "tm.h"

TM::TM()
{
    for(int i = 0; i<=11; i++) {
        q[i].id = i;
    }
}

state* TM::addTransition(int from, int to, char onSymbol, char newSymbol, char direction) {
    return q[from].addTransition(onSymbol, &q[to], newSymbol, direction);
}

