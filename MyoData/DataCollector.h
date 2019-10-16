#pragma once

#include <myo/myo.hpp>

class DataCollector : public myo::DeviceListener
{
	// Constants
	static const int NUM_OF_SENSOR = 8;

	int* emgData;
	float* accel;
	float* rotation;
	float* gyro;

public:
	DataCollector();
	~DataCollector();

	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg) override;
	void onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& accel) override;
	void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& rotation) override;
	void onGyroscopeData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& gyro) override;

	float* getAccel();
	float* getOrientationData();
	float* getGyroscopeData();
	int* getEMGData();
};

