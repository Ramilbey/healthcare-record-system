ALGORITHM HealthcareRecordSystem

// Global variables
DECLARE pharmacy_records, radiology_records AS integer arrays
DECLARE master_list AS string array
DECLARE n, pharmacy_sorted, radiology_sorted, records_generated

FUNCTION generate_patient_ids(n, department_array)
    CLEAR department_array
    FOR i FROM 0 TO n-1 DO
        id = RANDOM_NUMBER(0 to 9999999)  // Generates number between 0-9999999
        ADD id TO department_array
    END FOR
END FUNCTION

FUNCTION format_patient_id(id)
    // Convert number to 7-digit string with leading zeros, then add "PT" prefix
    number_str = CONVERT id TO string
    WHILE LENGTH(number_str) < 7 DO
        number_str = "0" + number_str
    END WHILE
    RETURN "PT" + number_str
END FUNCTION

FUNCTION display_array(ids, is_sorted, department_name)
    IF is_sorted THEN
        PRINT "Sorted " + department_name + " Records:"
    ELSE
        PRINT "Unsorted " + department_name + " Records:"
    END IF
    
    FOR i FROM 0 TO SIZE(ids)-1 DO
        IF ids IS integer array THEN
            PRINT format_patient_id(ids[i])
        ELSE
            PRINT ids[i]  // Already formatted strings
        END IF
    END FOR
END FUNCTION

