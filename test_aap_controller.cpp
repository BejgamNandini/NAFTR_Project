#include <iostream>
#include "aap_controller.h"

using namespace std;

void runTest(
    int testNumber,
    int r1,
    int r2,
    int r3,
    int r4
)
{
    int winner = 0;
    int contention = 0;

    processRequests(
        r1, r2, r3, r4,
        &winner,
        &contention
    );

    cout << "Test " << testNumber << endl;

    cout << "Requests = "
         << r1 << " "
         << r2 << " "
         << r3 << " "
         << r4 << endl;

    cout << "Winner = " << winner << endl;

    cout << "Contention = "
         << (contention ? "YES" : "NO")
         << endl;

    cout << endl;
}

int main()
{
    cout << "===== AAP Controller Test =====" << endl;
    cout << endl;

    // One request
    runTest(1, 1, 0, 0, 0);

    // Two simultaneous requests
    runTest(2, 1, 1, 0, 0);

    // Three simultaneous requests
    runTest(3, 1, 1, 1, 0);

    // No requests
    runTest(4, 0, 0, 0, 0);

    return 0;
}