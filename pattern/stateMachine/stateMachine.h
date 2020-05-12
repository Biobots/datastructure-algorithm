#ifndef SM_MACHINE_H
#define SM_MACHINE_H

#include <common.h>
#include <state.h>

#define LOOP_STATE(S_) \
    case State::S_: \
        internalLoop<State::S_>(); \
        break; \

class StateMachine
{
private:
    State curState;
public:
    StateMachine(State initialState)
    {
        curState = initialState;
    }
    ~StateMachine()
    {
        //if(curState != nullptr) delete curState; curState = nullptr;
    }
    void loop()
    {
        switch (curState)
        {
        LOOP_STATE(Top)
        LOOP_STATE(A)
        LOOP_STATE(B)
        }
    }
    void takeEvent()
    {
        Event e = Event::Init;
    }
};

#endif