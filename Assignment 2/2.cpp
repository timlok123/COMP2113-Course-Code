#include <iostream>
#include <limits>
#include<iomanip> // include for printing "01" after AABB (task 2)
#include<cmath> //include for checking collison of 2 bounding box (task 3)

using namespace std;

const int X = 0;
const int Y = 1;

const int MAXGEOM = 20;

struct AABB {
  double min[2];  // min[0] = xmin, min[1] = ymin
  double max[2];  // max[0] = xmax, max[1] = ymax

  // functions

  // Read a point set from user input and calculates AABB
  void ReadPointSet() {
    int n;
    double x, y;

    cin >> n;
    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      if (x < min[X]) min[X] = x;
      if (x > max[X]) max[X] = x;
      if (y < min[Y]) min[Y] = y;
      if (y > max[Y]) max[Y] = y;
    }
  }

  // Read a rectangle from user input and calculates AABB
  void ReadRectangle() {
    double x,y,w,h;

    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();

    cin>>x>>y>>w>>h;
    if (min[X]>(x-w/2)) min[X] = x-w/2;
    if (max[X]<(x+w/2)) max[X] = x+w/2;
    if (min[Y]>(y-h/2)) min[Y] = y-h/2;
    if (max[Y]<(y+h/2)) max[Y] = y+h/2;
  }

  // Read a circle from user input and calculates AABB
  void ReadCircle() {
    double x,y,r;

    min[X] = min[Y] = numeric_limits<double>::max();
    max[X] = max[Y] = numeric_limits<double>::lowest();

    cin>>x>>y>>r;
    if(max[X]<(x+r)) max[X] = x+r;
    if(min[X]>(x-r)) min[X] = x-r;
    if(max[Y]<(y+r)) max[Y] = y+r;
    if(min[Y]>(y-r)) min[Y] = y-r;
  }

};

// return true if two AABBs overlaps
//        false otherwise

bool IsOverlap(AABB p, AABB q) {
  // --- YOUR CODE HERE (Task 3) ---
  bool x_collide = false,y_collide = false;

  double x_length_p =p.max[0]- p.min[0];
  double y_length_p =p.max[1]- p.min[1];
  double x_length_q =q.max[0]- q.min[0];
  double y_length_q =q.max[1]- q.min[1];

  //Find the greatest and smallest  x,y value
  double real_max_x, real_max_y ,real_min_x,real_min_y;

  if(p.max[0]>q.max[0]) real_max_x = p.max[0];
  else real_max_x = q.max[0];

  if(p.max[1]>q.max[1]) real_max_y = p.max[1];
  else real_max_y = q.max[1];

  if(p.min[0]<q.min[0]) real_min_x = p.min[0];
  else real_min_x = q.min[0];

  if(p.min[1]<q.min[1]) real_min_y = p.min[1];
  else real_min_y = q.min[1];


  //determine whether they collide in the same x, y range
  // If the max x difference is greater than the sum of their length in x, they are not in the same range of x
  // So as y
  if ((x_length_p+x_length_q)>=(real_max_x - real_min_x)) x_collide=true;
  if ((y_length_p+y_length_q)>=(real_max_y - real_min_y)) y_collide=true;

  //return true if they overlap
  return x_collide && y_collide;
}


int main()
{
  char type;

  AABB boxes[MAXGEOM];

  AABB res; // input AAAB and result AABB
  // initialize bounds of result AABB
  res.min[X] = res.min[Y] = numeric_limits<double>::max();
  res.max[X] = res.max[Y] = numeric_limits<double>::lowest();

  // read geometry type and dispatch to the corresponding
  // AABB read geomety functions to read from user input handle
  // and compute AABB
  // store all AABBs in the array "boxes"
  int numBoxes = 0;

  cin >> type;
  while (type != '#') {
    switch (type) {
      case 'R':
        boxes[numBoxes++].ReadRectangle();
        break;
      case 'C':
        boxes[numBoxes++].ReadCircle();
        break;
      case 'P':
        boxes[numBoxes++].ReadPointSet();
        break;
      default:
        break;
    }
    cin >> type;
  }

  // display AABBs for input geometries by going through the array "boxes"

  for (int i = 0; i < numBoxes; i++) {
    //display in the format xmin xmax ymin ymax
     cout<<"AABB"<<" ";
     cout<<setw(2)<<setfill('0')<<i;
     cout<<": "<<boxes[i].min[0]<<" "<<boxes[i].max[0]<<" "<< boxes[i].min[1]<<" "<<boxes[i].max[1]<<endl;

  }

  cout << "Isolated AABBs:\n";

  // for each AABB, if it does not overlap with any other AABBs, display its ID
  // --- YOUR CODE HERE (Task 4) ---

  int record_overlap[MAXGEOM]={0};

  //For task 4, I use an array to record whether the bounding boxes overlap with other
  //If yes, the corresponding positon in record_overlap will increase 1
  //After all, if the position in record overlap is 0, they are the isolated bounding boxes

  for(int i = 0; i < numBoxes; i++){
    for (int k =i+1;k < numBoxes; k++){
      if(IsOverlap(boxes[i],boxes[k])){
        record_overlap[i] +=1;
        record_overlap[k] +=1;
    }
  }
}

 for(int i = 0; i < numBoxes; i++){
    if(record_overlap[i]==0){
            cout<<setw(2)<<setfill('0')<<i<<endl;
    }
  }

  return 0;
}
