#pragma once

#include <myo/myo.hpp>

class DataCollector : public myo::DeviceListener
{
	// Constants
	static const int NUM_OF_SENSOR = 8;

	int* emgData;
	float* accel;

public:
	DataCollector();
	~DataCollector();

	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg) override;
	void onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& accel) override;

	float* getAccel();
	int* getEMGData();
};

