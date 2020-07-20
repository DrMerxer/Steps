//
//  TrapAnimManager.hpp
//  Steps
//
//  Created by 张学祎 on 2016/10/16.
//
//

#ifndef TrapAnimManager_hpp
#define TrapAnimManager_hpp

#include <stdio.h>
#include <cocos2d.h>

using namespace cocos2d;

class TrapAnimManager{
public:
    TrapAnimManager(Layer layer);
    void initTrapLength(int length);
    void animCUBE(Sprite3D cube);
    void animONE(Layer tdlayer); //td=3d
    void animTWO(Layer tdlayer);
};

#endif /* TrapAnimManager_hpp */
