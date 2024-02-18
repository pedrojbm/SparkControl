/*
 * SparkDisplayControl.cpp
 *
 *  Created on: 12.02.2024
 *      Author: PedroJBM
 */

#include "BatteryManagement.h"

SFE_MAX1704X BatteryManagement::battery(MAX1704X_MAX17048); // Create a MAX17048


BatteryManagement::BatteryManagement():BatteryManagement(nullptr) {}


BatteryManagement::BatteryManagement(SparkDataControl* dc) {
	spark_dc = dc;
}

BatteryManagement::~BatteryManagement() {}

void BatteryManagement::init()
{
    Wire.begin();
    battery.begin();
    battery.quickStart();
    battery.setThreshold(20);
}

double BatteryManagement::getBatteryLevel()
{
    return battery.getSOC();
}