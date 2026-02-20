#include <stdio.h>
#include <string.h>

int main(){

    int age;
    char phonenumber[11];
    char name[100], lastname[100];
    int length;

    printf("\n- - Welcome to the Khun Miso ATM Bank - -\n");
    printf("\n\t- - Registration Steps - -\n");

    printf("\nWhat your first name: ");
    scanf("%s", name);

    printf("What your lastname: ");
    scanf("%s", lastname);

    while (1){
        printf("Enter your age : ");
        scanf("%d",&age);
        if (age>=12){
            printf("\n\t* You have completed the information *\n");
            break;
        } else {
            printf("\n** Under 12 years of age cannot open an account **\n");
        }
    }

    while (1){
        printf("\nPlz Enter your phone number (10 digits) : ");
        scanf("%s",phonenumber);
        length = strlen(phonenumber);
        if (length == 10 ){
            printf("\n\t* You have completed the information *\n");
            break;
        }else {
            printf("\n** Mobile number must be 10 characters long **\n");
        }
    }

    /* LOGIN */
    char user[100], password[100];
    char login_user[100], login_password[100];

    printf("\n\t- -  Register - -\n");
    printf("\nUser : ");
    scanf("%s", user);
    printf("Password : ");
    scanf("%s", password);

    while (1){
        printf("\n\t- - - Login - - -\n");
        printf("\nUser : ");
        scanf("%s", login_user);
        printf("Password : ");
        scanf("%s", login_password);

        if (strcmp(user, login_user) == 0 &&
            strcmp(password, login_password) == 0){
            printf("\n\t** Login Succeed **\n");
            break;
        }else {
            printf("\n\t** Login Failed **\n");
        }
    }

    /* ATM SYSTEM */
    int choice;
    int sum = 0;
    int num[12];
    char *mo[12] = {"Jan","Feb","Mar","Apr","May","Jun",
                    "Jul","Aug","Sep","Oct","Nov","Dec"};
    int money, amount;
    int wm = 0, sm = 0;
    int i;

    /* Fund variables */
    char command;
    int fund_choice = 0;
    float depositAmount[3] = {0};
    float minimumDeposit[3] = {10000.0,7000.0,9000.0};
    float summoney[3] = {0};
    float amount2;
    int select;

    do{
        printf("\n\t- - - - Main Menu - - - -\n");
        printf("\n1. Personal Information\n");
        printf("2. Check the balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw money\n");
        printf("5. Check financial accounting\n");
        printf("6. Fund of bank\n");
        printf("7. Exit menu\n");
        printf("\nEnter you list: ");
        scanf("%d", &choice);

        switch (choice){

        case 1:
            printf("\nYour name is %s %s\n", name, lastname);
            printf("Your age is %d\n", age);
            printf("Your phone number is %s\n",phonenumber);
            break;

        case 2:
            printf("\nCurrent balance: %d Baht\n", sum);
            break;

        case 3:
            sm = 0;
            printf("\nEnter deposit for 12 months\n");
            for (i = 0; i < 12; i++){
                printf("%s: ", mo[i]);
                scanf("%d", &num[i]);
                sm += num[i];
            }
            sum += sm;
            printf("\n** Deposit Successful **\n");
            break;

        case 4:
            printf("\nCurrent balance: %d\n", sum);
            printf("Input money: ");
            scanf("%d", &money);

            if (money > sum){
                printf("Not enough balance!\n");
                break;
            }

            if (money > 20000 || money % 100 != 0){
                printf("Withdraw must be <=20000 and multiple of 100\n");
                break;
            }

            sum -= money;
            wm += money;

            printf("\n--- Banknotes ---\n");

            amount = money / 1000;
            if (amount > 0){
                printf("1000 : %d\n", amount);
                money %= 1000;
            }

            amount = money / 500;
            if (amount > 0){
                printf("500 : %d\n", amount);
                money %= 500;
            }

            amount = money / 100;
            if (amount > 0){
                printf("100 : %d\n", amount);
            }

            break;

        case 5:
            printf("\nDeposited: %d\n", sm);
            printf("Withdrawn: %d\n", wm);
            break;

        case 6:

            do{
                printf("\n\t- - Main Fund Options - -\n");
                printf("\n'f' Fund options\n'd' deposit\n'w' withdraw\n'c' cancel\n'q' quit\n");
                printf("Enter: ");
                scanf(" %c", &command);

                switch (command){

                case 'f':
                    printf("\n1. Health fund\n2. Education Fund\n3. Life insurance fund\n");
                    printf("Select fund: ");
                    scanf("%d", &fund_choice);
                    break;

                case 'd':
                    if (fund_choice < 1 || fund_choice > 3){
                        printf("Please select fund first using 'f'\n");
                        break;
                    }

                    printf("Enter deposit amount: ");
                    scanf("%f", &amount2);

                    if (amount2 >= minimumDeposit[fund_choice-1]){
                        summoney[fund_choice-1] += amount2;
                        printf("Deposit successful!\n");
                    }else{
                        printf("Minimum deposit is %.2f\n",
                               minimumDeposit[fund_choice-1]);
                    }
                    break;

                case 'w':
                    printf("Select fund (1-3): ");
                    scanf("%d",&select);

                    if (select < 1 || select > 3){
                        printf("Invalid fund\n");
                        break;
                    }

                    printf("Current fund balance: %.2f\n",
                           summoney[select-1]);
                    printf("Enter withdraw amount: ");
                    scanf("%f", &amount2);

                    if (amount2 > summoney[select-1]){
                        printf("Not enough money\n");
                    }else{
                        summoney[select-1] -= amount2;
                        printf("Withdraw successful\n");
                    }
                    break;

                case 'c':
                    printf("Select fund (1-3) to cancel: ");
                    scanf("%d",&select);
                    if (select >=1 && select <=3){
                        summoney[select-1] = 0;
                        printf("Fund cancelled\n");
                    }
                    break;

                case 'q':
                    printf("Back to main menu...\n");
                    break;

                default:
                    printf("Invalid command\n");
                }

            }while (command != 'q');

            break;

        case 7:
            printf("\n** You have logged out **\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    }while (choice != 7);

    return 0;
}
