/*
Identify symmetric pairs within an array of pairs. Symmetric pairs consist of two pairs (a, b)
and (c, d) where c equals b and a equals d. For instance, (1, 2) and (2, 1) represent a
symmetric pair. This task involves finding all such symmetric pairs within the given array, with
the assumption that the first elements of all pairs are distinct.
*/

#include<stdio.h>
#include<stdlib.h>

struct pair{
    int first;
    int second;
};

// find number of symmetric pair
void findSymmetricPairs(struct Pair pairs[], int size) {
    int count = 0;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(pairs[i].first == pairs[j].second && pairs[i].second == pairs[j].first){
                count++;
            }
        }
    }
    printf("Number of symmetric pairs: %d\n", count);
}

int main(){
   //take pairs from user
    int size;
    printf("Enter the number of pairs: ");
    scanf("%d", &size);

    struct Pair pairs[size];
    printf("Enter the pairs: ");
    for(int i = 0; i < size; i++){
        scanf("%d %d", &pairs[i].first, &pairs[i].second);
    }
    
    findSymmetricPairs(pairs, size);
    
    return 0;
}

