#include<stdio.h>

int main(){

    int choice;
    int pin = 1385;
    int balance = 1000;

    while (1){

        int enterPin;
        

        printf("\nEnter PIN: ");
        scanf("%d", &enterPin);

        if (enterPin != pin){
            printf("Incorrect PIN\n");
            continue;
        }

        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Change PIN");
        printf("\n5. Exit\n");

        scanf("%d", &choice);

        if (choice == 1){
            printf("Your Balance = %d\n", balance);
        }

        if (choice == 2){
            int amount;

            printf("Enter amount to deposit: ");
            scanf("%d", &amount);

            if (amount > 0){
                balance = balance + amount;
                printf("Money deposited successfully.\n");
                printf("Updated Balance = %d\n", balance);
            }
            else{
                printf("Invalid amount\n");
            }
        }

        if (choice == 3){
            int amount;

            printf("Enter the withdrawal amount: ");
            scanf("%d", &amount);

            if (amount > balance){
                printf("Insufficient balance\n");
            }
            else if (amount > 0){
                balance = balance - amount;
                printf("Please collect your cash.\n");
                printf("Remaining Balance = %d\n", balance);
            }
            else{
                printf("Invalid amount\n");
            }
        }

        if (choice == 4){
            int oldPin, newPin;

            printf("Enter the old PIN: ");
            scanf("%d", &oldPin);

            if (oldPin == pin){
                printf("Enter the new PIN: ");
                scanf("%d", &newPin);

                pin = newPin;
                printf("PIN changed successfully.\n");
            }
            else{
                printf("Wrong old PIN\n");
            }
        }

        if (choice == 5){
            printf("Thank you for using ATM\n");
            break;
        }
    }

    return 0;
}
