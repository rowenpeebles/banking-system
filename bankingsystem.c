#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating the struct 'user' adding variables
struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main()
{
    struct user usr, usrl;
    int opt;
    int choice;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    char cont = 'y';
    float amount;

    // Displaying user menu
    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    // Prompting user to select an operation
    printf("\n\nYour choice:\t");
    scanf("%d", &opt);

    // Conditional IF statement for operation 1
    if (opt == 1)
    {
        system("clear");
        printf("Account No:\t");
        scanf("%s", usr.ac);
        printf("Phone no:\t");
        scanf("%s", usr.phone);
        printf("New Password:\t");
        scanf("%s", usr.password);

        usr.balance = 0;

        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);

        if (&fwrite != 0)
        {
            printf("\n\nAccount Successfully Registered");
        }

        else
        {
            printf("\n\nSomething went wrong, please try again");
        }

        fclose(fp);
    }

    // Conditional IF statement for operation 2
    if (opt == 2)
    {
        system("clear");
        printf("\nPhone Number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");

        if (fp == NULL)
        {
            printf("\nAccount number not registered");
        }

        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
        }

        if (!strcmp(pword, usr.password))
        {
            printf("\n\tWelcome %s", usr.phone);

            // Conditional switch-case statement nested in a while loop
            while (cont == 'y')
            {
                system("clear");
                printf("\n\n1. Balance Inquiry");
                printf("\n2. Deposit Cash");
                printf("\n3. Cash Withdrawl");
                printf("\n4. Online Transfer");
                printf("\n5. Change Password");
                printf("\n\nYour Choice:\t");
                scanf("%d", &choice);

                switch (choice)
                {
                    // Conditional switch-case statement for operation 1
                    case 1:
                        printf("\nYour current balance is %.2f", usr.balance);
                        break;
                    
                    // Conditional switch-case statement for operation 2
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "r");
                        fwrite(&usr, sizeof(struct user), 1, fp);

                        if (&fwrite != NULL) printf("\nSuccessfully Deposited");
                        fclose(fp);
                        break;
                    
                    // Conditional switch-case statement for operation 3
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "r");
                        fwrite(&usr, sizeof(struct user), 1, fp);

                        if (&fwrite != NULL) printf("\nSuccessfully Withdrawn %.2f", amount);
                        fclose(fp);
                        break;
                    
                    // Conditional switch-case statement for operation 4
                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s", phone);
                        printf("\nPlease enter the amount you would like to transfer:\t");
                        scanf("%f", &amount); 

                        if (amount > usr.balance) printf("\nInsufficient balance");

                        else
                        {
                            strcpy(filename, phone);
                            fp = fopen(strcat(filename, ".dat"), "r");

                            if (fp == NULL)
                            {
                                printf("\nPhone number not registered");
                                return 0;
                            }

                            fread(&usrl, sizeof(struct user), 1, fp);
                            fclose(fp);
                            fp = fopen(filename, "w");
                            usrl.balance += amount;
                            fwrite(&usrl, sizeof(struct user), 1, fp);

                            fclose(fp);

                            if (&fwrite != NULL)
                            {
                                printf("\nYou have successfully transferred %.2f to %s", amount, phone); 
                                strcpy(filename, usr.phone);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.balance -= amount;
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);
                            }
                        }
                    
                    // Conditional switch-case statement for operation 5
                    case 5:
                        printf("\nPlease enter your new password:\t");
                        scanf("%s", pword);
                        fp = fopen(filename, "w");
                        strcpy(usr.password, pword);
                        fwrite(&usr, sizeof(struct user), 1, fp);

                        if (&fwrite != NULL)
                        {
                            printf("\nPassword successfully changed");
                        }
                    break;
                    
                    // Conditional switch-case statement for default operation
                    default:
                        printf("\nInvalid Option");
                    
                }

                printf("\n\nDo you want to continue with the transaction? [y/n]\t");
                scanf("%s", &cont);
            }
        }

        else
        {
            printf("\nInvalid password");
        }
    }
    
    return 0;
}