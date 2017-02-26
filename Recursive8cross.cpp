#include <iostream>
#include <cmath>
using namespace std;

bool ok (int q[], int c){
   static int adj[8][5]= {
        {-1},                 // 0
        {0, -1},              // 1
        {0, 1, -1},           // 2
        {0, 2, -1},           // 3
        {1, 2, -1},           // 4
        {1, 2, 3, 4, -1},     // 5
        {2, 3, 5, -1},        // 6
        {4, 5, 6, -1}         // 7
    };

    for(int i=0;i<c;i++){
        if (q[c]==q[i])
        return false;
    }

    for (int i=0; i<5; i++) {

        if (adj[c][i]==-1)
            break;

        if (q[adj[c][i]]-q[c]==-1||q[adj[c][i]]-q[c]==1)
            return false;
    }
    return true;

}

void print(int q[], int &c){

    static int result=0;
    cout<<"   Solution #"<<++result<<endl;
    cout<<"       "<<q[1]+1<<q[4]+1<<endl;
    cout<<"      "<<q[0]+1<<q[2]+1<<q[5]+1<<q[7]+1<<endl;
    cout<<"       "<<q[3]+1<<q[6]+1<<endl;
    cout<<endl;

}

void move(int *q, int c){
        if(c==8){
            print(q,c);
            return;
        }

        for( int j=0; j<8; j++){
            q[c]=j;
            if(ok(q,c))
            move(q,c+1);
        }
}

int main() {
    int q[8]={0};

    move(q,0);

    return 0;
}


