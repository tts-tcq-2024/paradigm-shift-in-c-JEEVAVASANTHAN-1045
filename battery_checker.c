#include "battery_checker.h"
#include "temperature_monitor.h"
#include "soc_monitor.h"
#include "tocheck_chargerate.h"


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
