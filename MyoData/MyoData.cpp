#include "pch.h"
#include "MyoData.h"

#include "DataCollector.h"

// Variable

static myo::Hub* p_hub = nullptr;
static myo::Myo* p_myo = nullptr;
static DataCollector* p_collector = nullptr;

// External function

bool init()
{

	p_hub = new myo::Hub();
	std::cout << "Attempting to find a Myo..." << std::endl;

	p_myo = p_hub->waitForMyo(10000);

	if (!p_myo) return false;

	std::cout << "Connected to a Myo armband!" << std::endl;

	p_myo->setStreamEmg(myo::Myo::streamEmgEnabled);

	p_collector = new DataCollector();
	p_hub->addListener(p_collector);

	return true;
}

void run(int FPS)
{
	if (FPS != 0)
		p_hub->run(1000 / FPS);
}

int* get_emg_data()
{
	if (!p_myo) return nullptr;
	return p_collector->getEMGData();
}

float* get_rotation()
{
	if (!p_myo) return nullptr;
	return p_collector->getOrientationData();
}

float* get_gyro()
{
	if (!p_myo) return nullptr;
	return p_collector->getGyroscopeData();
}

float* get_accel()
{
	if (!p_myo) return nullptr;
	return p_collector->getAccel();
}

void close()
{
	if (p_collector != nullptr) {
		delete p_collector;
		p_collector = nullptr;
	}

	if (p_hub != nullptr) {
		delete p_hub;
		p_hub = nullptr;
		p_myo = nullptr;
	}
}
