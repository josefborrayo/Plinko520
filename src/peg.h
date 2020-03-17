#ifndef __PEG_AGENT__H
#define __PEG_AGENT__H 

#include "enviro.h"

using namespace enviro;

class pegController : public Process, public AgentInterface {

    public:
    pegController() : Process(), AgentInterface() {}

    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "n" ) {
                Agent& p = add_agent("Peg", -350, -150, 0, PEG_STYLE);
                //spawn_pegs();
            } 
        });
    }
    void start() {}
    void spawn_pegs(){
        Agent& p = add_agent("Peg", -350, -150, 0, PEG_STYLE);
        /*!
        y_separation = 15;
        x_separation = 15;
        for ( int rows = 0; rows < 20; rows++){
            shift = 10;
            if(rows%2==0){
                shift = 0;
            }
            for ( int cols = 0; cols < 10; cols++ ) {
                Agent& p = add_agent("Peg", -350 + cols*y_separation+ shift, -150 + rows*x_separation, 0, PEG_STYLE);
            }
        }*/
    }
    void update() {
    }
    void stop() {}

    int y_separation, x_separation, shift;

    const json PEG_STYLE = { 
                    {"fill", "#b5651d"}
                };
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