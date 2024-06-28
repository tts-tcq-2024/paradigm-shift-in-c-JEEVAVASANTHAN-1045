#include <stdio.h>
#include <assert.h>

#define OUTOFBOUNDARY 0
#define WITHINRANGE 1

int checkRange(float data, float min, float max, const char* nameOfBatteryParameter) {
 if (data > max || data < min) {
     printf("%s out of range!\n", nameOfBatteryParameter);
     return OUTOFBOUNDARY;
 }
 return WITHINRANGE;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 return checkRange(temperature, 0, 45, "Temperature") &&
        checkRange(soc, 20, 80, "State of Charge") &&
        checkRange(chargeRate, 0, 0.8, "Charge Rate");
}

int main() {
 assert(batteryIsOk(25, 70, 0.7));
 assert(!batteryIsOk(50, 85, 0));
}
