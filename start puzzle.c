#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_MOVES 120

void showUsers() {
    FILE *fp;
    char data[100];

    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("No existing users found.\n");
        return;
    }

    printf("\nExisting Users:\n");
    while (fgets(data, sizeof(data), fp)) {
        printf("- %s", data);
    }
    fclose(fp);
}

void saveUser(int id, char username[]) {
    FILE *fp = fopen("users.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "ID: %d  Name: %s\n", id, username);
        fclose(fp);
    }
}

int adminLogin() {
    char username[20], password[20];

    printf("\n--- ADMIN MODE ON ---\n");
    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if (strcmp(username, "sushantkr") == 0 && strcmp(password, "kalimata") == 0) {
        printf("Admin login successful!\n");
        return 1;
    } else {
        printf("Wrong username or password!\n");
        return 0;
    }
}

void deleteUserByID() {
    FILE *fp, *temp;
    char line[100];
    int id, delID;
    int found = 0;

    fp = fopen("users.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter User ID to delete: ");
    scanf("%d", &delID);

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "ID: %d", &id);

        if (id != delID) {
            fputs(line, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("User not found!\n");
    }
}

int checkWin(int puzzle[]) {
    int i;
    for (i = 0; i < 15; i++) {
        if (puzzle[i] != i + 1)
            return 0;
    }
    return 1;
}

void display(int puzzle[], int moves, int id, char username[]) {
    int i;
    system("cls");

    printf("====== PUZZLE GAME ======\n");
    printf("Player ID : %d\n", id);
    printf("Player Name : %s\n", username);
    printf("Moves Left: %d\n\n", MAX_MOVES - moves);

    for (i = 0; i < 16; i++) {
        printf("| ");
        if (puzzle[i] == 0)
            printf("  ");
        else
            printf("%2d", puzzle[i]);
        printf(" ");

        if ((i + 1) % 4 == 0) {
            printf("|\n");
            printf("-------------------------\n");
        }
    }
    printf("\nUse Arrow Keys (Q to Quit)\n");
}

int main() {
    char username[50];
    int userid;
    int puzzle[16] = {1,3,4,5,6,2,7,0,8,9,10,11,12,13,14,15};
    int poszero, moves = 0;
    char ch;
    int i;

    printf("====== PUZZLE GAME ======\n");
    showUsers();

    printf("\nPress D to delete a user OR any other key to continue: ");
    char option = getch();

    if (option == 'd' || option == 'D') {
        if (adminLogin()) {
            deleteUserByID();
        }
        printf("\nPress any key to continue...");
        getch();
    }

    printf("\nEnter your ID: ");
    scanf("%d", &userid);

    printf("Enter your name: ");
    scanf("%s", username);

    saveUser(userid, username);

    printf("\nWelcome %s (ID: %d)! Press any key to start...", username, userid);
    getch();

    while (1) {
        display(puzzle, moves, userid, username);

        if (checkWin(puzzle)) {
            printf("\n?? YOU WIN %s! ??\n", username);
            break;
        }

        if (moves >= MAX_MOVES) {
            printf("\nGAME OVER!\n");
            break;
        }

        ch = getch();
        if (ch == 0 || ch == 224)
            ch = getch();

        for (i = 0; i < 16; i++)
            if (puzzle[i] == 0)
                poszero = i;

        if (ch == 72 && poszero >= 4) {
            puzzle[poszero] = puzzle[poszero - 4];
            puzzle[poszero - 4] = 0;
            moves++;
        } else if (ch == 80 && poszero < 12) {
            puzzle[poszero] = puzzle[poszero + 4];
            puzzle[poszero + 4] = 0;
            moves++;
        } else if (ch == 75 && poszero % 4 != 0) {
            puzzle[poszero] = puzzle[poszero - 1];
            puzzle[poszero - 1] = 0;
            moves++;
        } else if (ch == 77 && poszero % 4 != 3) {
            puzzle[poszero] = puzzle[poszero + 1];
            puzzle[poszero + 1] = 0;
            moves++;
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }

	printf("\nThank you for playing PUZZLE GAME\n");
	return 0;
}

