typedef struct Node {
  int value;
  struct Node *next;
} Node;

void sll_print(Node *curr);
void sll_print_one_line(Node *curr);
void sll_push(Node *head, int val);
int sll_peek(Node *head);
