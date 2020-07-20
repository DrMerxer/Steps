#include "ObjSceneManager.h"
#include "My3DLayer.h"
#include "My2DLayer.h"
#include "CameraUtil.h"
#include "Vars.hpp"
//USING_NS_CC;
using namespace cocos2d;

//实现ObjSceneManager类中的createScene方法
Scene* ObjSceneManager::createScene()
{
    //创建一个场景对象
    auto scene = Scene::create();

    //获取可见区域尺寸
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //创建摄像机
    Camera* camera = Camera::createPerspective
    (
    	35, 										//摄像机视角 40-60之间是合理值
    	visibleSize.width/visibleSize.height, 		//视口长宽比
    	1, 											//near
    	100000										//far
    );
    camera->setCameraFlag(CameraFlag::USER1);		//设置摄像机编号标志
    CameraUtil::calCamera(0,0,0,0,camera_r,camera);				//计算摄像机参数并设置
    scene->addChild(camera);						//将摄像机添加到场景中

    //创建一个3D布景对象
    My3DLayer* layer3D = My3DLayer::create();
    layer3D->camera=camera;
    //将3D布景添加到场景中
    scene->addChild(layer3D);

    //创建一个2D布景对象
    My2DLayer* layer2D = My2DLayer::create();
    //将2D布景添加到场景中
    scene->addChild(layer2D);

    //返回场景
    return scene;
}
