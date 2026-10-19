#include <iostream>
#include "naftr.h"

using namespace std;

int main()
{
    int currentID = 10;
    int destinationID = 14;
    int numColumns = 5;

    int inPort = 3;

    int busy[4] = {0, 0, 0, 0};
    int congested[4] = {0, 0, 0, 0};
    int faulty[4] = {0, 0, 0, 0};

    int result = selectOutputPort(
        currentID,
        destinationID,
        numColumns,
        inPort,
        busy,
        congested,
        faulty
    );

    cout << "Selected Output Port: ";

    if (result == 0)
        cout << "North";
    else if (result == 1)
        cout << "East";
    else if (result == 2)
        cout << "South";
    else if (result == 3)
        cout << "West";
    else if (result == 4)
        cout << "LOCAL";

    cout << endl;

    return 0;
}