//
//  TimeLine.cpp
//  Steps
//
//  Created by Abner Mercer on 16/9/9.
//
//  Element registering HINT !!!!
//  THE REGISTERING TIME SPACE IS 0.1 SECOND INT TYPE
//  NO OTHER TYPE IS ALLOWED.

#include "TimeLine.hpp"

using namespace cocos2d;



void TimeLine::gameStart()
{
    stime=0.0f;
    CCLOG("gameStart()");
    //schedule(schedule_selector(TimeLine::updateCustom),0.1f,kRepeatForever,0);
    isRunning=true;
}

void TimeLine::gamePause(bool pauseSwitch)
{
    if(pauseSwitch) gamePlay.pauseTarget(this);
    else gamePlay.resumeTarget(this);
}

void TimeLine::gameEnd()
{
    gamePlay.unscheduleAll();
}

void TimeLine::registElement(
                             int elementIndex,
                             int beginTrigger,
                             int endTrigger,
                             float circleLength){
    
    eleIndex[elementIndex].beginTrigger=beginTrigger;
    eleIndex[elementIndex].endTrigger=endTrigger;
    eleIndex[elementIndex].circleLength=circleLength;
}

bool TimeLine::getDeath(int eleID)
{
    return true;
}

bool TimeLine::runStatus()
{
    return isRunning;
}

void TimeLine::timeUpdate(float currentTime)
{
    stime=currentTime;
}
