ALGORITHM HealthcareRecordSystem


FUNCTION generate_pharmacy(n, pharmacyID)
    CLEAR pharmacyID
    FOR i FROM 0 TO n-1 DO
        temp = RANDOM_NUMBER(0 to 9999999)
        ADD temp TO pharmacyID
    END FOR
END FUNCTION

FUNCTION generate_radiology(n, radiologyID)
    CLEAR radiologyID
    FOR i FROM 0 TO n-1 DO
        temp = RANDOM_NUMBER(0 to 9999999)
        ADD temp TO radiologyID
    END FOR
END FUNCTION

FUNCTION display_pharmacy(n, pharmacyID)
    FOR i FROM 0 TO n-1 DO
        PRINT "PT" + FORMAT(pharmacyID[i], 7 digits with leading zeros)
    END FOR
END FUNCTION


FUNCTION display_radiology(n, radiologyID)
    FOR i FROM 0 TO n-1 DO
        PRINT "PT" + FORMAT(radiologyID[i], 7 digits with leading zeros)
    END FOR
END FUNCTION


FUNCTION merge(arr, first, mid, last)
    CREATE temp array of size (last - first + 1)
    first1 = first
    last1 = mid
    first2 = mid + 1
    last2 = last
    index = 0
    
    WHILE first1 <= last1 AND first2 <= last2 DO
        IF arr[first1] <= arr[first2] THEN
            temp[index] = arr[first1]
            INCREMENT index and first1
        ELSE
            temp[index] = arr[first2]
            INCREMENT index and first2
        END IF
    END WHILE
    
  
    WHILE first1 <= last1 DO
        temp[index] = arr[first1]
        INCREMENT index and first1
    END WHILE
    
    WHILE first2 <= last2 DO
        temp[index] = arr[first2]
        INCREMENT index and first2
    END WHILE
    
    FOR i FROM 0 TO index-1 DO
        arr[first + i] = temp[i]
    END FOR
END FUNCTION

FUNCTION mergeSort(arr, first, last)
    IF first < last THEN
        mid = (first + last) / 2
        mergeSort(arr, first, mid)          // Sort left half
        mergeSort(arr, mid + 1, last)       // Sort right half
        merge(arr, first, mid, last)        // Merge sorted halves
    END IF
END FUNCTION

FUNCTION format_record(prefix, id)
    RETURN prefix + FORMAT(id, 7 digits with leading zeros)
END FUNCTION

FUNCTION merge_to_master(ph, rd, master)
    CLEAR master
    i = 0
    j = 0
    n1 = SIZE(ph)
    n2 = SIZE(rd)
    last_added = -1
    
    WHILE i < n1 AND j < n2 DO
        IF ph[i] < rd[j] THEN
            IF ph[i] != last_added THEN
                ADD format_record("PT", ph[i]) TO master
                last_added = ph[i]
            END IF
            INCREMENT i
        ELSE
            IF rd[j] != last_added THEN
                ADD format_record("RD", rd[j]) TO master
                last_added = rd[j]
            END IF
            INCREMENT j
        END IF
    END WHILE
    
    WHILE i < n1 DO
        IF ph[i] != last_added THEN
            ADD format_record("PT", ph[i]) TO master
            last_added = ph[i]
        END IF
        INCREMENT i
    END WHILE
    
    WHILE j < n2 DO
        IF rd[j] != last_added THEN
            ADD format_record("RD", rd[j]) TO master
            last_added = rd[j]
        END IF
        INCREMENT j
    END WHILE
END FUNCTION

FUNCTION display_master_list(master)
    FOR i FROM 0 TO SIZE(master)-1 DO
        PRINT master[i]
    END FOR
END FUNCTION

FUNCTION menu()
    PRINT "===== Healthcare Record System ====="
    PRINT "1. Generate records"
    PRINT "2. Show unsorted Pharmacy records"
    PRINT "3. Show unsorted Radiology records"
    PRINT "4. Sort pharmacy"
    PRINT "5. Sort radiology"
    PRINT "6. Show pharmacy records"
    PRINT "7. Show radiology records"
    PRINT "8. Merge into --> master list"
    PRINT "9. Show master list"
    PRINT "10. Exit"
END FUNCTION

BEGIN
    SEED random number generator with current time
    
    DECLARE n (number of records)
    DECLARE pharmacyID array
    DECLARE radiologyID array
    DECLARE master list
    
    WHILE TRUE DO
        CALL menu()
        READ choice
        
        CASE choice OF
            1: READ n
               CALL generate_pharmacy(n, pharmacyID)
               CALL generate_radiology(n, radiologyID)
               PRINT "Records generated"
               
            2: PRINT "Unsorted Records for Pharmacy"
               CALL display_pharmacy(n, pharmacyID)
               
            3: PRINT "Unsorted Records for Radiology"
               CALL display_radiology(n, radiologyID)
               
            4: START timer
               CALL mergeSort(pharmacyID, 0, n-1)
               STOP timer and CALCULATE duration
               PRINT "Pharmacy Records Sorted"
               PRINT "Duration: " + duration + " seconds"
               
            5: START timer
               CALL mergeSort(radiologyID, 0, n-1)
               STOP timer and CALCULATE duration
               PRINT "Radiology Records Sorted"
               PRINT "Duration: " + duration + " seconds"
               
            6: CALL display_sorted_pharmacy(n, pharmacyID)
            
            7: CALL display_sorted_radiology(n, radiologyID)
            
            8: START timer
               CALL merge_to_master(pharmacyID, radiologyID, master)
               STOP timer and CALCULATE duration
               PRINT "Master List Merged"
               PRINT "Duration: " + duration + " seconds"
               
            9: CALL display_master_list(master)
            
            10: EXIT loop
        END CASE
    END WHILE
END
