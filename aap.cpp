#include "aap.h"

int adaptiveArbitration(
    int request1,
    int request2,
    int request3,
    int request4
)
{
    if (request1)
        return 1;

    if (request2)
        return 2;

    if (request3)
        return 3;

    if (request4)
        return 4;

    return 0;
}

int countRequests(
    int request1,
    int request2,
    int request3,
    int request4
)
{
    return request1 + request2 + request3 + request4;
}