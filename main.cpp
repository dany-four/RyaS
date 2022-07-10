#include"RYClock"
#include"RYBase"
#include"RYFrame"
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL_image.h>
int main(int argc,char *argv[]){
    
    //SDL2
    SDL_Window* window = SDL_CreateWindow("RyaS",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,900,800,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);    
    SDL_Event eve;
    bool running = true;
    SDL_Rect SDLQuadI;

    SDL_Texture *texture = IMG_LoadTexture(renderer,"femboy.png");

    //RyaS
    int tw,th;
    SDL_QueryTexture(texture,NULL,NULL,&tw,&th);
    RYFrame myFrame(RYDot(tw,th),RYDot(4,4));
    SDL_Rect SDLQuadO = {0,0,myFrame.frame.w*3,myFrame.frame.h*3};
    SDLQuadI.w = myFrame.frame.w;
        SDLQuadI.h = myFrame.frame.h;
    RYClock gameCLock;
    float delta;
    while (running)
    {
        gameCLock.pointA();
        while(SDL_PollEvent(&eve)){
            switch (eve.type)
            {
            case SDL_QUIT:
                running = false;
                break;
  
            default:
                break;
            }
        }
        //RYFrame
        const Uint8 *key = SDL_GetKeyboardState(NULL);
                float s = 1;
                if(key[SDL_SCANCODE_W]){
                    SDLQuadO.y-=s;
                    myFrame.setFrame(0,4);
                }
                else if(key[SDL_SCANCODE_S]){
                    SDLQuadO.y+=s;
                    myFrame.setFrame(0,1);
                }
                if(key[SDL_SCANCODE_A]){
                    SDLQuadO.x-=s;
                    myFrame.setFrame(0,2);
                }
                else if(key[SDL_SCANCODE_D]){
                    SDLQuadO.x+=s;
                    myFrame.setFrame(0,3);
                }

        // Clear
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        // Draw
        SDLQuadI.x = myFrame.frame.x;
        SDLQuadI.y = myFrame.frame.y;
        //SDL_SetRenderDrawColor(renderer,255,255,255,255);
        //SDL_RenderDrawRect(renderer,&SDLQuadO);
        SDL_RenderCopy(renderer,texture,&SDLQuadI,&SDLQuadO);
        // Render
        SDL_RenderPresent(renderer);
        delta = gameCLock.pointB();
    }
    
    return 0;
}