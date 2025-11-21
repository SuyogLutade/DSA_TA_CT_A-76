#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#define max 40
typedef struct BST
{
    int num,visit;
    struct BST * right, * left;
} *BST;
BST getNode()
{
    BST new1;
    new1 = (BST)malloc(sizeof(struct BST));
    new1->left = NULL;
    new1->right = NULL;
    return new1;
}
void inorder(BST root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d,",root->num);
        inorder(root->right);
    }
}
void main()
{
    BST root = NULL, temp, new1;
    char res;
    int val, ch, n,flag;
    do
    {

        printf("\n Enter your choise :\n\t1.insert\n\t2.Display inorder sequence\n\t3.maximum & minimum data in BST \n\t : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:// insert
        printf("\nEnter the number of nodes you want to insert : ");
        scanf("%d",&n);
        do{

            if (root == NULL)
            {
                root = getNode();
                printf("Enter the number:");
                scanf("%d",&root->num);
                temp = root;
            }
            else
            {
                temp = root;
                flag = 0;
                new1 = getNode();
                printf("Enter the number:");
                scanf("%d",&val);
                new1->num = val;
                do
                {
                    if (new1->num < temp->num)
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = new1;
                            flag = 1;
                        }
                        else
                            temp = temp->left;
                    }
                    else
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = new1;
                            flag = 1;
                        }
                        else
                            temp = temp->right;
                    }
    
                } while (flag == 0);
            }
            n--;
        }while(n>0);
        break;
        case 2://inorder 
            printf("\n inorder : ");
            inorder(root);
        break;
        case 3:
            temp=root;
            while(temp->left!=NULL)
            temp=temp->left;
            printf("\n The miminum data is %d.",temp->num);
            temp=root;
            while(temp->right!=NULL)
            temp=temp->right;
            printf("\n The maximum data is %d.",temp->num);
        break;
        }
    }while (ch<=3&&ch>0);
}

