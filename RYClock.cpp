#include"RYClock"
#define _now std::chrono::steady_clock::now()
RYCLOCKCALL RYCLOCK RYClock::RYClock(){
    reset();
}

float RYCLOCKCALL RYCLOCK RYClock::getTime(){ 
    return duration<float>(_now-start_point).count();
}

//set clock to zero
void RYCLOCKCALL RYCLOCK RYClock::reset(){
    start_point = _now;
}

bool RYCLOCKCALL RYCLOCK RYClock::reset(float Seconds){
    if(getTime()>=Seconds){
        reset();
        return true;
    }
    return false;
}
 
void RYCLOCKCALL RYCLOCK RYClock::operator!(){
    reset();
}

void RYCLOCKCALL RYCLOCK RYClock::pointA(){
    old=getTime();
}
float RYCLOCKCALL RYCLOCK RYClock::pointB(){
    return getTime()-old;
}