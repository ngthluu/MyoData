#include "pch.h"
#include "DataCollector.h"

DataCollector::DataCollector()
{
	emgData = new int[NUM_OF_SENSOR];
	for (int i = 0; i < NUM_OF_SENSOR; ++i)
		emgData[i] = 0;

	accel = new float[3];
	for (int i = 0; i < 3; ++i)
		accel[i] = 0.0f;
}

DataCollector::~DataCollector()
{
	if (emgData != nullptr) {
		delete[] emgData;
		emgData = nullptr;
	}
	if (accel != nullptr) {
		delete[] accel;
		accel = nullptr;
	}
}

void DataCollector::onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
{
	for (int i = 0; i < NUM_OF_SENSOR; ++i) {
		emgData[i] = emg[i];
	}
}

void DataCollector::onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& accel)
{
	this->accel[0] = accel.x();
	this->accel[1] = accel.y();
	this->accel[2] = accel.z();
}

float* DataCollector::getAccel()
{
	return this->accel;
}

int* DataCollector::getEMGData()
{
	return this->emgData;
}