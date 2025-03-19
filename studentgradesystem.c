#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// Structure to store student data
struct Student {
    char name[50];
    int marks[5];  // Assuming 5 subjects
    float average;
    char grade;
};

// Function to calculate grade
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    struct Student s;
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);

    int total = 0;
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
        total += s.marks[i];
    }

    s.average = total / 5.0;
    s.grade = calculateGrade(s.average);
    
    students[*count] = s;
    (*count)++;

    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s\n", "Name", "Average", "Grade");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10c\n", students[i].name, students[i].average, students[i].grade);
    }
}

// Function to save student records to a file
void saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error saving to file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %c\n", students[i].name, students[i].average, students[i].grade);
    }

    fclose(file);
    printf("Student records saved successfully!\n");
}

// Main function
int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n====== Student Grade Management System ======\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save Records to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
