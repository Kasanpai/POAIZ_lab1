// //Laba_1.cpp 
// //part_5
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct student {
//    char Name[50];
//    char Surname[50];
//    char Faculty[20];
//    int Age;
//};
//
//int main() {
//
//    
//    struct student* students;
//    int num_students, i;
//    char search_name[50], search_surname[50];
//    int found = 0;
//
//    printf("Enter the number of students: ");
//    scanf("%d", &num_students);
//
//    students = (struct student*)malloc(num_students * sizeof(struct student));
//    if (students == NULL) {
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    printf("Enter information about the students:\n");
//    for (i = 0; i < num_students; i++) {
//        printf("Student %d:\n", i + 1);
//        printf("Name: ");
//        scanf("%s", students[i].Name);
//        printf("Surname: ");
//        scanf("%s", students[i].Surname);
//        printf("Faculty: ");
//        scanf("%s", students[i].Faculty);
//        printf("Age: ");
//        scanf("%d", &students[i].Age);
//    }
//
//    printf("\nEnter the name and surname to search: ");
//    scanf("%s %s", search_name, search_surname);
//
//    for (i = 0; i < num_students; i++) {
//        if (strcmp(students[i].Name, search_name) == 0 && strcmp(students[i].Surname, search_surname) == 0) {
//            found = 1;
//            printf("\nInformation about the student:\n");
//            printf("Name: %s\n", students[i].Name);
//            printf("Surname: %s\n", students[i].Surname);
//            printf("Faculty: %s\n", students[i].Faculty);
//            printf("Age: %d\n", students[i].Age);
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("\nStudent not found\n");
//    }
//
//    free(students);
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char Name[50];
    char Surname[50];
    char Faculty[20];
    int Age;
    struct student* next; // Указатель на следующий узел
};

// Функция для добавления студента в конец списка
void add_student(struct student** head, struct student new_student) {
    struct student* new_node = (struct student*)malloc(sizeof(struct student));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    *new_node = new_student; // Копируем данные студента
    new_node->next = NULL; // Новый узел будет последним

    if (*head == NULL) {
        *head = new_node; // Если список пуст, новый узел становится головой
    }
    else {
        struct student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Находим последний узел
        }
        temp->next = new_node; // Добавляем новый узел в конец списка
    }
}

// Функция для поиска студента по имени и фамилии
struct student* find_student(struct student* head, char* name, char* surname) {
    struct student* current = head;
    while (current != NULL) {
        if (strcmp(current->Name, name) == 0 && strcmp(current->Surname, surname) == 0) {
            return current; // Возвращаем найденный узел
        }
        current = current->next; // Переходим к следующему узлу
    }
    return NULL; // Если не найдено
}

// Функция для освобождения памяти
void free_students(struct student* head) {
    struct student* current = head;
    struct student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct student* students = NULL; // Указатель на голову списка
    int num_students, i;
    char search_name[50], search_surname[50];

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter information about the students:\n");
    for (i = 0; i < num_students; i++) {
        struct student new_student; // Временный объект для нового студента
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", new_student.Name);
        printf("Surname: ");
        scanf("%s", new_student.Surname);
        printf("Faculty: ");
        scanf("%s", new_student.Faculty);
        printf("Age: ");
        scanf("%d", &new_student.Age);
        add_student(&students, new_student); // Добавляем студента в список
    }

    printf("\nEnter the name and surname to search: ");
    scanf("%s %s", search_name, search_surname);

    struct student* found_student = find_student(students, search_name, search_surname);
    if (found_student != NULL) {
        printf("\nInformation about the student:\n");
        printf("Name: %s\n", found_student->Name);
        printf("Surname: %s\n", found_student->Surname);
        printf("Faculty: %s\n", found_student->Faculty);
        printf("Age: %d\n", found_student->Age);
    }
    else {
        printf("\nStudent not found\n");
    }

    free_students(students); // Освобождаем память
    return 0;
}
