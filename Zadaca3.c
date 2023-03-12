#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void deleteTree(struct node* node) {
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    printf("Deleting node: %d\n", node->data);
    free(node);
}

int main() {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node*)malloc(sizeof(struct node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct node*)malloc(sizeof(struct node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    deleteTree(root);
    root = NULL;

    return 0;
}
/*Функцијата deleteTree го прима коренот на дрвото како аргумент. Преку рекурзија,
 функцијата се повикува самата себе за да ги избрише јазлите во левото и десното поддрво. 
 Откако ќе ги избрише сите јазли во поддрвата, функцијата го брише и коренот на дрвото. 
 Ова е рекурзивен процес што се повторува се додека не се избришат сите јазли во дрвото.
прво создаваме корен на дрвото и додаваме два јазли во неговото лево и десно поддрво.
ја повикуваме функцијата deleteTree за да ги избришеме јазлите во дрвото, и го поставуваме коренот на NULL.*/