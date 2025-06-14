#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "add_remove.h"
#include "disp.h"

char id[20], pass[20];
int choice;
int found;
char line[50];
char tempId[20], tempPass[20];

struct Student {
    int number;
    char name[50];
    char surname[50];
    char gender[10];
};

void loadingAnimation(int seconds) {
    for (int i = 0; i < seconds; i++) {
        printf("Cikis Yapiliyor");
        for (int j = 0; j < 3; j++) {
            printf(".");
            fflush(stdout); 
            sleep(1); // 1 saniye bekle
        }
        printf("\r"); // Satırı temizle
    }
}

void waitForAnyKey() {
    printf("Press any key to return to the main menu...\n");
    getchar(); // İlk scanf'den sonra beklemek için kullanılır
    getchar(); // Kullanıcının tuşa basmasını bekler
}

int main()
{
    while(1){
        found=1;
        printf("Welcome to e-okul\n");
        printf("Please Enter Your ID Number\n");
        scanf("%s" , id);
        printf("Please Enter Your Password\n");
        scanf("%s", pass);

        FILE *dosya = fopen("users.txt", "r");
        if (dosya == NULL) {
            printf("Error! File doesn't open.\n");
            return 1;
        }

        while (fgets(line, sizeof(line), dosya)) {
            sscanf(line, "%[^,],%s", tempId, tempPass);
            if (strcmp(id, "admin") == 0 && strcmp(pass, "0000") == 0) {
                found = 2;
                break;
            }
            else if (strcmp(tempId, id) == 0 && strcmp(tempPass, pass) == 0) {
                found = 1;
                break;
            } else {
                found = 0;
            }
        }
        fclose(dosya);

        if(found == 2){
            while(1){
                printf("1- View all students \n");
                printf("2- Add/delete student \n");
                printf("3- View classes \n");
                printf("4- Search for a student \n");
                printf("5- View student grades and averages \n");
                printf("6- Add/delete Teacher \n");
                printf("7- Exit  \n");
                printf("Enter the number of menu: ");

                if (scanf("%d", &choice) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if(choice==0||choice>7){
                    printf("Wrong selection. Please try again.\n");
                    continue;
                }
                else if(choice==1){
                    printClassData("12A");
                    printClassData("12B");
                    printClassData("11A");
                    printClassData("11B");
                    printClassData("10A");
                    printClassData("10B");
                    printClassData("9A");
                    printClassData("9B");
                    waitForAnyKey();
                    continue;
                }
                else if(choice==2){
                    int operation;
                    printf("1- Add Student\n");
                    printf("2- Delete Student\n");
                    printf("Choose an operation: ");
                    scanf("%d", &operation);
                    printf("Enter the class file (e.g., 12A): ");
                    char filename[20];
                    scanf("%s", filename);
                    snprintf(filename, sizeof(filename), "%s.txt", filename);
                    if (operation == 1) {
                        addStudent(filename);
                    } else if (operation == 2) {
                        deleteStudent(filename);
                    } else {
                        printf("Invalid option.\n");
                    }
                    waitForAnyKey();
                    continue;
                }
                else if(choice==3){
                    printCustomFileData();
                    waitForAnyKey();
                    continue;
                }
                else if (choice == 4) {
                    char searchName[50], searchSurname[50];
                    printf("Enter student name (leave blank if not searching by name): ");
                    getchar();
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    printf("Enter student surname (leave blank if not searching by surname): ");
                    fgets(searchSurname, sizeof(searchSurname), stdin);
                    searchSurname[strcspn(searchSurname, "\n")] = '\0';

                    int result = searchStudent(searchName, searchSurname);
                    if (result != -1) {
                        printf("Selected student number: %d\n", result);
                    }
                    waitForAnyKey();
                }
                else if(choice==5){
                    printf("1 sewctin\n");
                    continue;
                }
                else if(choice==6){

                    int action;
                    printf("1- Add teacher\n");
                    printf("2- Remove teacher\n");
                    printf("Enter your action: ");
                    scanf("%d", &action);

                    if (action == 1) {
                        addUser(); // Kullanıcı ekleme
                    } else if (action == 2) {
                        deleteUser(); // Kullanıcı silme
                    } else {
                        printf("Invalid action!\n");
                    }
                }
                else if (choice == 7) {
                    loadingAnimation(1); // 3 saniye bekleyip animasyonu göster
                    break; // döngüden çık
                }
            }
        }
        else{
            printf("Wrong Password or ID number. Please try again\n");
            continue;
        }
    }
    return 0;
}
