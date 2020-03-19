#ifndef __COORDINATOR_AGENT__H
#define __COORDINATOR_AGENT__H 

#include "enviro.h"

using namespace enviro;

class CoordinatorController : public Process, public AgentInterface {

    public:
    CoordinatorController() : Process(), AgentInterface() {}

    void init() {
        spawn_pegs();
    }
    /*! spawns pegs to create the board */
    void spawn_pegs(){
        int start_x = -288;
        int start_y = -200;
        separation = 50;
        for ( int rows = 0; rows < 10; rows++){
            shift = separation/2;
            if(rows%2==0){
                shift = 0;
            }
            for ( int cols = 0; cols < 12; cols++ ) {
                Agent& p = add_agent("Peg", start_x + cols * separation + shift, start_y + rows * separation, 0, PEG_STYLE);
            }
        }
    }
    void start() {}
    void update() {}
    void stop() {}

    int separation, shift;

    const json PEG_STYLE = { 
                    {"fill", "#b5651d"},
                    {"stroke", "none"}
                };
};

class Coordinator : public Agent {
    public:
    Coordinator(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    CoordinatorController c;
};

DECLARE_INTERFACE(Coordinator)

#endif