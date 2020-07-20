#include "My3DLayer.h"
//#include "CameraUtil.h"
//#include "tileGenerator.hpp"
//#define cube_x 50
//#define path_height 0
//#define cube_height 70
//#define shadow_height 1
//#define map_addrp 26
#include "Vars.hpp"
USING_NS_CC;
using namespace cocos2d;

mapGenerator cmap;
int progressCount=0;//Gaming Progress Count
int updateCount=0;//Update Counter
int updateDirection=0;
//实现My3DLayer类中的init方法，初始化布景
bool My3DLayer::init()
{
	//调用父类的初始化
    if ( !Layer::init() )
    {
        return false;
    }
    
    //Setup timer
    schedule(schedule_selector(My3DLayer::updateTimeLine), 0.1f);
    
    //Add Box Model
    box=Sprite3D::create("c3b/cube.obj","c3b/cubeskin.png");
    box->setScale(0.8f);
    box->setPosition3D(Vec3(0,cube_height,0));
    //box->ignoreAnchorPointForPosition(true);
    box->setAnchorPoint(Vec2(0,0));
    this->addChild(box);


    //Generate Map
    mapLength=50;
    cmap.mapGen(mapLength,4);
    for(int i=0;i<mapLength;i++)
    {
        switch(cmap.mapGetType(i))
        {
            case 0:
                path[i]=Sprite3D::create("obj/path.obj","obj/path.png");
                path[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),path_height,cube_x*(cmap.getY(i))));
                path[i]->setScale(1.0f);
                pathShadow[i]=Sprite3D::create("obj/shadow.obj","obj/shadow.png");
                pathShadow[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),shadow_height,cube_x*(cmap.getY(i))));
                pathShadow[i]->setScale(1.0f);
                pathShadow[i]->setOpacity(60);
                this->addChild(path[i],1);
                this->addChild(pathShadow[i],2);
                break;
                
            case 1:
                path[i]=Sprite3D::create("c3b/trap1.c3b");
                path[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),path_height,cube_x*(cmap.getY(i))));
                path[i]->setScale(1.0f);
                pathShadow[i]=Sprite3D::create("obj/shadow.obj","obj/shadow.png");
                pathShadow[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),shadow_height,cube_x*(cmap.getY(i))));
                pathShadow[i]->setScale(1.0f);
                pathShadow[i]->setOpacity(60);
                CCLOG("RUNS");
                this->addChild(path[i],1);
                this->addChild(pathShadow[i],2);
                break;
            case 2:
                path[i]=Sprite3D::create("obj/trap2.obj");
                path[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),path_height,cube_x*(cmap.getY(i))));
                path[i]->setScale(1.0f);
                /*
                pathShadow[i]=Sprite3D::create("obj/shadow.obj","obj/shadow.png");
                pathShadow[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),shadow_height,cube_x*(cmap.getY(i))));
                pathShadow[i]->setScale(1.0f);
                pathShadow[i]->setOpacity(60);
                */
                CCLOG("RUNS");
                this->addChild(path[i],1);
                //this->addChild(pathShadow[i],2);
                break;
            case 3:
                break;
        }
        /*
    	path[i]=Sprite3D::create("obj/path.obj","obj/path.png");
    	path[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),path_height,cube_x*(cmap.getY(i))));
    	path[i]->setScale(1.0f);
        pathShadow[i]=Sprite3D::create("obj/shadow.obj","obj/shadow.png");
        pathShadow[i]->setPosition3D(Vec3(cube_x*(cmap.getX(i)),shadow_height,cube_x*(cmap.getY(i))));
        pathShadow[i]->setScale(1.0f);
        pathShadow[i]->setOpacity(60);*/
        
        //pathShadow[i]->setForce2DQueue(true);
        //pathShadow[i]->setForceDepthWrite(true);
        //pathShadow[i]->setColor(cc.c3b(0,0,0));
        
    }
    
//    加入地面Obj模型-----------------------------------------------------SEALED-----------------//
//    tileGenerator tileMap=*new tileGenerator(map);
    
//    Sprite3D* (sp3Floor)[length];
//    for(int i=0;i<length;i++)
//    {
//        sp3Floor[i]=Sprite3D::create("obj/plane.obj", "pic/plane.png");
//        sp3Floor[i]->setScale(1.0f);
//        sp3Floor[i]->setPosition3D(Vec3(tileMap.getX(i)*100,0,tileMap.getY(i)*100));
//        CCLOG("%d,%d",tileMap.getX(i),tileMap.getY(i));
//        //this->addChild(sp3Floor[i], 1);
//    }
    
