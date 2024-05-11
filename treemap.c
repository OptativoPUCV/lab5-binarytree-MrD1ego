#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    TreeMap * tree = (TreeMap *) malloc(sizeof(TreeMap));

    tree->root = NULL;
    tree->current = NULL;
    tree->lower_than = lower_than;
    
    //new->lower_than = lower_than;
    return tree;
    return NULL;
}


void insertTreeMap(TreeMap * tree, void* key, void * value)
{
    TreeNode *parent = NULL;
    TreeNode *current = tree->root;

    while (current != NULL) {
        if (is_equal(tree, current->pair->key, key)) {
            return;
        } else if (tree->lower_than(key, current->pair->key)) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    TreeNode *new_node = createTreeNode(key, value);
    if (new_node == NULL) {
        return;
    }

    if (parent == NULL) {
        tree->root = new_node;
    } else if (tree->lower_than(key, parent->pair->key)) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    tree->current = new_node;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}

Pair * minimum(void* key)
{
    return NULL;
}


Pair * searchTreeMap(TreeMap * tree, void* key) {

    TreeNode *current = tree->root;
    while (current != NULL) 
    {
        if (is_equal(tree, current->pair->key, key)) 
        {
            tree->current = current;
            return current->pair;
        } 
        else if (tree->lower_than(key, current->pair->key)) 
        {
            current = current->left;
        }
        else 
        {
            current = current->right;
        }
    }
    tree->current = NULL;
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
