#include "naftr.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int selectOutputPort(
    int currentID,
    int destinationID,
    int numColumns,
    int inPort,
    int busy[],
    int congested[],
    int faulty[]
)
{
    // =========================================================
    // 1. Calculate current coordinates
    // =========================================================

    int xCurrent = currentID % numColumns;
    int yCurrent = currentID / numColumns;

    // =========================================================
    // 2. Calculate destination coordinates
    // =========================================================

    int xDestination = destinationID % numColumns;
    int yDestination = destinationID / numColumns;

    cout << "Current Node: ("
         << xCurrent << "," << yCurrent << ")" << endl;

    cout << "Destination Node: ("
         << xDestination << "," << yDestination << ")" << endl;

    // =========================================================
    // 3. Check legitimate outports
    // =========================================================

    bool northValid = (yCurrent > 0);
    bool southValid = (yCurrent < numColumns - 1);
    bool westValid  = (xCurrent > 0);
    bool eastValid  = (xCurrent < numColumns - 1);

    cout << endl;
    cout << "Legitimate Outports:" << endl;
    cout << "North = " << (northValid ? "Valid" : "Invalid") << endl;
    cout << "East  = " << (eastValid  ? "Valid" : "Invalid") << endl;
    cout << "South = " << (southValid ? "Valid" : "Invalid") << endl;
    cout << "West  = " << (westValid  ? "Valid" : "Invalid") << endl;

    // =========================================================
    // 4. Determine D1-D8 region
    // =========================================================

    string region;

    if (xDestination > xCurrent && yDestination == yCurrent)
        region = "D1";

    else if (xDestination > xCurrent && yDestination < yCurrent)
        region = "D2";

    else if (xDestination == xCurrent && yDestination < yCurrent)
        region = "D3";

    else if (xDestination < xCurrent && yDestination < yCurrent)
        region = "D4";

    else if (xDestination < xCurrent && yDestination == yCurrent)
        region = "D5";

    else if (xDestination < xCurrent && yDestination > yCurrent)
        region = "D6";

    else if (xDestination == xCurrent && yDestination > yCurrent)
        region = "D7";

    else if (xDestination > xCurrent && yDestination > yCurrent)
        region = "D8";

    else
        region = "LOCAL";

    cout << endl;
    cout << "NAFTR Region: " << region << endl;

    // =========================================================
    // 5. LOCAL destination
    // =========================================================

    if (region == "LOCAL")
    {
        cout << "Destination reached." << endl;
        cout << "Selected Output Port: LOCAL" << endl;

        return 4;
    }

    // =========================================================
    // 6. Calculate z1 and z2
    // =========================================================

    double z1, z2;

    int x = xCurrent;

    if (x == 0)
    {
        z1 = 0;
        z2 = 0.5;
    }
    else
    {
        z1 = 0.5;
        z2 = 0;
    }

    // =========================================================
    // 7. Preferred weights
    //
    // Port numbering:
    // 0 = North
    // 1 = East
    // 2 = South
    // 3 = West
    // =========================================================

    double Wp[4] = {0, 0, 0, 0};

    if (region == "D1")
    {
        Wp[0] = 2 + z1;
        Wp[1] = 1;
        Wp[2] = 2 + z2;
        Wp[3] = 3;
    }

    else if (region == "D2")
    {
        Wp[0] = 2;
        Wp[1] = 1;
        Wp[2] = 3 + z1;
        Wp[3] = 3 + z2;
    }

    else if (region == "D3")
    {
        Wp[0] = 1;
        Wp[1] = 2 + z1;
        Wp[2] = 3;
        Wp[3] = 2 + z2;
    }

    else if (region == "D4")
    {
        Wp[0] = 2;
        Wp[1] = 3 + z1;
        Wp[2] = 3 + z2;
        Wp[3] = 1;
    }

    else if (region == "D5")
    {
        Wp[0] = 2 + z1;
        Wp[1] = 3;
        Wp[2] = 2 + z2;
        Wp[3] = 1;
    }

    else if (region == "D6")
    {
        Wp[0] = 3 + z1;
        Wp[1] = 3 + z2;
        Wp[2] = 2;
        Wp[3] = 1;
    }

    else if (region == "D7")
    {
        Wp[0] = 3;
        Wp[1] = 2 + z1;
        Wp[2] = 1;
        Wp[3] = 2 + z2;
    }

    else if (region == "D8")
    {
        Wp[0] = 3 + z1;
        Wp[1] = 1;
        Wp[2] = 2;
        Wp[3] = 3 + z2;
    }

    // =========================================================
    // 8. Busy / Congestion / Fault weights
    // =========================================================

    double Wb[4];
    double Wc[4];
    double Wf[4];
    double Wi[4];

    for (int i = 0; i < 4; i++)
    {
        Wb[i] = busy[i] ? 2 : 0;
        Wc[i] = congested[i] ? 3 : 0;
        Wf[i] = faulty[i] ? 10 : 0;

        Wi[i] = Wp[i] + Wb[i] + Wc[i] + Wf[i];
    }

    // =========================================================
    // 9. Make invalid outports unavailable
    // =========================================================

    const double INVALID = 9999;

    if (!northValid)
        Wi[0] = INVALID;

    if (!eastValid)
        Wi[1] = INVALID;

    if (!southValid)
        Wi[2] = INVALID;

    if (!westValid)
        Wi[3] = INVALID;

    // =========================================================
    // 10. Display final weights
    // =========================================================

    cout << endl;
    cout << "Final Weights:" << endl;

    if (northValid)
        cout << "North = " << Wi[0] << endl;
    else
        cout << "North = INVALID" << endl;

    if (eastValid)
        cout << "East  = " << Wi[1] << endl;
    else
        cout << "East  = INVALID" << endl;

    if (southValid)
        cout << "South = " << Wi[2] << endl;
    else
        cout << "South = INVALID" << endl;

    if (westValid)
        cout << "West  = " << Wi[3] << endl;
    else
        cout << "West  = INVALID" << endl;

    // =========================================================
    // 11. Find minimum legitimate outport
    // =========================================================

    int minIndex = -1;

    for (int i = 0; i < 4; i++)
    {
        if (Wi[i] < INVALID)
        {
            if (minIndex == -1 || Wi[i] < Wi[minIndex])
            {
                minIndex = i;
            }
        }
    }

    // =========================================================
    // 12. Livelock avoidance
    // =========================================================

    if (minIndex == inPort)
    {
        cout << endl;
        cout << "Minimum port is same as InPort." << endl;
        cout << "Applying livelock avoidance..." << endl;

        double secondMin = INVALID;
        int secondIndex = -1;

        for (int i = 0; i < 4; i++)
        {
            if (i != inPort && Wi[i] < secondMin)
            {
                secondMin = Wi[i];
                secondIndex = i;
            }
        }

        minIndex = secondIndex;
    }

    // =========================================================
    // 13. Find second-lowest weight
    // =========================================================

    double secondMin = INVALID;

    for (int i = 0; i < 4; i++)
    {
        if (i != minIndex && Wi[i] < secondMin)
        {
            secondMin = Wi[i];
        }
    }

    cout << endl;

    if (minIndex != -1)
        cout << "Minimum Weight = " << Wi[minIndex] << endl;

    if (secondMin < INVALID)
        cout << "Second Minimum Weight = " << secondMin << endl;

    // =========================================================
    // 14. Find tied second-lowest candidates
    // =========================================================

    int secondCandidates[4];
    int secondCount = 0;

    for (int i = 0; i < 4; i++)
    {
        if (i != minIndex && Wi[i] == secondMin)
        {
            secondCandidates[secondCount] = i;
            secondCount++;
        }
    }

    // =========================================================
    // 15. Random tie-breaking
    // =========================================================

    if (secondCount > 1)
    {
        cout << "Tie detected among second-lowest ports." << endl;

        srand(time(0));

        int randomIndex = rand() % secondCount;

        minIndex = secondCandidates[randomIndex];

        cout << "Random tie-breaking applied." << endl;
    }

    // =========================================================
    // 16. Display selected output port
    // =========================================================

    string portNames[5] =
    {
        "North",
        "East",
        "South",
        "West",
        "LOCAL"
    };

    cout << endl;

    if (minIndex >= 0 && minIndex < 4)
    {
        cout << "Selected Output Port: "
             << portNames[minIndex] << endl;
    }

    return minIndex;
}