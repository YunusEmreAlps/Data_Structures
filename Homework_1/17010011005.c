// linked list
// Phone Guide

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// ----------
// structure
struct contact
{
    char name[30];
    char surname[30];
    long long phone_num; // phone number

    struct contact *next;
};

// ----------
// global variable
struct contact *head=NULL, *temp, *dlkey; // !important!
struct contact *so_temp, so_val; // sort temp
struct contact *k, *m; // sort temp
// head is first box

char nm[30], srnm[30];
long long phnum,contnum=0; // phone number
int i=0, j=0, lc=1; // lc : length counter -> number
int counter = 0;

// ----------
// signature of functions
int menu();

void add_c(); // add contact
void srch_c(); // search contact
int  src_fun(int number, char A[30],char B[30],long long number2); // search functions
void updt_c(); // update contact information
void delt_c(); // delete contact
void sort_c(); // sort all contact information


// ----------
// main
int main()
{
    int control=0; // boolean -> false
    while(1)
    {
        switch(menu())
        {
        case 1: // Add
            system("cls"); // clear
            add_c();
            break;
        case 2: // Search
            system("cls"); // clear
            srch_c();
            break;
        case 3: // Update
            system("cls"); // clear
            updt_c();
            break;
        case 4: // Delete
            system("cls"); // clear
            delt_c();
            break;
        case 5: // Sort
            system("cls"); // clear
            sort_c();
            break;
        case 6: // Quit
            control=1; // true
            break;
        }

        if(control == 1)
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
    printf(" - 1. Add \n");
    printf(" - 2. Search \n");
    printf(" - 3. Update \n");
    printf(" - 4. Delete \n");
    printf(" - 5. Sort \n");
    printf(" - 6. Quit \n");
    printf(" ---------------\n");

    float pnum=0; // pnum : process number
    printf(" - Enter choice : ");

    while(1)
    {
        scanf("%f",&pnum);

        if((pnum == 1)||(pnum == 2)||(pnum == 3)||(pnum == 4)||(pnum == 5)||(pnum == 6))
            break;
        printf(" - Try again : ");
        while(getchar() != '\n'); // alphabetic control
    }

    return pnum; // integer
}

void add_c()
{
    system("cls"); // clear
    printf(" ---------------\n");
    printf(" - Process name : Add Contact \n");
    printf(" ---------------\n");

    char nm[30], srnm[30];
    long long res=0;
    int same_num = 0;

    struct contact *value;
    value = malloc(sizeof(struct contact)); // dynamic memory allocation

    // information
    getchar();
    printf(" - Name : ");
    gets(nm);
    printf(" - Surname : ");
    gets(srnm);
    printf(" - Phone number : ");
    while(1)
    {
        // phone number length  05536988910 == 5536988910
        scanf("%lld",&phnum);
        lc = 1;
        res = phnum;
        while(res > 9)
        {
            res = res / 10;
            lc++;
        }
        if(lc == 10)
        {
            same_num = src_fun(4,'A','B',phnum);
            if(same_num == 0){
                 printf(" - Process completed.\n");
                 break;
            }

            printf(" - You have this contact number. \n");
            getch();
            return;
        }
        printf(" - Try Again : ");
    }


    if(head == NULL) // empty
    {
        head = value;
        strcpy(head->name, nm);
        strcpy(head->surname, srnm);
        head->phone_num = phnum;
        head -> next = NULL;
    }

    else // head is not NULL
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = value;
        strcpy((temp->next)->name, nm);
        strcpy((temp->next)->surname, srnm);
        (temp->next)->phone_num = phnum;
        (temp->next)->next = NULL;
    }

    counter++; // total contact number
    getch();
}

