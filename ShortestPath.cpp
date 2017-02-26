#include<iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int toPath[]={6};//array for path

struct memoarray {
    int value;
    int direction;
};
memoarray memo[rows][cols]={0};

int cost(int i, int j){ // i is the row, j is the column
	int weight[rows][cols]={
	     {3,4,1,2,8,6},
	     {6,1,8,2,7,4},
	     {5,9,3,9,9,5},
	     {8,4,1,3,2,6},
	     {3,7,2,8,6,4}}; 

//base case
	if(j==0)
	    return weight[i][0]; 
	if(memo[i][j].value!=0){
            return memo[i][j].value;
	}
// recursive call
	int left = weight[i][j]+cost(i,j-1);
	int up =  weight[i][j]+cost(i-1>=0?i-1:rows-1,j-1);
	int down = weight[i][j]+cost(i+1<=rows-1?i+1:0,j-1);

// find the value of the shortest path through cell (i,j)

	int min = left;
	if(up<min){//check if up is smaller
            min=up;
            memo[i][j].direction=-1;//change direction accordingly
        }
 
	if(down<min){//check if down is smaller
            min=down;
            memo[i][j].direction=1;//change direction accordingly
   	}
    return memo[i][j].value=min;//put minimum cost in memo array
}

int main(){
   int ex[rows];
	// get the shortest path out of each cell on the right
	for( int i=0; i<rows; i++){
	    ex[i]=cost(i,cols-1);
	}
	// now find the smallest of them
	 int min=ex[0];
    
	for(int i=1; i<rows;i++)
            if(min>ex[i]){
            min=ex[i];
            toPath[0]=i;//find minimum end row
            }
	int j=6;        //j will be the row number
	for(int k=1;k<6;k++){
            toPath[k]=toPath[k-1]+ memo[toPath[k-1]][--j].direction;
	}

	cout<<"the shortest path is of length "<<min<<" and it costs: "<<endl;
	for(int g=5;g>=0;g--){
        cout<<toPath[g]<<",";
        }
        cout<<endl;
        
        return 0;
}
