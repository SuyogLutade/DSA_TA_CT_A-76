// 14. Creation of BST, tree traversal: inorder, preorder, postorders, BFS, DFS, mirror, children,
// sibling, parent of a node, GP of a node, uncle node
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
void preorder(BST root)
{
    if (root != NULL)
    {
        printf("%d,",root->num);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(BST root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->num);
    }
}
void mirror(BST root)
{
    BST stk[max],temp;
    int top=-1;
    top++;
    stk[top]=root;
    while(top>-1)
    {
        temp=stk[top]->left;
        stk[top]->left=stk[top]->right;
        stk[top]->right=temp;
        temp=stk[top];
        top--;
        if(temp->right!=NULL)
        stk[++top]=temp->right;
        if(temp->left!=NULL)
        stk[++top]=temp->left;
        
    }
    

}

void BFS(BST root)
{
    int r=-1,f=0;
    BST Que[max];
    r++;
    Que[r]=root;
    printf("\nBFS : ");
    while(r>=f)
    {
        if(Que[f]->left!= NULL)
        {
            r++;
            Que[r]=Que[f]->left;
        }
        if(Que[f]->right!= NULL)
        {
            r++;
            Que[r]=Que[f]->right;

        }
        printf("%d",Que[f]->num);
        f++;
    }
}
void DFS(BST root)
{
    BST stk[max],temp;
    int top=-1;
    top++;
    stk[top]=root;
   printf("\nDFS : ");
    while(top>-1)
    {
        temp=stk[top];
        top--;
        if(temp->right!=NULL)
        stk[++top]=temp->right;
        if(temp->left!=NULL)
        stk[++top]=temp->left;
        printf("%d,",temp->num);
    }
    
}
void main()
{
    BST root = NULL, temp, new1;
    char res;
    int val, ch, n,flag;
    do
    {

        printf("\n Enter your choise :\n\t1.insert\n\t2.Display inorder sequence\n\t3.Display preorder sequence \n\t4.Display postorder sequence \n\t5.BFS \n\t6.DFS \n\t7.Mirror (with preorder display) \n\t8.children nodes \n\t9.sibling nodes\n\t10.parent node\n\t11.GP of the node\n\t12.Uncle of node \n\t : ");
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
            case 3:// preorder  
                    printf("\n preorder : ");
                    preorder(root);

                break;
            case 4://postorder
                printf("\n postorder : ");
                postorder(root);
                
                break;
            case 5://BFS
                printf("\n BFS : ");
                BFS(root);
                break;
            case 6://DFS
                printf("\n DFS : ");
                // DFS is same as preorder for tree
                DFS(root);
                break;
            case 7://mirror
                mirror(root);
                printf("\n preorder : ");
                preorder(root);
                mirror(root);
            break;
            case 8://children
                printf("\n Enter the value of PARENT node : ");
                scanf("%d",&val);
                temp=root;
                while(temp!=NULL)
                {
                    if(temp->num<val)
                    temp=temp->right;
                    else if (temp->num>val)
                    temp=temp->left;
                    else
                    break;
                }
                if(temp!=NULL)
                {
                    if(temp->left!=NULL)
                    printf("\nthe left child node is : %d",temp->left->num);
                    else
                    printf("\nthere is no left node.");
                    if(temp->right!=NULL)
                    printf("\nthe right child node is : %d",temp->right->num);
                     else
                    printf("\nthere is no right node.");
                }
                else
                printf("\n Node not found.");
            break;
            case 9://sibling
                printf("\n Enter the value of node whose SIBLING is needed : ");
                scanf("%d",&val);
                temp=root;
                if (temp->num==val)
                printf("\n the given node is root node and has no sibling.");
                else
                {
                    while(temp!=NULL)
                    {

                        if(temp->num>val)
                        {
                            if(temp->left->num==val)
                            {
                                if(temp->right!=NULL)
                                {
                                    printf("\n the sibling of the node is %d.",temp->right->num);
                                    break;
                                }
                                else
                                printf("\n the sibling does not exist.");
                            }
                            else
                            {
                                temp=temp->left;
                            }
                        }
                        else
                        if(temp->num<val)
                        {
                            if(temp->right->num==val)
                            {
                                if(temp->left!=NULL)
                                {
                                    printf("\n the sibling of the node is %d",temp->left->num);
                                    break;
                                }
                                else
                                printf("\n the sibling does not exist.");
                            }
                            else
                            {
                                temp=temp->right;
                            }
                        }
                    }
                    if(temp==NULL)
                    printf("\n the node not found.");
                }
            break;
            case 10://parent
                printf("\n Enter the value of node whose PARENT is needed : ");
                scanf("%d",&val);
                temp=root;
                if (temp->num==val)
                printf("\n the given node is root node and has no parent.");
                else
                {
                    while(temp!=NULL)
                    {

                        if(temp->num>val)
                        {
                            if(temp->left->num==val)
                            {
                                printf("\n the parent of the node is %d.",temp->num);
                                break;
                            }
                            else
                            {
                                temp=temp->left;
                            }
                        }
                        else
                        if(temp->num<val)
                        {
                            if(temp->right->num==val)
                            {
                                printf("\n the parent of the node is %d.",temp->num);
                                break;
                            }
                            else
                            {
                                temp=temp->right;
                            }
                        }
                    }
                    if(temp==NULL)
                    printf("\n the node not found.");
                }
            break;
            case 11://Grandparent
                printf("\n Enter the value of node whose GRANDPARENT is needed : ");
                scanf("%d",&val);
                temp=root;
                if (temp->num==val)
                printf("\n the given node is root node and has no grandparent.");
                else if(temp->left->num==val || temp->right->num==val)
                printf("\n the given node is child of root node and has no grandparent.");
                else
                {
                    while(temp!=NULL)
                    {

                        if(temp->num>val)
                        {
                            if(temp->left->num==val)
                            {
                                printf("\n the grandparent of the node is %d.",new1->num);
                                break;
                            }
                            else
                            {
                                new1=temp;
                                temp=temp->left;
                            }
                        }
                        else
                        if(temp->num<val)
                        {
                            if(temp->right->num==val)
                            {
                                printf("\n the grandparent of the node is %d.",new1->num);
                                break;
                            }
                            else
                            {
                                new1=temp;
                                temp=temp->right;
                            }
                        }
                    }
                    if(temp==NULL)
                    printf("\n the node not found.");
                }
            break;
             case 12://uncle
                printf("\n Enter the value of node whose UNCLE is needed : ");
                scanf("%d",&val);
                temp=root;
                if (temp->num==val)
                printf("\n the given node is root node and has no uncle.");
                else if(temp->left->num==val || temp->right->num==val)
                printf("\n the given node is child of root node and has no uncle.");
                else
                {
                    while(temp!=NULL)
                    {

                        if(temp->num>val)
                        {
                            if(temp->left->num==val)
                            {
                                printf("\n the uncle of the node is %d.",new1->num);
                                break;
                            }
                            else
                            {
                                new1=temp->right;
                                temp=temp->left;
                            }
                        }
                        else
                        if(temp->num<val)
                        {
                            if(temp->right->num==val)
                            {
                                printf("\n the uncle of the node is %d.",new1->num);
                                break;
                            }
                            else
                            {
                                 new1=temp->left;
                                temp=temp->right;
                            }
                        }
                    }
                    if(temp==NULL)
                    printf("\n the node not found.");
                }
            break;
        }
    }while (ch<=13&&ch>0);
}