// ----------
void srch_c()
{
    system("cls"); // clear
    printf(" ---------------\n");
    printf(" - Process name : Search Contact \n");
    printf(" ---------------\n");

    float src_pnum = 0; // process number
    int c_counter = 0; // c counter

    while(1)
    {
        printf(" ---------------\n");
        printf(" - 1. Name \n");
        printf(" - 2. Surname \n");
        printf(" - 3. Name and Surname \n");
        printf(" - 4. Phone number \n");
        printf(" - 5. Quit \n");
        printf(" ---------------\n");
        printf(" - Enter choice : ");

        while(1)
        {
            scanf("%f",&(src_pnum));

            if((src_pnum == 1)||(src_pnum == 2)||(src_pnum == 3)||(src_pnum == 4)||(src_pnum == 5))
                break;
            printf(" - Try again : ");
            while(getchar() != '\n'); // alphabetic control
        }

        if(src_pnum == 5)
            break;

        switch((int)src_pnum)
        {
        case 1:
            system("cls");
            getchar();
            printf(" - Name : ");
            gets(nm);
            src_fun(1,nm,'A',0);
            getch();
            break;
        case 2:
            system("cls");
            getchar();
            printf(" - Surname : ");
            gets(srnm);
            src_fun(2,srnm,'B',0);
            getch();
            break;
        case 3:
            system("cls");
            getchar();
            printf(" - Name : ");
            gets(nm);
            printf(" - Surname : ");
            gets(srnm);
            getch();
            src_fun(3,nm,srnm,0);
            break;
        case 4:
            system("cls");
            printf(" - Phone number : ");
            scanf("%lld",&phnum);
            src_fun(4,'A','B',phnum);
            getch();
            break;
        }
    }

}

// ----------
void updt_c()
{
    system("cls");
    printf(" ---------------\n");
    printf(" - Process name : Update Information \n");
    printf(" ---------------\n");

    float upd_pnum, upd_pnum2;

    while(1)
    {
        printf(" ---------------\n");
        printf(" - 1. Phone number \n");
        printf(" - 2. Quit \n");
        printf(" ---------------\n");
        printf(" - Enter choice : ");

        while(1)
        {
            scanf("%f",&(upd_pnum));

            if((upd_pnum == 1)||(upd_pnum == 2))
                break;
            printf(" - Try again : ");
            while(getchar() != '\n'); // alphabetic control
        }

        if(upd_pnum == 2)
            break;

        switch((int)upd_pnum)
        {

        case 1:
            system("cls");
            printf(" -  Phone number : ");
            scanf("%lld",&phnum);
            int result = src_fun(4,'A','B',phnum);
            if(result !=0)
            {
                while(1)
                {
                    printf(" ---------------\n");
                    printf(" - 1. Update Name \n");
                    printf(" - 2. Update Surname \n");
                    printf(" - 3. Update Phone number \n");
                    printf(" - 4. Quit \n");
                    printf(" ---------------\n");
                    printf(" - Enter choice : ");
                    while(1)
                    {
                        scanf("%f",&(upd_pnum2));
                        if((upd_pnum2 == 1)||(upd_pnum2 == 2)||(upd_pnum2 == 3)||(upd_pnum2 == 4))
                            break;
                        printf(" - Try again :");
                        while(getchar() != '\n'); // alphabetic control
                    }

                    if(upd_pnum2 == 4)
                        break;

                    switch((int)upd_pnum2)
                    {
                    case 1:
                        system("cls");
                        getchar();
                        printf(" - Name : ");
                        gets(nm);
                        temp = head;
                        for(i=0 ; i<counter ; i++)
                        {
                            if(phnum == (temp->phone_num))
                            {
                                if(strlen(nm) > 0)
                                {
                                    strcpy(temp->name,nm);
                                    printf(" - Process completed \n");
                                }

                            }
                            temp = temp->next;
                        }
                        getch();
                        break;
                    case 2:
                        system("cls");
                        getchar();
                        printf(" - Surname : ");
                        gets(srnm);
                        temp = head;
                        for(i=0 ; i<counter ; i++)
                        {
                            if(phnum == (temp->phone_num))
                            {
                                if(strlen(srnm) > 0)
                                {
                                    strcpy(temp->surname,srnm);
                                    printf(" - Process completed \n");
                                }

                            }
                            temp = temp->next;
                        }
                        getch();
                        break;
                    case 3:
                        system("cls");
                        printf(" - Phone number : ");
                        int res=0, same_num=0;
                        while(1)
                        {
                            // phone number length  05536988910 == 5536988910
                            scanf("%lld",&contnum);
                            lc = 1;
                            res = phnum;
                            while(res > 9)
                            {
                                res = res / 10;
                                lc++;
                            }
                            if(lc == 10)
                            {
                                same_num = src_fun(4,'A','B',phnum);
                                if(same_num == 0) // print not found
                                    break;
                                printf(" - You have this contact number. \n");
                                menu();
                            }
                            printf(" - Try Again : ");
                        }

                        temp = head;
                        for(i=0 ; i<counter ; i++)
                        {
                            if(phnum == (temp->phone_num))
                            {
                                temp->phone_num=contnum;
                                printf(" - Process completed \n");
                            }
                            temp = temp->next;
                        }
                        getch();
                        break;

                    }
                }
            }

        }

    }
    getch();
}

