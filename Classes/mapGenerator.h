#ifndef __mapGenerator_H__
#define __mapGenerator_H__

#include "Vars.hpp"
class mapGenerator
{
public:
	struct coorMod {
			int x[arrayLength];
			int y[arrayLength];
			int cubeType[arrayLength];
		};
	void mapGen(int length, int difficulty);
    void mapSet(int x,int y, int cubeType, int serial);
	void mapClean();
	int getX(int serial);
	int getY(int serial);
	int mapGetType(int serial);
    

private:

	coorMod coorMap;
};

#endif
