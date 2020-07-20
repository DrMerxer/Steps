//
//  groundScale.hpp
//  Steps
//
//  Created by 张学祎 on 2016/9/29.
//
//

#ifndef groundScale_hpp
#define groundScale_hpp
#include <stdio.h>
#include "cocos2d.h"
#include "mapGenerator.h"
using namespace cocos2d;

class groundScale
{
public:
    static int xlength(mapGenerator map);
    static int ylength(mapGenerator map);
};

#endif /* groundScale_hpp */
