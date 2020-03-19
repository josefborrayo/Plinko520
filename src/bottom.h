#ifndef __BOTTOM_AGENT__H
#define __BOTTOM_AGENT__H 

#include "enviro.h"

using namespace enviro;

//! See defs/bottom.json and config.json for usage
class bottomController : public Process, public AgentInterface {

    public:
    bottomController() : Process(), AgentInterface() {}

    //! Nothing to do to initialize
    void init() {}
    //! Nothing to do to start
    void start() {}
    //! Nothing to do to update
    void update() {}
    //! Nothing to do to stop
    void stop() {}

};

//! See defs/bottom.json and config.json for usage
class bottom : public Agent {
    public:
    bottom(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    bottomController c;
};

DECLARE_INTERFACE(bottom)

#endif