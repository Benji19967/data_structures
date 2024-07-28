// typedef struct KV_Pair {
//   int key;
//   int value;
// } KV_Pair;

typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

void sll_print(Node *curr);
void sll_print_one_line(Node *curr);
void sll_push(Node *head, int key, int val);
Node *sll_peek(Node *head);
Node *sll_contains_key(Node *head, int key);
