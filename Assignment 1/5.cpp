#include<iostream>
#include<limits>

using namespace std;

void RetangleBB(double &xmin, double &xmax, double &ymin, double &ymax){
  double x,y,w,h;
  cin>>x>>y>>w>>h;

  if (xmin>(x-w/2)){
    xmin = x-w/2;
  }

  if (xmax<(x+w/2)){
    xmax = x+w/2;
  }

  if (ymin>(y-h/2)){
    ymin=(y-h/2);
  }

  if (ymax<(y+h/2)){
    ymax=(y+h/2);
  }
}
void CircleBB(double &xmin, double &xmax, double &ymin, double &ymax){
  double x,y,r;
  cin>>x>>y>>r;
  if(xmax < (x+r)){
    xmax = x+r;
  }
  if(xmin>(x-r)){
    xmin = x-r;
  }
  if(ymax<(y+r)){
    ymax = y+r;
  }
  if(ymin>(y-r)){
    ymin = y-r;
  }
}
//Can I assume n and i are integers?
void PointSetBB(double &xmin, double &xmax, double &ymin, double &ymax){
  int i,n;
  double x,y;
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>x>>y;
      if (xmin>x) xmin = x;
      if (xmax<x) xmax = x;
      if (ymin>y) ymin = y;
      if (ymax<y) ymax = y;
  }
}

int main(){
  char s = 'a';
  double xmin,xmax,ymin,ymax;
  xmin= numeric_limits<double>::max(); //greatest positive number
  xmax = numeric_limits<double>::lowest(); //greatest negative number
  ymin = numeric_limits<double>::max();
  ymax = numeric_limits<double>::lowest();

  while(s!='#'){
    cin>>s;
    if (s == 'R'){
      RetangleBB(xmin,xmax,ymin,ymax);
    }
    else if(s == 'C'){
      CircleBB(xmin,xmax,ymin,ymax);
    }
    else if(s == 'P'){
      PointSetBB(xmin,xmax,ymin,ymax);
    }
  }
  cout<<(xmin+xmax)/2<<" "<<(ymin+ymax)/2<<" "<<xmax-xmin<<" "<<ymax-ymin<<endl;
  return 0;
}
