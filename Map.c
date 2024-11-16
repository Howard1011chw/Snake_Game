#include <stdlib.h>
#include <stdio.h>
#include "Map.h"

// Define the origin of the map
Coor origin = {0, 0};

Map *create_map(int width, int height) {
    Map* map = (Map*)malloc(sizeof(Map));
    if (!map) {
        printf("Unable to allocate memory for Map\n");
        return NULL;
    }

    // Allocate memory for the head node
    map->head = (Node*)malloc(sizeof(Node));
    if (!map->head) {
        printf("Unable to allocate memory for head node\n");
        free(map); // Free previously allocated map
        return NULL;
    }

    // Initialize map properties
    map->height = height;
    map->width = width;

    // Initialize head node
    map->head->state = EMPTY; // Assuming EMPTY is defined elsewhere
    map->head->coordinates = origin;
    map->head->up = NULL;
    map->head->down = NULL;
    map->head->left = NULL;
    map->head->right = NULL;

    return map;
}