#include "pch.h"
#include "MyoData.h"

#include "DataCollector.h"

// Variable

static myo::Hub* p_hub = nullptr;
static myo::Myo* p_myo = nullptr;
static DataCollector* p_collector = nullptr;

// External function

bool myo_init()
{
	p_hub = new myo::Hub();
	p_myo = p_hub->waitForMyo(10000);
	if (!p_myo) return false;

	p_myo->setStreamEmg(myo::Myo::streamEmgEnabled);

	p_collector = new DataCollector();
	p_hub->addListener(p_collector);

	return true;
}

void get_emg_data(int *& result)
{
	if (!p_myo) return;
	result = p_collector->getEMGData();
}

void get_accel(float *& result)
{
	if (!p_myo) return;
	result = p_collector->getAccel();
}

void myo_exit()
{
	delete p_collector;
	p_collector = nullptr;

	if (p_hub != nullptr) {
		delete p_hub;
		p_hub = nullptr;
		p_myo = nullptr;
	}
}
