#include <iostream>
#include <string>
#include <vector>
using namespace std;

class adjMatrix{
	
	int m[10][10];          //adjacency matrix
	string v[10];           //array to store cities name
	int n;          
	
	public:
		adjMatrix(){
			for(int i=0;i<10;i++){
				v[i]="";
				for(int j=0;j<10;j++){
					m[i][j]=0;
				}
			}
		}
		
		void getgraph();
		void displayMatrix();
		bool is_connected();
		void DFS(int node,vector<bool>& visited);
};

void adjMatrix::getgraph(){
	int t;
	char c;
	cout<<"\nEnter no of cities(max 10):";
	cin>>n;
	cout<<"\nEnter name of cities:";
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"\nIs there exists a path between "<<v[i]<<" city and "<<v[j]<< "(y/n):";
			cin>>c;
			if(c=='y'){
				cout<<"Enter time required from "<<v[i]<<" to reach "<<v[j]<<" city in minutes:";
				cin>>t;
				m[i][j]=t;
			}
			else if(c=='n'){
				m[i][j]=0;
			}
			else{
				cout << "\n unknown entry";
			}
		}

	}
}

void adjMatrix::displayMatrix(){
	for(int i=0;i<n;i++){
		cout<<"\t"<<v[i];		
	}
	for(int i=0;i<n;i++){

		cout<<"\n"<<v[i];
		
		for(int j=0;j<n;j++){
			
			cout<<"\t"<<m[i][j];
		}
		
	}
}

bool adjMatrix::is_connected(){
	vector<bool> visited(n,false);            // Initialize all nodes as not visited
	DFS(0,visited);                          
	//Check if all nodes are visited
	for(int i=0;i<n;i++){
		if(!visited[i])
			return false;
	}
	return true;
}

void adjMatrix::DFS(int node,vector<bool>& visited){
	visited[node]=true;                             //make current node as visited
	for(int i=0;i<n;i++){
		if(m[node][i]!=0 && visited[i]!=true){      //If there is an edge and node is not visited
			DFS(i,visited);             // Recursively visit the adjacent node
		}
	}
}

int main(){
    int m;
    adjMatrix a;

    do{
        cout << "\n\n Enter the choice";
        cout << "\n 1.Enter graph";
        cout << "\n 2.Display adjacency matrix for cities";
        cout << "\n 3.Check if Graph is Connected or not";
        cout << "\n 4.Exit \n";
        cin >> m;

        switch (m)
        {
        case 1:
            a.getgraph();
            break;
        case 2:
            a.displayMatrix();
            break;
        case 3:
        	if(a.is_connected()){
        		cout<<"\nGraph is connected"<<endl;
			}else{
				cout<<"\nGraph is not connected"<<endl;
			}
            break;
        case 4:
            break;
        default:
            cout << "\n unknown choice";
        }
    }while(m!=4);
    
    return 0;
}
