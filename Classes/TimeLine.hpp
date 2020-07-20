//
//  TimeLine.hpp
//  Steps
//
//  Created by Abner Mercer on 16/9/9.
//
//

#ifndef TimeLine_hpp
#define TimeLine_hpp
#include <stdio.h>
#include "cocos2d.h"
//#include "Time.h"
#include "stdio.h"
#include "Vars.hpp"
#define ELEMENT_MAX_AMOUNT 10

//The Timer steps-on according to the frame rate
//Standard Frame-rate is 60 fps

using namespace cocos2d;

struct Element{
    int eleID;
    int beginTrigger;
    int endTrigger;
    float circleLength;
    bool trigger=false;
};




class TimeLine{
private:
    Element eleIndex[ELEMENT_MAX_AMOUNT];
    bool isRunning=false;
public:
    Scheduler gamePlay;
    TimeLine(int eleAmount)
    {
        for(int i=0;i<eleAmount;i++)
        {
            eleIndex[i].eleID=i;//eleIndexID sync with Array Index
        }
    }
    TimeLine()
    {
        CCLOG("This constructor is for demostration purpose.");
    }
    void gameStart();
    void gamePause(bool pauseSwitch);
    void gameEnd();
    void registElement(int elementIndex, int beginTrigger, int endTrigger, float circleLength);
    void timeUpdate(float currentTime);
    bool runStatus();
    bool getDeath(int eleID);
};


#endif /* TimeLine_hpp */
