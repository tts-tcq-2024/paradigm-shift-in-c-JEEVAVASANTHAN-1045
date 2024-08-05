#include "soc_monitor.h"
#include "tocheck_valuerange.h"
#include "warning.h"

const float SOC_LOWER_LIMIT = 20.0;
const float SOC_UPPER_LIMIT = 80.0;
const float SOC_WARNING_TOLERANCE = 0.05 * SOC_UPPER_LIMIT;

int isSocOk(float soc) {
    checkEarlyWarning(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, SOC_WARNING_TOLERANCE, "Warning: Approaching SoC discharge!", "Warning: Approaching SoC peak!");
    return isValueInRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge out of range!");  
}
