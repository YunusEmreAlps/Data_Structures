// linked list(stack)
// infix to postfix

// infix bir ifadeyi postfix'e çevirme

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// ----------
// structure
struct mystack  // last in first out
{
    char data;
    struct mystack *next; // single way
};

// ----------
// global variables
FILE *ptr;
struct mystack *head=NULL, *temp;
struct mystack *value;

char r_str[50]; // read string (infix)
char n_str[50]; // new string (postfix)
char t_str[50]; // temp string
char t_str2[50]; // temp string
char t_str3[50]; // temp string
char tmp;

int i=0,j=0, m=0, k=0; // loop variable

// ----------
// signature of functions
void file_read();
int priority(char chr); // operator priority
void convert(); // infix -> postfix
void list();

// ----------
// main
int main()
{
    convert();
    list();

    getch();
    return 0;
}

// ----------
// functions
void file_read() // This file read only just first line
{
    //   open("path","mode");
    ptr=fopen("C:\\Users\\Dell\\Desktop\\Data Structures\\Homework_3\\infix.txt","r"); // read mode

    if(ptr==NULL)
    {
        printf(" - File Error \n");
        printf(" - The file connection is lost.\n");
        exit(-1);
    }
    else
    {
        fscanf(ptr,"%s",r_str);
        printf(" - %s \n",r_str);
    }
    fclose(ptr);
}

int priority(char chr)
{
    int pri_num=0; // priority number

    if(chr=='(')
        return pri_num=0;
    else if((chr=='+')||(chr=='-'))
        return 1;
    else if((chr=='*')||(chr=='/'))
        return 2;
    else if((chr=='^'))
        return 3;
}

