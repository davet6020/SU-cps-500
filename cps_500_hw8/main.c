#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  struct TreeNode {
    int value;
    int cnt;
    struct TreeNode *left;
    struct TreeNode *right;
  };

  struct Tree {
    struct TreeNode *root;
  };

  struct TreeNode *add_min_node(int value, struct TreeNode* Min);
  struct TreeNode *add_node(int value, struct TreeNode* Node);
  int check_bst(struct TreeNode *BST, int min, int max);
  int compare_nodes(struct TreeNode *N1, struct TreeNode *N2);
  struct TreeNode *create_node(int value);
  void del_min(int *arr, int cnt, int min);
  int get_min(int *arr, int cnt);
  void heap_sort(int arr[], int n);
  void make_min_heap(int arr[], int n, int i);
  void print_array(int *arr, int cnt);
  void print_nodes(struct TreeNode *Node, char Side);

int main(void) {
  int j, cnt;

  struct TreeNode *Tree1 = NULL;
  struct TreeNode *Tree2 = NULL;
  if(Tree1 == NULL) {
    Tree1 = create_node(1);  // Always make it 1
  }
  if(Tree2 == NULL) {
    Tree2 = create_node(1);  // Always make it 1
  }

  /* Seed rand with time */
  srand(time(NULL));

  /* Build Tree1 */
  for(int i=0; i<=4; i++) {
    j = rand() % 99 +1;   /* Add 1 so we never gen a node same value as root */
    add_node(j, Tree1);
  }

  /* Build Tree2 */
  for(int i=0; i<=4; i++) {
    j = rand() % 99 +1;
    add_node(j, Tree2);
  }

  printf("========== Question 1 ==========\nT1: ");
  print_nodes(Tree1, 'O');
  printf("\nT2: ");
  print_nodes(Tree2, 'O');
  printf("\n");

  int ans = compare_nodes(Tree1, Tree2);

  if(ans == 1) {
    printf("These trees are isomorphic\n\n");
  } else {
    printf("These trees are not isomorphic\n\n");
  }

  printf("========== Question 2 ==========\n");

  /* Build a tree to test */
  struct TreeNode *BST = NULL;
  if(BST == NULL) {
    BST = create_node(rand() % 99);
  }

  for(int i=0; i<=4; i++) {
    j = rand() % 99;
    add_node(j, BST);
  }

  printf("BST: ");
  print_nodes(BST, 'O');
  printf("\n");

  // ans = check_bst(BST);
  ans = check_bst(BST, 0, 99);

  if(ans == 1) {
    printf("This is a Binary Search Tree\n\n");
  } else {
    printf("This is NOT a Binary Search Tree\n\n");
  }

  printf("========== Question 3 ==========\n");
  /*
    Build an array to test
  */
  int Min_Heap[6] = {1, 2, 4, 5, 3, 6};

  cnt = sizeof(Min_Heap)/sizeof(Min_Heap[0]);
  print_array(Min_Heap, cnt);
  printf("\n");

  /* Get the location of the min value of array Min_Heap */
  int min = get_min(Min_Heap, cnt);

  /* Delete the value at the location of min */
  del_min(Min_Heap, cnt, min);
  cnt--;
  printf("Removed the root node\n");
  print_array(Min_Heap, cnt);

  heap_sort(Min_Heap, cnt);

  print_array(Min_Heap, cnt);
  printf("\n");

} // End of main()


int get_min(int *arr, int cnt) {
  int min = arr[0];
  int tmp = 0;
  for(int i=0; i<cnt; i++) {
    if(arr[i] < min) {
      min = arr[i];
      tmp = i;
    }
  }
  return tmp;
}


void del_min(int *arr, int cnt, int min) {
  cnt--;
  arr[min] = arr[cnt];
}


void heap_sort(int arr[], int node) {
  for(int i=(node/2)-1; i>=0; i--){
    make_min_heap(arr, node, i);
  }

  for(int i=node-1; i>=0; i--) {
    int tmp=arr[0];
    arr[0]=arr[i];
    arr[i]=tmp;
    make_min_heap(arr, i, 0);
  }
}


void make_min_heap(int arr[], int node, int i)  {
  int root = i;
  int Left=(2 * i)+1;
  int Right=(2 * i)+2;

  if(Left < node && arr[Left] < arr[root]){
    root = Left;
  }

  if(Right < node && arr[Right] < arr[root]){
    root = Right;
  }

  /* Next parent */
  if (root != i) {
    int tmp=arr[i];
    arr[i]=arr[root];
    arr[root]=tmp;
    make_min_heap(arr, node, root);
  }
}


/* Add a new node to the tree */
struct TreeNode *add_min_node(int value, struct TreeNode* Min) {
  if(Min == NULL) {
    return create_node(value);
  }

  if(value == Min->value) {
    ++Min->cnt;
    return Min;
  }

  if(value < Min->value) {
    if(Min->left == NULL) {
      Min->left = create_node(value);
      return Min->left;
    } else {
      return add_node(value, Min->left);
    }
  } else {
    if(Min->right == NULL) {
      Min->right = create_node(value);
      return Min->right;
    } else {
      return add_node(value, Min->right);
    }
  }

  return 0;
}


/* Add a new node to the tree */
struct TreeNode *add_node(int value, struct TreeNode* Node) {
  if(Node == NULL) {
    return create_node(value);
  }

  if(value == Node->value) {
    ++Node->cnt;
    return Node;
  }

  if(value < Node->value) {
    if(Node->left == NULL) {
      Node->left = create_node(value);
      return Node->left;
    } else {
      return add_node(value, Node->left);
    }
  } else {
    if(Node->right == NULL) {
      Node->right = create_node(value);
      return Node->right;
    } else {
      return add_node(value, Node->right);
    }
  }

  return 0;
}


int check_bst(struct TreeNode *B, int min, int max) {
  if (B == NULL) {
    return 1;
  }

  if(B->left !=NULL && B->left->value > B->value) {
    return 0;
  }

  if(B->right != NULL && B->right->value < B->value) {
    return 0;
  }

  if (B->value < min || B->value > max) {
    return 0;
  }

  return check_bst(B->left, min, B->value-1) && check_bst(B->right, B->value+1, max);
}


/* Compares each node */
int compare_nodes(struct TreeNode *N1, struct TreeNode *N2) {
  if(N1 == NULL && N2 == NULL) {          /* Both empty so, Equal */
      return 1;
  } else if(N1 == NULL || N2 == NULL) {   /* Only one empty so, Not Equal */
      return 0;
  } else {
      return compare_nodes(N1->left, N2->left) && compare_nodes(N1->right, N2->right);
  }
}


struct TreeNode *create_node(int value) {
  struct TreeNode *temp;
  temp = (struct  TreeNode*) malloc(sizeof(struct TreeNode));
  temp->value = value;
  temp->cnt = 1;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}


/* Print out the nodes of the tree.
  Root node : is 'O'
  Left node : is 'L'
  Right node: is 'R'
*/
void print_nodes(struct TreeNode *Node, char Side) {
  /* List nodes in the left subtree */
  if(Node->left != NULL){
    print_nodes(Node->left, 'L');
  }

  /* Output the current node value */
  for(int i=0; i<Node->cnt; i++) {
    printf("%d:%c, ", Node->value, Side);
  }

  /* List nodes in the right subtree */
  if(Node->right != NULL) {
    print_nodes(Node->right, 'R');
  }
}


void print_array(int *arr, int cnt) {
  printf("Min = {");
  for(int i=0; i<cnt; i++) {
    printf("%d ", arr[i]);
  }
  printf("}\n");
}


