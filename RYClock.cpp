#include"RYClock"
#define _now std::chrono::steady_clock::now()

RYCLOCKCALL RYClock::RYClock(){
    reset();
}

float RYCLOCKCALL RYClock::getTime(){ 
    return duration<float>(_now-start_point).count();
}

//set clock to zero
void RYCLOCKCALL RYClock::reset(){
    start_point = _now;
}
// return true if clock has been reset
bool RYCLOCKCALL RYClock::resetEach(float Seconds){
    if(getTime()>=Seconds){
        reset();
        return true;
    }
    return false;
}
void RYCLOCKCALL RYClock::operator!(){
    reset();
}

void RYCLOCKCALL RYClock::pointA(){
    old=getTime();
}
float RYCLOCKCALL RYClock::pointB(){
    return getTime()-old;
}