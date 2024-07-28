#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 129

// Define the structure to hold student records
typedef struct {
    char name[MAX_NAME_LEN]; // Student name (up to 128 characters)
    int age;                 // Student age
    char grade;              // Student grade
    float height;            // Student height in feet
    int isEnrolled;          // Enrollment status (1 for true, 0 for false)
} Record;

/**
 * Function to read records from a file.
 * filename: Name of the file to read from.
 * records: Array to store the records read from the file.
 * numRecords: Number of records to read.
 */
void readRecordsFromFile(const char *filename, Record records[], int numRecords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRecords; i++) {
        fscanf(file, "%s %d %c %f %d", records[i].name, &records[i].age, &records[i].grade, &records[i].height, &records[i].isEnrolled);
    }

    fclose(file);
}

/**
 * Function to write records to a file.
 * filename: Name of the file to write to.
 * records: Array containing the records to write.
 * numRecords: Number of records to write.
 */
void writeRecordsToFile(const char *filename, Record records[], int numRecords) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numRecords; i++) {
        fprintf(file, "%s %d %c %f %d\n", records[i].name, records[i].age, records[i].grade, records[i].height, records[i].isEnrolled);
    }

    fclose(file);
}

int main() {
    Record records[15]; // Array to hold 15 records

    // Read five records from input file
    readRecordsFromFile("exp1b.txt", records, 5);

    // Adding 10 more records manually
    for (int i = 5; i < 15; i++) {
        snprintf(records[i].name, MAX_NAME_LEN, "Student%d", i + 1);
        records[i].age = 20 + (i - 5);  // Adjusted to start at age 20
        records[i].grade = 'A' + (i - 5); // Adjusted to start at grade 'A'
        records[i].height = 5.5 + (i - 5) * 0.1; // Adjusted to start at height 5.5
        records[i].isEnrolled = 1;
    }

    // Write ten records to output file
    writeRecordsToFile("output_exp1b.txt", records, 15);

    // Print all 15 records
    for (int i = 0; i < 15; i++) {
        printf("Name: %s, Age: %d, Grade: %c, Height: %.1f, Enrolled: %d\n", records[i].name, records[i].age, records[i].grade, records[i].height, records[i].isEnrolled);
    }

    printf("Records have been written to output_exp1b.txt\n");
    return 0;
}
