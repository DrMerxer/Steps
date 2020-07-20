#ifndef __CameraUtil_H__
#define __CameraUtil_H__

#include "cocos2d.h"
#include "Vars.hpp"
using namespace cocos2d;

#define CAMERA_R 1100

class CameraUtil
{
  public:
    static float degree;//摄像机朝向角度
    static float yj;//摄像机仰角
    static void calCamera(float yjSpan,float cxSpan,int x,int y,int camera_r,Camera* camera)
    {

        //计算当前观察角度下摄像机的位置
        float cy=sin(yj*3.1415926535898/180)*camera_r;
	    float cxz=cos(yj*3.1415926535898/180)*camera_r+130;

	    //DO NOT TOUCH
		float cx=sin(degree*3.1415926535898/180)*cxz+x+130;
		float cz=cos(degree*3.1415926535898/180)*cxz+y+130;
        
		//计算当前摄像机的UP向量
        float upY=cos(yj*3.1415926535898/180);
        float upXZ=sin(yj*3.1415926535898/180);
        float upX=-upXZ*sin(degree*3.1415926535898/180);
        float upZ=-upXZ*cos(degree*3.1415926535898/180);
        
		//更新摄像机参数
		camera->setPosition3D(Vec3(cx,cy,cz));
		camera->lookAt(Vec3(0+x,50,0+y), Vec3(upX,upY,upZ));
    }
    
    int CameraDATX(int x);
    
    int CameraDATY(int y);
    
};


#endif
