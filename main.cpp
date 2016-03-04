#include <iostream>
#include "tm.h"


#define ASCIINUMMOVE 48;
#define REJECT 11
#define ACCEPT 10

using namespace std;

string inspectLine(string line, TM* turing) {
    char currentState, nextState, currentSym, nextSym, direction;
    int curNumber, nextNumber;
    unsigned i = 1;
    string input;
    while(i < line.length() - 2) {
        if(line[i] == 'q') {
            i++;
            currentState = line[i];
            curNumber = int(currentState) - ASCIINUMMOVE;
            i+=2;
            currentSym = line[i];
            i+=4;
            nextState = line[i];
            switch(nextState) {
            case 'a':
                nextNumber = ACCEPT;
                break;
            case 'r':
                nextNumber = REJECT;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                nextNumber = nextState - ASCIINUMMOVE;
                break;
            default:
                cerr << "Error: Unknown next state symbol: " << nextState << endl;
            }

            i+=2;
            nextSym = line[i];
            i+=2;
            direction = line[i];
            i+=2;
            turing->addTransition(curNumber, nextNumber, currentSym, nextSym, direction);
            //cout << currentState << " " << currentSym << " " << nextState << " " << nextSym << " " << direction <<endl;
        } else {
            i++;
            while(line[i] != '#') {
                input += line[i];
                i++;
            }
            return input;
        }
    }
    return NULL;
}


char runString(TM turing, string input, int curState, unsigned strPos, int stepNO) {
    char answer = 'N';
    char tmpAns;
    if(curState == 10)
        return 'Y';
    if(curState == 11)
        return 'N';

    if(stepNO < 20) {
        char in;
        if(strPos >= input.length() || input[strPos] == 'e')
            in = '_';
        else in = input[strPos];
        switch(in) {
        case 'a':
            if(turing.q[curState].noA != 0) {
                for(int i = 0; i<turing.q[curState].noA; i++) {
                    tmpAns = runString(turing, input, turing.q[curState].a[i].toState->id, strPos + 1, stepNO + 1);
                    if(answer == 'Y')
                        return 'Y';
                    if(answer == 'N')
                        answer = tmpAns;
                }
            }
            break;
        case 'b':
            if(turing.q[curState].noB != 0) {
                for(int i = 0; i<turing.q[curState].noB; i++) {
                    tmpAns = runString(turing, input, turing.q[curState].b[i].toState->id, strPos + 1, stepNO + 1);
                    if(answer == 'Y')
                        return 'Y';
                    if(answer == 'N')
                        answer = tmpAns;
                }
            }
            break;
        case '_':
            if(turing.q[curState].no_ != 0) {
                for(int i = 0; i<turing.q[curState].no_; i++) {
                    tmpAns = runString(turing, input, turing.q[curState]._[i].toState->id, strPos + 1, stepNO + 1);
                    if(answer == 'Y')
                        return 'Y';
                    if(answer == 'N')
                        answer = tmpAns;
                }
            }
            break;
        }
    } else {
        return '?';
    }
    return answer;
}



int main()
{
    string line;
    string input;
    getline(cin, line);

    TM machine;
    input = inspectLine(line, &machine);

    char accepts = runString(machine, input, 0, 0, 0);

    if(accepts == 'Y')
        cout << "M stops and accepts w" << endl;
    else if (accepts == 'N')
        cout << "M stops and rejects w" << endl;
    else
        cout << "Do not know" << endl;

    return 0;
}

