//
//  ControlLayer.hpp
//  Steps
//
//  Created by Abner Mercer on 16/8/27.
//
//

#ifndef _ControlLayer_hpp_
#define _ControlLayer_hpp_


#include <stdio.h>
#include "cocos2d.h"
#include "CameraUtil.h"
#include "TimeLine.hpp"
#include "Vars.hpp"
using namespace cocos2d;

//#define YJ_CUTIL 40
//#define CAMERA_R_CUTIL 800

#define DURATION 0.15f
//#define CUBE_HEIGHT
//1 (sec)

class ControlLayer
{
    
    TimeLine tlc;//Time Line Control Object
    
public:
    
    void moveToPosition(int x, int y, Sprite3D* cube, Camera* camera,int direction);
    
    int Xcalc(int x);
    
    int Ycalc(int y);
    
    void run(int x, int y, Sprite3D* cube, Camera* camera, int direction);
    
    void setFlag();
    
};



#endif /* ControlLayer_hpp */
