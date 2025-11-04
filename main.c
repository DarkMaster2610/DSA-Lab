#include <stdio.h>

#define MAX_NODES 100
#define NULL_INDEX -1


typedef struct {
    int data;
    int prev_index;
    int next_index;
} Node;


Node list_nodes[MAX_NODES];


int head_index = NULL_INDEX;
int tail_index = NULL_INDEX;
int free_index = 0;


void initialize_list() {
    head_index = NULL_INDEX;
    tail_index = NULL_INDEX;
    free_index = 0;
    }

int allocate_node() {
    if (free_index < MAX_NODES) {
        return free_index++;
    }
    return NULL_INDEX; // No free nodes available
}

city, we won't reuse slots)
void free_node(int index) {
    // This implementation doesn't track freed slots for reuse,
    // but a more advanced version would manage a "free list."
}

// Function to insert a node at the end of the list
void insert_end(int data) {
    int new_node_index = allocate_node();
    if (new_node_index == NULL_INDEX) {
        printf("Error: List is full.\n");
        return;
    }

    list_nodes[new_node_index].data = data;
    list_nodes[new_node_index].next_index = NULL_INDEX;

    if (head_index == NULL_INDEX) { // List is empty
        list_nodes[new_node_index].prev_index = NULL_INDEX;
        head_index = new_node_index;
        tail_index = new_node_index;
    } else { // List is not empty
        list_nodes[new_node_index].prev_index = tail_index;
        list_nodes[tail_index].next_index = new_node_index;
        tail_index = new_node_index;
    }
}

// Function to delete a node with a specific data value
void delete_node(int data) {
    int current_index = head_index;
    while (current_index != NULL_INDEX) {
        if (list_nodes[current_index].data == data) {
            int prev = list_nodes[current_index].prev_index;
            int next = list_nodes[current_index].next_index;

            // Adjust the links of the adjacent nodes
            if (prev != NULL_INDEX) {
                list_nodes[prev].next_index = next;
            } else { // Deleting the head
                head_index = next;
            }

            if (next != NULL_INDEX) {
                list_nodes[next].prev_index = prev;
            } else { // Deleting the tail
                tail_index = prev;
            }

            free_node(current_index); // In a real implementation, you would reuse this index
            return;
        }
        current_index = list_nodes[current_index].next_index;
    }
    printf("Element %d not found.\n", data);
}

// Function to print the list in forward order
void print_forward() {
    printf("List (forward): ");
    int current_index = head_index;
    while (current_index != NULL_INDEX) {
        printf("%d -> ", list_nodes[current_index].data);
        current_index = list_nodes[current_index].next_index;
    }
    printf("NULL\n");
}

// Function to print the list in reverse order
void print_reverse() {
    printf("List (reverse): ");
    int current_index = tail_index;
    while (current_index != NULL_INDEX) {
        printf("%d -> ", list_nodes[current_index].data);
        current_index = list_nodes[current_index].prev_index;
    }
    printf("NULL\n");
}

int main() {
    initialize_list();

    insert_end(10);
    insert_end(20);
    insert_end(30);
    print_forward();
    print_reverse();

    printf("Deleting 20...\n");
    delete_node(20);
    print_forward();

    printf("Inserting 40...\n");
    insert_end(40);
    print_forward();
    print_reverse();

    return 0;
}
