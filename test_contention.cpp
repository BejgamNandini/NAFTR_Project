#include <iostream>
#include "contention_detector.h"

using namespace std;

int main()
{
    cout << "===== Contention Detector Test =====" << endl;
    cout << endl;

    // Test 1: One request
    cout << "Test 1: Requests = 1 0 0 0" << endl;
    cout << "Contention = "
         << detectContention(1, 0, 0, 0)
         << endl;
    cout << endl;

    // Test 2: Two requests
    cout << "Test 2: Requests = 1 1 0 0" << endl;
    cout << "Contention = "
         << detectContention(1, 1, 0, 0)
         << endl;
    cout << endl;

    // Test 3: Three requests
    cout << "Test 3: Requests = 1 1 1 0" << endl;
    cout << "Contention = "
         << detectContention(1, 1, 1, 0)
         << endl;
    cout << endl;

    // Test 4: No requests
    cout << "Test 4: Requests = 0 0 0 0" << endl;
    cout << "Contention = "
         << detectContention(0, 0, 0, 0)
         << endl;

    return 0;
}