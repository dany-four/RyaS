g++ -c RYClock.cpp -D RYCLOCK_EXPORTS
g++ -shared -DBUILD_DLL RYCLock.o -o RYClock.dll -Wl,--subsystem,windows 