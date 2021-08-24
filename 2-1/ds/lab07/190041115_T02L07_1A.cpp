#include <iostream>
#include <cstdlib>
using namespace std;

const int mx = 1e5+10;

int arr[mx];	
int tree[mx*3];

void init(int node,int b,int e){
	
	if(b==e){ 
		tree[node]=arr[b];
		return;
	}

	int left=node*2, right=left+1, mid=(b+e)/2;

	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e,int i,int j){

	if(i>e || j<b) 
		return 0;

	if(b>=i && e<=j) 
		return tree[node];

	int left=node*2, right=left+1, mid=(b+e)/2;
	int p1=query(left,b,mid,i,j),
		p2=query(right,mid+1,e,i,j);

	return p1+p2;
	
}

void update(int node,int b,int e,int i,int newvalue){

	if(i>e || i<b)
		return;
	if(b>=i && e<=i){
		tree[node]=newvalue; //b>=i && e<=i or e==i
		return;
	}

	int left=node*2, right=left+1, mid=(b+e)/2;

	update(left,b,mid,i,newvalue);
	update(right,mid+1,e,i,newvalue);
	tree[node]=tree[left]+tree[right];

}

void print(int node, int b, int e) {
    if(b == e) {
        cout << tree[node] << " ";
        return;
    }
    int left=node*2, right=left+1, mid=(b+e)/2;

	print(left,b,mid);
	print(right,mid+1,e);
}

int main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin >> arr[i];

    init(1,1,n); 

    int x, a, b;

    while(q--){
        cin >> x;
        if(x == 1) {
            cin >> a;
            cout << query(1, 1, n, a, a) << " (";
            update(1, 1, n, a, 0);
            for(int i = 1; i <= n; i++) {
                cout << query(1, 1, n, i, i) << " ";
            }
            cout << ")\n";
        } else if(x == 2) {
            cin >> a >> b;
            int temp = query(1, 1, n, a, a);
            b += temp;
            update(1, 1, n, a, b);
            /*
            for(int i = 1; i <= n; i++) {
                cout << query(1, 1, n, i, i) << " ";
            }
            */
            print(1, 1, n);
            cout << "\n";
        } else {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}
/*
5
14
1
13
2
*/
