#ifndef __PEG_AGENT__H
#define __PEG_AGENT__H 

#include "enviro.h"

using namespace enviro;

class pegController : public Process, public AgentInterface {

    public:
    pegController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    
    void update() {}
    void stop() {}
};

class peg : public Agent {
    public:
    peg(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    pegController c;
};

DECLARE_INTERFACE(peg)

#endif