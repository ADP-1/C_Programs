#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int DATA[MAX_SIZE];  // Array to store node data
int LINK[MAX_SIZE];  // Array to store next node indices
int start = -1;      // Index of the first node in the linked list
int Avail = 0;       // Index to manage available nodes in the array

void traversing() {
    int PTR = start;
    printf("Linked List: ");
    while (PTR != -1) {
        printf("%d -> ", DATA[PTR]);
        PTR = LINK[PTR];
    }
    printf("NULL\n");
}

void countLink() {
    int ptr = start;
    int COUNT = 0;
    while (ptr != -1) {
        COUNT++;
        ptr = LINK[ptr];
    }
    printf("Number of Nodes: %d\n", COUNT);
}

int search(int ITEM) {
    int ptr = start;
    while (ptr != -1 && DATA[ptr] != ITEM) {
        ptr = LINK[ptr];
    }
    return (ptr != -1 && DATA[ptr] == ITEM) ? ptr : -1;
}

void insertSpecific(int Item, int Pos) {
    if (Avail == -1) {
        printf("Overflow: Linked list is full.\n");
        return;
    }
    
    int new_node = Avail;
    Avail = LINK[Avail];  // Update Avail to next available node
    
    if (Pos == 1) {
        LINK[new_node] = start;
        start = new_node;
    } else {
        int ptr = start;
        int count = 1;
        while (count < Pos - 1 && ptr != -1) {
            ptr = LINK[ptr];
            count++;
        }
        if (ptr == -1) {
            printf("Invalid position to insert.\n");
            return;
        }
        LINK[new_node] = LINK[ptr];
        LINK[ptr] = new_node;
    }
    DATA[new_node] = Item;
}

void insert_at_first(int item) {
    insertSpecific(item, 1);
}

void insert_at_End(int item) {
    int pos = 1;
    int ptr = start;
    while (ptr != -1) {
        ptr = LINK[ptr];
        pos++;
    }
    insertSpecific(item, pos);
}


void delete_Specific(int loc, int ploc) {
    if (start == -1) {
        printf("Underflow: Linked list is empty.\n");
        return;
    }
    if (ploc == -1) {
        start = LINK[start];
    } else {
        LINK[ploc] = LINK[loc];
    }
    LINK[loc] = Avail;
    Avail = loc;
}

void del_First() {
    delete_Specific(start, -1);
}

void del_Last() {
    if (start == -1) {
        printf("Underflow: Linked list is empty.\n");
        return;
    }
    int loc = start;
    int ploc = -1;
    while (LINK[loc] != -1) {
        ploc = loc;
        loc = LINK[loc];
    }
    if (ploc == -1) {
        start = LINK[start];
    } else {
        LINK[ploc] = -1;
    }
    LINK[loc] = Avail;
    Avail = loc;
}

void del_item(int Item) {
    int ploc = -1;
    int loc = start;
    while (loc != -1 && DATA[loc] != Item) {
        ploc = loc;
        loc = LINK[loc];
    }
    if (loc == -1) {
        printf("Item %d not found in the linked list.\n", Item);
        return;
    }
    if (ploc == -1) {
        start = LINK[loc];
    } else {
        LINK[ploc] = LINK[loc];
    }
    LINK[loc] = Avail;
    Avail = loc;
    printf("Item %d deleted from the linked list.\n", Item);
}

int main() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        LINK[i] = i + 1;  // Initialize all LINKs to point to the next index
    }
    LINK[MAX_SIZE - 1] = -1;  // Last LINK points to -1 indicating end of list

    int choice, item, pos;
    while (1) {
        printf("\n\n1. Display\n2. Count Nodes\n3. Search\n4. Insert At Beginning\n5. Insert At End\n6. Insert At Specific Position\n7. Delete the First Node\n8. Delete the Last Node\n9. Delete Specific Node\n10. Delete Node By its Data\n11. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traversing();
                break;

            case 2:
                countLink();
                break;

            case 3:
                printf("Enter the value to be Searched: ");
                scanf("%d", &item);
                pos = search(item);
                if (pos != -1) {
                    printf("Item found at position %d.\n", pos + 1);
                } else {
                    printf("Item not found in the linked list.\n");
                }
                break;

            case 4:
                printf("Enter the value to Insert at Start: ");
                scanf("%d", &item);
                insert_at_first(item);
                break;

            case 5:
                printf("Enter the value to Insert at End: ");
                scanf("%d", &item);
                insert_at_End(item);
                break;

            case 6:
                printf("Enter the position of node to insert: ");
                scanf("%d", &pos);
                printf("Enter the Data to insert in node: ");
                scanf("%d", &item);
                insertSpecific(item, pos);
                break;

            case 7:
                del_First();
                break;

            case 8:
                del_Last();
                break;

            case 9:
                printf("Enter the position of node: ");
                scanf("%d", &pos);
                delete_Specific(pos - 1, -1);  // Convert position to zero-indexed
                break;

            case 10:
                printf("Enter the Node's Item: ");
                scanf("%d", &item);
                del_item(item);
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
