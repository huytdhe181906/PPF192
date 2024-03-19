#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    int quantity;
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void showMenu() {
    printf("\n=======================MENU============================\n");
    printf("| 1- Add a book to the list                   Press: 1 |\n");
    printf("| 2- Search for a book                        Press: 2 |\n");
    printf("| 3- Update a book                            Press: 3 |\n");
    printf("| 4- Delete a book                            Press: 4 |\n");
    printf("| 5- Show the list of books in alphabetical   Press: 5 |\n");
    printf("| 6- Show the list of books in ascending      Press: 6 |\n");
    printf("| 7- Exit the program                         Press: 7 |\n");
    printf("========================================================\n");
    printf("Enter Your Choice: ");
}

int isFull() {
    return bookCount == MAX_BOOKS;
}

int isEmpty() {
    return bookCount == 0;
}

void addBook() {
    if (isFull()) {
        printf("\nSorry! The List is full!\n");
        return;
    }

    printf("\nEnter title of the book: ");
    scanf("%s", books[bookCount].title);

    printf("Enter quantity of the book: ");
    scanf("%d", &books[bookCount].quantity);

    printf("\nAdded!\n");
    bookCount++;
}

void searchBook() {
    if (isEmpty()) {
        printf("\nSorry! The List is empty!\n");
        return;
    }

    char title[50];
    printf("\nEnter title of the book: ");
    scanf("%s", title);

    int found = 0;
    int i;
    for ( i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("\nFound it!\n");
            printf("Title: %s, Quantity: %d\n", books[i].title, books[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNot found!\n");
    }
}

void updateBook() {
    if (isEmpty()) {
        printf("\nSorry! The List is empty!\n");
        return;
    }

    char title[50];
    printf("\nEnter title of the book: ");
    scanf("%s", title);

    int found = 0;
    int i;
	for ( i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            found = 1;
            printf("Enter new title of the book: ");
            scanf("%s", books[i].title);

            printf("Enter new quantity of the book: ");
            scanf("%d", &books[i].quantity);

            printf("\nUpdated!\n");
            break;
        }
    }

    if (!found) {
        printf("\nNot found!\n");
    }
}

void removeBook() {
    if (isEmpty()) {
        printf("\nSorry! The List is empty!\n");
        return;
    }

    char title[50];
    printf("\nEnter title of the book: ");
    scanf("%s", title);

    int found = 0;
    int i;
	for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            found = 1;
            int j;
			for ( j = i; j < bookCount - 1; j++) {
                strcpy(books[j].title, books[j + 1].title);
                books[j].quantity =books[j + 1].quantity;
            }
            bookCount--;
            printf("\nThis book has been removed from list successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nNot found!\n");
    }
}

void printBooksInAlphabeticalOrder() {
    if (isEmpty()) {
        printf("\nSorry! The List is empty!\n");
        return;
    }

    int i, j;
	for ( i = 0; i < bookCount - 1; i++) {
        
		for ( j = i + 1; j < bookCount; j++) {
            if (strcmp(books[i].title, books[j].title) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("\nList of books in alphabetical order:\n");
    for (i = 0; i < bookCount; i++) {
        printf("%s, %d\n", books[i].title, books[i].quantity);
    }
}

void printBooksInAscendingQuantity() {
    if (isEmpty()) {
        printf("\nSorry! The List is empty!\n");
        return;
    }

    int i;
	for ( i = 0; i < bookCount - 1; i++) {
        int j;
		for ( j = i + 1; j < bookCount; j++) {
            if (books[i].quantity > books[j].quantity) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("\nList of books in ascending quantity:\n");
    for (i = 0; i < bookCount; i++) {
        printf("%s, %d\n", books[i].title, books[i].quantity);
    }
}

int main() {
    int userChoice, check = 1;

    do {
        showMenu();scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                if (!isFull()) {
                    addBook();
                } else {
                    printf("\nSorry! The List is full!\n");
                }
                break;
            case 2:
                searchBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                printBooksInAlphabeticalOrder();
                break;
            case 6:
                printBooksInAscendingQuantity();
                break;
            case 7:
                check = 0;
                break;
            default:
                printf("\n>>>Wrong input!!!!\n");
                break;
        }
    } while (check == 1);

    printf("\nGood Bye!");

    return 0;
}
