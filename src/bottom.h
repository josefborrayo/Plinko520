#ifndef __BOTTOM_AGENT__H
#define __BOTTOM_AGENT__H 

#include "enviro.h"

using namespace enviro;

class bottomController : public Process, public AgentInterface {

    public:
    bottomController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

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