#pragma once

#ifdef MYODATA_EXPORTS
#define MYODATA_API __declspec(dllexport)
#else
#define MYODATA_API __declspec(dllimport)
#endif

// This is the myo connector api
// Can help us get data from myo and transfer it to Python program (by dll file)


extern "C" MYODATA_API bool init();

extern "C" MYODATA_API void run(int FPS);
extern "C" MYODATA_API int* get_emg_data();
extern "C" MYODATA_API float* get_accel();

extern "C" MYODATA_API void close();