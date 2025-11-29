Quality of Implementation 
___
Mergo sort O(n log n) - works well for large datasets
```
void mergeSort(vector<int>& arr, int first, int last){
  if(first < last) {
    int mid = (first + last ) / 2;
    mergeSort(arr, first, mid)
    mergeSort(arr, mid+1,  last)
    merge(arr, first, mid, last)
  }
}
```
---
Removing duplicates while merging
```
int last_added = -1;
while(1 < n1 && j < n2){
  if(ph[i] < rd[j]{
    if(ph[i] != last_added) {
      master.push_back(format_record("PT", ph[i];
      last_added = ph[i];
    }
    i++;
  }
}
```
---
input validation
```
if( n < 0 || n > 1000000){
  cout << "Invalid value : value should be between 1 and 1000000" << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>:: max(), '\n');
}
```
Prevents invalid input and buffer overflow. Clears input for recovery using cin.clear().
---
Workflow control
```
if(!isPharmacySorted){
  cout<< "Pharmacy records are unsorted. Pls use option 4 to sort" << endl;
}
```
If user tries to input a choice which can only be executed after specific choice has been run. Program checks if that specific choice has first been executed after that next chosen choice runs. It helps to prevent program from crushing and executing operations in wrong order. The same logic applies with all 10 menu function operations. 
---
Perfomance TRackingn 
```
clock_t before = clock();
mergeSOrt(pharmacyID, 0, n-1);
clock_t duration = clock() - before;
cout << "Duration " << (float)duration / CLOCKS_PER_SEC << "seconds"<< enld;
```
Using clock() to compare algorithms. The same logic applies for departments to calculate the performance.










