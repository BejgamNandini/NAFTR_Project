#include <iostream>
#include "monitor_module.h"

using namespace std;

int main()
{
    cout << "===== 4-Port Monitor Module Test =====" << endl;
    cout << endl;

    // Channel status
    // 0 = Not congested
    // 1 = Congested

    int north = 0;
    int east  = 1;
    int south = 1;
    int west  = 1;

    // North MM
    int northMM = monitorCongestion(
        north,
        east,
        west,
        south
    );

    // East MM
    int eastMM = monitorCongestion(
        east,
        north,
        west,
        south
    );

    // South MM
    int southMM = monitorCongestion(
        south,
        north,
        east,
        west
    );

    // West MM
    int westMM = monitorCongestion(
        west,
        north,
        east,
        south
    );

    cout << "North MM = " << northMM << endl;
    cout << "East  MM = " << eastMM << endl;
    cout << "South MM = " << southMM << endl;
    cout << "West  MM = " << westMM << endl;

    return 0;
}