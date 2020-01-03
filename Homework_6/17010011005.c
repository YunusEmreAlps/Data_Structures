// binary search tree

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// ----------
// structure
struct tree{
  int data;
  int height;
  int balance;
  struct tree *left;
  struct tree *right;
};
// ----------
// global variables
struct tree *temp;
struct tree *newnode;

// ----------
// signature of functions
int menu();

struct tree* createnode(int value);
struct tree* addnode(struct tree *root, int value);
struct tree* deletenode(struct tree *root, int value);

void inorder_list(struct tree *root);
void balance_list(struct tree *root);

int maxh(int l, int r); // maximum height function
int heightt(struct tree *root); // tree height
int balancet(struct tree *root); // tree balance
int balance_res(struct tree *root);
int find_max(struct tree *root);
int find_min(struct tree *root);

// ----------
// main function
int main()
{
    int number=0;
    int ex_ctrl=0; // exit control = boolean FALSE
    struct tree *root=NULL;

    printf(" - Enter root number : ");
    scanf("%d",&(number));
    root=addnode(root, number);

    while(1)
    {
        switch(menu())
        {
            case 1: // add a data to tree
                printf(" - Enter number : ");
                scanf("%d",&(number));
                addnode(root, number);

                break;
            case 2: // list to tree data
                inorder_list(root);
                printf(" - data \t height \t balanced factor \n");
                balance_list(root);
                printf("\n");

                if(balance_res(root)!=0)
                {
                    printf(" - Not Balanced \n");
                }
                else
                    printf(" - Balanced \n");

                printf("\n");
                break;
            case 3:
                printf(" - Enter number : ");
                scanf("%d",&(number));
                deletenode(root, number);
                break;
            case 4: // exit
                ex_ctrl=1; // boolean TRUE
                break;
        }

        if(ex_ctrl==1)
            break;
    }

    getch();
    return 0;
}

// ----------
// menu function
int menu()
{
    float mn_pnum=0;

    printf(" ---------------\n");
    printf(" - 1.) Add \n");
    printf(" - 2.) List \n");
    printf(" - 3.) Delete \n");
    printf(" - 4.) Exit \n");
    printf(" ---------------\n");
    printf(" - Enter your choice : ");

    while(1)
    {
       scanf("%f",&(mn_pnum));

       if((mn_pnum==1) || (mn_pnum==2) || (mn_pnum==3) || (mn_pnum==4))
            break;
        printf(" - Please try again : ");
        while(getchar() != '\n');
    }
    return mn_pnum;
}

// ----------
// create node function
struct tree* createnode(int value)
{
    newnode=malloc(sizeof(struct tree));
    newnode->data=value;
    newnode->height=1;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// ----------
// add node function
struct tree* addnode(struct tree *root, int value)
{
    if(root==NULL)
        return createnode(value);

    if((root->data)>value) // left < root < right
    {
      // left
      temp=root;
      temp->left=addnode(temp->left, value);
    }
    if((root->data)<value) // left < root < right
    {
        // right
        temp=root;
        temp->right=addnode(temp->right, value);
    }
    return root;
}

// ----------
// in order_list function
void inorder_list(struct tree *root)
{
    if(root==NULL)
        return;

    inorder_list(root->left);
    root->height=heightt(root);
    inorder_list(root->right);
}

// ----------
// maxh function
int maxh(int l, int r)
{
    if(l>r)
        return l;
    else
        return r; // else
}

// ----------
// height function
int heightt(struct tree *root)
{
    if(root==NULL)
        return 0;

    else
        return maxh(heightt(root->left), heightt(root->right))+1;
}

// ----------
// balance function
int balancet(struct tree *root)
{
    if((root->left==NULL) && (root->right==NULL))
        return 0;

    if((root->left==NULL) && (root->right!=NULL))
        return (root->right->height);

    if((root->left!=NULL) && (root->right==NULL))
        return -1*(root->left->height);

    if((root->left!=NULL) && (root->right!=NULL))
        return ((root->right->height)-(root->left->height));
}

// ----------
// balance list function
void balance_list(struct tree *root)
{
    if(root==NULL)
        return;

    balance_list(root->left);
    root->balance=balancet(root);
    printf(" - %d \t\t %d \t\t %d \n",root->data, root->height, root->balance);
    balance_list(root->right);
}

// ----------
// balance result function
int balance_res(struct tree *root)
{
    if(root==NULL)
        return;

    int res=0; // FALSE -> balance

    balance_res(root->left);
    if(((root->balance)<-1) || ((root->balance)>1))
    {
        res=root->balance;
        return res;
    }
    balance_res(root->right);
}

// ----------
// maximum number
int find_max(struct tree *root){

    while((root->right)!=NULL)
        root=root->right;

    return root->data;
}

// ----------
// find minimum number
int find_min(struct tree *root){

    while((root->left)!=NULL)
        root=root->left;
    return root->data;
}

// ----------
// delete function
struct tree* deletenode(struct tree *root, int value)
{
    if(root==NULL)
        return NULL;
    if((root->data)==value)
    {
        if(((root->left==NULL)) && (root->right==NULL))
            return NULL;
        if((root->right!=NULL))
        {
            root->data=find_min(root->right);
            root->right=deletenode(root->right, find_min(root->right));
            return root;
        }
        root->data=find_max(root->left);
        root->left=deletenode(root->left, find_max(root->left));
        return root;
    }

    if((root->data)>value) // left < root < right
    {
        // left
        root->left=deletenode(root->left, value);
    }
    if((root->data)<value) // left < root < right
    {
        // right
        root->right=deletenode(root->right, value);
    }
    return root;
}
