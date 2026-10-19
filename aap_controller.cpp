#include "aap_controller.h"
#include "aap.h"
#include "contention_detector.h"

int processRequests(
    int request1,
    int request2,
    int request3,
    int request4,
    int *winner,
    int *contention
)
{
    // Detect whether multiple packets are requesting
    // the same output port.
    *contention = detectContention(
        request1,
        request2,
        request3,
        request4
    );

    // AAP selects the winning request.
    *winner = adaptiveArbitration(
        request1,
        request2,
        request3,
        request4
    );

    return 0;
}