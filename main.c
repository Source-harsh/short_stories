#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start_write() {
    char name[100];
    printf("Enter the title of the story: ");
    fgets(name, sizeof(name), stdin);

    // Remove the trailing newline character
    name[strcspn(name, "\n")] = '\0';

    // Allocate memory for the story title (not strictly necessary here)
    char *temp = malloc(strlen(name) + 1);
    strcpy(temp, name);
    free(temp);

    // Open the file for appending
    FILE *file1 = fopen(name, "a");
    if (file1 == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    printf("Enter the story (type 'exit' to finish):\n");

    // Write story to the file
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "exit", 4) == 0) {
            break;
        }
        fputs(line, file1);
    }
    fclose(file1);
}

void story_read(char *filename) {
    // Correctly open the file for reading
    FILE *file1 = fopen(filename, "r");
    if (file1 == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    printf("Story content:\n");
    while (fgets(line, sizeof(line), file1)) {
        printf("%s", line);
    }
    fclose(file1);
}

int main() {
    int choice;
    printf("Enter the choice:\n1 : To write and upload a story\n2 : To read a story\n");
    scanf(" %d", &choice);
    getchar(); // Clear the input buffer

    if (choice == 1) {
        start_write();
    } else if (choice == 2) {
        char name[100];
        printf("Enter the name of the story: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
        story_read(name);
    } else {
        printf("Choose the correct option.\n");
    }

    return 0;
}
