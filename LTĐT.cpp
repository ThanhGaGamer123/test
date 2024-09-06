#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    //Doc va bieu dien do thi duoi dang ma tran ke
    int a[100][100]={0},n,m;
    ifstream input ("D:/IT/input/dothi.inp");
    ofstream output ("D:/IT/output/dothi.out");
    if(input && output){
        input>>n>>m;
        int index1,index2,index3;
        while(input>>index1){
            input>>index2>>index3;
            a[index1][index2]=index3;
            a[index2][index1]=index3;
        }
        input.close();
        
        for(int i=1;i<=n;i++){ //in ra ma tran ke
            cout<<endl;
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
        }

        //Giai quyet bai toan
        output<<"dinh bac le: ";
        for(int i=1;i<=n;i++){
            int degree=0;
            for(int j=1;j<=m;j++){
                if(a[i][j]!=0) degree++;
            }
            if(degree%2!=0) output<<i<<" ";
        }
        output<<endl<<"dinh bac chan: ";
        for(int i=1;i<=n;i++){
            int degree=0;
            for(int j=1;j<=m;j++){
                if(a[i][j]!=0) degree++;
            }
            if(degree%2==0) output<<i<<" ";
        }
        output<<endl<<"dinh co don: ";
        for(int i=1;i<=n;i++){
            int alone=1;
            for(int j=1;j<=m;j++){
                if(a[i][j]!=0) alone=-1;
            }
            if(alone==1) output<<i<<" ";
        }
        int max=INT_MIN,min=INT_MAX,dinhmax=1,dinhmin=1;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=m;j++){
                sum+=a[i][j];
            }
            if(sum>max){
                max=sum;
                dinhmax=i;
            }
            if(sum<min && sum!=0){
                min=sum;
                dinhmin=i;
            }
        }
        output<<endl<<"dinh co trong so lon nhat: "<<dinhmax;
        output<<endl<<"dinh co trong so be nhat: "<<dinhmin;

        output.close();
    }

    return 0;
}