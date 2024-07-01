#include <stdio.h>

#define TSize 11
#define Prime 7

int hash1(int key) {
    return key % TSize;
}

int hash2(int key) {
    return Prime - (key % Prime);
}

void insert(int hashTable[], int key) {
    int index = hash1(key);
    int stepSize = hash2(key);

    while (hashTable[index] != -1) {
        index = (index + stepSize) % TSize;
    }
    hashTable[index] = key;
}
void printTable(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TSize; i++) {
        if (hashTable[i] != -1)
            printf("%d: %d\n", i, hashTable[i]);
        else
            printf("%d: \n", i);
    }
}

int main() {
    int hashTable[TSize];
    for (int i = 0; i < TSize; i++) {
        hashTable[i] = -1;
    }

    int keys[] = {15, 20, 114, 189, 119, 165, 19, 152, 53, 165, 102};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }
    printTable(hashTable);

    return 0;
}
