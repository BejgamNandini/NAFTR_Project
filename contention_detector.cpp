#include "contention_detector.h"

int detectContention(
    int request1,
    int request2,
    int request3,
    int request4
)
{
    int requestCount =
        request1 +
        request2 +
        request3 +
        request4;

    // Contention occurs when more than one packet
    // requests the same output port.
    if (requestCount > 1)
        return 1;

    return 0;
}