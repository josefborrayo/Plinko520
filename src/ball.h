#ifndef __BALL_AGENT__H
#define __BALL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class ballController : public Process, public AgentInterface {

    public:
    ballController() : Process(), AgentInterface() {}

    void init() {
        watch("screen_click", [&](Event &e) {
            teleport(e.value()["x"], e.value()["y"],0);
        });
        
    }
    void start() {}
    void update() {
        omni_apply_force(0.0,500.0);
    }
    void stop() {}

};

class ball : public Agent {
    public:
    ball(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    ballController c;
};

DECLARE_INTERFACE(ball)

#endif