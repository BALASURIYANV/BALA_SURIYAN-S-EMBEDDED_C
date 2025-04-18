#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 12
#define COLS 3

typedef enum {
    AC,
    NON_AC,
    SLEEPER
} BusType;

typedef struct {
    char name[50];
    int age;
    char gender;
    int isBooked;
} Passenger;

Passenger buses[3][ROWS][COLS];

void Buses() {
    for (int b = 0; b < 3; b++)
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++) {
                buses[b][i][j].isBooked = 0;
            }
}

int display(BusType type) {
    printf("Seat layout for %s bus:\n", type == AC ? "AC" : (type == NON_AC ? "NON-AC" : "SLEEPER"));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (buses[type][i][j].isBooked)
                printf(" X ");
            else
                printf(" %2d ", i * COLS + j + 1);
        }
        printf("\n");
    }
}

int booking(BusType type) {
    int seatNum;
    printf("Enter seat number to book: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > ROWS * COLS) {
        printf("Invalid seat number.\n");
        return;
    }
    int i = (seatNum - 1) / COLS;
    int j = (seatNum - 1) % COLS;
    if (buses[type][i][j].isBooked) {
        printf("\nPlease select another seat, this one is already booked.\n");
        return;
    }

    Passenger *p = &buses[type][i][j];
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &p->gender);
    p->isBooked = 1;
    printf("\nSeat %d successfully booked!!!\n", seatNum);

    FILE *file = fopen("passengerdetails.txt", "a");
    if (file != NULL) {
        fprintf(file, "\nBus Type: %s, \nSeat: %d,\n Name: %s,\n Age: %d,\n Gender: %c\n",
            type == AC ? "AC" : (type == NON_AC ? "NON-AC" : "SLEEPER"),
            seatNum, p->name, p->age, p->gender);
        fclose(file);
    } else {
        printf("Error saving passenger details.\n");
    }
}

int cancelling(BusType type) {
    int seatNum;
    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > ROWS * COLS) {
        printf("\nInvalid seat number.\n");
        return;
    }
    int i = (seatNum - 1) / COLS;
    int j = (seatNum - 1) % COLS;
    if (!buses[type][i][j].isBooked) {
        printf("\nThis seat is not booked.\n");
        return;
    }
    buses[type][i][j].isBooked = 0;
    printf("\nSeat %d successfully cancelled.\n", seatNum);
}

int view(BusType type) {
    int seatNum;
    printf("Enter seat number to view details: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > ROWS * COLS) {
        printf("Invalid seat number.\n");
        return;
    }
    int i = (seatNum - 1) / COLS;
    int j = (seatNum - 1) % COLS;
    Passenger *p = &buses[type][i][j];
    if (!p->isBooked) {
        printf("\nSeat is not booked.\n");
        return;
    }
    printf("Passenger Details:\n");
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Gender: %c\n", p->gender);
}

int main() {
    int choice, busChoice;
    Buses();
    while (1) {
        printf("\n***WELCOME TO BS TICKET RESERVATIONS***");
        printf("\nSelect Bus Type: 0=AC  1=NON-AC  2=SLEEPER\nEnter choice for bus type: ");
        scanf("%d", &busChoice);
        if (busChoice < 0 || busChoice > 2) {
            printf("Invalid bus type.\n");
            continue;
        }
        printf("\n1. Display Seats\n2. Book Seat\n3. Cancel Seat\n4. View Passenger Details\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 5)
            break;
        BusType type = (BusType)busChoice;
        switch (choice) {
            case 1: display(type); break;
            case 2: booking(type); break;
            case 3: cancelling(type); break;
            case 4: view(type); break;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
