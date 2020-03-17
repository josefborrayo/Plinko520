#ifndef __POINT_BOX_AGENT__H
#define __POINT_BOX_AGENT__H 

#include "enviro.h"

using namespace enviro;

class point_boxController : public Process, public AgentInterface {

    public:
    point_boxController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class point_box : public Agent {
    public:
    point_box(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    point_boxController c;
};

DECLARE_INTERFACE(point_box)

#endif