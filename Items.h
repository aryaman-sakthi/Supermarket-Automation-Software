#include<stdio.h>
#include "Bill.h"

struct Item
{
    int code;
    char name[15];
    char type[15];
    int quantity;
    int price;
    float weight;
    struct Item *next;
};
typedef struct Item item;

item *head=NULL;

int total_amount;

void insert_item(int code,char name[],char type[],int quantity,int price,float weight)
{
    item *temp = ( item *) malloc( sizeof(item));
                if(temp==NULL)
                {
                    printf("\nMemory allocation fails");
                    return;
                }

                temp->code=code;
                strcpy(temp->name,name);
                strcpy(temp->type,type);
                temp->quantity=quantity;
                temp->price=price;
                temp->weight=weight;
                temp->next=head;
                head=temp;
}

void display()
{
    if(head==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    item *temp=head;
    printf("\n<===================================================================================================>\n");
    printf("\t\t\t\t\tINVENTORY\n");
    printf("<===================================================================================================>\n\n");
    printf("\n");
    printf("Code\t\tName\t\t\tType\t\t\tQuantity\t\tPrice\t\tWeight\n");
    while(temp->next!=NULL)
    {

        printf("%d\t\t",temp->code);
        printf("%s\t\t\t",temp->name);
        printf("%s\t\t\t",temp->type);
        printf("%d\t\t",temp->quantity);
        printf("%d\t\t",temp->price);
        fflush(stdin);
        printf("%.2f\n",temp->weight);
        temp=temp->next;
    }
    fflush(stdin);
    printf("%d\t\t",temp->code);
    printf("%s\t\t\t",temp->name);
    printf("%s\t\t\t",temp->type);
    printf("%d\t\t",temp->quantity);
    printf("%d\t\t",temp->price);
    fflush(stdin);
    printf("%.2f\n",temp->weight);// last element to be printed
}
void item_details()
{
    int code,quantity,price;
    char name[15],type[15];
    float weight;

    printf("\nEnter Item Code: ");
    scanf("%d",&code);
    printf("\nEnter Item Name: ");
    scanf("%s",name);
    printf("\nEnter Item Type: ");
    scanf("%s",type);
    printf("\nEnter Total Quantity: ");
    scanf("%d",&quantity);
    printf("\nEnter Item Price: ");
    scanf("%d",&price);
    printf("\nEnter Item Weight: ");
    scanf("%f",&weight);

    insert_item(code,name,type,quantity,price,weight);
}

int scan_items(int date)
{
    int code;
    float scanweight,quanti;

        printf("Enter the Item Code: ");
        scanf("%d",&code);
        printf("\nEnter the Weight: ");
        scanf("%f",&scanweight);

        item *cur,*temp;
        cur=head;
        while (cur->code!=code)
        {
            cur = cur->next;
        }
        if (cur==NULL)
            printf("\nInvaid Code");
        else
        {
            int item_price;
            float quan;
            quan=scanweight/(cur->weight);
            item_price=(cur->price)*quan;

            printf("\n");
            printf("Code\t\tName\t\t\tType\t\t\tQuantity\t\tUnitPrice\t\tItem Price\n");
            fflush(stdin);
            printf("%d\t\t",cur->code);
            printf("%s\t\t\t",cur->name);
            printf("%s\t\t\t",cur->type);
            printf("%.0f\t\t",quan);
            printf("%d\t\t",cur->price);
            printf("%d\n",item_price);

            total_amount=total_amount + item_price;

            insert_record(cur->code,cur->name,cur->type,quan,cur->price,item_price,date);
        }
}

void dec_inventory()
{
    bill *temp2=head2;
    item *cur=head;
    int code,quan;

    while (temp2->next!=NULL)
    {
        code=temp2->code;
        quan=temp2->quantity;
        printf("%d,%d",code,quan);
        while (cur->code!=code)
        {
            cur = cur->next;
        }
        cur->quantity=cur->quantity-quan;
    }
}


void bill_generation()
{


    total_amount=0;

    int opt,date;
    printf("\nEnter the Date (YYYYMMDD) :");
    scanf("%d",&date);
    while(1)
    {


        printf("\n\n1.Scan New\t2.Generate Bill\t3.Exit\n");
        printf("Option:");
        scanf("%d",&opt);

        switch (opt){
            case 1:
                scan_items(date);
                break;
            case 2:
                display_bill();
                printf("\nTotal Amount=%d",total_amount);
                head2=NULL;
                return;
            case 3:
                return;

    }

    }
}

void restock_inventory()
{
    int code,newq;
    printf("\nEnter the Item code:");
    scanf("%d",&code);

    item *cur;
        cur=head;
        while (cur->code!=code)
        {
            cur = cur->next;
        }
        if (cur==NULL)
            printf("\nInvaid Code");
        else
        {
            printf("\nItem Details:\n");
            printf("\nCode\tName\t\tQuantity\n");
            printf("%d\t",cur->code);
            printf("%s\t\t",cur->name);
            printf("%d\n",cur->quantity);

            printf("\nEnter Updated Quantity:");
            scanf("%d",&newq);

            cur->quantity=newq;
            printf("\n\nInventory Updated Successfully...");
        }


}

void update_price()
{
    int code,newp;
    printf("\nEnter the Item code:");
    scanf("%d",&code);

    item *cur;
        cur=head;
        while (cur->code!=code)
        {
            cur = cur->next;
        }
        if (cur==NULL)
            printf("\nInvaid Code");
        else
        {
            printf("\nItem Details:\n");
            printf("\nCode\tName\t\tPrice\n");
            printf("%d\t",cur->code);
            printf("%s\t\t",cur->name);
            printf("%d\n",cur->price);

            printf("\nEnter Updated Price:");
            scanf("%d",&newp);

            cur->price=newp;
            printf("\n\nPrice Updated Successfully...");
        }


}

void display_inventory()
{
    int opt;
    char type[15];
    printf("\n\n1:All Inventory\t\t2:Specific Type\t\t3:Exit\nOption:");
    scanf("%d",&opt);
    while(1){
        switch (opt){
            case 1:
                display();
                return;
            case 2:
                printf("\n______________________________________________________________________________________\n");
                printf("\t\t\t\t\tItem Types\n\t\tGeneral       Stationary      Food\n\t\tBathroom      Medicines       Furniture\n");
                printf("\n______________________________________________________________________________________\n");
                printf("\nEnter Item Type: ");
                scanf("%s",type);
                display_type(type);
                break;
            case 3:
                return;
        }
    }
}

void display_type(char type[])
{
    int j=0;
    char a;
    if(head==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    item *temp=head;
    printf("\n<===================================================================================================>\n\t\t\t\t");
    while (type[j])
    {
        a = type[j];
        putchar(toupper(a));
        j++;
    }
    printf("\n<===================================================================================================>\n\n");
    printf("\n");


    printf("Code\t\tName\t\t\tType\t\t\tQuantity\t\tPrice\t\tWeight\n");

    while(temp->next!=NULL)
    {
        if (strcmp(temp->type,type)==0)
        {
            printf("%d\t\t",temp->code);
            printf("%s\t\t\t",temp->name);
            printf("%s\t\t\t",temp->type);
            printf("%d\t\t",temp->quantity);
            printf("%d\t\t",temp->price);
            fflush(stdin);
            printf("%.2f\n",temp->weight);
            temp=temp->next;
        }
    }
    if (strcmp(temp->type,type)==0)
    {

        fflush(stdin);
        printf("%d\t\t",temp->code);
        printf("%s\t\t\t",temp->name);
        printf("%s\t\t\t",temp->type);
        printf("%d\t\t",temp->quantity);
        printf("%d\t\t",temp->price);
        fflush(stdin);
        printf("%.2f\n",temp->weight);// last element to be printed
    }
}

void create_inventory()
{
    insert_item(012,"soap","general",150,75,25);
    insert_item(023,"pen","stationary",200,10,5.0);
    insert_item(030,"crosin","medicine",150,60,50.0);
    insert_item(044,"pencil","stationary",250,5,10.0);
}
