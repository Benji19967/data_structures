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
Node *sll_new_node_kv(int key, int value);
Node sll_new_node_stack();
void sll_push_node(Node *head, Node *node);
void sll_append_after_node(Node *head, Node *node);
Node *sll_delete_node(Node *head, Node *node);
Node *sll_find_by_key(Node *head, int key);
Node *sll_peek(Node *head);
void sll_delete(Node **head);

void sll_print(Node *curr);
void sll_print_one_line(Node *curr);
