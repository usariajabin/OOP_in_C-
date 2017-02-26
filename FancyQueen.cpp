#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool ok(int q[], int col){
    for(int i=0; i<col; i++)
        if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
            return false;
    return true;
}

void backtrack(int &col){
    col--;//this method goes back one column.
    if(col==-1){
        exit(1);
    }
}

void print(int q[]) {
    static int count =0;
    cout<< ++ count<<endl;
	int i,j,k,l;
    typedef char box[5][7];
    box bb,wb,*board[8][8];
    char ws = char(219);
  
    box bq =
    {
        ws, ws, ws, ws, ws, ws, ws,
        ws, ' ', ws, ' ', ws, ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ws, ws, ws, ws, ws, ws
    };
    
    
    box wq =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ws, ' ', ws, ' ', ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };//end of wq
    for(i=0;i<5;i++)//create the black boxes
        for( j=0;j<7;j++)
        {wb[i][j]=' ';
            bb[i][j]=char(219);
        }
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0){
                if(q[i]==j){
                    board[i][j]=&wq;
                } else {
                    board[i][j]=&wb;
                }
            } else {
                if(q[i]==j){
                    board[i][j]=&bq;
                } else {
                   board[i][j]=&bb;
                }
            }
    
    

  
    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<'_';
    cout<<endl;
 
    for(i=0;i<8;i++)
        for(k=0;k<5;k++)
        {cout<<" "<<char(179); //print left border
            for(j=0;j<8;j++)
                for(l=0;
                    l<7;l++)
                    cout<<(*board[i][j])[k][l];
            cout<<char(179)<<endl; 
        }
    
    cout<<" ";
    for(i=0;i<7*8;i
        ++)
        cout<<char(196);
    cout<<endl;


}
int main(){
    int q[8]; q[0]=0;
    int c=1;
    
    bool from_backtrack=false;
    
    while(true){
        while(c<8){
            
            if(!from_backtrack)q[c]=-1;
            from_backtrack=true;
            
            while(q[c]<8){
                q[c]++;
                
                if(q[c]==8){
                    from_backtrack=true;
                    backtrack(c);
                    break;
                }
                
                if(ok(q,c)){
                    from_backtrack=false;
                    c++;
                    break;
                }
                
            }
            
        }
        print(q);
        from_backtrack=true;
        backtrack(c);
    }
    
    
}
