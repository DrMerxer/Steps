//
//  groundScale.cpp
//  Steps
//
//  Created by 张学祎 on 2016/9/29.
//
//

#include "groundScale.hpp"
#include "Vars.hpp"
int groundScale::xlength(mapGenerator map)
{
    int max=0;
    for(int i=0;i<arrayLength;i++)
    {
        if(map.getX(i)>max)
        {
            max=map.getX(i);
        }
    }
    return (max*cube_x/ground_x)+1;
}

int groundScale::ylength(mapGenerator map)
{
    int max=0;
    for(int i=0;i<arrayLength;i++)
    {
        if(map.getY(i))
        {
            max=map.getY(i);
        }
    }
    return (max*cube_x/ground_x)+1;
}
