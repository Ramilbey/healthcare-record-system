#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
#include <sstream>

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
        cout << "PT" << setw(7) << setfill('0') << radiologyID[i] << endl;
    }
}

void merge ( vector<int>& arr, int first, int mid, int last) {
    vector<int> temp (last -first +1);
    int first1 = first ;
    int last1 = mid;
    int first2 = mid + 1 ;
    int last2 = last;
    int index = 0;

    while(first1 <= last1 && first2 <= last2 ) {
        if (arr[first1] <= arr[first2]) {
            temp[index ++] = arr[first1 ++];
        }else {
            temp[index ++] = arr[first2 ++];
        }

    }
    while (first1 <= last1) {
        temp[index ++] = arr[first1 ++];
    }
    while (first2 <= last2) {
        temp[index ++] = arr[first2 ++];
    }
    for ( int i = 0 ; i < index ; i++ ) {
        arr[first + i] = temp[i];
    }


}

void mergeSort( vector<int>& arr, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void display_sorted_pharmacy(int& n, vector<int>& pharmacyID) {
    for (int i = 0; i < n; i++) {
        cout <<"PT"<< setw(7) << setfill('0')<<pharmacyID[i] <<endl;
    }
}

void display_sorted_radiology(int& n, vector<int>& radiologyID) {
    for (int i = 0; i < n; i++) {
        cout <<"PT"<< setw(7) << setfill('0')<< radiologyID[i] <<endl;
    }
}

string format_record(const string& prefix, int id) {
    stringstream ss;
    ss << prefix << setw(7) << setfill('0') << id;
    return ss.str();
}

void merge_to_master(vector<int>& ph, vector<int>& rd, vector<string>& master) {
    master.clear();
    int i = 0, j = 0;
    int n1 = ph.size();
    int n2 = rd.size();

    int last_added = -1;  // track last numeric ID to avoid duplicates

    while (i < n1 && j < n2) {
        if (ph[i] < rd[j]) {
            if (ph[i] != last_added) {
                master.push_back(format_record("PT", ph[i]));
                last_added = ph[i];
            }
            i++;
        } else {
            if (rd[j] != last_added) {
                master.push_back(format_record("PT", rd[j]));
                last_added = rd[j];
            }
            j++;
        }
    }

    while (i < n1) {
        if (ph[i] != last_added) {
            master.push_back(format_record("PT", ph[i]));
            last_added = ph[i];
        }
        i++;
    }

    while (j < n2) {
        if (rd[j] != last_added) {
            master.push_back(format_record("PT", rd[j]));
            last_added = rd[j];
        }
        j++;
    }
}


void display_master_list(vector<string>& master) {
    for (int i = 0; i < master.size(); i++) {
        cout << master[i] << endl;
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
    vector<string> master;

    int choice;
    while (true) {
        menu();
        cin>>choice;
        if (choice == 1) {
            cout << "Please enter the value to generate IDs "<<endl;
            cin >> n;
            if (n <= 0 || n >1000000) {
                cout << "Error: please enter values between 1 and 1000000" << endl;
            }else {
                generate_pharmacy(n, pharmacyID);
                generate_radiology(n, radiologyID);
                cout<<"Records generated "<<endl;
            }
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
            clock_t before = clock();
            mergeSort(pharmacyID, 0, n-1);
            clock_t duration  = clock() - before;
            cout << fixed << setprecision(6);
            cout << "Pharmacy Records Sorted "<<endl;
            cout <<"Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds " <<endl;
        }
        else if (choice == 5) {
            clock_t before = clock();
            mergeSort(radiologyID, 0, n-1);
            cout << fixed << setprecision(6);
            clock_t duration = clock() - before;
            cout << "Radiology Records Sorted "<<endl;
            cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds " <<endl;
        }
        else if (choice == 6) {
            display_sorted_pharmacy(n , pharmacyID);
        }
        else if (choice == 7) {
            display_sorted_radiology(n, radiologyID);
        }
        else if (choice == 8) {
            clock_t before = clock();
            merge_to_master(pharmacyID, radiologyID, master);
            clock_t duration = clock() - before;
            cout << fixed << setprecision(6);
            cout << "Master List Merged "<<endl;
            cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds " <<endl;
        }else if (choice == 9){
            display_master_list(master);
        }else if (choice == 10){
            break;
        }
    }
    return 0;
}
