//
//  MissionData.hpp
//  Steps_alpha
//
//  Created by 张学祎 on 2016/10/17.
//
//

#ifndef MissionData_hpp
#define MissionData_hpp
#define MissionLength 10
#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class MissionData
{
private:
    int currentMission;
    int attrCircleLength[MissionLength];
    int attrTriggerBegin[MissionLength];
    int attrTriggerEnd[MissionLength];
public:
    int getLength(int ID);
    int getBegin(int ID);
    int getEnd(int ID);
    
    
};

#endif /* MissionData_hpp */
