// before every C project, you must type #include <stdio.h>
// #include <stdlib.h> is for allocating memory
#include <stdio.h> 
#include <stdlib.h>

// Step 1: Create a blueprint for the node
struct ListNode {
    int val; // introduce integer val for single digit number 0-9
    struct ListNode* next; // pointer to point the next node in the chain
};

// Step 2: Create a system to add the two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // add a temporary dummy node to safely tie the answer on the list
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;

    // now we create a pointer that moves along with the chain
    struct ListNode* curr = &dummyHead;

    // introduce integer carry to track overflow (either 0 or 1)
    int carry = 0;

    // create a while loop to show keep adding columns as long as there are still digits or carry left
    while (l1 != NULL || l2 != NULL || carry != 0) {
        // != is not and || is or
        int sum = carry; // introduce the first column = leftover carry

        // if l1 has a digit, we add it to the current sum and step to its next node
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next; 
        }

        // if l2 has a digit, we add it to our sum and step to the next node
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next; 
        }

        // to identify if there's carry, we divide it by ten (floor function)
        // single digit -> 0, double digit (more than 10) -> 1
        carry = sum / 10;

        // memory allocation system
        // to allocate the memory, we need to manually reserve space in the computer's memory for a new node
        // to know how much memory to reserve, we need to know the size of the data -> sizeof
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10; // store the single digit remainder after dividing by 10
        newNode->next = NULL; // set the remainder to the next point to NULL = 0
        
        // connect the newly created node to the answer chain
        curr->next = newNode;

        // move the pointer forward for our freshly made node
        curr = curr->next;
    }

    // after this process, we need to return everything after the dummy anchor node
    return dummyHead.next;

}

// Step 3: Create a helper function for building new nodes
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Step 4: Create a function to turn typed number into reversed link
struct ListNode* buildListFromInput() {
    int number;
    scanf("%d", &number);
    // to read the input, we use scanf

    // so that the code doesn't crash, when user types 0 return 0
    if (number == 0) {
        return createNode(0);
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    // separate the integer into individual digits from right to left 
    while (number > 0) {
        int digit = number % 10; // taking the last digit
        struct ListNode* newNode = createNode(digit);

        if (head == NULL) {
            head = newNode; // first node 
            tail = head;
        } else {
            tail->next = newNode; // connect new node to the end of chain
            tail = tail->next;
        }

        number = number / 10; // drop the current digit
    }

    return head;
}

// Step 5: Make print function
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

// Step 6: The main trial
int main() {
    printf("--- STARTING REVERSE ADDITION TRIAL ---\n");

    // create function to input the 2 integers
    printf("Enter the first positive number: ");
    struct ListNode* l1 = buildListFromInput();

    printf("Enter the second positive number: ");
    struct ListNode* l2 = buildListFromInput();

    // "call" the reversed link function we made in Step 4
    printf("\n--- CONVERTING TO REVERSED LINKED LISTS ---\n");
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    printf("-------------------------------------------\n");

    // "call" the additional function in Step 2
    struct ListNode* result = addTwoNumbers(l1, l2);

    // print the outcome using function in Step 5
    printf("Output Sum List  : ");
    printList(result);
    printf("-------------------------------------------\n");

    return 0;
}