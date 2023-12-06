#include "dictionary.h"
#include<cmath>

char tombstone[] = "tombstone";

Dictionary::Dictionary(){
    N = DICT_SIZE;
    A = new struct Entry[N];
    for(int i = 0;i<N;i++){
        A[i].key = nullptr; 
        A[i].value = 0;
    }
};


int Dictionary::hashValue(char key[]){
    int hashValue = 0;
    // compute hash
    int p = 31;
    int i = 0;
    int pow_p = 1;
    while(key[i]!='\0'){
        hashValue += key[i]*pow_p;
        pow_p*=p;
        i++;
    }

    double A = (sqrt(5)-1)/2;
    hashValue = floor(N*(hashValue*A - floor(hashValue*A)));

    return hashValue;
}

int Dictionary::findFreeIndex(char key[]){
    int hash = hashValue(key);
    int original_hash = hash;
    struct Entry* target = A+hash;

    while(target->key!=nullptr){
        if(strcmp(target->key,tombstone)==0){ //checks for tombstone : we treat it as a free index
            break;
        }
        if(hash == 63){ // if we reach the end we want to cycle back to the start of the array
            target = A;
            hash = 0;
        }
        else{
            target = target+1;
            hash = hash+1;
        }
        if(hash == original_hash){
            return -1;
        }
    }
    return hash;
}

struct Entry* Dictionary::get(char key[]){
    int hash = hashValue(key);
    //int original_hash = hash;
    struct Entry* target = A+hash;
    int visited = 0; // Keep track of visited slots
    while (visited < N) {
        if(target->key == nullptr)
            return NULL;
        if (strcmp(target->key, key) == 0)
            return target;
        visited++;
        if (hash==63){
            target = A;
            hash = 0;
        }else{
            target += 1;
            hash++;
        }
    }
    return NULL;
}

bool Dictionary::put(Entry e) {
    int hash = findFreeIndex(e.key);

    if(hash!=-1){
        A[hash] = e;
        return true;
    }
    else
        return false;
    
}

bool Dictionary::remove(char key[]){
    struct Entry* target = get(key);

    if(target==NULL){
        return false;
    }
    else{
        strcpy(target->key, tombstone);
        target->value = 0;
        return true;
    }
    
}

