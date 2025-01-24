/*
SCT221-0207/2023 -- Marylyne Nashipae
SCT221-0181/2023 -- Brian Kyalo Kimanzi
SCT221-0522/2022 -- Kaguchia Kago 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 200

// A Huffman tree node
struct Minimum_heap_node {
    char character;           // Character
    unsigned freq;       // Frequency of the characters
    struct Minimum_heap_node *left, *right; // Left and right child
};

// A MinHeap structure
struct Minimum_heap {
    unsigned size;       // Current size of heap
    unsigned capacity;   // Maximum capacity of  heap
    struct Minimum_heap_node** array; // Array of heap nodes
};

// Allocate a new node
struct Minimum_heap_node* newNode(char data, unsigned freq) {
    struct Minimum_heap_node* temp = (struct Minimum_heap_node*)malloc(sizeof(struct Minimum_heap_node));
    temp->character = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min-heap
struct Minimum_heap* createMinHeap(unsigned capacity) {
    struct Minimum_heap* minHeap = (struct Minimum_heap*)malloc(sizeof(struct Minimum_heap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Minimum_heap_node**)malloc(minHeap->capacity * sizeof(struct Minimum_heap_node*));
    return minHeap;
}

// Swap two min-heap nodes
void swapMinHeapNode(struct Minimum_heap_node** a, struct Minimum_heap_node** b) {
    struct Minimum_heap_node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function
void minHeapify(struct Minimum_heap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extract minimum value node from the heap
struct Minimum_heap_node* extractMin(struct Minimum_heap* minHeap) {
    struct Minimum_heap_node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    -- minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the heap
void insertMinHeap(struct Minimum_heap* minHeap, struct Minimum_heap_node* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build a min-heap
void buildMinHeap(struct Minimum_heap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Check if a node is a leaf
int isLeaf(struct Minimum_heap_node* root) {
    return !(root->left) && !(root->right);
}

// Create and build a min-heap
struct Minimum_heap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct Minimum_heap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman tree
struct Minimum_heap_node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Minimum_heap_node *left, *right, *top;
    struct Minimum_heap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print Huffman codes
void printCodes(struct Minimum_heap_node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman Codes
void HuffmanCodes(char data[], int freq[], int size) {
    struct Minimum_heap_node* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}


int main() { 
    int size; 

    printf("Enter the number of characters: "); 
    scanf("%d", &size); 
    char characters[size]; 
    int freq[size]; 

    printf("Enter the characters and their frequencies:\n"); 
    for (int i = 0; i < size; i++) { 

        printf("Character %d: ", i + 1); 
        scanf(" %c", &characters[i]); 
        printf("Frequency of %c: ", characters[i]); 
        scanf("%d", &freq[i]); 

        } 

    printf("Huffman Code for the given data are:\n"); 

    HuffmanCodes(characters, freq, size);

    return 0;
}

