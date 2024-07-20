#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* key;
    char* value;
    struct node* next;
};

void setNode(struct node* node, const char* key, const char* value) {
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
}

struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

void setHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

int hashFunc(struct hashMap* mp, const char* key) {
    int bucket;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = (sum * factor + key[i]) % mp->capacity;
    }
    bucket = sum;
    return bucket;
}

void insert(struct hashMap* mp, const char* key, const char* value) {
    int bucket = hashFunc(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);
    newNode->next = mp->arr[bucket];
    mp->arr[bucket] = newNode;
}

void dele(struct hashMap* mp, const char* key) {
    int bucket = hashFunc(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucket];
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucket] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

char* search(struct hashMap* mp, const char* key) {
    int bucket = hashFunc(mp, key);
    struct node* bucketHead = mp->arr[bucket];
    while (bucketHead != NULL) {
        if (strcmp(key, bucketHead->key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Key not found";
}

int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    setHashMap(mp);
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("elite_Programmer: %s\n", search(mp, "elite_Programmer"));
    printf("Yogaholic: %s\n", search(mp, "Yogaholic"));
    printf("pluto14: %s\n", search(mp, "pluto14"));
    printf("decentBoy: %s\n", search(mp, "decentBoy"));
    printf("GFG: %s\n", search(mp, "GFG"));
    printf("randomKey: %s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");
    dele(mp, "decentBoy");
    printf("decentBoy: %s\n", search(mp, "decentBoy"));
    return 0;
}
