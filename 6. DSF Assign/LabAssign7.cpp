#define infinity 9999
#define MAX 20
#include <iostream>
using namespace std;

typedef struct edge
{
    int s,d,w;
}edg;

class graph
{
    
    int G[MAX][MAX];
    int n;
    int set[20][20],cnt[20];
    int noe;
    public:
        graph()
        {
            n=0;
        }
        void readgraph();
        void printgraph();
        void edgelist();
        edg e[100];
        void selection_sort(edg e[100], int n);
        
        int kruskal(graph &);
        int findset(int);    
};

void graph::readgraph()
{
    int i,j,vi,vj,weight;
	cout<<"\nEnter no. of vertices : ";
	cin>>n;
	cout<<"\nEnter no. of edges : ";
	cin>>noe;
	for(i=0;i<n;i++)            // Initialize 
		for(j=0;j<n;j++)
			G[i][j] = 0;
			
	for(i=0;i<noe;i++)
	{
	    cout<<"\nEnter an edge (src,dest,weight): ";
		cin>>vi>>vj>>weight;
		G[vi][vj] = G[vj][vi] = weight;
	}
}

void graph::printgraph() 
{
	
	int i,j;
	cout<<"\nList of edges : ";
	for(i=0;i<n-1;i++)     //Scan the upper triangle of the adjacency matrix
		for(j=i+1;j<n;j++)
			if(G[i][j]!=0)
				cout<<"\n(src,dest,weight) = ("<<i<<","<<j<<","<<G[i][j]<<")";
}

void graph::edgelist()
{
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(G[i][j]!=0)
            {
                e[k].s=i;
                e[k].d=j;
                e[k].w=G[i][j];
                k++;
            }
        }
    }
    cout<<"src\tdes\twght\n";
    for(i=0;i<k;i++)
    {
        cout<<e[i].s<<"\t";
        cout<<e[i].d<<"\t";
        cout<<e[i].w<<"\n";
    }
    selection_sort(e,k);
}

void graph::selection_sort(edg e[100], int n)
{
    int temp=0,min=0,j,pos=0,k,i,mins=0,temps=0,tempd=0;
    edg tempe, mine;
    for(i=0;i<n;i++)
    {
        mine=e[i];pos=i;
        for(j=i+1;j<n;j++)
        {
            if(e[j].w<mine.w)
            {
                mine=e[j];
                pos=j;
            }
        }
        tempe=e[i];
        e[i]=mine;
        e[pos]=tempe;
    }
    
    cout<<"\nElements sorted are ";
    for(k=0;k<n;k++)
    {
        cout<<"\n"<<e[k].s<<"\t"<<e[k].d<<"\t"<<e[k].w;
    }
}

int graph::findset(int x)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<cnt[i];j++)
        {
            if(x==set[i][j])
            {
                return i;
            }
        }
    }
    return -1;
}

int graph::kruskal(graph &mst)
{
    int i,j,min_cost=0;
    edgelist();
    for(i=0;i<n;i++)
    {
        set[i][0]=i;
        cnt[i]=1;
    }
    cout<<"\nList of new edges : \n";
    for(i=0;i<noe;i++)
    {
        int p1=findset(e[i].s);
        int p2=findset(e[i].d);
        if(p1!=p2)
        {
            mst.G[e[i].s][e[i].d]=e[i].w;
            mst.G[e[i].d][e[i].s]=e[i].w;
            min_cost=min_cost + e[i].w;
            cout<<e[i].s<<"\t"<<e[i].d<<"\t"<<e[i].w<<"\n";
            
            for(j=0;j<cnt[p2];j++)
            {
                set[p1][cnt[p1]]=set[p2][j];
                cnt[p1]++;
            }
            cnt[p2]=0;
        }
    }
    return min_cost;
}

int main()
{
    int opt,total_cost;
    graph g,mst;
    do{
        cout<<"\n\n1.Read\n2.Kruskal Algo\n3.Exit\n";
        cout<<"Enter your choice : ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            g.readgraph();
            break;
            
            case 2:
            total_cost=g.kruskal(mst);
            cout<<"Minimum Cost is : "<<total_cost<<endl;
            break;
        }
    }while(opt!=3);
return 0;
}