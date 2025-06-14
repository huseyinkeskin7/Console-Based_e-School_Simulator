#include "disp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printClassData(const char* className) {
    char filename[20];
    snprintf(filename, sizeof(filename), "%s.txt", className);
    FILE *dosya = fopen(filename, "r");
    if (dosya == NULL) {
        printf("Error! %s file doesn't open.\n", filename);
        return;
    }
    struct Student students[100];
    int count = 0;

    while (fscanf(dosya, "%d,%[^,],%[^,],%[^,\n]\n", &students[count].number, students[count].name, students[count].surname, students[count].gender) == 4) {
        count++;
    }
    fclose(dosya);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].number > students[j + 1].number) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s %s (%s)\n", students[i].number, students[i].name, students[i].surname, students[i].gender);
    }
}

void printCustomFileData() {
    char filename[20];
    printf("Enter the name of the .txt file (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt"); // Dosya uzantýsýný ekle

    FILE *dosya = fopen(filename, "r");
    if (dosya == NULL) {
        printf("Error! %s file doesn't open.\n", filename);
        return;
    }

    // Dosyadaki satýrlarý yazdýr
    char line[100]; // Satýr için yeterli boyut
    printf("Contents of %s:\n", filename);
    while (fgets(line, sizeof(line), dosya)) {
        printf("%s", line); // Satýrý yazdýr
    }

    fclose(dosya);
}

int searchStudent(const char* searchName, const char* searchSurname) {
    char* classFiles[] = {"9A.txt", "9B.txt", "10A.txt", "10B.txt", "11A.txt", "11B.txt", "12A.txt", "12B.txt"};
    int matchCount = 0;
    char line[100];
    int selectedMatch = -1;

    for (int i = 0; i < 8; i++) {
        FILE *dosya = fopen(classFiles[i], "r");
        if (dosya == NULL) {
            printf("Error! %s file doesn't open.\n", classFiles[i]);
            continue;
        }

        int lineNum = 1;
        while (fgets(line, sizeof(line), dosya)) {
            struct Student student;
            sscanf(line, "%d,%[^,],%[^,],%s", &student.number, student.name, student.surname, student.gender);

            int nameMatch = (strlen(searchName) > 0) && strcmp(student.name, searchName) == 0;
            int surnameMatch = (strlen(searchSurname) > 0) && strcmp(student.surname, searchSurname) == 0;

            if ((strlen(searchName) > 0 && strlen(searchSurname) > 0 && nameMatch && surnameMatch) ||
                (strlen(searchName) > 0 && nameMatch && strlen(searchSurname) == 0) ||
                (strlen(searchSurname) > 0 && surnameMatch && strlen(searchName) == 0)) {
                matchCount++;
                printf("%d - %s: %d %s %s %s\n", matchCount, classFiles[i], student.number, student.name, student.surname, student.gender);
            }
        }
        fclose(dosya);
    }

    if (matchCount == 0) {
        printf("No matching students found.\n");
        return -1;
    } else {
        printf("Enter the number of the student you want to select: ");
        scanf("%d", &selectedMatch);

        if (selectedMatch <= 0 || selectedMatch > matchCount) {
            printf("Invalid selection.\n");
            return -1;
        } else {
            printf("Student %d selected.\n", selectedMatch);
            return selectedMatch;
        }
    }
}
