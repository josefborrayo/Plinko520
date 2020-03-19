#ifndef __BACKGROUND_AGENT__H
#define __BACKGROUND_AGENT__H 

#include "enviro.h"

using namespace enviro;

//! Used to create background agents (Gradient).
class backgroundController : public Process, public AgentInterface {

    public:
    backgroundController() : Process(), AgentInterface() {}

    //! Nothing to do to initialize
    void init() {}
    //! Nothing to do to start
    void start() {}
    //! Nothing to do to update
    void update() {}
    //! Nothing to do to stop
    void stop() {}

};

//! See defs/background.json and config.json for usage
class background : public Agent {
    public:
    background(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    backgroundController c;
};

DECLARE_INTERFACE(background)

#endif