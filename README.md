# Plinko520

## Overview

This game was developed as a final project for UW's EEP520 Software for Embedded Systems course, utilizing Elma and Enviro. 

A modified version of Plinko was implemented, allowing the user 10 chances to score a maximum of 1000 points.

***Future modifications may include bonus chances given a streak of 100 point scores to further increase the highscore as well as unlockable plinko balls(dependant on highscore)***

![Game image](docs/gameface.PNG)



## Installation/Game-Setup

To begin, install docker using a method most suitable for your supported platform here:
https://docs.docker.com/install/

### 1. Cloning this Repo
Using a command line, navigate to a suitable location to contain this program and run the following command:
```
> git clone https://github.com/josefborrayo/Plinko520
```


This project utilizes version 1.6 of enviro, more info here: https://github.com/klavinslab/enviro

### 2. Starting Docker
Run one of the following suitable for your platform:

**MAC**
```
> docker run -v $PWD/clonelocation:/source -it klavins/520w20:cpp bash
```

**WINDOWS**
```
> docker run -p80:80 -p8765:8765 -v /c/Users/username/clonelocation:/source -it klavins/enviro:v1.6 bash
```
### 3. Starting enviro
After initializing your docker instance run the following two commands
```
> esm start
> enviro
```
### 4. Playing the game
Navigate to localhost in your browser to see the game ready to play!

Note:
Click anywhere in the top portion of the board to spawn in your Plinko ball. 

Resetting the game only resets your current score and ball count, highscores stay, Good Luck!


## Summary

### Key Challenges
The main challenges of this project were spawning pegs and adding data labels. To overcome the first issue i utilized Dr. Klavin's spawner example to create a coordinator agent that runs in the background, I was initially trying to spawn these pegs while in the peg agent as to avoid creating 120+ static peg agents in the config.json file. For data labels I decided to modify the specific stats that i wanted to update, within ball.h, so I could track scores and update them in one fell swoop as opposed to emitting events from ball and watching for them in point_box.

### Aknowledgements
Special thanks to Dr. Klavins for providing example code as well as the eviro platform to help support the developement of this project and thanks to John V. for assisting in debugging issues (my reset keypress was crashing enviro :D).


