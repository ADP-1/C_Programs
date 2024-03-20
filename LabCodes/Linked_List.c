#include <stdio.h>
#include <stdlib.h>

// Print the Linked List
void traversing(int *DATA, int *LINK, int START)
{
    int PTR = START;
    while (PTR != -1)
    {
        printf("%d -> ", DATA[PTR]);
        PTR = LINK[PTR];
    }
    printf("NULL");
}

void countLink(int *DATA, int *LINK, int START)
{
    int ptr = START;
    int COUNT = 0;
    while (ptr != -1)
    {
        COUNT++;
        ptr = LINK[ptr];
    }
    printf("No of Nodes are: %d\n", COUNT);
}

int search(int *DATA, int *LINK, int START, int ITEM)
{
    int ptr = START;

    while (ptr != -1 && DATA[ptr] != ITEM)
    {
        ptr = LINK[ptr];
    }

    return (ptr != -1 && DATA[ptr] == ITEM) ? ptr : -1;
}

void insertSpecific(int *DATA, int *LINK, int *START, int *AVAIL, int Item, int Pos)
{
    int new_node = *AVAIL;
    *AVAIL = LINK[new_node];
    DATA[new_node] = Item;

    int ptr = *START;
    int count = 1;

    while (count != Pos - 1 && ptr != -1)
    {
        ptr = LINK[ptr];
        count++;
    }

    if (Pos == 1)
    {
        LINK[new_node] = *START;
        *START = new_node;
    }
    else if (ptr != -1)
    {
        LINK[new_node] = LINK[ptr];
        LINK[ptr] = new_node;
    }
    else
    {
        printf("Invalid position to insert\n");
    }
}

void insert_at_first(int *Data, int *Link, int *Start, int *Avail, int item)
{
    int new_node = *Avail;
    *Avail = Link[new_node];
    Data[new_node] = item;
    Link[new_node] = *Start;
    *Start = new_node;
}

void insert_at_End(int *Data, int *Link, int *Start, int *Avail, int item)
{
    int new_node = *Avail;
    *Avail = Link[new_node];
    Data[new_node] = item;
    Link[new_node] = -1;

    if (*Start == -1)
    {
        *Start = new_node;
        return;
    }

    int ptr = *Start;
    while (Link[ptr] != -1)
    {
        ptr = Link[ptr];
    }

    Link[ptr] = new_node;
}

void delete_Specific(int *Data, int *Link, int *Start, int *Avail, int loc, int ploc)
{
    if (*Start == -1)
    {
        printf("UnderFlow");
        return;
    }

    if (ploc == -1)
    {
        *Start = Link[*Start];
    }
    else
    {
        Link[ploc] = Link[loc];
    }

    Link[loc] = *Avail;
    *Avail = loc;
}

void del_First(int *Data, int *Link, int *Start, int *Avail)
{
    if (*Start == -1)
    {
        printf("UnderFlow");
        return;
    }
    int ptr = *Start;
    *Start = Link[*Start];
    Link[ptr] = *Avail;
    *Avail = ptr;
}

void del_Last(int *Data, int *Link, int *Start, int *Avail)
{
    int loc = *Start;
    int ploc = -1;
    while (Link[loc] != -1)
    {
        ploc = loc;
        loc = Link[loc];
    }

    if (ploc == -1)
    {
        *Start = Link[*Start];
    }
    else
    {
        Link[ploc] = -1;
    }

    Link[loc] = *Avail;
    *Avail = loc;
}

void del_item(int *Data, int *Link, int *Start, int *Avail, int Item)
{
    int ploc = -1;
    int loc = -1;
    int ptr = *Start;

    while (ptr != -1)
    {
        if (Data[ptr] == Item)
        {
            loc = ptr;
            break;
        }
        else
        {
            ploc = ptr;
            ptr = Link[ptr];
        }
    }

    if (loc == -1)
    {
        printf("Item not found in the linked list\n");
        return;
    }

    if (ploc == -1)
    {
        *Start = Link[loc];
    }
    else
    {
        Link[ploc] = Link[loc];
    }

    Link[loc] = *Avail;
    *Avail = loc;

    printf("Item %d deleted from the linked list\n", Item);
}

int main()
{
    int DATA[10] = {0};
    int LINK[10] = {0};
    int start = -1;
    int Avail = 0;

    int choice, item, pos;
    while (1)
    {
        printf("\n\n1.Display \n2.Count Nodes \n3.Search \n4.Insert At Beginning \n5.Insert At Last \n6.Insert At Specific. \n7.Delete the First Node \n8.Delete the End Node \n9.Delete Specific Node \n10.Delete Node By its Data\n11.EXIT\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traversing(DATA, LINK, start);
            printf("\n");
            break;

        case 2:
            countLink(DATA, LINK, start);
            printf("\n");
            break;

        case 3:
            printf("Enter the value to be Searched : ");
            scanf("%d", &item);
            search(DATA, LINK, start, item);
            printf("\n");
            break;

        case 4:
            printf("Enter the value to Insert at Start : ");
            scanf("%d", &item);
            insert_at_first(DATA, LINK, &start, &Avail, item);
            printf("\n");
            break;

        case 5:
            printf("Enter the value to Insert at End : ");
            scanf("%d", &item);
            insert_at_End(DATA, LINK, &start, &Avail, item);
            printf("\n");
            break;

        case 6:
            printf("Enter the position of node to insert : ");
            scanf("%d", &pos);
            printf("\n");
            printf("Enter the Data to insert in node : ");
            scanf("%d", &item);
            insertSpecific(DATA, LINK, &start, &Avail, item, pos);
            printf("\n");
            break;

        case 7:
            del_First(DATA, LINK, &start, &Avail);
            printf("\n");
            break;

        case 8:
            del_Last(DATA, LINK, &start, &Avail);
            printf("\n");
            break;

        case 9:
            printf("Enter the position of node : ");
            scanf("%d", &pos);
            delete_Specific(DATA, LINK, &start, &Avail, pos, -1);
            printf("\n");
            break;

        case 10:
            printf("Enter the Node's Item : ");
            scanf("%d", &item);
            del_item(DATA, LINK, &start, &Avail, item);
            printf("\n");
            break;

        case 11:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    // // For Traverse and print the whole Linked List
    // traversing(DATA,LINK,START);

    // // For Searching
    // int searchResult = search(DATA, LINK, START, 80);
    // if (searchResult != -1){
    //     printf("\nItem 80 found at position %d\n", searchResult);
    // }
    // else{
    //     printf("\nItem 80 not found in the linked list\n");
    // }

    // // Inserting A node in it.
    // printf("\nBefore Insertion:\n");
    // traversing(DATA, LINK, START);

    // insertSpecific(DATA, LINK, &START, &AVAIL, 50, 3);

    // printf("\nAfter Insertion:\n");
    // traversing(DATA, LINK, START);

    // // Counting the Nodes
    // int nodeCount = countLink(DATA, LINK, START);
    // printf("\nNumber of nodes in the linked list: %d\n", nodeCount);

    // printf("\nBefore Inserting node at front and end:\n");
    // traversing(DATA, LINK, START);
    // // insertion at the first
    // insert_at_first(DATA ,LINK , &START ,&AVAIL,2);
    // // insertion at the End
    // insert_at_End(DATA, LINK, &START, &AVAIL, 66);

    // printf("\nAfter Inserting :\n");
    // traversing(DATA, LINK, START);

    return 0;
}