GLOBAL VARIABLES
isPharmacySorted ← FALSE
isRadiologySorted ← FALSE
isMasterMerged ← FALSE

FUNCTION generate_pharmacy(n, pharmacyID)
CLEAR pharmacyID
FOR i FROM 0 TO n-1
randomNum ← RANDOM_INTEGER(0, 9999999)
APPEND randomNum TO pharmacyID
END FOR
END FUNCTION

FUNCTION generate_radiology(n, radiologyID)
CLEAR radiologyID
FOR i FROM 0 TO n-1
randomNum ← RANDOM_INTEGER(0, 9999999)
APPEND randomNum TO radiologyID
END FOR
END FUNCTION

FUNCTION display_unsorted(list, prefix)
FOR each id IN list
PRINT prefix + formatted_7_digit_zero_padded(id)
END FOR
END FUNCTION

FUNCTION merge(arr, first, mid, last)
CREATE temp ARRAY of size (last - first + 1)
i1 ← first, i2 ← mid + 1, idx ← 0

    WHILE i1 ≤ mid AND i2 ≤ last
        IF arr[i1] ≤ arr[i2]
            temp[idx] ← arr[i1]
            i1 ← i1 + 1
        ELSE
            temp[idx] ← arr[i2]
            i2 ← i2 + 1
        END IF
        idx ← idx + 1
    END WHILE

    WHILE i1 ≤ mid
        temp[idx] ← arr[i1]
        i1 ← i1 + 1
        idx ← idx + 1
    END WHILE

    WHILE i2 ≤ last
        temp[idx] ← arr[i2]
        i2 ← i2 + 1
        idx ← idx + 1
    END WHILE

    COPY temp BACK to arr[first … last]
END FUNCTION

FUNCTION mergeSort(arr, first, last)
IF first < last
mid ← (first + last) / 2
mergeSort(arr, first, mid)
mergeSort(arr, mid + 1, last)
merge(arr, first, mid, last)
END IF
END FUNCTION

FUNCTION format_record(id)
RETURN "PT" + zero_padded_7_digits(id)
END FUNCTION

FUNCTION merge_to_master(pharmacyID, radiologyID, master)
CLEAR master
i ← 0, j ← 0
lastAdded ← -1

    WHILE i < size(pharmacyID) AND j < size(radiologyID)
        IF pharmacyID[i] < radiologyID[j]
            IF pharmacyID[i] ≠ lastAdded
                APPEND format_record(pharmacyID[i]) TO master
                lastAdded ← pharmacyID[i]
            END IF
            i ← i + 1
        ELSE
            IF radiologyID[j] ≠ lastAdded
                APPEND format_record(radiologyID[j]) TO master
                lastAdded ← radiologyID[j]
            END IF
            j ← j + 1
        END IF
    END WHILE

    WHILE i < size(pharmacyID)
        IF pharmacyID[i] ≠ lastAdded
            APPEND format_record(pharmacyID[i]) TO master
            lastAdded ← pharmacyID[i]
        END IF
        i ← i + 1
    END WHILE

    WHILE j < size(radiologyID)
        IF radiologyID[j] ≠ lastAdded
            APPEND format_record(radiologyID[j]) TO master
            lastAdded ← radiologyID[j]
        END IF
        j ← j + 1
    END WHILE
END FUNCTION

FUNCTION display_master(master)
FOR each record IN master
PRINT record
END FOR
END FUNCTION

FUNCTION show_menu()
PRINT "===== Healthcare Record System ====="
PRINT "1. Generate records"
PRINT "2. Show unsorted Pharmacy records"
PRINT "3. Show unsorted Radiology records"
PRINT "4. Sort pharmacy"
PRINT "5. Sort radiology"
PRINT "6. Show sorted pharmacy records"
PRINT "7. Show sorted radiology records"
PRINT "8. Merge into master list"
PRINT "9. Show master list"
PRINT "10. Exit"
END FUNCTION

MAIN PROGRAM
SEED_RANDOM_GENERATOR()
DECLARE pharmacyID, radiologyID AS empty lists of integers
DECLARE master AS empty list of strings
DECLARE n, choice

    WHILE TRUE
        show_menu()
        READ choice

        IF choice NOT IN 1..10
            PRINT "Invalid choice"
            CONTINUE
        END IF

        IF choice = 1
            PRINT "Enter number of records to generate: "
            READ n
            IF n ≤ 0 OR n > 1000000
                PRINT "Error: n must be between 1 and 1,000,000"
            ELSE
                generate_pharmacy(n, pharmacyID)
                generate_radiology(n, radiologyID)
                PRINT "Records generated successfully"
            END IF

        ELSE IF choice = 2
            IF pharmacyID IS EMPTY
                PRINT "No records. Generate first (Option 1)"
            ELSE
                PRINT "Unsorted Pharmacy Records:"
                display_unsorted(pharmacyID, "PT")
            END IF

        ELSE IF choice = 3
            IF radiologyID IS EMPTY
                PRINT "No records. Generate first (Option 1)"
            ELSE
                PRINT "Unsorted Radiology Records:"
                display_unsorted(radiologyID, "PT")
            END IF

        ELSE IF choice = 4
            IF pharmacyID IS EMPTY
                PRINT "No records. Generate first"
            ELSE
                START_TIMER
                mergeSort(pharmacyID, 0, n-1)
                duration ← STOP_TIMER
                isPharmacySorted ← TRUE
                PRINT "Pharmacy records sorted in", duration, "seconds"
            END IF

        ELSE IF choice = 5
            IF radiologyID IS EMPTY
                PRINT "No records. Generate first"
            ELSE
                START_TIMER
                mergeSort(radiologyID, 0, n-1)
                duration ← STOP_TIMER
                isRadiologySorted ← TRUE
                PRINT "Radiology records sorted in", duration, "seconds"
            END IF

        ELSE IF choice = 6
            IF pharmacyID IS EMPTY
                PRINT "No records"
            ELSE IF NOT isPharmacySorted
                PRINT "Pharmacy records not sorted yet. Use option 4"
            ELSE
                display_unsorted(pharmacyID, "PT")  // already sorted
            END IF

        ELSE IF choice = 7
            IF radiologyID IS EMPTY
                PRINT "No records"
            ELSE IF NOT isRadiologySorted
                PRINT "Radiology records not sorted yet. Use option 5"
            ELSE
                display_unsorted(radiologyID, "PT")
            END IF

        ELSE IF choice = 8
            IF pharmacyID IS EMPTY OR radiologyID IS EMPTY
                PRINT "Generate records first"
            ELSE IF NOT isPharmacySorted
                PRINT "Sort pharmacy records first (Option 4)"
            ELSE IF NOT isRadiologySorted
                PRINT "Sort radiology records first (Option 5)"
            ELSE
                START_TIMER
                merge_to_master(pharmacyID, radiologyID, master)
                duration ← STOP_TIMER
                isMasterMerged ← TRUE
                PRINT "Master list merged in", duration, "seconds"
            END IF

        ELSE IF choice = 9
            IF master IS EMPTY OR NOT isMasterMerged
                PRINT "Master list not created. Use option 8 first"
            ELSE
                display_master(master)
            END IF

        ELSE IF choice = 10
            EXIT LOOP
        END IF
    END WHILE

END MAIN