#ifndef __My3DLayer_H__
#define __My3DLayer_H__

#include "cocos2d.h"
#include "mapGenerator.h"
#include <cmath>
#include "ControlLayer.hpp"
#include "TimeLine.hpp"
#include "groundScale.hpp"
using namespace cocos2d;

#define X_MAX 200
#define X_V 1.0f

class My3DLayer : public cocos2d::Layer
{
public:
	Camera* camera;//摄像机
	Sprite3D* (msp)[1024];//地面obj
	Sprite3D* (path)[1024];//path
    Sprite3D* (pathShadow)[1024];
	Sprite3D* spC3tNH;//女孩骨骼动画模型
	Animate3D* animateNH;//女孩骨骼动画
	Sprite3D* box;
    int mapLength;
	//Camera&Box Moving Parameters
	int cx=0;
	int cy=0;
    
    ControlLayer control;
    
	//初始化的方法
	virtual bool init();

	int directionPointer(int progressCount,mapGenerator map);

    bool onMyTouchBegan(Touch *touch, Event *event);		//触控开始事件的回调方法
	void onMyTouchMoved(Touch *touch, Event *event);		//触控点移动事件的回调方法
	void onMyTouchEnded(Touch *touch, Event *event);		//触控结束事件的回调方法
	void onMyTouchCancelled(Touch *touch, Event *event);	//触控终止事件的回调方法
    void updateTimeLine(float dt);
    static void setFlag();
    
    
    //Cocos2d-x中定义的一个宏，创建指定类型的对象
    //并做好相应的初始化与释放工作
    CREATE_FUNC(My3DLayer);
};



#endif
