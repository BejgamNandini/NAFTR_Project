#include <iostream>

#include "naftr.h"
#include "monitor_module.h"
#include "ars.h"
#include "aap_controller.h"

using namespace std;

int main()
{
    cout << "========================================" << endl;
    cout << "     NAFTR FULL SYSTEM TEST" << endl;
    cout << "========================================" << endl;
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

    cout << "Current Node      = " << currentID << endl;
    cout << "Destination Node  = " << destinationID << endl;
    cout << "Input Port        = " << inPort << endl;
    cout << endl;

    cout << "Channel Status:" << endl;
    cout << "North = " << congested[0] << endl;
    cout << "East  = " << congested[1] << endl;
    cout << "South = " << congested[2] << endl;
    cout << "West  = " << congested[3] << endl;
    cout << endl;

    // -------------------------------
    // ARS + MM + NAFTR
    // -------------------------------
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
    cout << "NAFTR/ARS Selected Port = "
         << selectedPort << endl;
    cout << endl;

    // -------------------------------
    // Create requests
    // -------------------------------
    int request1 = 1;
    int request2 = 1;
    int request3 = 0;
    int request4 = 0;

    cout << "Requests to same output:" << endl;
    cout << "Request 1 = " << request1 << endl;
    cout << "Request 2 = " << request2 << endl;
    cout << "Request 3 = " << request3 << endl;
    cout << "Request 4 = " << request4 << endl;
    cout << endl;

    // -------------------------------
    // AAP + Contention Detector
    // -------------------------------
    int winner = 0;
    int contention = 0;

    processRequests(
        request1,
        request2,
        request3,
        request4,
        &winner,
        &contention
    );

    cout << "AAP Winner = " << winner << endl;

    cout << "Contention = "
         << (contention ? "DETECTED" : "NOT DETECTED")
         << endl;

    cout << endl;
    cout << "========================================" << endl;
    cout << "       FULL SYSTEM TEST COMPLETE" << endl;
    cout << "========================================" << endl;

    return 0;
}