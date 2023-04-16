// This is basic C program that performs menu driven functions on Linked List items
// This is completely beginner level code.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int info;
    struct node *link;
} *start = NULL;
// 1st function creating a list
void createlist()
{
    if (start == NULL)
    {
        int n;
        printf("Enter the number of nodes : ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            struct node *temp;
            struct node *newnode;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\n Enter the number to be inserted : ");
            scanf("%d", &data);
            start->info = data;
            for (int i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter the number to be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("The list is created \n");
    }
    else
        printf("the list is already created");
}

// 2nd function traverse to the list
void traverse()
{
    struct node *temp;
    if (start == NULL)
        printf("the list is empty");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("->%d  ", temp->info);
            temp = temp->link;
        }
    }
}

// 3rd function to insert element at the begining of the list

void atFront()
{

    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter the number to  be inserted: ");
    scanf("%d", &data);

    temp->info = data;
    temp->link = start;
    start = temp;
}

// 4th function to insert element at the end of the list

void insertEnd()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("Enter the number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *last = start;
        while (last->link != NULL)
        {
            last = last->link;
        }
        last->link = temp;
    }
}

// 5th function to insert element at a given position

void insertpos()
{
    int pos, data;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));

    printf("enter the number to be inserted");
    scanf("%d", &data);
    printf("Enter the position");
    scanf("%d", &pos);
    temp = start;
    newnode->info = data;
    newnode->link = NULL;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->link;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

// 6th function to delete first element

void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        temp = start;
        start = start->link;
        free(temp);
    }
}

// 7th function to delete last element

void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
    {
        printf(" The list is Empty");
    }
    else
    {
        temp = start;
        while (temp->link != NULL)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = NULL;
    }
}

// 8th function to delete at a given position

void deletePos()
{
    struct node *temp, *pos;
    int index;
    if (start == NULL)
    {
        printf(" the list is Empty");
    }
    else
    {
        printf("Enter index");
        scanf("%d", &index);

        pos = malloc(sizeof(struct node));
        temp = start;

        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->link;
        }
        pos = temp->link;
        temp->link = pos->link;
        free(pos);
    }
}

// 9th function to find the maximum element present in the list

void maximum()
{
    int i;
    struct node *temp;
    if (start == NULL)
    {
        printf("the list i s empty");
    }
    else
    {
        temp = start;
        int max = temp->info;
        while (temp != NULL)
        {
            if (temp->info > max)
            {
                max = temp->info;
            }
            temp = temp->link;
        }
        printf(" Maximum number is %d", max);
    }
}

// 10th function to find the average or mean of the elements in the list

void mean()
{
    int a[10];
    int i;
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        int sum = 0, count = 0;
        float m;
        while (temp != NULL)
        {
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }

        m = sum / count;
        printf("\nMean is %f ", m);
    }
}

// 11th function is to count the total number of elements and sum them

void count_and_sum()
{

    if (start == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct node *temp;
        int sum, count;
        sum = count = 0;
        temp = start;
        while (temp != NULL)
        {
            sum += temp->info;
            temp = temp->link;
            count++;
        }
        printf("  the total no of elements in the list is %d and sum of all elements is %d\n", count, sum);
    }
}

// 12th function is to check if the list is sorted

void is_sort()
{

    if (start == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int x = INT_MIN;
        int sort = -1;
        struct node *temp;
        temp = start;
        while (temp != NULL)
        {
            if (temp->info < x)
            {
                printf("The list is not sorted ");
                sort = 1;
                break;
            }
            else
            {
                x = temp->info;
                temp = temp->link;
            }
        }
        if (sort == -1)
        {
            printf("The list is sorted ");
        }
    }
}

// 13th function is to sort the list

