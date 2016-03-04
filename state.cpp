#include "state.h"

state::state()
{
    noA = 0;
    noB = 0;
    no_ = 0;
    id = -1;
}

state* state::addTransition(char onSymbol, state* toState, char newSymbol, char direction) {
    transition* toAdd;
    int* no;

    switch(onSymbol) {
    case 'a':
        toAdd = a;
        no = &noA;
        break;
    case 'b':
        toAdd = b;
        no = &noB;
        break;
    case '_':
        toAdd = _;
        no = &no_;
        break;
    default:
        std::cerr << "Error occured: Unknown transition symbol: " << onSymbol << std::endl;
        return NULL;
    }

    toAdd[*no].onTape = onSymbol;
    toAdd[*no].toState = toState;
    toAdd[*no].newSymbol = newSymbol;
    toAdd[*no].direction = direction;
    (*no)++;
    return toState;
}
