/********************************
*Operations on Binary Search Tree
*Using Linked Lists
*********************************/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct queue {
    struct node *data;
    struct queue *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
    }
    else if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node* findMin(struct node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

struct node* findMax(struct node* root) {
    while(root->right != NULL) root = root->right;
    return root;
}

struct node* delete(struct node* root, int data) {
    if(root == NULL) {
        printf("Element not found.\n");
    }
    else if(data < root->data) {
        root->left = delete(root->left, data);
    }
    else if(data > root->data) {
        root->right = delete(root->right, data);
    }
    else {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct node* root) {
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void enqueue(struct queue** front, struct queue** rear, struct node* data) {
    struct queue* newNode = (struct queue*) malloc(sizeof(struct queue));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;

    if(*rear == NULL) {
        *front = *rear = newNode;
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

struct node* dequeue(struct queue** front, struct queue** rear) {
    if(*front == NULL) {
        return NULL;
    }

    struct queue* temp = *front;
    struct node* data = temp->data;
    *front = (*front)->next;

    if(*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    return data;
}

void levelOrder(struct node* root) {
    if(root == NULL) {
        return;
    }

    struct queue* front = NULL;
    struct queue* rear = NULL;
    enqueue(&front, &rear, root);

    while(front != NULL) {
        struct node* temp = dequeue(&front, &rear);
        printf("%d ", temp->data);

        if(temp->left != NULL) {
            enqueue(&front, &rear, temp->left);
        }

        if(temp->right != NULL) {
            enqueue(&front, &rear, temp->right);
        }
    }
}

int height(struct node* root) {
    if(root == NULL) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

struct node* search(struct node* root, int data) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->data == data) {
        return root;
    }
    else if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void printNodeHeights(struct node* node) {
    if (node == NULL)
        return;
    int nodeHeight = height(node);
    printf("Node value: %d, Height: %d\n", node->data, nodeHeight);
    printNodeHeights(node->left);
    printNodeHeights(node->right);
}

void printNodeDepths(struct node* node, int depth) {
    if (node == NULL)
        return;
    printf("Node value: %d, Depth: %d\n", node->data, depth);
    printNodeDepths(node->left, depth + 1);
    printNodeDepths(node->right, depth + 1);
}

int main() {
    struct node* root = NULL;
    int choice, data;

    while(1) {
        printf("\n**************************MAIN MENU**************************");
        printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Level Order\n7. Height of tree\n8. Min\n9. Max\n10. Search\n11. Print Node Heights\n12. Print Node Depths\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Level order traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 7:
                printf("Height of the tree: %d\n", height(root));
                break;

            case 8:
                printf("Minimum value: %d\n", findMin(root)->data);
                break;

            case 9:
                printf("Maximum value: %d\n", findMax(root)->data);
                break;

            case 10:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                struct node* temp = search(root, data);
                if(temp != NULL) {
                    printf("Element found.\n");
                }
                else {
                    printf("Element not found.\n");
                }
                break;

            case 11:
                printf("Node Heights:\n");
                printNodeHeights(root);
                break;

            case 12:
                printf("Node Depths:\n");
                printNodeDepths(root, 0);
                break;

            case 13:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
