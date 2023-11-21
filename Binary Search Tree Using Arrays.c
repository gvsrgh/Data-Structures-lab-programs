/********************************
*Operations on Binary Search Tree
*Using Arrays
*********************************/
#include<stdio.h>
#define SIZE 20

int BinarySearchTree[SIZE];

void insert(int data){
    int ptr = 0;
    while(BinarySearchTree[ptr] != 0){
        if(data > BinarySearchTree[ptr])
            ptr = 2*ptr+2;
        else
            ptr = 2*ptr+1;
    }
    BinarySearchTree[ptr] = data;
}

void inorder(int ptr){
    if(BinarySearchTree[ptr] != 0){
        inorder(2*ptr+1);
        printf("%d ",BinarySearchTree[ptr]);
        inorder(2*ptr+2);
    }
}

void preorder(int ptr){
    if(BinarySearchTree[ptr] != 0){
        printf("%d ",BinarySearchTree[ptr]);
        preorder(2*ptr+1);
        preorder(2*ptr+2);
    }
}

void postorder(int ptr){
    if(BinarySearchTree[ptr] != 0){
        postorder(2*ptr+1);
        postorder(2*ptr+2);
        printf("%d ",BinarySearchTree[ptr]);
    }
}

void levelorder(int ptr){
    int queue[SIZE], front = 0, rear = -1, i;
    if(BinarySearchTree[ptr] != 0){
        queue[++rear] = ptr;
        while(front <= rear){
            ptr = queue[front++];
            printf("%d ", BinarySearchTree[ptr]);
            if(BinarySearchTree[2*ptr+1] != 0)
                queue[++rear] = 2*ptr+1;
            if(BinarySearchTree[2*ptr+2] != 0)
                queue[++rear] = 2*ptr+2;
        }
    }
}

int height(int ptr){
    if(BinarySearchTree[ptr] == 0)
        return -1;
    else{
        int leftHeight = height(2*ptr+1);
        int rightHeight = height(2*ptr+2);
        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

int min(int ptr){
    while(BinarySearchTree[2*ptr+1] != 0)
        ptr = 2*ptr+1;
    return BinarySearchTree[ptr];
}

int max(int ptr){
    while(BinarySearchTree[2*ptr+2] != 0)
        ptr = 2*ptr+2;
    return BinarySearchTree[ptr];
}

int search(int data){
    int ptr = 0;
    while(BinarySearchTree[ptr] != 0){
        if(data == BinarySearchTree[ptr])
            return 1;
        else if(data > BinarySearchTree[ptr])
            ptr = 2*ptr+2;
        else
            ptr = 2*ptr+1;
    }
    return 0;
}

int main(){
    int choice, data;
    for(int i=0; i<SIZE; i++)
        BinarySearchTree[i] = 0;
    do{
        printf("\n**************************MAIN MENU**************************");
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Level Order\n6. Height\n7. Min\n8. Max\n9. Search\n10. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                inorder(0);
                break;
            case 3:
                preorder(0);
                break;
            case 4:
                postorder(0);
                break;
            case 5:
                levelorder(0);
                break;
            case 6:
                printf("Height of the tree is %d",height(0));
                break;
            case 7:
                printf("Min element is %d",min(0));
                break;
            case 8:
                printf("Max element is %d",max(0));
                break;
            case 9:
                printf("Enter the data to be searched: ");
                scanf("%d",&data);
                if(search(data))
                    printf("Element found");
                else
                    printf("Element not found");
                break;
        }
    }while(choice != 10);
    return 0;
}
