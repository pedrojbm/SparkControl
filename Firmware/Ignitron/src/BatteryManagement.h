/*
 * BatteryManagement.h
 *
 *  Created on: 12.02.2024
 *      Author: PedroJBM
 */

#ifndef BATTERYMANAGEMENT_H_
#define BATTERYMANAGEMENT_H_

#include <Arduino.h>
#include <Wire.h> // Needed for I2C
#include <SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library

#include "SparkDataControl.h"
#include "Config_Definitions.h"

class SparkDataControl;

class BatteryManagement
{
    public:
        BatteryManagement();
        BatteryManagement(SparkDataControl* dc);
        virtual ~BatteryManagement();

        void init();

        double getBatteryLevel();
        bool getPGOOD();
        bool getCHG();

        void setDataControl(SparkDataControl *dc) {
            spark_dc = dc;
        }

    private:
        
        static SFE_MAX1704X battery;
        SparkDataControl* spark_dc;
        
        SparkDataControl* dataControl() {return spark_dc;}
};

#endif /* BATTERYMANAGEMENT_H_ */
