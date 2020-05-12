#ifndef SM_STATE_H
#define SM_STATE_H

#include <common.h>

enum class State
{
    Top,

    A,
    B,
    C,

    D,
    E
};

enum class Event
{
    Init,
    Loop,
    Stop
};

template<State cur, Event trig>
void eventProcess()
{
    printf("no specific function, exiting!");
}

template<State pre, State nxt>
void transition()
{
    printf("no specific function, exiting!");
}

template<State cur>
void internalLoop()
{
    printf("no specific function, exiting!");
}

template<State cur>
void upLayer()
{
    printf("no specific function, exiting!");
}

template<>
void eventProcess<State::Top, Event::Init>()
{
    printf("Initializing!");
}

template<>
void transition<State::Top,State::A>()
{
    printf("from top to A");
};

template<>
void internalLoop<State::Top>()
{
    printf("top looping");
};

template<>
void internalLoop<State::A>()
{
    printf("A looping");
};

template<>
void upLayer<State::A>()
{
    printf("back to top");
};

#endif