// Laba_1.cpp 
// part_5



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct student {
    char Name[50];
    char Surname[50];
    char Faculty[50];
    int Age;
};

int main() {
    struct student students[MAX_STUDENTS];
    int num_students, i;
    char search_name[50], search_surname[50];
    int found = 0;


    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter information about the students:\n");
    for (i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].Name);
        printf("Surname: ");
        scanf("%s", students[i].Surname);
        printf("Faculty: ");
        scanf("%s", students[i].Faculty);
        printf("Age: ");
        scanf("%d", &students[i].Age);
    }

    printf("\nEnter the name and surname to search: ");
    scanf("%s %s", search_name, search_surname);

    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].Name, search_name) == 0 && strcmp(students[i].Surname, search_surname) == 0) {
            found = 1;
            printf("\nInformation about the student:\n");
            printf("Name: %s\n", students[i].Name);
            printf("Surname: %s\n", students[i].Surname);
            printf("Faculty: %s\n", students[i].Faculty);
            printf("Age: %d\n", students[i].Age);
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found\n");
    }

    return 0;
}











