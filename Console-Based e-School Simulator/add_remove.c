#include "add_remove.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addStudent(const char* filename) {
    struct Student newStudent;

    printf("Enter student number: ");
    scanf("%d", &newStudent.number);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student surname: ");
    scanf("%s", newStudent.surname);
    printf("Enter student gender: ");
    scanf("%s", newStudent.gender);

    FILE *dosya = fopen(filename, "a");
    if (dosya == NULL) {
        printf("Error! File doesn't open.\n");
        return;
    }

    fprintf(dosya, "%d,%s,%s,%s\n", newStudent.number, newStudent.name, newStudent.surname, newStudent.gender);
    fclose(dosya);
    printf("Student added successfully!\n");
}

void deleteStudent(const char* filename) {
    FILE *dosya = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char line[100];
    int lineNum = 1;
    int deleteLine;

    if (dosya == NULL || tempFile == NULL) {
        printf("Error! File doesn't open.\n");
        return;
    }

    printf("Students in %s:\n", filename);
    while (fgets(line, sizeof(line), dosya)) {
        printf("%d: %s", lineNum, line);
        lineNum++;
    }

    printf("Enter the line number of the student to delete: ");
    scanf("%d", &deleteLine);

    rewind(dosya);
    lineNum = 1;
    while (fgets(line, sizeof(line), dosya)) {
        if (lineNum != deleteLine) {
            fputs(line, tempFile);
        }
        lineNum++;
    }

    fclose(dosya);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
    printf("Student deleted successfully!\n");
}

void addUser() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *dosya = fopen("users.txt", "a");
    if (dosya == NULL) {
        printf("Error! users.txt file doesn't open.\n");
        return;
    }

    fprintf(dosya, "%s,%s\n", username, password);
    fclose(dosya);
    printf("User added successfully!\n");
}

void deleteUser() {
    FILE *dosya = fopen("users.txt", "r");
    FILE *tempFile = fopen("temp_users.txt", "w");
    char line[100];
    int lineNum = 1;
    int deleteLine;

    if (dosya == NULL || tempFile == NULL) {
        printf("Error! File doesn't open.\n");
        return;
    }

    printf("Current users in users.txt:\n");
    while (fgets(line, sizeof(line), dosya)) {
        printf("%d: %s", lineNum, line);
        lineNum++;
    }

    printf("Enter the line number of the user to delete: ");
    scanf("%d", &deleteLine);

    rewind(dosya);
    lineNum = 1;
    while (fgets(line, sizeof(line), dosya)) {
        if (lineNum != deleteLine) {
            fputs(line, tempFile);
        }
        lineNum++;
    }

    fclose(dosya);
    fclose(tempFile);
    remove("users.txt");
    rename("temp_users.txt", "users.txt");
    printf("User deleted successfully!\n");
}
