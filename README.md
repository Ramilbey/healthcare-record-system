# Healthcare Record Sorting System

This program manages two categories of healthcare records:

- **Pharmacy patient IDs** (`PTxxxxxxx`)
- **Radiology patient IDs** (`RDxxxxxxx`)

It can generate IDs, sort them using **Merge Sort**, and merge them into a **Master List** without duplicates.

---

## Features

### 1. Generate Records
Creates `n` random numeric IDs for:
- Pharmacy
- Radiology

Each ID is formatted as:

---

### 2. Display Unsorted Records
Shows the generated pharmacy or radiology lists before sorting.

---

### 3. Sort Records (Merge Sort)
Uses Merge Sort for both lists.  
Execution time is displayed using `clock()`.

Example:

---

### 4. Display Sorted Records
Shows the pharmacy or radiology records after sorting.

---

### 5. Merge Into Master List
Merges the two sorted lists (Pharmacy + Radiology):
- Sorted
- No duplicates
- Maintains prefixes (PT / RD)
- Displays merge time

---

### 6. Display Master List
Shows the final merged list of all unique records.

---

## Menu Options


---

## Algorithms Used

### Merge Sort
- Time complexity: **O(n log n)**
- Stable
- Used to sort both record lists

### Two-Pointer Merge
Used to merge the sorted lists while eliminating duplicates efficiently.

---

## Compile & Run

Compile with g++:

```bash
g++ -o healthcare main.cpp
