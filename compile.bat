g++ main.cpp RYBase.cpp ^
 -I%SDL2I% -L%SDL2L% ^
 -I%SDL2IMGI% -L%SDL2IMGL% ^
 -lmingw32 -lSDL2main -lSDL2 ^
 -lSDL2_image ^
 -L. -lRYClock ^
 -o main.exe

main.exe