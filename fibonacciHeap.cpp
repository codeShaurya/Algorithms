#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val,degree;
	Node *left,*right,*parent,*child;
	bool mark;	
	Node(int x)
	{
		val=x;degree=0;mark=0;left=right=parent=child=0;
	}
};

class Heap{
    public:
    int n;
    Node *minRoot;map<int,Node*> m;
    Heap(Node* x){
	//n =0;
        x->right=x;x->left=x;
        minRoot=x;n=1;
    }
    Heap(){
        n=0;minRoot=0;
    }
    void Union(Heap h2)
    {   
	    n=n+h2.n;
            Node *min1=this->minRoot,*min2=h2.minRoot;
	    if(!min1){
		minRoot=min2;return;
	    }
	    if(!min2){
		return;
	    }
	    Node *x=min1->left,*y=min2->left; //x - left child in min[H1] and y - left child in min[H2]
	    x->right=min2; min2->left=x;
	    y->right=min1; min1->left=y;
	    min1->val<min2->val?minRoot=min1:minRoot=min2; //making root to minimum element in new heap
    }
    void insert(int a)
    {
		Node* x=new Node(a); // creating node variable
        	m[a]=x;
		x->left=x;x->right=x; 
        	Heap h2(x);	// creating new heap from new node
		Union(h2);      // Union of two heap
    }
    void printHeap(Node* x)
    {
	    if(!x)
		return;
	    Node* it=x;
	    do
            {
		cout<<it->val<<" ";
            	printHeap(it->child);
	    	it=it->right;
	    }while(it!=x);
    }
    void printRootList() // function to print heap's root of all heap trees
    {
        Node* x=minRoot;
        if(!x)return;
	    Node* it=x;
	do{
	    	cout<<it->val<<" ";
	    	it=it->right;
	}while(it!=x);
	cout<<"\n";
    }
    Node* extract_min()
    {
        if(!minRoot){
		cout<<"Heap is EMPTY\n";
		return 0;
	}
	Node* z=minRoot; // stores the min element to return
	Node* it=z->child;//exploring all child and concatenate
	while(it!=0)
        {
            Node* next=DeleteRoot(it);//n--;// deletes child node
            Heap h2(it); // create separate heap tree from deleted child node
	    Union(h2); // concatenate the two heaps
            it->parent=0;
            it=next;
	}
        minRoot=DeleteRoot(z); // deletes minimum element from root list and assign minRoot = z->right
	consolidate();n--;
        m.erase(m.find(z->val));//keep every element distinct
        return z;
    }
    void consolidate()
    {
	Node* a[100];
	for(int i=0;i<100;i++)
	    a[i]=0;
        Node* it=minRoot;
        while(it!=0)
        {
            Node* x=it;int d=x->degree;
            it=minRoot=DeleteRoot(x);
            while(a[d]!=0)
            {
                Node* y=a[d];
                if(x->val>y->val)
			swap(x,y);
                Link(x,y);a[d]=0;d+=1;
            }
            a[d]=x;
        }
        this->minRoot=NULL;
        for(int i=0;i<100;i++)
        {
            if(a[i])
            {
                Heap h2(a[i]);Union(h2);
            }
        }
    }
    void Link(Node* x,Node* y)
    {
        Node* temp=x->child;x->child=y;y->parent=x;
        if(temp){
            y->right=temp;y->left=temp->left;
            temp->left->right=y;
            temp->left=y;
        }
        else {
	    y->right=y;y->left=y;
	}
        x->degree++;
        y->mark=false;
    }
    Node* DeleteRoot(Node* x)
    {
        if(x->right==x)return 0;
        else
        {
            x->left->right=x->right;x->right->left=x->left;
            return x->right;
        }
    }
    void decrease_key(Node* x,int k)
    {
	if(x==NULL)
	{
		cout << "No such value exist to decrease" << endl;
		return;
	}
        if(k>x->val)
        {
            cout<<"ERROR\n";
            return;
        }
	
	int x_val = x->val; // to modified map
        x->val=k;
	m.erase(m.find(x_val)); // modifying map
	m[k] = x; // modifying map
        Node* y=x->parent;
        if(y&&x->val<y->val)
        {
            cut(x,y);
            cascading_cut(y);
        }
        if(x->val<minRoot->val)
        	minRoot=x;
    }
    void cut(Node* x,Node* y)
    {
        Node* temp=DeleteRoot(x);
        y->child=temp;
        //n--;//work_around
        Heap h2(x);Union(h2);
        x->parent=0;x->mark=false;
    }
    void cascading_cut(Node* y)
    {
        Node* z=y->parent;
        if(z)
        {
            if(!y->mark) // if y is unmarked then mark y
            {
                y->mark=true;
            }
            else 
            {
                cut(y,z);
                cascading_cut(z);
            }
        }
    }
    void Delete(Node* x)
    {
        if(!x)
        {
            cout<<"No such element\n";
            return;
        }
        decrease_key(x,INT_MIN);
        Node* z=extract_min();
    }
};
void print(Heap heap)
{
    cout<<"Heap is: ";
    if(!heap.minRoot)cout<<"EMPTY\n";
    else {heap.printHeap(heap.minRoot);cout<<"\n";}
}
int main()
{
    	Heap heap;
    	cout<<"1.INSERT 2.EXTRACT_MIN 3.DECREASE-KEY 4.DELETE 5.PRINT_ROOTLIST 6.PRINT HEAP \n";
	bool flag = false;
	while(1)
	{
		if(flag)
			break;
		int x;
		cin>>x;
		switch(x)
		{
			case 1:
			{
				cout<<"Enter value: ";
				int n;cin>>n;
				heap.insert(n);
				cout<<"Root list is: ";heap.printRootList();
				break;
			}
			case 2:
			{
                		Node* x=heap.extract_min();
                		if(x)cout<<"Min extracted is: "<<x->val<<endl;
                		print(heap);
				break;
			}
		        case 3:
		        {
				int n,k;
				cout<<"Enter current and final value\n";
				cin>>n>>k;
				heap.decrease_key(heap.m[n],k);
				print(heap);
				break;
		        }
		        case 4:
		        {
				int n;
				cout<<"Enter value to be deleted\n";
				cin>>n;
				heap.Delete(heap.m[n]);
				print(heap);
				break;
		        }
			case 5:
			{
				cout <<"Root List is: ";
				heap.printRootList();
				break;
			}
			case 6:
			{
				print(heap);
				break;
			}
			default:
				cout<<"Enter valid option\n";
				flag = true;
			}
	}
	return 0;
}

