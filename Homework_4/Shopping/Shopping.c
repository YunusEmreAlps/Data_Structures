// linked list (queue)
// e-shopping

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// ----------
// structure
struct order
{
    char o_name[50]; // order name (Computer, Phone, Camera, ...)
    char o_owname[50]; // order owner name
    char o_owsurname[50]; // order owner surname

    int o_owage; // order owner age
    int o_shift; // order shift

    float o_price; // order price

    struct order *next;
};

// ----------
// global variables
struct order *head=NULL, *temp;
struct order *value;
struct order *k, *t; // loop variables

char t_name[50]; // temp name
char t_oname[50]; // temp owner name
char t_osurname[50]; // temp owner surname

float t_price=0; // temp price

int t_shift; // temp shift
int t_oage; // temp owner age

int counter=0; // total order number

// ----------
// signature of functions
int menu();

void ord_add();
void ord_sort();
void ord_list();
void ord_del();
void del_fun(); // delete function

// ----------
// main function
int main()
{
    int control=0; // boolean false
    while(1)
    {
        switch(menu())
        {
        case 1: // add
            system("cls"); // clear
            ord_add();
            ord_sort();
            ord_list();
            getch();
            break;
        case 2: // delete
            system("cls"); // clear
            ord_del();
            ord_sort();
            del_fun();
            ord_list();
            getch();
            break;
        case 3: // list
            system("cls"); // clear
            ord_list();
            getch();
            break;
        case 4: // quit
            system("cls");
            printf(" - Have a good day.\n");
            control=1; // boolean true
            break;
        }
        if(control==1)
            break;
    }

    getch();
    return 0;
}

// ----------
// functions
int menu()
{
    system("cls"); // clear
    printf(" ---------------\n");
    printf(" - 1.) Add \n");
    printf(" - 2.) Delete \n");
    printf(" - 3.) List \n");
    printf(" - 4.) Quit \n");
    printf(" ---------------\n");
    printf(" - Enter choice : ");

    float m_num=0; // menu number
    while(1)
    {
        scanf("%f",&m_num);
        if((m_num==1)||(m_num==2)||(m_num==3)||(m_num==4))
            break;
        printf(" - Try again : ");
        while(getchar()!='\n');
    }
    return m_num;
}

void ord_add() // this function add a order to the last element in list.
{
    printf(" ---------------\n");
    getchar();
    printf(" - Enter owner name : ");
    gets(t_oname);
    printf(" - Enter owner surname : ");
    gets(t_osurname);
    printf(" - Enter owner age : ");
    while(1)
    {
        scanf("%d",&t_oage);
        if (t_oage > 0)
            break;
        printf(" - Try again : ");
    }
    getchar();
    printf(" - Enter order name : ");
    gets(t_name);
    printf(" - Enter order price : ");
    while(1){
        scanf("%f",&t_price);
        if(t_price > 0)
            break;
        printf(" - Try Again : ");
    }
    printf(" ---------------\n");

    if(head==NULL) // list is empty
    {
        value=malloc(sizeof(struct order)); // dynamic memory allocation
        head=value;
        strcpy(head->o_owname, t_oname);
        strcpy(head->o_owsurname, t_osurname);
        head->o_owage=t_oage;
        strcpy(head->o_name, t_name);
        head->o_price=t_price;
        head->o_shift=0;
        head->next=NULL;
        counter++;
    }
    else // list is not empty
    {
        value=malloc(sizeof(struct order)); // dynamic memory allocation
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        (temp->next)=value;
        strcpy((temp->next)->o_owname, t_oname);
        strcpy((temp->next)->o_owsurname, t_osurname);
        (temp->next)->o_owage=t_oage;
        strcpy((temp->next)->o_name, t_name);
        (temp->next)->o_price=t_price;
        (temp->next)->o_shift=0;
        (temp->next)->next=NULL;
        counter++;
    }
}

void ord_sort()
{

    struct order *s_temp; // sort temp
    int i=0, j=0;

    temp=head;
    for(k=temp; k!=NULL; k=k->next)
    {
        s_temp=head;
        t_price=0;
        t_shift=0;
        t_oage=0;
        j=0;
        for(t=s_temp; t!=NULL; t=t->next) // sorting
        {
            if((j>i)&&(k->o_price < t->o_price))
            {
                strcpy(t_oname,k->o_owname); // swapping
                strcpy(t_osurname,k->o_owsurname); // swapping
                strcpy(t_name,k->o_name); // swapping
                t_price=k->o_price;
                t_oage=k->o_owage;
                t_shift=k->o_shift;


                strcpy(k->o_owname,t->o_owname); // swapping
                strcpy(k->o_owsurname,t->o_owsurname); // swapping
                strcpy(k->o_name,t->o_name);
                k->o_price=t->o_price;
                k->o_shift=t->o_shift;
                k->o_shift=k->o_shift;
                k->o_owage=t->o_owage;

                strcpy(t->o_owname,t_oname); // swapping
                strcpy(t->o_owsurname,t_osurname); // swapping
                strcpy(t->o_name,t_name);
                t->o_price=t_price;
                t->o_shift=t_shift;
                t->o_shift+=1;
                t->o_owage=t_oage;
            }
            j+=1;
        }
        i+=1;
    }
}

void ord_list()  // show all data
{
    printf("\n");
    temp=head;
    for(k=temp; k!=NULL ; k=k->next)
    {
        printf(" - %s \t %s \t %.3d \t %s \t %.4f \t %d \n",k->o_owname,k->o_owsurname,k->o_owage,k->o_name, k->o_price, k->o_shift);
    }
}

void ord_del() // delete
{
    int del_control=0; // boolean false
    if(head != NULL)
    {

        temp=head;
        for(k=temp; k!=NULL; k=k->next)
        {

            if(k->o_shift > 2) // minimum 3
            {
                k->o_price=-1; // assign -1
                del_control=1; // boolean true
                counter--;
            }
        }


        temp=head;
        if(del_control==0)
        {
            head=temp->next;
            counter--;
        }
    }
    else
    {
        printf(" - List is empty.\n");
    }
}

void del_fun() // delete function
{
    if(head != NULL) // list is not empty
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if((temp->next)->o_price ==-1)
                temp->next=NULL;
            else
                temp=temp->next;
        }

    }
}