// ----------
void delt_c()
{
    system("cls");
    printf(" ---------------\n");
    printf(" - Process name : Delete Contact \n");
    printf(" ---------------\n");

    int result = 0;
    int del_count = 0;
    float del_pnum = 0;
    getchar();
    printf(" - Surname : ");
    gets(srnm);
    result = src_fun(2,srnm,'B',0);
    if(result > 0)
    {
        while(1)
        {
            temp = head;
            for(i=0; i<counter ; i++)
            {
                if(strcmp(srnm,temp->surname) == 0)
                {
                    del_pnum = 0;
                    printf(" ---------------\n");
                    printf(" - %s\t%s\t%d \n",temp->name, temp->surname, temp->phone_num);
                    printf(" ---------------\n");
                    printf(" - This contact will delete ? \n");
                    printf(" 1.) Yes \n");
                    printf(" 2.) No \n");
                    printf(" ---------------\n");
                    printf(" - Enter choice : ");

                    while(1)
                    {
                        scanf("%f",&del_pnum);
                        if((del_pnum == 1)||(del_pnum == 2))
                        {
                            break;
                        }
                        printf(" - Try again : ");
                    }


                    if(del_pnum == 1)  // Yes
                    {
                        // first item
                        temp = head;
                        if(del_count == 0) // head
                        {
                            head = temp->next;
                        }

                        // middle item
                        if((del_count != 0)&&(del_count != (counter-1)))
                        {
                            temp = head;
                            for(i=0; i<counter; i++)
                            {
                                if(i == (del_count-1))
                                {
                                    temp->next = (temp->next)->next;
                                }
                                if(temp->next != NULL)
                                {
                                    temp = temp->next;
                                }
                            }

                        }

                        // last item
                        if(del_count == (counter-1))
                        {
                            temp=head;
                            for(i=0 ; i<(counter-1); i++)
                            {
                                if((counter-1) == (i))
                                {
                                    temp->next = NULL;
                                }
                                temp = temp->next;
                            }
                        }

                    }
                }
                temp = temp->next;
                del_count++;
            }
            printf(" ---------------\n");
            printf(" - Do you want to quit : ");
            scanf("%f",&del_pnum);
            if(del_pnum == 2)
                break;

        }

    }
    counter--;
    getch();
}

