#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

void addContact() {
    struct Contact c;
    FILE *fp;

    fp = fopen("contacts.dat", "ab"); // append binary
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter phone number: ");
    scanf("%s", c.phone);

    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}

void viewContacts() {
    struct Contact c;
    FILE *fp;

    fp = fopen("contacts.dat", "rb");
    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(c), 1, fp)) {
        printf("%s - %s\n", c.name, c.phone);
    }

    fclose(fp);
}

void searchContact() {
    struct Contact c;
    FILE *fp;
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", name);

    fp = fopen("contacts.dat", "rb");
    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("Contact Found: %s - %s\n", c.name, c.phone);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Contact not found.\n");
}

void deleteContact() {
    struct Contact c;
    FILE *fp, *temp;
    char name[50];
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", name);

    fp = fopen("contacts.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    if (found)
        printf("Contact deleted successfully!\n");
    else
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
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
