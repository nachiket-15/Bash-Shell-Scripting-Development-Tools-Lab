#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int prn;
    char name[25];
    struct Node *next;
};

void print(struct Node *president)
{
    printf("Hackathon club is: \n");
    int count = 0;
    struct Node *ptr = president;
    while (ptr != NULL)
    {
        printf("%d - %s    ", ptr->prn, ptr->name);
        ptr = ptr->next;
        count++;
    }
    printf("\n\nTotal Members in Hackathon Club are %d\n", count);
}

void insert_between(struct Node *president, int position, char name[], int prn)
{
    int count = 1;
    struct Node *ptr = president;
    while (count < position)
    {
        count++;
        ptr = ptr->next;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newnode->name, name);
    newnode->prn = prn;

    struct Node *store = ptr->next;
    ptr->next = newnode;
    newnode->next = NULL;
    newnode->next = store;
}

void insert_secretary(struct Node *president, char name[], int prn)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newnode->name, name);
    newnode->prn = prn;
    newnode->next = NULL;
    struct Node *temp = president;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}


void delete_secretary(struct Node *president)
{
    if (president == NULL)
    {
        printf("List is already empty");
    }
    else if (president->next == NULL)
    {
        free(president);
        president = NULL;
    }
    else
    {
        struct Node *current = president;
        struct Node *prev = president;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        current = NULL;
    }
}

void delete_president(struct Node**president){
    struct Node *ptr = *president;
    *president = ptr->next;
    free(ptr);
    ptr = NULL;
}

void delete_member_at_position(struct Node *president, int position){

        struct Node*current=president;
        struct Node*prev=president;
        int count=1;
        while(count<=position){
            prev=current;
            current=current->next;
            count++;
        }
        prev->next=current->next;
        free(current);
        current=NULL;
    
}
int main()
{
    printf("Enter the Name of President: \n");
    char name[25];
    scanf("%s", name);

    printf("Enter the PRN of president: \n");
    int prn;
    scanf("%d", &prn);
    
    struct Node *president = (struct Node *)malloc(sizeof(struct Node));
    president->prn = prn;
    strcpy(president->name, name);
    president->next = NULL;

    printf("Enter the name of Secretary: \n");
    char sec[25];
    scanf("%s", sec);

    printf("Enter the PRN of Secretary: \n");
    int prn_sec;
    scanf("%d", &prn_sec);

    insert_secretary(president, sec, prn_sec);

    insert_between(president, 1, "Virat", 112103043);
    insert_between(president, 2, "Rohit", 112103012);
    insert_between(president, 3, "Jasprit", 112103047);
    insert_between(president, 4, "Rahul", 112103114);
    insert_between(president, 5, "Suryakumar", 112103030);
    printf("\n");
    print(president);

    delete_secretary(president);
    printf("\nAfter deleting Secretary Club is:\n");
    print(president);


    delete_president(&president);
    printf("\nAfter deleting President Club is:\n");
    print(president);

    printf("\nEnter a position to delete member at that position:\n");
    int no;scanf("%d",&no);

    delete_member_at_position(president,no);
    printf("\nHackathon Club after deletion at %d :\n",no);
    print(president);

    return 0;
}
