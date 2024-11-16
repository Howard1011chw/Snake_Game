#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_


// Define the states that nodes can be in
enum State {
    FOOD, 
    EMPTY,
    SNAKE,
};

// Define the coordinate that node in 
typedef struct {
    int x;
    int y;
}Coor;

// struct that represent a node in the map
typedef struct {
    enum State state;         // State of the node
    Coor coordinates;  // Coordinate of the node
    // Pointers to the nodes in four different direction
    struct Node* up;
    struct Node* down;
    struct Node* left;
    struct Node* right;
} Node;



typedef struct {
    Node* head;  // Pointer to the head of the linked list
    int width;   // Width of the map
    int height;  // Height of the map
} Map;

Map *create_map(int width, int height);
void add_node(Map* map, int x, int y, enum State state);
Node *get_node(Map* map, int x, int y);
State *current_state(Node* node);  
void *change_state(Node* node, State state); 
void free_map(Map* map);

#endif