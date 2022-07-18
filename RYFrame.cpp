#include"RYFrame"
using namespace RY;
RYCALL RYFRAME Frame::Frame(Dot<> TextureSize, Dot<> numberOfSprites):sizeLow(TextureSize), sizeHigh(numberOfSprites){
    clip = sizeLow/sizeHigh;
    position.y=0;
    frame = position < clip;
    Quad a(1.f,1.f,1.f,1.f);
    
}
void RYCALL RYFRAME Frame::updateClip(){
    frame.x=position.x*clip.x;
    frame.y=position.y*clip.y;
}

void RYCALL RYFRAME Frame::setFrame(unsigned int x, unsigned int y){
    x != 0 ? position.x = x-1:0;
    y != 0 ? position.y = y-1:0;
    animate();
}
void RYCALL RYFRAME Frame::animate(){
    updateClip(); 
    if(InternalClock.reset(0.12f))
    {
        if(position.x==sizeHigh.x-1)//minus 1 because position starts at 0
            position.x = 0;
        else 
            position.x++;
    }
}
