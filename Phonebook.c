#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[100];
int count = 0;

void addContact() {
    printf("Enter name: ");
    scanf("%s", contacts[count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[count].phone);
    count++;
    printf("Contact added!\n");
}

void viewContacts() {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact() {
    char name[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

void deleteContact() {
    char name[50];
    int found = 0;
    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            printf("Contact deleted.\n");
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=== PHONE BOOK ===\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
