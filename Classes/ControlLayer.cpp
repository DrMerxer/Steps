//
//  ControlLayer.cpp
//  Steps
//
//  Created by Abner Mercer on 16/8/27.
//
//
#include "ControlLayer.hpp"
#include "Vars.hpp"
using namespace cocos2d;

float camY=sin(CameraUtil::yj*3.1415926535898/180)*CAMERA_R;//Camera Height(Y)

void ControlLayer::moveToPosition(int x, int y, cocos2d::Sprite3D *cube, cocos2d::Camera *camera, int direction)
{
    //CCLOG("%d",CameraUtil::yj);
    
    
    
    FiniteTimeAction* moveActCube=MoveTo::create(DURATION, Vec3(x*cube_x,cube_height,y*cube_x));
    FiniteTimeAction* moveActCamera=MoveTo::create(DURATION, Vec3(Xcalc(x*cube_x),camY,Ycalc(y*cube_x)));
    FiniteTimeAction* moveYUp=MoveBy::create(DURATION/2, Vec3(0,cube_x/2,0));
    FiniteTimeAction* moveYDown=MoveBy::create(DURATION/2, Vec3(0,-cube_x/2,0));
    FiniteTimeAction* rotateActCube;
    if(direction==0)
    {
        rotateActCube=RotateBy::create(DURATION,Vec3(0,0,90));
        cube->setRotation3D(Vec3(0,0,0));
    }else{
        rotateActCube=RotateBy::create(DURATION,Vec3(90,0,0));
        cube->setRotation3D(Vec3(0,0,0));
    }
    
    cube->runAction(moveActCube);
    cube->runAction(rotateActCube);
    cube->runAction(Sequence::create(moveYUp,moveYDown, NULL));
    camera->runAction(
                      Sequence::create(
                                       moveActCamera,//MoveTo::create(DURATION, Vec3(Xcalc(x*50),camY,Ycalc(y*50))),
                                       CallFuncN::create(CC_CALLBACK_0(ControlLayer::setFlag, this)),
                                       NULL
                                      )
                      );
}

int ControlLayer::Xcalc(int x)
{
    float cxz=cos(40*3.1415926535898/180)*CAMERA_R;
    float cx=sin(CameraUtil::degree*3.1415926535898/180)*cxz+x+30;
    return cx;
}


int ControlLayer::Ycalc(int y)
{
    float cxz=cos(40*3.1415926535898/180)*CAMERA_R;
    float cz=cos(CameraUtil::degree*3.1415926535898/180)*cxz+y+30;
    return cz;
}

void ControlLayer::run(int x, int y, Sprite3D* cube, Camera* camera, int direction)
{
    moveToPosition(x, y, cube, camera, direction);
    if(!tlc.runStatus())
    {
        tlc.gameStart();
    }
}

void ControlLayer::setFlag()
{
    runs=true;
}

