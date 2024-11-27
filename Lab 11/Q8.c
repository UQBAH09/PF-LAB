#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define FILE_NAME "books.txt"

// Structure to store book information
typedef struct
{
    int book_id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int quantity;
    float price;
} Book;

// Function prototypes
void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();
void calculateInventoryValue();
int bookExists(int id);

int main()
{
    int choice;
    while (1)
    {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book by ID or Title\n");
        printf("4. Update Book Details\n");
        printf("5. Delete a Book\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            updateBook();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
            calculateInventoryValue();
            break;
        case 7:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addBook()
{
    FILE *file = fopen(FILE_NAME, "a+");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.book_id);

    if (bookExists(book.book_id))
    {
        printf("Book with ID %d already exists.\n", book.book_id);
        fclose(file);
        return;
    }

    printf("Enter Title: ");
    getchar();
    fgets(book.title, MAX_TITLE, stdin);
    strtok(book.title, "\n"); 

    printf("Enter Author: ");
    fgets(book.author, MAX_AUTHOR, stdin);
    strtok(book.author, "\n");

    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    if (book.quantity < 0)
    {
        book.quantity = 0;
    }

    printf("Enter Price: ");
    scanf("%f", &book.price);
    if (book.price < 0)
    {
        book.price = 0;
    }

    fprintf(file, "%d,%s,%s,%d,%.2f\n", book.book_id, book.title, book.author, book.quantity, book.price);
    printf("Book added successfully.\n");
    fclose(file);
}

void viewBooks()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error opening file or no records found.\n");
        return;
    }

    Book book;
    printf("\n%-10s %-30s %-30s %-10s %-10s\n", "Book ID", "Title", "Author", "Quantity", "Price");
    printf("--------------------------------------------------------------------------------\n");
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        printf("%-10d %-30s %-30s %-10d %-10.2f\n", book.book_id, book.title, book.author, book.quantity, book.price);
    }
    fclose(file);
}

void searchBook()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    int id;
    char title[MAX_TITLE];
    int found = 0;
    Book book;

    printf("Enter Book ID: ");
    scanf("%d", &id);
    getchar();

    printf("Enter Title: ");
    fgets(title, MAX_TITLE, stdin);
    strtok(title, "\n");

    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        if (book.book_id == id || strcmp(book.title, title) == 0)
        {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", book.book_id, book.title, book.author, book.quantity, book.price);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Book not found.\n");
    }
    fclose(file);
}

void updateBook()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile)
    {
        printf("Error opening file.\n");
        return;
    }

    int id, found = 0;
    Book book;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        if (book.book_id == id)
        {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new price: ");
            scanf("%f", &book.price);
            printf("Book updated successfully.\n");
        }
        fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.book_id, book.title, book.author, book.quantity, book.price);
    }

    if (!found)
    {
        printf("Book with ID %d not found.\n", id);
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

void deleteBook()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile)
    {
        printf("Error opening file.\n");
        return;
    }

    int id, found = 0;
    Book book;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        if (book.book_id != id)
        {
            fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.book_id, book.title, book.author, book.quantity, book.price);
        }
        else
        {
            found = 1;
        }
    }

    if (found)
    {
        printf("Book deleted successfully.\n");
    }
    else
    {
        printf("Book with ID %d not found.\n", id);
    }

    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

void calculateInventoryValue()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Book book;
    float totalValue = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        totalValue += book.quantity * book.price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);
    fclose(file);
}

int bookExists(int id)
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        return 0;
    }

    Book book;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%f\n", &book.book_id, book.title, book.author, &book.quantity, &book.price) != EOF)
    {
        if (book.book_id == id)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