void sort()
{
    struct node *current = start;
    struct node *index = NULL;
    int temp;

    if (start == NULL)
    {
        printf("The llist Is empty");
    }
    else
    {
        while (current != NULL)
        {
            index = current->link;
            while (index != NULL)
            {
                if (current->info > index->info)
                {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            current = current->link;
        }
    }
}

// 14th function is to remove duplicate elements from the list

void remove_duplicate()
{
    int count = 0;
    struct node *p, *q;
    p = start;
    q = start->link;

    if (start == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        sort();
        while (q != NULL)
        {
            if (p->info == q->info)
            {
                p->link = q->link;
                free(q);
                q = p->link;
                count += 1;
            }
            else
            {
                p = q;
                q = q->link;
            }
        }

        if (count == 0)
        {
            printf("There were no duplicates in the list");
        }
        else
        {
            printf("All %d duplicates are removed from the list", count);
        }
    }
}

// 15th function is to reverse the elements of list using sliding pointers

void reverse_Sliding()
{
    struct node *p, *q, *r;
    p = start;
    q = r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    start = q;
    printf("The list is reversed.\n");
}

// 16th function is to reverse the elements of the list

void reverseLL()
{
    struct node *prev, *curr, *temp;

    if (start == NULL)
        printf("List is empty\n");

    else
    {
        prev = start;
        curr = start->link;
        start = start->link;
        prev->link = NULL;
        while (start != NULL)
        {
            start = start->link;
            curr->link = prev;

            prev = curr;
            curr = start;
        }
        start = prev;
        temp = start;
        while (temp != NULL)
        {
            printf("->%d", temp->info);
            temp = temp->link;
        }
        printf("\tThe list is reversed.\n");
    }
}

// 17th function is to reverse the list using reccursion

void RReverse(struct node *p)
{

    if (p != NULL)
    {
        RReverse(p->link);
        printf(" -> %d", p->info);
    }
}

// 18th function is to search for a element in the list

void search()
{
    int found = -1;
    int key, count = 0;
    struct node *tr = start;
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("\n Enter the element you want to search: ");

        scanf("%d", &key);
        while (tr != NULL)
        {
            if (tr->info == key)
            {
                found = 1;
                break;
            }
            else
            {
                tr = tr->link;
                count += 1;
            }
        }
        if (found == 1)
        {
            printf("The key is found in %d no of search ", count + 1);
        }
        else
        {
            printf("The key is not found");
        }
    }
}

// 19th function is to search for a element in a list and bring it to the head of the list i.e Move to head

void improved_search()
{

    if (start == NULL)
    {
        printf("The link list is empty");
    }
    else
    {
        struct node *temp = start;
        struct node *q = NULL;
        int key, count = 0;
        int found = -1;

        printf("Enter the element you want to search for: ");
        scanf("%d", &key);
        while (temp != NULL)
        {
            if (key == temp->info)
            {
                found = 1;
                q->link = temp->link;
                temp->link = start;
                start = temp;
                break;
            }
            else
            {
                count++;
                q = temp;
                temp = temp->link;
            }
        }

        if (found == 1)
        {
            printf("The key is found in %d no of search and moved to head", count + 1);
        }
        else
        {
            printf("The key is not found");
        }
    }
}

// 20th function is to check if there is any loop in the ll

void is_loop()
{
    struct node *p, *q;
    p = q = start;
    do
    {
        p = p->link;
        q = q->link;
        q = q ? q->link : q;
    } while (p && q && p != q);
    if (p == q)
    {
        printf(" The link list contains a loop ");
    }
    else
        printf(" The link list does not contain a loop ");
}

int main()
{
    int choice;
    char opt;
    int i = 0;
    printf(" : Welcome to the Menu Driven Program :\n");
    while (i < 40)
    {
        printf("*");
        i++;
    }
    if (start == NULL)
        printf("\nDo you want to Create List: Y or N : ");
    scanf("%c", &opt);
    {

        if (opt == 'Y' || opt == 'y')
        {
            createlist();
            printf("\nList Created now you can perform operations following\n");
            while (1)
            {
                printf("\n\t1  To see list\n");

                printf("\t2  For insertion at"
                       " starting\n");

                printf("\t3  For insertion at"
                       " end\n");

                printf("\t4  For insertion at "
                       "any position\n");

                printf("\t5  For deletion of "
                       "first element\n");

                printf("\t6  For deletion of "
                       "last element\n");

                printf("\t7  For deletion of "
                       "element at any position\n");

                printf("\t8  To find maximum among"
                       " the elements\n");

                printf("\t9  To find mean of "
                       "the elements\n");

                printf("\t10 To count the no of elements and find sum of them\n");

                printf("\t11 To check if the elements are sorted\n");

                printf("\t12 Remove duplicates from the list of elements\n");

                printf("\t13 Sort the elements\n");

                printf("\t14 To to reverse the elements of list using sliding pointers\n");

                printf("\t15 To reverse the elements of the list\n");

                printf("\t16 Recursive reverse\n");

                printf("\t17 To search for a element in the list\n");

                printf("\t18 To search for a element in a list and bring it to the head of the list i.e Move to head\n");

                printf("\t19 To check whether a loop is present in the list\n");

                printf("\t20 Exit:\n");

                printf("\n\tEnter Choice :\t\n");
                
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    traverse();
                    break;
                case 2:
                    atFront();
                    break;
                case 3:
                    insertEnd();
                    break;
                case 4:
                    insertpos();
                    break;
                case 5:
                    deleteFirst();
                    break;
                case 6:
                    deleteEnd();
                    break;
                case 7:
                    deletePos();
                    break;
                case 8:
                    maximum();
                    break;
                case 9:
                    mean();
                    break;
                case 10:
                    count_and_sum();
                    break;
                case 11:
                    is_sort();
                    break;
                case 12:
                    remove_duplicate();
                    break;
                case 13:
                    sort();
                    break;
                case 14:
                    reverse_Sliding();
                    break;
                case 15:
                    reverseLL();
                    break;
                case 16:
                    RReverse(start);
                    break;
                case 17:
                    search();
                    break;
                case 18:
                    improved_search();
                    break;
                case 19:
                    is_loop();
                    break;
                case 20:
                    exit(1);
                    break;
                default:
                    printf("Incorect choice\n");
                }
            }
        }

        else if (opt == 'N' || opt == 'n')

        {
            printf("No list is Created hence operations cannot be performed \n Run the program again to create a new list\n");
            exit(1);
        }
        else
        {
            printf("Incorect Choice");
            exit(0);
        }
    }

    return 0;
}
