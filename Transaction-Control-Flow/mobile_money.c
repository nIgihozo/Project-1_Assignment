#include <stdio.h>

 int main(void)
 {
    float balance = 0.0;
    float amount;
    int choice;
    int depositCount = 0;
    int withdrawCount = 0;

    while (1)

    {
        /*Choices to choose to continue with*/
        printf("===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            /*Clear input buffer*/  
            while (getchar() != '\n')
                    ;   
            continue;
        }

        switch (choice)

        /*Case scenerios*/
        {
            /*Deposit Case*/
        case 1: 
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount <= 0)
                {
                    printf("Invalid amount. Please enter a positive value.\n");
                    continue;
                }
                    balance += amount;
                    depositCount++;
                    printf("Deposited successfully! New balance: %.0f RWF\n", balance);
                    break;

            /*Withdraw Case*/
        case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount <= 0)
                {
                    printf("Invalid amount. Please enter a positive value.\n");
                    continue;
                }
                else if (amount > balance)
                {
                    printf("Transaction Rejected: Insufficient balance.\nCurrent balance: %.0f RWF\n", balance);
                    continue;
                }
                else
                {
                    balance -= amount;
                    withdrawCount++;
                    printf("Withdrawal succeeded! New balance: %.0f RWF\n", balance);
                    break;
                }

            /*Check Balance Case*/
        case 3:
              printf("Current balance: %.0f RWF\n", balance);
              break;
        
        /*Transaction Summary Case*/
        case 4:
                printf("Transaction Summary:\n");
                printf("Deposits: %d\n", depositCount);
                printf("Withdrawals: %d\n", withdrawCount);
                break;

            /*Exit Case*/
        case 5:
                printf("System Terminated.\n");
                return (0);

            /*Default Case*/
        default:
                 printf("Invalid Choice. Please choose from the available options!\n");
                 continue;
    }
}
  
  return (0);


 }