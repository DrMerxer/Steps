#include "mapGenerator.h"
#include <stdlib.h>
#include <time.h>

#define TRAP_TYPE 4

//difficulty is the rate that generate more trap. 0~10 Higher = Easier.

void mapGenerator::mapGen(int length,int difficulty)
{
	int biter=0;//iterator when generating blocks
	for(int i=0;i<arrayLength;i++)
	{
		coorMap.x[i]=0;
		coorMap.y[i]=0;
		coorMap.cubeType[i]=0;
	}

	int periodSto=0;//iterator when generating turns
	int xpos=0;//X position marker
	int ypos=0;//y position marker
	bool turn=false;
	srand((unsigned)time(0));//Reset rand-seed
	while(biter<length)
	{
		periodSto=(rand()%(9-3))+3; //Calculate straight road length
		if(turn)
		{
			for(int i=0;i<periodSto;i++)
			{
				coorMap.x[biter]=xpos;
				coorMap.y[biter]=ypos;
				if((rand()%10)>difficulty)//
				{
                    if(i!=0)
                        coorMap.cubeType[biter]=(rand()%(TRAP_TYPE))+1;
                    //+1 to isolate the normal road.
                }else{
                    coorMap.cubeType[biter]=0;
                }
				xpos++;
				biter++;
			}
			periodSto=0;
			turn=!turn;
		}else{
			for(int i=0;i<periodSto;i++)
			{
				coorMap.x[biter]=xpos;
				coorMap.y[biter]=ypos;
				if((rand()%10)>difficulty)
				{
                    if(i!=0)
                        coorMap.cubeType[biter]=(rand()%(TRAP_TYPE))+1;
                }else{
                    coorMap.cubeType[biter]=0;
                }
				ypos++;
				biter++;
			}
			periodSto=0;
			turn=!turn;
		}
	}
}

void mapGenerator::mapClean()
{
	for(int i=0;i<arrayLength;i++)
	{
		coorMap.x[i]=0;
		coorMap.y[i]=0;
		coorMap.cubeType[i]=0;
	}
}

int mapGenerator::getX(int serial)
{
	return coorMap.x[serial];
}
int mapGenerator::getY(int serial)
{
	return coorMap.y[serial];
}
int mapGenerator::mapGetType(int serial)
{
	return coorMap.cubeType[serial];
}

void mapGenerator::mapSet(int x, int y, int cubeType, int serial)
{
    coorMap.x[serial]=x;
    coorMap.y[serial]=y;
    coorMap.cubeType[serial]=cubeType;
}
