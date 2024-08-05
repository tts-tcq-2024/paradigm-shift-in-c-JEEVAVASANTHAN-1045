#include "battery_checker.h"
#include "temperature_checker.h"
#include "soc_checker.h"
#include "charge_rate_check.h"


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
