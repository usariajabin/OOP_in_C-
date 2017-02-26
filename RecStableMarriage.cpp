#include <iostream>
#include<cmath>

using namespace std;

bool ok(int q[], int col) {
    int mp[3][3]={0,2,1,
                0,2,1,
                1,2,0};
    int wp[3][3]={2,1,0,
                0,1,2,
                2,0,1};
    
    int nm = col,    //new man
    nw = q[col]; //new woman
    
    for (int i = 0; i < col; ++i) {
        int cm = i,    //current man
        cw = q[i]; //current woman
        if(cw==nw) return false;
        if((mp[cm][nw]<mp[cm][cw])&&(wp[nw][cm]<wp[nw][nm])) return false;
        if((mp[nm][cw]<mp[nm][nw])&&(wp[cw][nm]<wp[cw][cm])) return false;
     
    }
    return true;
}

void print(int q[]){
       int i,j;
       cout<<"Man"<<"  "<<"Woman"<<endl;
       for( i=0;i<3;i++){
          cout<<" "<<i<<"     "<<q[i]<<endl;
       }
}

void move(int* q, int i){
         if(i==3){
             print(q);
             return;
         }

         for(int j=0;j<3;j++){ 
             q[i]=j;
             if(ok(q,i))
             move(q,i+1);
         }

}
int main(){
	int q[8];

	move(q,0);

	return 0;
}