// MERGESORT IMPLEMENTATION
FUNCTION merge(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    
    CREATE left_arr[n1], right_arr[n2]
    
    // Copy data to temporary arrays
    FOR i FROM 0 TO n1-1 DO
        left_arr[i] = arr[left + i]
    END FOR
    FOR j FROM 0 TO n2-1 DO
        right_arr[j] = arr[mid + 1 + j]
    END FOR
    
    i = 0, j = 0, k = left
    
    // Merge the temporary arrays back
    WHILE i < n1 AND j < n2 DO
        IF left_arr[i] <= right_arr[j] THEN
            arr[k] = left_arr[i]
            i = i + 1
        ELSE
            arr[k] = right_arr[j]
            j = j + 1
        END IF
        k = k + 1
    END WHILE
    
    // Copy remaining elements from left array
    WHILE i < n1 DO
        arr[k] = left_arr[i]
        i = i + 1
        k = k + 1
    END WHILE
    
    // Copy remaining elements from right array
    WHILE j < n2 DO
        arr[k] = right_arr[j]
        j = j + 1
        k = k + 1
    END WHILE
END FUNCTION

FUNCTION mergeSort(arr, left, right)
    IF left < right THEN
        mid = left + (right - left) / 2  // Avoids overflow
        
        mergeSort(arr, left, mid)        // Sort first half
        mergeSort(arr, mid + 1, right)   // Sort second half
        merge(arr, left, mid, right)     // Merge sorted halves
    END IF
END FUNCTION

// MERGE DEPARTMENTS WITH DUPLICATE REMOVAL
FUNCTION merge_departments_to_master(pharmacy, radiology, master)
    CLEAR master
    i = 0, j = 0
    n1 = SIZE(pharmacy), n2 = SIZE(radiology)
    
    WHILE i < n1 AND j < n2 DO
        IF pharmacy[i] < radiology[j] THEN
            ADD format_patient_id(pharmacy[i]) TO master
            i = i + 1
        ELSE IF radiology[j] < pharmacy[i] THEN
            ADD format_patient_id(radiology[j]) TO master
            j = j + 1
        ELSE
            // Equal values (duplicates) - add only once
            ADD format_patient_id(pharmacy[i]) TO master
            i = i + 1
            j = j + 1
        END IF
    END WHILE
    
    // Add remaining pharmacy elements
    WHILE i < n1 DO
        ADD format_patient_id(pharmacy[i]) TO master
        i = i + 1
    END WHILE
    
    // Add remaining radiology elements
    WHILE j < n2 DO
        ADD format_patient_id(radiology[j]) TO master
        j = j + 1
    END WHILE
END FUNCTION

// TIMING FUNCTIONS
FUNCTION measure_sorting_time(department_array, department_name)
    START high_resolution_timer
    CALL mergeSort(department_array, 0, SIZE(department_array)-1)
    STOP timer
    duration = CALCULATE duration in milliseconds
    PRINT department_name + " sorting time: " + duration + " ms"
    RETURN duration
END FUNCTION

FUNCTION measure_merge_time(pharmacy, radiology, master)
    START high_resolution_timer
    CALL merge_departments_to_master(pharmacy, radiology, master)
    STOP timer
    duration = CALCULATE duration in milliseconds
    PRINT "Merge time: " + duration + " ms"
    RETURN duration
END FUNCTION

// EMPIRICAL ANALYSIS FUNCTION
FUNCTION run_empirical_analysis()
    test_sizes = [1000, 5000, 16000, 32000, 85000, 150000, 300000, 512000, 800000, 1000000]
    trials = 5
    
    PRINT "Running empirical analysis..."
    PRINT "n, Pharmacy_Time, Radiology_Time, Merge_Time"
    
    FOR EACH size IN test_sizes DO
        total_pharmacy_time = 0
        total_radiology_time = 0
        total_merge_time = 0
        
        FOR trial FROM 1 TO trials DO
            // Generate records for this trial
            CALL generate_patient_ids(size, pharmacy_records)
            CALL generate_patient_ids(size, radiology_records)
            
            // Measure pharmacy sort time
            START timer
            CALL mergeSort(pharmacy_records, 0, size-1)
            STOP timer
            pharmacy_time = duration in ms
            total_pharmacy_time = total_pharmacy_time + pharmacy_time
            
            // Measure radiology sort time
            START timer
            CALL mergeSort(radiology_records, 0, size-1)
            STOP timer
            radiology_time = duration in ms
            total_radiology_time = total_radiology_time + radiology_time
            
            // Measure merge time
            START timer
            CALL merge_departments_to_master(pharmacy_records, radiology_records, master_list)
            STOP timer
            merge_time = duration in ms
            total_merge_time = total_merge_time + merge_time
        END FOR
        
        // Calculate averages
        avg_pharmacy = total_pharmacy_time / trials
        avg_radiology = total_radiology_time / trials
        avg_merge = total_merge_time / trials
        
        PRINT size + ", " + avg_pharmacy + ", " + avg_radiology + ", " + avg_merge
    END FOR
END FUNCTION

// MAIN MENU
FUNCTION display_main_menu()
    PRINT "===== Healthcare Record System ====="
    PRINT "1. Generate and sort records"
    PRINT "2. Show unsorted Pharmacy records"
    PRINT "3. Show unsorted Radiology records"
    PRINT "4. Show sorted Pharmacy records"
    PRINT "5. Show sorted Radiology records"
    PRINT "6. Merge and show master list"
    PRINT "7. Run empirical analysis (for report)"
    PRINT "8. Exit"
    PRINT "Enter choice: "
END FUNCTION

// MAIN PROGRAM
BEGIN
    SEED random number generator with current time
    SET pharmacy_sorted = FALSE, radiology_sorted = FALSE, records_generated = FALSE
    
    WHILE TRUE DO
        CALL display_main_menu()
        READ choice
        
        CASE choice OF
            1: PRINT "Enter number of records (max 1,000,000): "
               READ n
               IF n < 1 OR n > 1000000 THEN
                   PRINT "Error: Please enter between 1 and 1,000,000 records"
                   CONTINUE
               END IF
               
               // Generate records
               CALL generate_patient_ids(n, pharmacy_records)
               CALL generate_patient_ids(n, radiology_records)
               SET records_generated = TRUE
               
               // Sort and measure time
               pharmacy_time = measure_sorting_time(pharmacy_records, "Pharmacy")
               radiology_time = measure_sorting_time(radiology_records, "Radiology")
               
               SET pharmacy_sorted = TRUE, radiology_sorted = TRUE
               PRINT "Records generated and sorted successfully!"
               
            2: IF NOT records_generated THEN
                   PRINT "Please generate records first (Option 1)"
               ELSE
                   CALL display_array(pharmacy_records, FALSE, "Pharmacy")
               END IF
               
            3: IF NOT records_generated THEN
                   PRINT "Please generate records first (Option 1)"
               ELSE
                   CALL display_array(radiology_records, FALSE, "Radiology")
               END IF
               
            4: IF NOT pharmacy_sorted THEN
                   PRINT "Please sort records first (Option 1)"
               ELSE
                   CALL display_array(pharmacy_records, TRUE, "Pharmacy")
               END IF
               
            5: IF NOT radiology_sorted THEN
                   PRINT "Please sort records first (Option 1)"
               ELSE
                   CALL display_array(radiology_records, TRUE, "Radiology")
               END IF
               
            6: IF NOT pharmacy_sorted OR NOT radiology_sorted THEN
                   PRINT "Please sort both departments first (Option 1)"
               ELSE
                   merge_time = measure_merge_time(pharmacy_records, radiology_records, master_list)
                   PRINT "Merged Master List (duplicates removed):"
                   CALL display_array(master_list, TRUE, "Master")
               END IF
               
            7: CALL run_empirical_analysis()
               
            8: PRINT "Exiting program. Goodbye!"
               EXIT PROGRAM
               
            DEFAULT: PRINT "Invalid choice. Please enter 1-8."
        END CASE
        PRINT ""  // Empty line for readability
    END WHILE
END
