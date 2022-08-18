#define infinity 9999
#define MAX 20

#include<iostream>
#include<stdlib.h>
using namespace std;

class graph{
	
	int G[MAX] [MAX];
	int n;
	public:
		graph(){
			n = 0;
		}
		void readgraph();
		void printgraph();
		void dijkstra(int start);
		
};

void graph::readgraph(){
	
	int i,j,vi,vj,no_of_edges, weight;
	cout<<"\nEnter no, of vertices: ";
	cin>>n;
	
	for(i=0;i<n;i++){        // Initialize the adjacency matrix
		for(j=0;j<n;j++){
			G[i][j] = 0;
		}
	cout<<"\nEnter no, of edges: ";
	cin>>no_of_edges;
	cout<<"\nEnter the list of edges: ";
	
	for(i=0;i<no_of_edges;i++){
		
		cout<<"\nEnter an edge (src,dest,weight): ";
		cin>>vi>>vj>>weight;
		G[vi][vj] = G[vj][vi] = weight;
	}
}

}

void graph::printgraph() 
{
	
	int i,j;
	cout<<"\nList of edges in the spanning tree: ";
	for(i=0;i<n-1;i++)     //Scan the upper triangle of the adjacency matrix
		for(j=i+1;j<n;j++)
			if(G[i][j]!=0)
				cout<<"\n(src,dest,weight) = ("<<i<<","<<j<<","<<G[i][j]<<")";
			
		
	
}

void graph::dijkstra(int start){
	
	int cost[MAX][MAX];
	int min_distance, distance[MAX],from[MAX];
	int visited[MAX],i,j,cnt=0,nextnode;
	
	// create cost [][] matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			
			if(G[i][j]==0)
				cost[i][j]= infinity;
			
			else
				cost[i][j]=G[i][j];
			
		}
		
		// initialise visited[],distance[] and from[]
		for(i=0;i<n;i++)
		  {
			distance[i]=cost[start][i];
			from[i]= start;
			visited[i]=0;
		  }
		distance[start]=0;visited[start]=1;cnt=1;
		      //no.of vertices to be visited
		while(cnt<=n-1)
		  {
		  	//find the vertex at minimum distance from the tree
		  	min_distance=infinity;
		  	for(i=0;i<n;i++)
		  	    if(visited[i]==0 && distance[i] <min_distance)
				  {
		  	    	nextnode=i;
		  	    	min_distance=distance[i];
				  }
			visited[nextnode]=1;
			//update the distance[] array
			for(i=0;i<n;i++){
				if(visited[i]==0 &&(min_distance+cost[nextnode][i]<distance[i]))
				{
					distance[i]=cost[nextnode][i]+min_distance;
					from[i]=nextnode;
				}
			}
			
			       cnt++;
		  }
		  for(i=0;i<n;i++)
		  {
		  	if(i!=start)
			  {
		  		cout<<"\n distance of "<<i<<" is "<<distance[i];
		  		cout<<"\tpath= "<<i;
		  		j=i;
		  		do{
		  		    j=from[j];
		  			cout<<"<-"<<j;
				  } while(j!=start);
			  }
		  }
		
}
	
int main()
	{
		graph g1;
		int start;
		g1.readgraph();
		cout<<"\n graph is:\n";
		g1.printgraph();
		cout<<"\nEnter start vertex: \n";
		cin>>start;
		g1.dijkstra(start);
		
		return 0;
	}
