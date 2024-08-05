#include <stdio.h>
#include <assert.h>

typedef struct {
    const char* name;
    float min;
    float max;
    float value;
} BatteryParameter;

#define OUT_OF_BOUNDARY 0
#define WITHIN_RANGE 1

int checkRange(BatteryParameter parameter) {
    if (parameter.value < parameter.min || parameter.value > parameter.max) {
        printf("%s out of range!\n", parameter.name);
        return OUT_OF_BOUNDARY;
    }
    return WITHIN_RANGE;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryParameter parameters[] = {
        {"Temperature", 0, 45, temperature},
        {"State of Charge", 20, 80, soc},
        {"Charge Rate", 0, 0.8, chargeRate}
    };

    for (int i = 0; i < sizeof(parameters) / sizeof(parameters[0]); ++i) {
        if (checkRange(parameters[i]) == OUT_OF_BOUNDARY) {
            return 0;
        }
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));       // Expected: within range
    assert(!batteryIsOk(50, 85, 0));        // Expected: out of range
    printf("All tests passed!\n");
    return 0;
}
