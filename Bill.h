#include<stdio.h>


struct Bill
{
    int code;
    char name[15];
    char type[15];
    float quantity;
    int unit_price;
    int item_price;
    int date;
    struct Item *next;
};
typedef struct Bill bill;

bill *head2=NULL;
bill *point=NULL;

int billno=12424;

void insert_record(int code,char name[],char type[],float quantity,int unit_price, int item_price,int date)
{
    bill *temp = ( bill *) malloc( sizeof(bill));
                if(temp==NULL)
                {
                    printf("\nMemory allocation fails");
                    return;
                }

                temp->code=code;
                strcpy(temp->name,name);
                strcpy(temp->type,type);
                fflush(stdin);
                temp->quantity=quantity;
                temp->unit_price=unit_price;
                temp->item_price=item_price;
                temp->date=date;
                temp->next=head2;
                head2=temp;
                point=temp;
}

void display_bill()
{
    if(head2==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    bill *temp=head2;
    printf("\n=============================================================================================>\n");
    printf("\t\t\t\t\tBILL NO:%d\n",billno);
    printf("\n=============================================================================================> \n\n");
    billno++;
    printf("Code\t\tName\t\t\tType\t\t\tQuantity\t\tUnitPrice\t\tItem Price\n");

    while(temp->next!=NULL)
    {

        printf("%d\t\t",temp->code);
        printf("%s\t\t\t",temp->name);
        printf("%s\t\t\t",temp->type);
        fflush(stdin);
        printf("%.0f\t\t",temp->quantity);
        printf("%d\t\t",temp->unit_price);
        printf("%d\n",temp->item_price);
        temp=temp->next;
    }
    printf("%d\t\t",temp->code);
    printf("%s\t\t\t",temp->name);
    printf("%s\t\t\t",temp->type);
    fflush(stdin);
    printf("%.0f\t\t",temp->quantity);
    printf("%d\t\t",temp->unit_price);
    printf("%d\n",temp->item_price);// last element to be printed
    printf("Date:%d\n",temp->date);
}

int day_stat(int dat)
{
    int tsale=0,profit=0;
    bill *temp=point;

    while(temp->next!=NULL)
    {
        if (temp->date=dat)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
        temp=temp->next;
    }
    if (temp->date=dat)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
    printf("\nTotal Sales\t\tProfit\n");
    printf("%d\t\t%d",tsale,profit);
}


int item_stat(int c)
{
    int tsale=0,profit=0;
    bill *temp=point;

    while(temp->next!=NULL)
    {
        if (temp->code=c)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
        temp=temp->next;
    }
    if (temp->code=c)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
    printf("\nTotal Sales\t\tProfit\n");
    printf("%d\t\t%d",tsale,profit);
}

void type_stat(char type[])
{
    int tsale=0,profit=0;
    bill *temp=point;

    while(temp->next!=NULL)
    {
        if (strcmp(temp->type,type)==0)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
        temp=temp->next;
    }
    if (strcmp(temp->type,type)==0)
        {
            tsale=tsale+temp->item_price;
            profit=profit+(temp->item_price*0.75);
        }
    printf("\nTotal Sales\t\tProfit\n");
    printf("%d\t\t%d",tsale,profit);
}

void sales_statistics()
{
    printf("\n<====================================================================================================>\n");
    printf("\t\t\t\t\tSales Statistics\n");
    printf("\n<====================================================================================================>\n");

    while(1)
    {
        int opt,date,start,last,code;
        char typ[15];
        printf("\n1:Day Statistic\t\t 2:Time Period Statistics\n 3:Item Statistics\t\t 4:Type Statistics\nOption:");
        scanf("%d",&opt);

        switch (opt){
            case 1:
                printf("\nEnter the Date(yyyymmdd): ");
                scanf("%d",&date);
                day_stat(date);
                break;
            case 2:
                printf("\nEnter the Start Date: ");
                scanf("%d",start);
                printf("\nEnter the End Date: ");
                scanf("%d",last);
                for (int i=start;i<=last;i++)
                    day_stat(i);
                break;
            case 3:
                printf("\nEnter the Item Code: ");
                scanf("%d",&code);
                item_stat(code);
                break;
            case 4:
                printf("\nEnter the Item Type: ");
                scanf("%c",typ);
                item_stat(typ);
                break;
        }

    }
}
