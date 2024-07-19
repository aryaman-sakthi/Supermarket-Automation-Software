#include<stdio.h>
#include "Items.h"


int login;
int Emp_login()
{
    char name[30],pass[20],ans='y';

    while (ans=='y')
    {

        printf("\nEnter Employee Username: ");
        scanf("%s",&name);
        printf("\nEnter the Password: ");
        scanf("%s",&pass);

        if (strcmp(name, "Arya") == 0 && strcmp(pass, "abc") == 0)
        {
            printf("\nSuccess\n\n");
            login = 1;
            return login;
        }
        return 0;
    }
}

int Manager_login()
{
    char name[30],pass[20],ans='y';

    while(ans=='y')
    {
        printf("\nEnter Manager Username: ");
        scanf("%s",&name);
        printf("\nEnter the Password: ");
        scanf("%s",&pass);

        if (strcmp(name, "Aryaman") == 0 && strcmp(pass, "aaa") == 0)
        {
            printf("\nSuccess\n\n");
            login = 1;
            return login;
        }
        return 0;
    }
}

void menu()
{
    char type[15];
    int option;
    printf("\nChoose Operation : \n1:Add new item \t\t\t2:Display Inventory \n3:Generate Bill \t\t4:Restock Inventory \n5:Update Price\t\t\t6:Sales Stats\n7:Exit SAS\n");
    printf("Option:");
    scanf("%d",&option);
    switch (option){
        case 1:
            printf("\n");
            item_details();
            break;
        case 2:
            printf("\n");
            display_inventory();
            break;
        case 3:
            printf("\n");
            bill_generation();
            break;

        case 4:
            restock_inventory();
            break;
        case 5:
            update_price();
            break;
        case 6:
            sales_statistics();
            break;
        case 7:
            return;
    }
}

int main()
{
    create_inventory();
    Emp_login();
    if (login==1)
        while (1==1)
            menu();

}


