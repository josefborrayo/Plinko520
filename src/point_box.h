#ifndef __POINT_BOX_AGENT__H
#define __POINT_BOX_AGENT__H 

#include "enviro.h"

using namespace enviro;
using namespace std;

class point_boxController : public Process, public AgentInterface {

    public:
    point_boxController() : Process(), AgentInterface() {}

    void init() {
        update_labels();
    }

    void start() {}

    void update() {}

    void stop() {}

    /*! 
        Updates all point box labels with appropiate Score values
        Provides ability to add labels to invisible point boxes to track stats.
    */
    void update_labels(){
        int pos = abs(x());
        int labelx = -8;
        int labely = -25;
        if(pos < 20){
            label("100", -12, labely);
        } 
        else if(pos > 30 && pos < 70){
            label("75", labelx, labely);
        }
        else if(pos > 80 && pos < 120){
            label("50", labelx, labely);
        }
        else if(pos > 130 && pos < 170){
            label("25", labelx, labely);
        }
        else if(pos > 180 && pos < 220){
            label("50", labelx, labely);
        }
        else if(pos > 230 && pos < 270){
            label("25", labelx, labely);
        }
        else if(x()==-350){
            label("Balls Remaining:", 21, -5);
        }

        /*! stats */
        else if(x()==-348){
            label("Current Score:", 35, -22);
        }
        else if(x()==-346){
            label("(press 'R' to reset)", -125, -40);
        }
        else if(x()==349){
            label("High Score:", -130, -15);
        }
    }
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