void convert()
{
    file_read();

    int control=0;
    for(i=0; i<strlen(r_str); i++)
    {
        if(r_str[i]=='(')
        {
            control++;
        }
        if(r_str[i]==')')
        {
            control--;
        }
    }

    if(control == 0) // o parenthesis == c parenthesis
    {
        for(i=0; i<strlen(r_str); i++)
        {
            if((r_str[i]=='+')||(r_str[i]=='-')||(r_str[i]=='*')||(r_str[i]=='/')||(r_str[i]=='^')) // +
            {
                if(head==NULL) // list is empty +
                {
                    value=malloc(sizeof(struct mystack)); // dynamic memory allocation
                    head=value;
                    head->data=r_str[i];
                    head->next=NULL;
                    printf("%c \n",head->data);
                }

                else // list is not empty
                {
                    temp=head;
                    while(temp->next!=NULL) // head->next == NULL
                    {
                        temp=temp->next;
                    }

                    if(priority(r_str[i])> priority(temp->data)) // read_string:* > temp->data:+ ,
                    {
                        value=malloc(sizeof(struct mystack));
                        temp->next=value;
                        (temp->next)->data=r_str[i];
                        (temp->next)->next=NULL;
                        temp=head;
                        while(temp!=NULL) // print
                        {
                            printf("%c",temp->data);
                            temp=temp->next;
                        }
                        printf("\t");
                        for(j=0; j<strlen(n_str); j++){
                            printf("%c",n_str[j]);
                        }
                        printf("\n");
                    }
                    else if(priority(r_str[i])==priority(temp->data)) // read_string:+ == temp->data:-
                    {
                        n_str[m]+=temp->data;
                        m++;
                        temp->data=r_str[i]; // swapping process

                        temp=head;
                        while(temp!=NULL) // print
                        {
                            printf("%c",temp->data);
                            temp=temp->next;
                        }
                        printf("\t");
                        for(j=0; j<strlen(n_str); j++){
                            printf("%c",n_str[j]);
                        }
                        printf("\n");

                    }
                    else if(priority(r_str[i])<priority(temp->data)) // read_string:+ == temp->data:*
                    {
                        k=0;
                        temp=head;
                        while(temp!=NULL)
                        {
                            t_str[k]=temp->data;
                            k++;
                            temp=temp->next;
                        }

                        for(k=0; k<strlen(t_str); k++) // sorting algorithm
                        {
                            for(j=0; j<strlen(t_str); j++)
                            {
                                if(priority(t_str[k])<t_str[j] && k<j)
                                {
                                        tmp=t_str[k];
                                        t_str[k]=t_str[j];
                                        t_str[j]=tmp;
                                }
                            }
                        }

                        for(k=0; k<strlen(t_str); k++) // Add
                        {
                            if(t_str[k]!= '!') // empty
                            {
                                n_str[m]+=t_str[k];
                                m++;
                            }
                        }

                        temp=head;
                        while(temp!=NULL) // print
                        {
                            printf("%c",temp->data);
                            temp=temp->next;
                        }
                        printf("\t");
                        for(j=0; j<strlen(n_str); j++){
                            printf("%c",n_str[j]);
                        }
                        printf("\n");

                        head=NULL; // Stack is empty
                        value=malloc(sizeof(struct mystack));
                        head=value;
                        head->data=r_str[i];
                        head->next=NULL;

                        while(temp!=NULL) // print
                        {
                            printf("%c",temp->data);
                            temp=temp->next;
                        }
                        printf("\n");
                    }

                }
            }
            // ----------
            else if(r_str[i]=='(') // !important!
            {
                if(head==NULL) // list is empty +
                {
                    value=malloc(sizeof(struct mystack));
                    head=value;
                    head->data=r_str[i];
                    head->next=NULL;
                    printf("%c \n",head->data);
                }
                else // list is not empty
                {
                    temp=head;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }

                    value=malloc(sizeof(struct mystack));
                    (temp->next)=value;
                    (temp->next)->data=r_str[i];
                    (temp->next)->next=NULL;
                    temp=head;
                    while(temp!=NULL)
                    {
                        printf("%c",temp->data);
                        temp=temp->next;
                    }
                    printf("\n");
                }
            }
            // ----------
            else if(r_str[i]==')')
            {
                temp=head; // don't forget first component
                while(temp!=NULL)
                {
                    if(temp->data=='(')
                    {
                        break;
                    }
                    temp=temp->next;

                }

                k=0;
                while(temp!=NULL)
                {
                    if(temp->data!='(')
                    {
                        t_str3[k]=temp->data;
                        k++;
                        if(temp == head)
                        {
                           head=temp->next;
                        }
                        else
                            temp->data='!';
                    }
                    if(temp->data=='(')
                    {
                        if(temp == head)
                        {
                           head=temp->next;
                        }
                         else
                            temp->data='!';
                    }
                    temp=temp->next;
                }

                temp=head;
                while(temp!=NULL)
                {
                    if(temp->data=='!')
                    {
                       temp->next=temp->next->next;
                    }
                    else
                    {
                        temp->next=NULL;
                    }

                    temp=temp->next;
                }

                for(k=0; k<strlen(t_str3); k++)
                {
                    for(j=0; j<strlen(t_str3); j++)
                    {
                        if(priority(t_str3[k])<t_str3[j] && k<j)
                        {
                            tmp=t_str3[k];
                            t_str3[k]=t_str3[j];
                            t_str3[j]=tmp;
                        }
                    }
                }

                for(k=0; k<strlen(t_str3); k++)
                {
                    if(t_str3[k]!= '!')
                    {
                        n_str[m]+=t_str3[k];
                        m++;
                    }

                }

                temp=head;
                while(temp!=NULL) // print
                {
                    if(temp!= '!')
                    {
                        printf("%c",temp->data);
                    }
                    temp=temp->next;
                }
                printf("\t");
                for(j=0; j<strlen(n_str); j++)
                {
                    if(n_str != '!')
                        printf("%c",n_str[j]);
                }
                printf("\n");

            }
            // ----------
            else // it means number or character
            {
                n_str[m]+=r_str[i];
                m++;
            }
        }

        // ----------
        // if stack is not empty
        if(head!=NULL)
        {
            k=0;
            temp=head;
            while(temp!=NULL)
            {
                t_str2[k]=temp->data;
                k++;
                temp=temp->next;
            }

            for(k=0; k<strlen(t_str2); k++)
            {
                for(j=0; j<strlen(t_str2); j++)
                {
                    if(priority(t_str2[k])<t_str2[j] && k<j)
                    {
                        tmp=t_str2[k];
                        t_str2[k]=t_str2[j];
                        t_str2[j]=tmp;
                    }
                }
            }

            for(k=0; k<strlen(t_str2); k++)
            {
                if(t_str2[k]!='(')
                {
                    n_str[m]+=t_str2[k];
                    m++;
                }
            }
            temp=head;
            while(temp!=NULL) // print
            {
                printf("%c",temp->data);
                temp=temp->next;
            }
            printf("\t");
            for(j=0; j<strlen(n_str); j++)
            {
                printf("%c",n_str[j]);
            }
            printf("\n");

            head=NULL;
            value=malloc(sizeof(struct mystack));
            head=value;
            head->data=r_str[i];
            head->next=NULL;
            temp=head;

            while(temp!=NULL) // print
            {
                printf("%c",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }

    else
    {
        printf(" - Mismatch parenthesis Error.\n");
    }
}

void list()
{
    for(i=0; i<strlen(n_str); i++)
    {
        if(n_str[i]!='(')
            printf("%c",n_str[i]);
    }
}
