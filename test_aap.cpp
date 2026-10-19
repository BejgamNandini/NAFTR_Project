#include <iostream>
#include "aap.h"

using namespace std;

int main()
{
    cout << "===== AAP + Contention Test =====" << endl;
    cout << endl;

    // Test 1: Only one request
    int count1 = countRequests(1, 0, 0, 0);

    cout << "Test 1: Requests = 1 0 0 0" << endl;
    cout << "Request Count = " << count1 << endl;
    cout << "Winner = "
         << adaptiveArbitration(1, 0, 0, 0)
         << endl;
    cout << "Contention = "
         << (count1 > 1 ? "YES" : "NO") << endl;
    cout << endl;

    // Test 2: Two simultaneous requests
    int count2 = countRequests(1, 1, 0, 0);

    cout << "Test 2: Requests = 1 1 0 0" << endl;
    cout << "Request Count = " << count2 << endl;
    cout << "Winner = "
         << adaptiveArbitration(1, 1, 0, 0)
         << endl;
    cout << "Contention = "
         << (count2 > 1 ? "YES" : "NO") << endl;
    cout << endl;

    // Test 3: Three simultaneous requests
    int count3 = countRequests(1, 1, 1, 0);

    cout << "Test 3: Requests = 1 1 1 0" << endl;
    cout << "Request Count = " << count3 << endl;
    cout << "Winner = "
         << adaptiveArbitration(1, 1, 1, 0)
         << endl;
    cout << "Contention = "
         << (count3 > 1 ? "YES" : "NO") << endl;
    cout << endl;

    // Test 4: No requests
    int count4 = countRequests(0, 0, 0, 0);

    cout << "Test 4: Requests = 0 0 0 0" << endl;
    cout << "Request Count = " << count4 << endl;
    cout << "Winner = "
         << adaptiveArbitration(0, 0, 0, 0)
         << endl;
    cout << "Contention = "
         << (count4 > 1 ? "YES" : "NO") << endl;

    return 0;
}