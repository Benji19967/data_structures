typedef struct Node {
  int value;
  struct Node *next;
} Node;

void print_linked_list(Node *curr);
void push(Node *head, int val);
