#include "tocheck_chargerate.h"
#include "tocheck_valuerange.h"
#include "warning.h"

int isChargeRateOk(float chargeRate) {
    checkEarlyWarningForChargeRate(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
    return isChargeRateInRange(chargeRate, 0.8, "Charge Rate out of range!");
}
