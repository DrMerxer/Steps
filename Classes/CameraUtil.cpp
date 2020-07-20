#include "CameraUtil.h"
#include "Vars.hpp"
float CameraUtil::degree=-135;
float CameraUtil::yj=40;
int CameraDATX(int x)
{
    float cxz=cos(CameraUtil::yj*3.1415926535898/180)*CAMERA_R;
    float cx=sin(CameraUtil::degree*3.1415926535898/180)*cxz+x-30;
    return cx;
}

int CameraDATY(int y)
{
    float cxz=cos(CameraUtil::yj*3.1415926535898/180)*CAMERA_R;
    float cz=cos(CameraUtil::degree*3.1415926535898/180)*cxz+y-30;
    return cz;
}
