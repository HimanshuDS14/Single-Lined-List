#include<stdio.h>

struct node
{
    int data;
    struct node*next;
};

struct node*start=NULL;

void insert_first()
{
    struct node*temp;
    int item;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not allocated");
    }
    printf("Enter a item : ");
    scanf("%d" , &item);
    temp->data = item;


    if(start==NULL)
    {
        temp->next = NULL;
        start = temp;
    }
    else
    {
        struct node*t;
        t = start;
        temp->next = t;
        start = temp;

    }
}

void display()
{
    struct node*temp;
    temp = start;
    if(temp==NULL)
    {
        printf("List is Empty");

    }
    else
    {
        printf("List is : ");
        while(temp!=NULL)
        {
            printf("%d " , temp->data);
            temp = temp->next;
        }
    }


}

void insert_last()
{

    struct node*temp;
    int item;
    temp =(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not Allocated");
    }
    else
    {
        printf("Enter a item : ");
        scanf("%d" , &item);
        temp->data = item;

    }
    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        struct node*t;
        t = start;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp->next = NULL;
    }
}

void insert_at_location()
{
    int item,loc,i;
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not Allocated");
    }
    else
    {

        printf("Enter a data : ");
        scanf("%d" , &item);
        temp->data = item;
        temp->next = NULL;

    }
    struct node*t;
    t = start;
    printf("Enter a location : ");
    scanf("%d" , &loc);
    for(i=0;i<loc;i++)
    {
        t = t->next;

        if(t==NULL)
        {
            printf("Node not available");
            return;
        }

    }
    temp->next = t->next;
    t->next  = temp;


}

void delete_first()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        temp = start;
        start = start->next;

    }


}


void delete_last()
{
    struct node*temp,*temp1;
    if(start==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);

    }
}

void delete_at_location()
{
    struct node*temp , *temp1;
    int loc,i;
    if(start==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        printf("Enter a location : " );
        scanf("%d" , &loc);

        temp = start;
        for(i=0;i<loc;i++)
        {
            temp1 = temp;
            temp = temp->next;

            if(temp==NULL)
            {
                printf("Can't delete");
                return;
            }
        }
        temp1->next = temp->next;
        free(temp);


    }
}



void search()
{
    struct node*temp;
    int item;
    int flag=0;
    if(start==NULL)
    {
        printf("list is Empty");
        return;
    }
    else
    {
        temp = start;
        printf("Enter a search item : ");
        scanf("%d" , &item);

        while(temp!=NULL)
        {
            if(temp->data == item)
            {
                flag=1;

            }
            temp = temp->next;
        }

        if(flag==1)
        {
            printf("Item found in list");
        }
        else
        {
            printf("Item not found in lits");
        }


    }

}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1 Insert first\n");
        printf("2 Insert Last\n");
        printf("3 Insert at Location\n");
        printf("4 Delete First\n");
        printf("5 Delete Last\n");
        printf("6 Delete at location\n");
        printf("7 Search\n");

        printf("8 Exit\n");
        printf("Enter a choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {
        case 1:
            insert_first();
            display();
            break;
        case 2:
            insert_last();
            display();
            break;
        case 3:
            insert_at_location();
            display();
            break;
        case 4:
            delete_first();
            display();
            break;
        case 5:
            delete_last();
            display();
            break;
        case 6:
            delete_at_location();
            display();
            break;
        case 7:
            search();
            break;

        case 8:
            exit(0);

        }
    }
}

