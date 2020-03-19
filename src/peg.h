#ifndef __PEG_AGENT__H
#define __PEG_AGENT__H 

#include "enviro.h"

using namespace enviro;

//! See src/coordinator.json for usage
class pegController : public Process, public AgentInterface {

    public:
    pegController() : Process(), AgentInterface() {}

    //! Nothing to do to initialize
    void init() {}
    //! Nothing to do to start
    void start() {}
    //! Nothing to do to update
    void update() {}
    //! Nothing to do to stop
    void stop() {}
};

//! See src/coordinator.json for usage
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