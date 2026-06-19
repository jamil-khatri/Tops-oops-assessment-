#include <iostream>
using namespace std;

int main() {
    int hours;

    cout << "Enter hours studied today: ";
    cin >> hours;

    if(hours >= 8)
        cout << "Excellent! Keep up the great work.";
    else if(hours >= 5)
        cout << "Good progress. Stay consistent!";
    else if(hours >= 2)
        cout << "You can do better. Keep studying.";
    else
        cout << "Time to focus and start studying!";

    return 0;
}