void sort_c()
{
    system("cls");
    printf(" ---------------\n");
    printf(" - Process name : Sort Contacts \n");
    printf(" ---------------\n");
    printf(" - 1. Name (A-Z)\n");
    printf(" - 2. Phone Number \n");
    printf(" ---------------\n");
    printf(" -Enter choice : ");
    float sort_pnum = 0;
    while(1)
    {
        scanf("%f",&sort_pnum);
        if((sort_pnum == 1)||(sort_pnum == 2))
        {
            break;
        }
        printf(" - Try Again : ");
    }
    if(head !=NULL && sort_pnum == 1)  // A-Z
    {

        int sort_res = 0;
        for(k=head; k!=NULL; k=k->next)
        {
            for(m=k->next; m!= NULL ; m= m->next)
            {
                sort_res = strcmp(k->name,m->name);

                if(sort_res > 0)
                {
                    strcpy(so_val.name,k->name);
                    strcpy(so_val.surname,k->surname);
                    so_val.phone_num = k->phone_num;

                    strcpy(k->name,m->name);
                    strcpy(k->surname,m->surname);
                    k->phone_num = m->phone_num;

                    strcpy(m->name,so_val.name);
                    strcpy(m->surname,so_val.surname);
                    m->phone_num = so_val.phone_num;

                }

            }
        }


        temp= head;
        for(i=0; i<counter; i++)
        {
            printf(" - %s\t%s\t%lld \n",temp->name,temp->surname,temp->phone_num);
            temp=temp->next;
        }
    }

    else if(head !=NULL  && sort_pnum == 2)
    {

        temp = head;
        for(k=head; k!= NULL; k=k->next)
        {
            for(m=k->next; m!=NULL ; m=m->next)
            {

                if(k->phone_num > m->phone_num)
                {

                    strcpy(so_val.name,k->name);
                    strcpy(so_val.surname,k->surname);
                    so_val.phone_num = k->phone_num;

                    strcpy(k->name,m->name);
                    strcpy(k->surname,m->surname);
                    k->phone_num = m->phone_num;

                    strcpy(m->name,so_val.name);
                    strcpy(m->surname,so_val.surname);
                    m->phone_num = so_val.phone_num;
                }
            }
        }

        temp= head;
        system("cls");
        printf(" ---------------\n");
        for(i=0; i<counter; i++)
        {
            printf(" - %s\t%s\t%lld \n",temp->name,temp->surname,temp->phone_num);
            temp=temp->next;
        }

    }

    getch();
}

int src_fun(int number,char A[30],char B[30],long long number2)
{
    int c_counter = 0;
    temp = head;

    if (number == 1)
    {
        for(i=0 ; i<counter ; i++)
        {
            if(strcmp(A,temp->name) == 0)
            {
                printf(" - %s\t%s\t%lld \n",temp->name, temp->surname, temp->phone_num);
                c_counter++;
            }
            temp = temp->next;
        }
        if(c_counter == 0)
        {
            printf(" - Not Found \n");
        }
    }

    else if(number == 2)
    {
        for(i=0 ; i<counter ; i++)
        {
            if(strcmp(A,temp->surname) == 0)
            {
                printf(" - %s\t%s\t%lld \n",temp->name, temp->surname, temp->phone_num);
                c_counter++;
            }
            temp = temp->next;
        }
        if(c_counter == 0)
        {
            printf(" - Not Found \n");
        }
    }

    else if(number == 3)
    {
        for(i=0 ; i<counter ; i++)
        {
            if((strcmp(A,temp->name) == 0)&&(strcmp(B,temp->surname) == 0))
            {
                printf(" - %s\t%s\t%lld \n",temp->name, temp->surname, temp->phone_num);
                c_counter++;
            }
            temp = temp->next;
        }
        if(c_counter == 0)
        {
            printf(" - Not Found \n");
        }
    }

    else if(number == 4)
    {
        for(i=0 ; i<counter ; i++)
        {
            if(phnum == (temp->phone_num))
            {
                printf(" - %s\t%s\t%lld \n",temp->name, temp->surname, temp->phone_num);
                c_counter++;
            }
            temp = temp->next;
        }
        if(c_counter == 0)
        {
            printf(" - Not Found \n");
        }
    }
    return c_counter;
}
