#pragma once

#ifdef MYODATA_EXPORTS
#define MYODATA_API __declspec(dllexport)
#else
#define MYODATA_API __declspec(dllimport)
#endif

// This is the myo connector api
// Can help us get data from myo and transfer it to Python program (by dll file)


extern "C" MYODATA_API bool myo_init();

extern "C" MYODATA_API void get_emg_data(int*& result);
extern "C" MYODATA_API void get_accel(float*& result);

extern "C" MYODATA_API void myo_exit();