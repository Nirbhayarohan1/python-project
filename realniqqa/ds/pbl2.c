#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <limits.h> 
#define MAX_DOCS 100 
#define MAX_WORDS 50 
#define MAX_LEN 100 
typedef struct { 
char content[MAX_LEN]; 
char keywords[MAX_WORDS][MAX_LEN]; 
int keyword_count; 
} Document; 
// Global variables 
Document docs[MAX_DOCS]; 
int similarity[MAX_DOCS][MAX_DOCS]; 
int doc_count = 0; 
// Function prototypes 
void addDocument(); 
int calculateSimilarity(char keywords1[MAX_WORDS][MAX_LEN], 
int count1, char keywords2[MAX_WORDS][MAX_LEN], int count2); 
void computeSimilarityMatrix(); 
void primMST(); 
void displayClusters(); 
void reportKeywords(); 
// Function to add a document 
void addDocument() { 
if (doc_count >= MAX_DOCS) { 
printf("Maximum document limit reached!\n"); 
return; 
} 
printf("Enter document content: "); 
getchar(); // Clear buffer 
fgets(docs[doc_count].content, MAX_LEN, stdin); 
    docs[doc_count].content[strcspn(docs[doc_count].content, "\n")] = 0; 

    printf("Enter number of keywords: "); 
    scanf("%d", &docs[doc_count].keyword_count); 

    printf("Enter keywords (space-separated): "); 
    getchar(); // Clear buffer 
    for (int i = 0; i < docs[doc_count].keyword_count; i++) { 
        scanf("%s", docs[doc_count].keywords[i]); 
    } 

    doc_count++; 
} 

// Function to calculate similarity between two documents 
int calculateSimilarity(char keywords1[MAX_WORDS][MAX_LEN], 
int count1, char keywords2[MAX_WORDS][MAX_LEN], int count2) { 
    int common = 0; 
    for (int i = 0; i < count1; i++) { 
        for (int j = 0; j < count2; j++) { 
            if (strcmp(keywords1[i], keywords2[j]) == 0) { 
                common++; 
            } 
        } 
    } 
    return common; 
} 

// Function to compute similarity matrix 
void computeSimilarityMatrix() { 
    for (int i = 0; i < doc_count; i++) { 
        for (int j = 0; j < doc_count; j++) { 
            if (i != j) { 
                similarity[i][j] = calculateSimilarity(docs[i].keywords, 
docs[i].keyword_count, 
docs[j].keywords, 
docs[j].keyword_count); 
            } else { 
                similarity[i][j] = 0; 
            } 
        } 
    } 
} 
// Function to implement Prim's algorithm for MST 
void primMST() { 
    int parent[MAX_DOCS]; 
    int key[MAX_DOCS]; 
    int mstSet[MAX_DOCS]; 

    for (int i = 0; i < doc_count; i++) { 
        key[i] = INT_MAX; 
        mstSet[i] = 0; 
    } 

    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < doc_count - 1; count++) { 
        int min = INT_MAX, u; 

        for (int v = 0; v < doc_count; v++) { 
            if (mstSet[v] == 0 && key[v] < min) { 
                min = key[v]; 
                u = v; 
            } 
        } 

        mstSet[u] = 1; 

for (int v = 0; v < doc_count; v++) { 
            if (similarity[u][v] && mstSet[v] == 0 && similarity[u][v] < 
key[v]) { 
                parent[v] = u; 
                key[v] = similarity[u][v]; 
            } 
        } 
    } 

    printf("\nMST (Minimum Spanning Tree):\n"); 
    for (int i = 1; i < doc_count; i++) { 
        printf("Document %d - Document %d (Similarity: %d)\n", 
parent[i] + 1, i + 1, similarity[i][parent[i]]); 
    } 
} 

// Function to display clustered groups (simple approach) 
void displayClusters() { 
    printf("\nClustered Groups (Based on MST):\n"); 
    for (int i = 0; i < doc_count; i++) { 
        printf("Document %d: %s\n", i + 1, docs[i].content); 
    } 
} 
// Function to report most common keywords 
void reportKeywords() { 
    printf("\nMost Common Keywords:\n"); 
    for (int i = 0; i < doc_count; i++) { 
        printf("Document %d: ", i + 1); 
        for (int j = 0; j < docs[i].keyword_count; j++) { 
            printf("%s ", docs[i].keywords[j]); 
        } 
        printf("\n"); 
    } 
} 

// Main function 
int main() { 
    int choice; 
while (1) { 
        printf("\n--- Document Clustering System ---\n"); 
        printf("1. Add Document\n"); 
        printf("2. Compute Similarity Matrix\n"); 
        printf("3. Generate Clusters (MST)\n"); 
        printf("4. Display Clusters\n"); 
        printf("5. Generate Keyword Report\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch (choice) { 
            case 1: 
                addDocument(); 
                break; 
            case 2: 
                computeSimilarityMatrix(); 
                printf("Similarity matrix computed successfully!\n"); 
                break;
            case 3: 
                primMST(); 
                break; 
            case 4: 
                displayClusters(); 
                break; 
            case 5: 
                reportKeywords(); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
return 0; 
}