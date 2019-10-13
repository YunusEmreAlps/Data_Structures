// linked list

// Yunus Emre Alpu
// 17010011005
// cift yonlu dairesel linked list kullanarak kullanicidan metin almak.
// sessiz harfleri cift sesli harfleri tek indislere yerlestirmek.
// bu harfleri siralamak ve frekanslarini yazmak

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// ----------
// structure
struct message
{
    char text; // put only one character
    struct message *prev;
    struct message *next;
};

// ----------
// global variables
struct message *head=NULL, *temp, *temp1;
struct message *k;
struct message txt_temp;

char msg[50]; // user message (CAR)
char msg_let[50]; // user message (C-A-R)
char vwls[5]= {'A','E','I','O','U'}; // vowels
char cnst[21]= {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'}; // consonants
char alphb[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int rep[26];
int i, j;
int com_counter=0; // component counter

// ----------
// signature of functions
int menu();
void msg_add();
void msg_upp(); // uppercase (first)
void msg_lst(); // show all data
void msg_upd(); // update
void chr_rep(); // character repetition
void cha_lst();
// ----------
// main
int main()
{
    int control=0; // boolean -> false
    while(1) // infinity loop
    {
        switch(menu())
        {
        case 1:
            msg_add();
            msg_upd();
            msg_lst();
            chr_rep();
            break;

        case 2:
            msg_lst();
            break;
        case 3:
            chr_rep();
            break;
        case 4: // Quit
            control=1; // boolean -> true
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
    printf(" - 1. Continue \n");
    printf(" - 2. List \n");
    printf(" - 3. Character repetition table \n");
    printf(" - 4. Quit \n");
    printf(" ---------------\n");

    float menu_pro=0; // menu_pro : menu process

    printf(" - Enter choice : ");
    while(1) // infinity loop
    {
        scanf("%f",&menu_pro);
        if((menu_pro==1)||(menu_pro==2)||(menu_pro==3)||(menu_pro==4)) // status is positive
            break;
        printf(" - Try again : ");
        while(getchar() != '\n'); // menu_pro != number
    }

    return menu_pro; // integer
}

void msg_upp(char msg[50]) // Yunus
{
    i=0;
    while(msg[i] != '\0')  // Upper_case
    {
        if((msg[i]!=' ')&&(msg[i]>='a' && msg[i]<= 'z'))  // A=65, a=97, Z=90, z=122
        {
            msg[i]= msg[i]-32; // YUNUS
        }
        i++;
    }
    int m=0,t=0;
    char msg_cnst[50];
    char msg_vwls[50];

    for(i=0; i<50; i++) // array is empty
    {
        msg_cnst[i]=' ';
        msg_vwls[i]=' ';
    }

    for(i=0; i<strlen(msg); i++)
    {
        for(j=0; j<strlen(cnst); j++)
        {
            if(msg[i]==cnst[j])
            {
                msg_cnst[m]=msg[i];
                m++;
            }
        }
        for(j=0; j<strlen(vwls); j++)
        {
            if(msg[i]==vwls[j])
            {
                msg_vwls[t]=msg[i];
                t++;
            }
        }
    }

    int c_num=0, v_num=0;
    c_num=m;
    v_num=t;

    //   t   >   m
    if(v_num >= c_num)
    {
        m=0,t=0;
        for(i=0; i<strlen(msg); i++)
        {
            if((msg_cnst[m]>= 'A' && msg_cnst[m]<= 'Z')&&(i%2==0))
            {
                msg_let[i]=msg_cnst[m];
                msg_cnst[m] =' ';
                m++;
            }
            else if((msg_vwls[t]>= 'A' && msg_vwls[t]<= 'Z'))
            {
                msg_let[i] = msg_vwls[t];
                msg_vwls[t] = ' ';
                t++;
            }

        }
    }

    else if(c_num>v_num)
    {
        m=0,t=0;
        for(i=0; i<strlen(msg); i++)
        {
            if((msg_vwls[t]>= 'A' && msg_vwls[t]<= 'Z')&&(i%2!=0))
            {
                msg_let[i]=msg_vwls[t];
                msg_vwls[t] =' ';
                t++;
            }
            else if((msg_cnst[m]>= 'A' && msg_cnst[m]<= 'Z'))
            {
                msg_let[i] = msg_cnst[m];
                msg_cnst[m] = ' ';
                m++;
            }
        }

    }
}

void msg_add()
{
    system("cls"); // clear
    printf(" ---------------\n");
    getchar();
    printf(" - Text : ");
    gets(msg);
    printf(" ---------------\n");

    int l_counter=0; // character counter
    for(i=0; i<strlen(msg); i++) // empty control
    {
        if(msg[i] != ' ')
            l_counter++;
    }

    if(strlen(msg)>0 && l_counter!=0)
    {
        msg_upp(msg); // uppercase

        for(i=0; i<strlen(msg); i++)
        {
            struct message *val;
            val=malloc(sizeof(struct message));
            if(head==NULL) // empty
            {
                head=val;
                head->text=msg_let[i];
                head->next=head;
                head->prev=head;
                com_counter++;
            }

            else
            {
                temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=val;
                (temp->next)->text=msg_let[i];
                (temp->next)->next=head;
                (temp->next)->prev=temp;
                com_counter++;
            }
        }

    }
    else if(l_counter==0) // empty message
    {
        printf(" - Text is empty .\n");
    }
    getch();
}

void msg_lst()
{
    system("cls");
    printf(" - ");
    temp=head;
    for(i=0; i<com_counter; i++)
    {
        printf("%c->",temp->text);
        temp=temp->next;
    }
    getch();
}

void msg_upd()
{
    system("cls");
    cha_lst();

    // ----------
    temp=head;
    for(i=0; i<com_counter; i++)
    {
        if(temp->text!='A' && temp->text!='E' && temp->text!='I' && temp->text!='O' && temp->text!='U') // M,Z,N
        {
            temp1=head;
            for(j=0; j<com_counter; j++)
            {
                if(temp1->text!='A' && temp1->text!='E' && temp1->text!='I' && temp1->text!='O' && temp1->text!='U') // M,Z,N
                {
                    if(((temp->text)<(temp1->text))&&(i<j))
                    {
                        txt_temp.text=temp->text;
                        temp->text=temp1->text;
                        temp1->text=txt_temp.text;
                    }
                }
                temp1=temp1->next;
            }
        }
        temp=temp->next;
    }

    for(i=0; i<com_counter; i++)
    {
        if(temp->text=='A' || temp->text=='E' || temp->text=='I' || temp->text=='O' || temp->text=='U') // M,Z,N
        {
            temp1=head;
            for(j=0; j<com_counter; j++)
            {
                if(temp1->text=='A' || temp1->text=='E' || temp1->text=='I' || temp1->text=='O' || temp1->text=='U') // M,Z,N
                {
                    if(((temp->text)>(temp1->text))&&(i<j))
                    {
                        txt_temp.text=temp->text;
                        temp->text=temp1->text;
                        temp1->text=txt_temp.text;
                    }
                }
                temp1=temp1->next;
            }
        }
        temp=temp->next;
    }
    getch();
}

void chr_rep()
{
    /* -> AMAZON
          A:2
          M:1
          N:1
          O:1
          Z:1
    */
    int number=0;
    for(i=0; i<26; i++)
    {
        temp=head;
        number=0;
        for(j=0; j<com_counter; j++)
        {

            if(temp->text == alphb[i])
            {
                number++;
            }
            temp=temp->next;
        }
        rep[i]=number;
    }

    printf("\n");
    for(i=0; i<26; i++)
    {
        printf(" - %c : %d \n",alphb[i],rep[i]);
    }
    getch();
}

void cha_lst()
{
    int a=0,b=0;
    char upd_cnst[50];
    char upd_vwls[50];

    for(i=0; i<50; i++) // array is empty
    {
        upd_cnst[i]=' ';
        upd_vwls[i]=' ';
    }

    for(i=0; i<com_counter; i++)
    {
        for(j=0; j<strlen(cnst); j++)
        {
            if(temp->text==cnst[j])
            {
                upd_cnst[a]=temp->text;
                a++;
            }
        }
        for(j=0; j<strlen(vwls); j++)
        {
            if(temp->text==vwls[j])
            {
                upd_vwls[b]=temp->text;
                b++;
            }
        }
        temp=temp->next;
    }

    int c_upd=0, v_upd=0;
    c_upd=a;
    v_upd=b;

    //   t   >   m
    if(v_upd >= c_upd)
    {
        a=0,b=0;
        temp=head;
        for(i=0; i<com_counter; i++)
        {
            if((upd_cnst[a]>= 'A' && upd_cnst[a]<= 'Z')&&(i%2==0))
            {
                temp->text=upd_cnst[a];
                upd_cnst[a] =' ';
                a++;
            }
            else if((upd_vwls[b]>= 'A' && upd_vwls[b]<= 'Z'))
            {
                temp->text = upd_vwls[b];
                upd_vwls[b] = ' ';
                b++;
            }
            temp=temp->next;
        }
    }

    else if(c_upd>v_upd)
    {
        a=0,b=0;
        temp=head;
        for(i=0; i<com_counter; i++)
        {
            if((upd_vwls[b]>= 'A' && upd_vwls[b]<= 'Z')&&(i%2!=0))
            {
                temp->text=upd_vwls[b];
                upd_vwls[b] =' ';
                b++;
            }
            else if((upd_cnst[a]>= 'A' && upd_cnst[a]<= 'Z'))
            {
                temp->text= upd_cnst[a];
                upd_cnst[a] = ' ';
                a++;
            }
            temp=temp->next;
        }
    }

}
