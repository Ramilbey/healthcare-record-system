#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void generate_pharmacy(int& n, vector<int>& pharmacyID) {

    for (int i = 0; i < n; i++) {
        int temp = rand() % 10000000;
        pharmacyID.push_back(temp);
    }
}

void generate_radiology(int& n, vector<int>& radiologyID) {
    for (int i = 0; i < n; i++) {
        int temp = rand() % 10000000;
        radiologyID.push_back(temp);
    }
}

void display_pharmacy(int& n, vector<int>& pharmacyID) {
    for (int i = 0; i < n; i++) {
        cout << "PT" << setw(7) << setfill('0') << pharmacyID[i] << endl;
    }
}

void display_radiology(int& n, vector<int>& radiologyID) {
    for (int i = 0; i < n; i++) {
        cout << "RD" << setw(7) << setfill('0') << radiologyID[i] << endl;
    }
}

// void menu (display_pharmacy(), display_radiology()) {}



int main() {
    srand(time(0));

    int n;
    cout << "Please enter the value to generate IDs "<<endl;
    cin >> n;

    vector<int> pharmacyID;
    vector<int> radiologyID;

    generate_pharmacy(n, pharmacyID);
    generate_radiology(n, radiologyID);
    display_pharmacy(n, pharmacyID);
    cout << endl;
    display_radiology(n , radiologyID);


    // cout<< "Menu"<< endl;
    // cout << "generate records"<< endl;
    // cout << "show unsorted Pharmacy records" << endl;
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