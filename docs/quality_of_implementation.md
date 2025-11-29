# Quality of Implementation

## Merge Sort - O(n log n)

```cpp
void mergeSort(vector<int>& arr, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}
```
Optimal for large datasets with guaranteed O(n log n) complexity.

---

## Duplicate Removal

```cpp
int last_added = -1;
while (i < n1 && j < n2) {
    if (ph[i] < rd[j]) {
        if (ph[i] != last_added) {
            master.push_back(format_record("PT", ph[i]));
            last_added = ph[i];
        }
        i++;
    }
}
```
Tracks last added value to prevent duplicates during merge operations.

---

## Input Validation

```cpp
if (n < 0 || n > 1000000) {
    cout << "Invalid value: value should be between 1 and 1000000" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
```
Validates range (1-1,000,000), prevents buffer overflow, and recovers input stream.

---

## Workflow Control

```cpp
if (!isPharmacySorted) {
    cout << "Pharmacy records are unsorted. Please use option 4 to sort" << endl;
}
```
Enforces operation order across all menu functions to prevent crashes.

---

## Performance Tracking

```cpp
clock_t before = clock();
mergeSort(pharmacyID, 0, n - 1);
clock_t duration = clock() - before;
cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds" << endl;
```
Measures execution time for algorithm comparison and optimization.
