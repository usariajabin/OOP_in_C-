#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
    int mp[3][3]={0,2,1,
                  0,2,1,
                  1,2,0};
    int wp[3][3]={2,1,0,
                  0,1,2,
                  2,0,1};
bool ok(int q[],int c){
        for(int i=0;i<c;i++){
           if(q[c]==q[i]) return false;
        }
        for(int i=0; i<c;i++){
           if( ( mp[c][q[i]]<mp[c][q[c]] )&& ( wp[q[i]][c]<wp[q[i]][i]) )
                return false;
          if( ( wp[q[c]][i]<wp[q[c]][c] )&& ( mp[i][q[c]]<mp[i][q[i]]) )
                return false;
        }
        return true;
}

void backtrack(int &c){
        c--;
        if(c==-1) return;
}

void print(int q[])
    {
       int i,j;
       cout<<"Man"<<"  "<<"Woman"<<endl;
       for( i=0;i<3;i++)
       {
          cout<<" "<<i<<"     "<<q[i]<<endl;
       }
}
int main(){
        int q[3];
        q[0]=0;
        int c=1;

        bool from_backtrack=false;

        while(1){
            while(c<3){

        if(!from_backtrack)
            q[c]=-1;

        from_backtrack=false;
            while(q[c]<3){
                q[c]++;

        while(q[c]==3)                
             { backtrack(c);
                   q[c]++;

              }

        if (ok(q,c)) break;
        }
        c++;
        }

        print(q); 
     backtrack(c);
     from_backtrack=true;
    }

}

