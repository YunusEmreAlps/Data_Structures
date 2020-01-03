// linked list (single way)

// 17010011005 Yunus Emre Alpu
// Reverse Linked list with recursive function

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// IMPORTANT -> if number is 0 loop is end.
// ----------
// structure
struct num_list
{
    float number;
    struct num_list *next;
};

// ----------
// global variables
struct num_list *head=NULL, *temp;
struct num_list *value;

int counter=0;

// ----------
// signature of functions
int menu();
void list();
void adding();
void rev_list(); // reverse list

// ----------
// main function
int main()
{
    int control=0; // boolean false

    while(1)
    {
        switch(menu())
        {
        case 1: // add a number
            add();
            break;
        case 2: // list
            list();
            getch();
            break;
        case 3: // reverse list
            rev_list();
            list();
            getch();
            break;
        case 4: // exit
            control=1;
            break;
        }

        if(control==1) // exit
        {
            break;
        }
    }

    getch();
    return 0;
}

// ----------
// menu function
int menu()
{
    system("cls");
    printf(" - ---------------\n");
    printf(" - 1.) Add a number \n");
    printf(" - 2.) List \n");
    printf(" - 3.) Reverse list \n");
    printf(" - 4.) Exit \n");
    printf(" - ---------------\n");
    printf(" - Enter choice : ");

    float mn_pro=0; // menu process number

    while(1)
    {
        scanf("%f",&mn_pro);

        if((mn_pro==1)||(mn_pro==2)||(mn_pro==3)||(mn_pro==4))
        {
            break;
        }
        printf(" - Try again : ");
        while(getchar() != '\n');
    }

    printf("\n");

    return mn_pro;
}

// ----------
// add function
void add()
{
    value=malloc(sizeof(struct num_list));

    float tmp_num;
    printf(" - Enter number : ");
    scanf("%f",&tmp_num);
    if(tmp_num != 0)
    {
        if(head==NULL)
        {
            head=value;
            head->number=tmp_num;
            head->next=NULL;
            counter++;
        }

        else
        {
            temp=head;
            while(temp->next!= NULL)
            {
                temp=temp->next;
            }

            (temp->next)=value;
            (temp->next)->number=tmp_num;
            (temp->next)->next=NULL;
            counter++;
        }

       list();
       getch();
       system("cls");
       add();
    }
}

// ----------
// list function
void list()
{
    int i=0;

    temp=head;
    for(i=0; i<counter ; i++)
    {
        printf("  %.3f \\",temp->number);
        temp=temp->next;
    }
}

// ----------
// reverse list function
void rev_list()
{
    struct num_list *prev=NULL, *next=NULL;

    temp=head;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next; // NULL
    }

    head=prev;
}
