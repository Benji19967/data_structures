typedef struct Node {
  int value;
  struct Node *next;
} Node;

void print_linked_list(Node *curr);
void print_linked_list_one_line(Node *curr);
void push(Node *head, int val);
