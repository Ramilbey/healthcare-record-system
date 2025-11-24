#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void generate_pharmacy(int& n, vector<int>& pharmacyID) {
    pharmacyID.clear();
    for (int i = 0; i < n; i++) {
        int temp = rand() % 10000000;
        pharmacyID.push_back(temp);
    }
}

void generate_radiology(int& n, vector<int>& radiologyID) {
    radiologyID.clear();
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

void menu() {

    cout<< "\n=====Healthcare Record System=====\n"<< endl;
    cout << "1. Generate records"<< endl;
    cout << "2. Show unsorted Pharmacy records" << endl;
    cout << "3. Show unsorted Radiology records" << endl;
    cout << "4. Sort pharmacy"<< endl;
    cout << "5. Sort radiology" << endl;
    cout << "6. Show pharmacy records" << endl;
    cout << "7. Show radiology records" << endl;
    cout << "8. Merge into --> master list" << endl;
    cout << "9. Show master list" << endl;
    cout << "10. Exit" << endl;
}

int main() {
    srand(time(0));

    int n;
    vector<int> pharmacyID;
    vector<int> radiologyID;


    int choice;
    while (true) {
        menu();
        cin>>choice;
        if (choice == 1) {
            cout << "Please enter the value to generate IDs "<<endl;
            cin >> n;
            generate_pharmacy(n, pharmacyID);
            generate_radiology(n, radiologyID);

            cout<<"Records generated "<<endl;
        }
        else if (choice == 2) {
            cout<< "Unsorted Records for Pharmacy "<<endl;
            display_pharmacy(n, pharmacyID);
        }
        else if (choice == 3) {
            cout<< "Unsorted Records for Radiology "<<endl;
            display_radiology(n, radiologyID);
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            return 0;
        }
        else {
            cout << "invalid choice";
        }
    }



    return 0;
}