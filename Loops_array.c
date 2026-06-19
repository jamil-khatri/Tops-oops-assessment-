#include <iostream>
using namespace std;

int main() {
    float screenTime[7];
    float total = 0, average;

    for(int i = 0; i < 7; i++) {
        cout << "Enter screen time for day " << i + 1 << ": ";
        cin >> screenTime[i];
        total += screenTime[i];
    }

    average = total / 7;

    cout << "\nTotal Screen Time = " << total;
    cout << "\nAverage Screen Time = " << average;

    if(average > 6)
        cout << "\nWarning: Average exceeds healthy limit!";

    return 0;
}
