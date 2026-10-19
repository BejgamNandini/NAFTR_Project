#include <iostream>
#include "ars.h"

using namespace std;

int main()
{
    cout << "===== ARS Test =====" << endl;
    cout << endl;

    // 5x5 mesh
    int currentID = 12;
    int destinationID = 24;
    int numColumns = 5;

    // Input port
    // 0 = North
    // 1 = East
    // 2 = South
    // 3 = West
    // 4 = Local
    int inPort = 2;

    // Channel status
    int busy[4]      = {0, 0, 0, 0};
    int congested[4] = {0, 1, 0, 0};
    int faulty[4]    = {0, 0, 0, 0};

    // Call ARS
    int selectedPort = adaptiveRoutingDecision(
        currentID,
        destinationID,
        numColumns,
        inPort,
        busy,
        congested,
        faulty
    );

    cout << endl;
    cout << "ARS Selected Output Port = "
         << selectedPort << endl;

    return 0;
}