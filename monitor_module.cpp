#include "monitor_module.h"

int monitorCongestion(
    int currentCongestion,
    int other1,
    int other2,
    int other3
)
{
    // AND gate:
    // Check whether all three other channels are congested
    int allOthersCongested = other1 && other2 && other3;

    // OR gate:
    // Current channel is congested OR all other channels are congested
    int mmOutput = currentCongestion || allOthersCongested;

    return mmOutput;
}