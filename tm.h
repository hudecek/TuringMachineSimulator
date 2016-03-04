#ifndef TM_H
#define TM_H

#include "state.h"


class TM
{
public:
    TM();
    state q[12];
    state* addTransition(int from, int to, char onSymbol, char newSymbol, char direction);
};

#endif // TM_H
