#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<vector<pii>> g;
#define node priority_queue<pii, vector<pii>, greater<pii>>

struct Node
{
  int key;
  Node *parent;
  Node *child;
  Node *left;
  Node *right;
  int m;
  int d;
  Node(int x)
  {
    key = x;
    parent = NULL;
    child = NULL;
    left = NULL;
    right = NULL;
    m = 0;
    d = 0;
  }
};
class FH
{
public:
  Node *h;
  int n;
  int md;
  Node *min;
  FH();
  void insert(int);
  void concatenate(FH, FH);
  FH unite(FH, FH);
  void extractMin();
  void remove_node(Node *);
  void print();
  node head;
  void consolidate();
  void link(Node *, Node *);
  bool empty()
  {
    return head.empty();
  }
};

FH::FH()
{
  h = NULL;
  min = NULL;
  md = 0;
}

void exchange(Node *x, Node *y)
{
  swap(x->key, y->key);
  swap(x->m, y->m);
  swap(x->d, y->d);
}

void view(Node *x)
{
  if (x == 0)
    return;
  Node *t = x;
  do
  {
    cout << t->key << " ";
    t = t->right;
  } while (t != x);
  cout << endl;
  view(x->child);
}

void FH::print()
{
  Node *i = h;
  if (i == NULL)
  {
    cout << "Heap is empty" << endl;
    return;
  }
  cout << "List\n";
  do
  {
    cout << i->key << " ";
    i = i->right;
  } while (i != h && i->right != NULL);
  cout << endl;
}

void FH::concatenate(FH h1, FH h2)
{
  Node *x = h1.min->left;
  Node *y = h2.min->left;
  x->right = h2.min;
  h2.min->left = x;
  y->right = h1.min;
  h1.min->left = y;
}

void FH::insert(int x)
{
  Node *t = new Node(x);
  t->left = t;
  t->right = t;

  if (this->h == 0)
  {
    this->h = t;
    this->n = 1;
    this->min = t;
    return;
  }
  FH o;
  o.h = t;
  o.n = 1;
  o.min = t;
  concatenate(*this, o);
  (this->n) += 1;
  if (this->min->key > x)
  {
    this->min = t;
  }
  return;
}

FH FH::unite(FH h1, FH h2)
{
  if (h1.h == NULL)
    return h2;
  if (h2.h == NULL)
    return h1;

  concatenate(h1, h2);
  if (h1.min->key > h2.min->key)
    h1.min = h2.min;
  h1.n = h1.n + h2.n;
  return h1;
}

void FH::remove_node(Node *z)
{
  Node *t, *i;
  if (z == this->h)
  {
    Node *lt = h->left;
    this->h = this->h->right;
    lt->right = h;
  }
  else
  {
    t = this->h;
    i = t;
    do
    {
      if (i->right == z)
      {
        i->right = i->right->right;
        i->right->left = i;
      }
      else
        i = i->right;
    } while (i != t);
  }
}

void FH::link(Node *x, Node *y)
{
  remove_node(y);
  print();
  if (x->child == 0)
  {
    x->child = y;
  }
  else
  {
    Node *xcf = x->child;
    Node *xcl = xcf->left;

    y->right = xcf;
    xcf->left = y;
    xcl->right = y;
    y->left = xcl;
  }
  x->child = y;
  x->d = (x->d) + 1;

  y->parent = x;
  y->m = 0;
}

void FH::consolidate()
{
  Node *a[1 + md];
  int i;
  for (i = 0; i < md + 1; i++)
    a[i] = 0;
  Node *t = h;
  do
  {
    Node *x = t;
    int d = x->d;
    while (d < 1 + md && a[d] != 0)
    {
      Node *y = a[d];
      if (x->key > y->key)
      {
        exchange(x, y);
      }
      //                cout<<"Linking "<<x->key<<"  "<<y->key<<endl;

      link(x, y);
      a[d] = 0;
      d = d + 1;
    }
    a[d] = x;
    t = t->right;
  } while (t != h);

  this->min = 0;
  t = h;
  do
  {
    if (this->min == 0 || this->min->key > t->key)
      this->min = t;
    t = t->right;
  } while (t != h);
}

void FH::extractMin()
{
  Node *z = this->min;
  if (z == NULL)
    return;
  Node *t = z->child, *i = t;
  while (i != t)
  {
    insert(i->key);
    i = i->right;
  }
  remove_node(z);
  view(h);
  if (z->right == z)
    this->min = NULL;
  else
  {
    this->min = z->right;
    consolidate();
  }
  this->n = this->n - 1;
}

int main()
{
  int s, n, e, f, x, y, d, i;
  cin >> n >> e;
  g.assign(n + 1, vector<pii>());
  for (i = 0; i < e; i++)
  {
    cin >> x >> y >> d;
    g[x].push_back(make_pair(y, d));
  }
  FH o;
  vector<int> dist(n + 1, INT_MAX);
  cin >> s >> f;
  dist[s] = 0;
  o.head.push(make_pair(dist[s], s));
  while (!o.head.empty())
  {
    pii z = o.head.top();
    o.head.pop();
    int p = z.second;
    for (int j = 0; j < g[p].size(); j++)
    {
      if (z.first + g[p][j].second < dist[g[p][j].first])
      {
        dist[g[p][j].first] = z.first + g[p][j].second;
        o.head.push(make_pair(dist[g[p][j].first], g[p][j].first));
      }
    }
  }
  cout << "Distance= " << dist[f] << endl;
}

/*

4 5
1 2 5
1 3 1
2 4 6
3 4 10
3 2 2
1 4

*/
