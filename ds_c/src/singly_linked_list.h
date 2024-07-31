// typedef struct KV_Pair {
//   int key;
//   int value;
// } KV_Pair;

typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

Node *sll_new_node();
Node sll_new_node_stack();
void sll_push_node(Node *head, Node *node);
Node *sll_peek(Node *head);
Node *sll_contains_key(Node *head, int key);
void sll_push(Node *head, int key, int val);
void sll_print(Node *curr);
void sll_print_one_line(Node *curr);
