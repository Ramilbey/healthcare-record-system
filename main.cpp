#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void generate_pharmacy(int& n, vector<int>& randomNumbers) {
    cout << "enter the value to generate pharmacy " << endl;
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int temp = rand() % 9999999;
        randomNumbers.push_back(temp);
    }
}

void display_pharmacy(int& n, vector<int>& randomNumbers) {
    for (int i = 0; i < n; i++) {
        cout << "PT"<<randomNumbers[i] << endl;
    }
}


int main() {
    int n;
    vector<int> randomNumbers;
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