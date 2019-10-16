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

	rotation = new float[4];
	for (int i = 0; i < 4; ++i)
		rotation[i] = 0.0f;

	gyro = new float[3];
	for (int i = 0; i < 3; ++i)
		gyro[i] = 0.0f;
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
	if (rotation != nullptr) {
		delete[] rotation;
		rotation = nullptr;
	}
	if (gyro != nullptr) {
		delete[] gyro;
		gyro = nullptr;
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

void DataCollector::onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& rotation)
{
	this->rotation[0] = rotation.x();
	this->rotation[1] = rotation.y();
	this->rotation[2] = rotation.z();
	this->rotation[3] = rotation.w();
}

void DataCollector::onGyroscopeData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& gyro)
{
	this->gyro[0] = gyro.x();
	this->gyro[1] = gyro.y();
	this->gyro[2] = gyro.z();
}

float* DataCollector::getAccel()
{
	return this->accel;
}

float* DataCollector::getOrientationData()
{
	return this->rotation;
}

float* DataCollector::getGyroscopeData()
{
	return this->gyro;
}

int* DataCollector::getEMGData()
{
	return this->emgData;
}