#ifndef __BALL_AGENT__H
#define __BALL_AGENT__H 

#include "enviro.h"

using namespace enviro;
using namespace std;

//! See defs/ball.json and config.json for usage
class ballController : public Process, public AgentInterface {

    public:
    ballController() : Process(), AgentInterface(), ball_count(10) {}

    void init() {

        /*! teleport ball and reduce ball count */
        watch("screen_click", [&](Event &e) {
            if( (e.value()["x"]<350 && e.value()["x"]>-350) && (e.value()["y"]>-400 && e.value()["y"]<-200)){
                teleport(e.value()["x"], e.value()["y"],0);
                ball_count-=1;
            }
            clear_label();
        });
        
        /*! Physical reset of ball state and current score(not highscore)*/
        watch("keydown",[&](Event &k){
            auto r = k.value()["key"].get<std::string>();
            if(r == "r"){
                teleport(65, -1500,0);
                score = 0;
                ball_count=10;
            }
        });

        /*! Score tracking and ballcount reset.*/
        notice_collisions_with("bottom", [&](Event &b){
            double pos = abs(x());
            if(pos<20){
                score += 100;
            }
            else if(pos>30 && pos<70){
                score += 75;
            }
            else if(pos>80 && pos<120){
                score += 50;
            }
            else if(pos>130 && pos<170){
                score += 25;
            }
            else if(pos>180 && pos<220){
                score += 50;
            }
            else if(pos>230 && pos<270){
                score += 25;
            }

            if(ball_count==10){
                score = 0;
            }
            
            if(score > highscore){
                highscore = score;
            }
            if(ball_count <= 0){
                    score = 0;
                    ball_count=10;
                }
        });      
        
    }
    //! Nothing to do to start
    void start() {}

    /*! move ball and apply label updates*/
    void update() {
        omni_apply_force(0.0,500.0);
        Agent& bcount_stat = find_agent(18);
        bcount_stat.label(std::to_string(ball_count), 125, -5);
        Agent& spb_stat = find_agent(20);
        spb_stat.label(std::to_string((int) score), 125, -22);
        Agent& hs_stat = find_agent(23);
        hs_stat.label(std::to_string((int) highscore), -55, -15);
    }

    //! Nothing to do to stop
    void stop() {}

    double score, highscore;
    int ball_count;
    
};

//! See defs/ball.json and config.json for usage
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