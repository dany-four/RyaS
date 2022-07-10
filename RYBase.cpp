#include"RYBase"
RYQuad RYDot::operator < (const RYDot& OtherDot){
    return RYQuad(*this,OtherDot);
}
RYDot RYDot::operator - (const RYDot& OtherDot){
    return RYDot({this->x-OtherDot.x,this->y-OtherDot.y});
}