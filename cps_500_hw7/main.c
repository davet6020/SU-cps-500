#include<stdio.h>
#include<stdlib.h>

#define AZ 26

typedef struct listNode {
	int value;
	struct listNode *next;
}Node;

typedef struct list {
	Node *head;
}List;



/* Driver program to test above functions */
int main() {

	// Question 1
	void q1Pop(struct listNode *head);
	void printLL(struct listNode *node);
	void push(struct listNode **head, int new_val);
	// Question 2
	void popArr(struct listNode *head);
	void printArr(char *arr, int cnt);
	void pushArr(char *arr, char *stackArr, int size, int cnt);
	// Question 3
	void q3Pop(struct listNode *head);
	// Question 4
	void enqueue();
	void dequeue();

	struct listNode* head = NULL;	// Initialize listNode LL

	// Put A-Z on the linked list
	char c;
	for(c='Z'; c>='A'; c--) {
		push(&head, c);
	}

	printf("===== Question 1 =====\n");
	printf("Node A-Z: ");
	printLL(head);

	// Remove Every other node starting with B
	q1Pop(head);

	printf("\nNode Every other node removed: ");
	printLL(head);
	printf("\n\n===== Question 2 =====\n");
	int size = 0;

	char *stackArr = (char*) malloc(100 * sizeof(char));	// If you do not allocate stackArr with malloc it cannot be realloc'd

	char tmpArr[] = {'a', 'b', 'c', 'd', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
							'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};	// Larger than AZ

	size = sizeof(tmpArr)/sizeof(tmpArr[0]);
	pushArr(tmpArr, stackArr, size, (AZ));
	printArr(stackArr, size);
	printf("\n");

	printf("===== Question 3 =====\n");
	head = NULL;	// Initialize listNode LL
	// Put A-E on the linked list
	for(c='E'; c>='A'; c--) {
		push(&head, c);
	}

	printf("Node: ");
	printLL(head);
	printf("\n");
	printf("\nAdding 'Z' to the linked list.\n");
	push(&head, 'Z');
	printLL(head);
	printf("\n");

	printf("\nRemoving most recently added node from the linked list.\n");
	q3Pop(head);
	printf("\n");

	printf("\n===== Question 4 =====\n");

	return 0;
}

	void enqueue() {

	}

	// A gueue is a FIFO, think line at the grocery store.
	// Remove the one that went into the queue first.
	void dequeue() {

	}

// Stacks only remove from one side of the data structure.
// The last one if is the first one off.
// We just added 'Z' so now remove it.
void q3Pop(struct listNode *node) {
	if (node == NULL) {
		return;
	}

	struct listNode *temp;

	temp = node;
	node = node->next;
	free(temp);

	while (node != NULL) {
		printf("%c ", node->value);
		node = node->next;
	}
}


// pop off every other LL node.  I know its not an array but pop makes sense to me.
void q1Pop(struct listNode *head) {
	if (head == NULL) {
		return;
	}

	printf("head: %c\n", head->value);

	struct listNode *prev = head;
	struct listNode *node = head->next;

	while (prev != NULL && node != NULL) {
		prev->next = node->next;
		prev = prev->next;

		if (prev != NULL) {
			free(node);		// Delete old node before moving to next
			node = prev->next;
		}
	}
}


void push(struct listNode **head, int new_val) {
	struct listNode* new_node = (struct listNode*) malloc(sizeof(struct listNode));
	new_node->value = new_val;
	new_node->next = (*head);
	(*head) = new_node;
}


void printLL(struct listNode *node) {
	while (node != NULL) {
		printf("%c ", node->value);
		node = node->next;
	}
}

void pushArr(char *arr, char *stackArr, int size, int cnt) {
	char ch = 'X';

	if(size > cnt) {
		printf("Warning, you are trying to put more elements on the array than is allowed.\n");
		printf("Your data is %d elements long but the array is only %d elements long.\n", size, cnt);
		printf("Extras will be ignored unless you press 'r|R' to resize the array to fit the extras: ");
		scanf("%c", &ch);
	}

	if(ch == 'r' || ch == 'R') {
		// They chose r or T, resize stackArr to be the size of the array they passed in.
		stackArr = (char *)realloc(stackArr, size * sizeof(char));
		cnt = size;
	}

	for(int i=0; i<cnt; i++) {
		stackArr[i] = arr[i];
	}

	printf("\n");
}

void printArr(char *arr, int cnt) {
	printf("arr = {");
	for(int i=(cnt); i>=0; i--) {
		printf("%c ", arr[i]);
	}
	printf("}\n");
}


void q3Push(struct listNode **head, int new_val) {
	struct listNode* new_node = (struct listNode*) malloc(sizeof(struct listNode));
	new_node->value = new_val;
	new_node->next = (*head);
	(*head) = new_node;
}





