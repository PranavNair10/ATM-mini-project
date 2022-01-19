#include <stdio.h>
#include <windows.h>
#include <time.h>
int main(){
    int pin=1234,option,enteredpin,count=0,amt=1;
    float balance=5000;
    int continuetransac=1;
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t                     %s",ctime(&now));
    printf("\n\t\t\t===============================*Welcome to ICICI ATM*===============================");
    while(pin!=enteredpin){
        printf("\n Please enter your pin");
        scanf("%d",&enteredpin);
        if(enteredpin!=pin){
            Beep(610,500);
            printf("Invalid Pin!!!");
        }
        count++;
        if(count==3 && pin!=enteredpin){
            exit(0);
        }
    }

       while(continuetransac!=0){
            printf("\n\t\t\t\t=================*Available Transactions*=================");
        printf("\n\t\t1.Withdrawal");
        printf("\n\t\t2.Deposit");
        printf("\n\t\t3.Check Balance");    
        printf("\n\n\tPlease select the option:");
        scanf("%d",&option);
        switch(option){
            case 1:
            while(amt%500!=0){
                printf("\n\t\tEnter the amount:");
                scanf("%d",&amt);
                if(amt%500!=0){
                    printf("\n\t The amount should be a multiple of 500!");
                }
            }
            if(balance<amt){
                printf("\n\t Insufficient Balance!");
                amt=1;
                break;
            }
            else{
                balance-=amt;
                printf("\n\t\tYou have withdrawn Rs.%d. Your new balance is %.2f",amt,balance);
                printf("\n\t\t\t=================*Thank You for banking with ICICI*=================");
                amt=1;
                break;
            }
            case 2:
            printf("\n\t\t Please enter your amount");
            scanf("%d",&amt);
            balance+=amt;
            printf("\n\t\tYou have deposited Rs.%d. Your new balance is %.2f",amt,balance);
            printf("\n\t\t\t=================*Thank You for banking with ICICI!!!*=================");
            amt=1;
            break;
            case 3:
            printf("\n\t\tYour Balance is Rs.%.2f",balance);
            break;
            default:
            Beep(610,500);
            printf("\n\t\tInvalid Option!!!");
        }
        printf("\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No]");
        scanf("%d",&continuetransac);
       }
    return 0;
}