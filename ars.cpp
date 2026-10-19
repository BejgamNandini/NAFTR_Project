#include "ars.h"
#include "naftr.h"
#include "monitor_module.h"

int adaptiveRoutingDecision(
    int currentID,
    int destinationID,
    int numColumns,
    int inPort,
    int busy[],
    int congested[],
    int faulty[]
)
{
    // Generate Monitor Module outputs
    int mmCongested[4];

    for (int i = 0; i < 4; i++)
    {
        int other1 = congested[(i + 1) % 4];
        int other2 = congested[(i + 2) % 4];
        int other3 = congested[(i + 3) % 4];

        mmCongested[i] = monitorCongestion(
            congested[i],
            other1,
            other2,
            other3
        );
    }

    // Use Monitor Module congestion results in NAFTR
    int selectedPort = selectOutputPort(
        currentID,
        destinationID,
        numColumns,
        inPort,
        busy,
        mmCongested,
        faulty
    );

    return selectedPort;
}