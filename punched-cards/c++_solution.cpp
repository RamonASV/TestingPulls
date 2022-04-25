#include <iostream>
using namespace std;
#include <vector>
void validate(int c1,int m1,int y1,int k1, int &cas){
  while((c1+m1+y1+k1)>1000000){
            if(m1>0){
              m1--;
            }
            else if(y1>0){
              y1--;
            }
            else if(k1>0){
              k1--;
            }
          }
        cout << "Case #" << cas++ << ": " << c1 <<" "<<m1<<" "<<y1<<" 
"<<k1<<"\n";
}
int main (){
  int c, m, y, k, t, cmin=0,mmin=0,ymin=0,kmin=0,s, cas=1;
  cin>>t;
  while(t--){
    for(int i=1;i<4;i++){
      cin>>c;
      cin>>m;
      cin>>y;
      cin>>k;
      if (i==1){
        cmin=c;
        mmin=m;
        ymin=y;
        kmin=k;
      }
      if (cmin>c){
        cmin=c;
      }
      if (mmin>m){
        mmin=m;
      }
      if (ymin>y){
        ymin=y;
      }
      if (kmin>k){
        kmin=k;
      }
    }
    if((cmin+mmin+ymin+kmin)<1000000){
      cout << "Case #" << cas++ << ": " << "IMPOSSIBLE" << endl;
    }
    else{
      s=mmin+ymin+kmin;
      if (s<1000000){
        cmin=1000000-s;
        cout << "Case #" << cas++ << ": " << cmin<<" "<<mmin<<" "<<ymin<<" 
"<<kmin<<"\n";
      }
      else if (s>=1000000){
        cmin=0;
        s=ymin+kmin;
        if (s>=1000000){
          mmin=0;
          validate(cmin,mmin,ymin,kmin,cas);
        }
        else {
          validate(cmin,mmin,ymin,kmin,cas);
        }
      }
    }
  }
}
