//2554709 黒田蒼史
//fishFunc2.c
//魚が正しい方向を向いて進むように修正したプログラム


#include <stdio.h>
#include <handy.h>

void fishLeft(double x,double y,double size);
void fishRight(double x,double y,double size);

void fishLeft(double x,double y,double size){
    HgFan(x,y,size,
          225.0*3.14159/180.0,
          495.0*3.14159/180.0);

    HgCircle(x-size/3.0,y+size/2.0,size/4.0);

    double bone_x = x + size;
    double bone_y = x + size*3.0;

    HgLine(bone_x,y,bone_y,y);

    double interval = (size*2.0)/6.0;

    for(int i=1;i<=5;i++){
        double bone_X = bone_x + i*interval;
        HgLine(bone_X,y-size/2.0,bone_X,y+size/2.0);
    }

    double tail_x = x + size*4.0;

    HgLine(bone_y,y,tail_x,y+size);
    HgLine(bone_y,y,tail_x,y-size);
}

void fishRight(double x,double y,double size){
    HgFan(x,y,size,
          45.0*3.14159/180.0,
          315.0*3.14159/180.0);

    HgCircle(x+size/3.0,y+size/2.0,size/4.0);

    double bone_x = x - size;
    double bone_y = x - size*3.0;

    HgLine(bone_x,y,bone_y,y);

    double interval = (size*2.0)/6.0;

    for(int i=1;i<=5;i++)
    {
        double bone_X = bone_x - i*interval;
        HgLine(bone_X,y-size/2.0,bone_X,y+size/2.0);
    }

    double tail_x = x - size*4.0;

    HgLine(bone_y,y,tail_x,y+size);
    HgLine(bone_y,y,tail_x,y-size);}

int main(void){
    double x,y,size,dx,dy;
    HgOpen(400,400);
    x=200;
    y=200;
    size=10;

    dx=-0.9*size;
    dy=0.5*size;

    while(1){
        HgClear();

        if(dx < 0){
            fishLeft(x,y,size);}
        else{
            fishRight(x,y,size);}

        if(x+dx < size || x+dx > 400-size*4.0){
            dx = -dx;}
        x += dx;

        if(y+dy < size || y+dy > 400-size*4.0){
            dy = -dy;}
        y += dy;

        HgSleep(0.1);}
}