#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string goal;

    ofstream outFile("goals.txt", ios::app);

    cout << "Enter today's goal: ";
    getline(cin, goal);

    outFile << goal << endl;
    outFile.close();

    cout << "\nSaved Goals:\n";

    ifstream inFile("goals.txt");
    while(getline(inFile, goal)) {
        cout << goal << endl;
    }

    inFile.close();

    return 0;
}