//    Sprite3D* baseFloor=Sprite3D::create("obj/plane.obj");
//    this->addChild(baseFloor);
//    Texture2D::TexParams texParam;
//    Image *textImage = new (std::nothrow) cocos2d::Image();
//    textImage->initWithImageFile("pic/plane.png");
//    cocos2d::Texture2D *texture = new (std::nothrow)cocos2d::Texture2D();
//    texture->initWithImage(textImage);
//    //Texture2D::TexParams texParam={GL_LINEAR,GL_LINEAR,GL_REPEAT,GL_REPEAT};
//    texParam.wrapS = GL_REPEAT;
//    texParam.wrapT = GL_REPEAT;
//    texParam.minFilter = GL_LINEAR;
//    texParam.magFilter = GL_LINEAR;
//    texture->setTexParameters(texParam);
//    texture->setMaxS(0.1f);
//    texture->setMaxT(0.1f);
//    baseFloor->setScale(1.0f);
//    baseFloor->setTexture(texture);
//    baseFloor->getMesh()->getTexture()->setTexParameters(texParam);
    
    int miter=0;
    int xlen=0;int ylen=0;
    xlen=groundScale::xlength(cmap);
    ylen=groundScale::ylength(cmap);
    for(int i=0;i<ylen+1;i++)
    {
        for(int j=0;j<xlen+1;j++)
        {
            msp[miter]=Sprite3D::create("obj/ground.obj","pic/desk.png");
            msp[miter]->setPosition3D(Vec3(map_addrp + i * 2500, 0, map_addrp + j * 2500));
            this->addChild(msp[miter]);
            miter++;
        }
    }
    
    

    //Add Light----------------------------------------------------------
	auto dirLight2 = DirectionLight::create(
			Vec3(0.4f,-0.7f,0.5f),
			Color3B::WHITE
			);
    this->addChild(dirLight2);

	/*
	//创建并播放骨骼动画
	auto animation = Animation3D::create("c3b/girl.c3b");
	if (animation)
	{
		animateNH = Animate3D::create(animation);
		//骨骼动画速度
		animateNH->setSpeed(animateNH->getSpeed()*0.9f);
		spC3tNH->runAction(RepeatForever::create(animateNH));
	}
	 */

	//设置此布景层渲染用摄像机
	this->setCameraMask((unsigned short)CameraFlag::USER1);

	//设置定时回调


	//触控监听
	auto listenerTouch = EventListenerTouchOneByOne::create();
	listenerTouch->onTouchBegan = CC_CALLBACK_2(My3DLayer::onMyTouchBegan, this);
	listenerTouch->onTouchMoved = CC_CALLBACK_2(My3DLayer::onMyTouchMoved, this);
	listenerTouch->onTouchEnded = CC_CALLBACK_2(My3DLayer::onMyTouchEnded, this);
	listenerTouch->onTouchCancelled = CC_CALLBACK_2(My3DLayer::onMyTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerTouch,this);
    

    return true;
}

/*
void My3DLayer::update(float delta)
{
	xc=xc+xcv;
	if(xc>X_MAX)
	{
		xc=X_MAX;
		xcv=-X_V;
		//骨骼动画反放
		animateNH->setSpeed(-1.0f*animateNH->getSpeed());
	}
	if(xc<-X_MAX)
	{
		xc=-X_MAX;
		xcv=X_V;
		//骨骼动画不反放
		animateNH->setSpeed(-1.0f*animateNH->getSpeed());
	}
	spC3tNH->setPosition3D( Vec3( xc,0,-250) );
}
*/

//开始触控事件的处理方法
bool My3DLayer::onMyTouchBegan(Touch *touch, Event *event)
{
    //CCLOG("%d",runs);
    CameraUtil::yj=10;
    //CCLOG("%f",CameraUtil::yj);
	return true;
}

//触控移动事件的处理方法
void My3DLayer::onMyTouchMoved(Touch *touch, Event *event)
{
    
}

//触控结束事件的处理方法

void My3DLayer::onMyTouchEnded(Touch *touch, Event *event)
{
    
    //CCLOG("%d",runs);
    if(runs)
    {
        
        My3DLayer::setFlag();
        //CCLOG("%d",runs);
        int direction=directionPointer(progressCount, cmap);
        progressCount++;
        CCLOG("%d",progressCount);
        control.run(
                    cmap.getX(progressCount),
                    cmap.getY(progressCount),
                    box,
                    camera,
                    direction
                    );
//        if(progressCount>5)
//        {
//            this->removeChild(path[progressCount-5]);
//            this->removeChild(pathShadow[progressCount-5]);
//        }
    }
    //CCLOG("%d:FINALE",runs);
}

//触控终止事件的处理方法
void My3DLayer::onMyTouchCancelled(Touch *touch, Event *event)
{
	//调用onMyTouchEnded方法
	//onMyTouchEnded(touch, event);
    this->removeAllChildren();
}


void My3DLayer::setFlag()
{
    //CCLOG("RUN");
    runs=false;
    //CCLOG("%d",runs);
}

int My3DLayer::directionPointer(int progressCount, mapGenerator map)
{
    if(map.getX(progressCount+1)-map.getX(progressCount)==0)
    {
        return 1;
    }else if(map.getY(progressCount+1)-map.getY(progressCount)==0){
        return 0;
    }
    return 0;
}

void My3DLayer::updateTimeLine(float dt)
{
    stime=stime+0.1f;
    log("%d",stime);
}

