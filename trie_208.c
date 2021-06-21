#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //bzero

#define  bool int
#define  true 1
#define  false 0

typedef struct Trie{
    bool isEnd;
    struct Trie *children[26];
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie *ret = malloc(sizeof(Trie));
    bzero(ret, sizeof(Trie));
    ret->isEnd = 1;

    return ret;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int len = strlen(word);

    int index = 0;
    for (index = 0; index < len; index++)
    {
        if (obj->children[word[index] - 'a'] == NULL){
            Trie *node = trieCreate();
            obj->children[word[index] - 'a'] = node;
        }else{
            if (index == len - 1){
                obj->children[word[index] - 'a']->isEnd = 1;
            }
        }
        obj = obj->children[word[index] - 'a'];
    }
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int len = strlen(word);
    int index = 0;
    
    for (index = 0; index < len; index++)
    {
        if (obj->children[word[index] - 'a'] == NULL){
            return false;
        }
        obj = obj->children[word[index] - 'a'];
    }
    if (!obj->isEnd)
        return false;

    return true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    int len = strlen(prefix);
    int index = 0;
    
    for (index = 0; index < len; index++)
    {
        if (obj->children[prefix[index] - 'a'] == NULL){
            return false;
        }
        obj = obj->children[prefix[index] - 'a'];
    }

    return true;
}

void trieFree(Trie* obj) {
    /*从上至下开始free的话 下面的指针无法得到释放 需要保存上面的指针然后从后道前逐个释放 递归 释放*/
    int index = 0;

    for(index = 0; index < 26; index++)
    {
        if (obj->children[index])
            trieFree(obj->children[index]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 
*/

int main()
{
    Trie* obj = trieCreate();
    trieInsert(obj, "app");
    trieInsert(obj, "apple");
    trieInsert(obj, "bob");
    bool param_2 = trieSearch(obj, "apple");
    bool param_5 = trieSearch(obj, "app");
    bool param_3 = trieStartsWith(obj, "bo");
    bool param_4 = trieStartsWith(obj, "boa");
    printf(" %d %d %d %d", param_2, param_3, param_4, param_5);
    trieFree(obj);

    return 0;
}