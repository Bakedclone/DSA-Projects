#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtFirst(int data, struct node **first, struct node **last)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*first == NULL)
    {
        *first = newnode;
        newnode->next = *first;
        *last = newnode;
    }
    else
    {
        newnode->next = *first;
        *first = newnode;
        (*last)->next = *first;
    }
}

void insertAtLast(int data, struct node **first, struct node **last)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*first == NULL)
    {
        *first = newnode;
        newnode->next = *first;
        *last = newnode;
    }
    else
    {
        (*last)->next = newnode;
        newnode->next = *first;
        *last = newnode;
    }
}
void display(struct node *first)
{
    struct node *temp = first;

    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != first);
}
void main()
{
    struct node *first = NULL, *last = NULL;

    int n, m, o, data, flag = 1, count = 0, splits, c, i, j;

    while (1)
    {
        system("cls");
        printf("\t\t\t\tSplit Circular Linked-List\n");
        printf("\t\t\t--------------------------------------\n");
        printf("1) Create Circular Linked-List\n");
        printf("2) Split Circular Linked-List\n");
        printf("3) Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            while (flag)
            {

                printf("\nCreate Linked-List\n------------------\n");
                printf("1) Insert at First\n");
                printf("2) Insert at Last\n");
                printf("3) Display\n");
                printf("4) Return to main menu\n");
                printf("\nEnter your choice : ");
                scanf("%d", &m);
                if (m == 1)
                {
                    printf("\nEnter Element : ");
                    scanf("%d", &data);
                    insertAtFirst(data, &first, &last);
                    count++;
                }
                else if (m == 2)
                {
                    printf("\nEnter Element : ");
                    scanf("%d", &data);
                    insertAtLast(data, &first, &last);
                    count++;
                }
                else if (m == 3)
                {
                    printf("\nCircular Linked-List : ");
                    display(first);
                    printf("\n");
                }
                else if (m == 4)
                {
                    flag = 0;
                }
                else
                {
                    printf("\nEnter correct choice\n");
                }
            }
            break;
        case 2:
        {
            printf("\n%d Splits are possible\n", count);
            printf("Enter no. of splits : ");
            scanf("%d", &splits);

            struct node *f[splits], *slow, *fast;

            i = 1;
            j = 0;

            f[j] = first;
            slow = first;
            fast = first->next;

            while (fast->next != first)
            {
                if (i == splits)
                {
                    slow->next = f[j];
                    slow = fast;
                    f[++j] = fast;
                    fast = fast->next;
                    i = 1;
                }
                else
                {
                    slow = slow->next;
                    fast = fast->next;
                    i++;
                }
            }
            if (i == splits)
            {
                slow->next = f[j];
                f[++j] = fast;
            }
            fast->next = f[j];

            for (i = 0; i <= j; i++)
            {
                printf("\n%d ) Split : ", i + 1);
                display(f[i]);
            }
            printf("\n\n");
            system("pause");
            system("cls");
        }
        break;

        case 3:
            exit(0);
        default:
            printf("\nEnter correct choice\n");
            break;
        }
    }
}
