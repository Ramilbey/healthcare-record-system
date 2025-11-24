#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void generate_pharmacy(int& n, vector<int>& randomNumbers) {
    for (int i = 0; i < n; i++) {
        int temp = rand() % 10000000;
        randomNumbers.push_back(temp);
    }
}

void display_pharmacy(int& n, vector<int>& randomNumbers) {
    for (int i = 0; i < n; i++) {
        cout << "PT" << setw(7) << setfill('0') << randomNumbers[i] << endl;
    }
}


int main() {
    srand(time(0));

    int n;
    vector<int> randomNumbers;
    cout << "Please enter the value to generate IDs "<<endl;
    cin >> n;
    generate_pharmacy(n, randomNumbers);
    display_pharmacy(n, randomNumbers);

    // cout<< "Menu"<< endl;
    // cout << "generate records"<< endl;
    // cout << "show unsorted Radiology records" << endl;
    // cout << "sort radiology"<< endl;
    // cout << "sort pharmacy" << endl;
    // cout << "show radiology records" << endl;
    // cout << "show pharmacy records" << endl;
    // cout << "merge into --> master list" << endl;
    // cout << "show master list" << endl;
    // cout << "exit" << endl;




    return 0;
}