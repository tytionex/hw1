#include "split.h"
#include <iostream>
using namespace std;

void printNode(struct Node *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->value << ",";
  printNode(node->next);
}

void freeList(struct Node* head)
{
  struct Node* tmp;

  while (head != NULL)
  {
      tmp = head;
      head = head->next;
      delete tmp;
  }

}

int main()
{
  Node *head = NULL;
  Node *odd = NULL;
  Node *even = NULL;

  Node *a = new Node(1, NULL);
  Node *b = new Node(2, NULL);
  Node *c = new Node(3, NULL);
  Node *d = new Node(4, NULL);
  Node *e = new Node(5, NULL);
  Node *f = new Node(6, NULL);
  Node *g = new Node(7, NULL);
  Node *h = new Node(8, NULL);
  Node *i = new Node(9, NULL);

  head = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  g->next = h;
  h->next = i;
  i->next = NULL;
  /*
  Node *i = new Node(9, NULL);
  Node *h = new Node(8, i);
  Node *g = new Node(7, h);
  Node *f = new Node(6, g);
  Node *e = new Node(5, f);
  Node *d = new Node(4, e);
  Node *c = new Node(3, d);
  Node *b = new Node(2, c);
  Node *a = new Node(1, b);
  */

  
  cout << "head presplit: ";
  printNode(head);
  cout << endl;

  split(head, odd, even);

  cout << "head: ";
  printNode(head);
  cout << endl;

  cout << "odd: ";
  printNode(odd);
  cout << endl;

  cout << "even: ";
  printNode(even);
  cout << endl;
  
  freeList(odd);
  freeList(even);
  // cout << a->value << endl;

  //split(head, odd, even);
  return 0;
}