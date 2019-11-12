// A C++ program to check if two given line segments intersect 
#include <bits/stdc++.h> 
#include <iostream> 
#define pdd pair<double, double> 
using namespace std; 

//struct Point 
//{ 
//	int x; 
//	int y; 
//}; 


void displayPoint(pdd P) 
{ 
    cout << "(" << P.first << ", " << P.second 
         << ")" << endl; 
} 
  
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D) 
{ 
    // Line AB represented as a1x + b1y = c1 
    double a1 = B.second - A.second; 
    double b1 = A.first - B.first; 
    double c1 = a1*(A.first) + b1*(A.second); 
  
    // Line CD represented as a2x + b2y = c2 
    double a2 = D.second - C.second; 
    double b2 = C.first - D.first; 
    double c2 = a2*(C.first)+ b2*(C.second); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
    { 
        // The lines are parallel. This is simplified 
        // by returning a pair of FLT_MAX 
        return make_pair(FLT_MAX, FLT_MAX); 
    } 
    else
    { 
        double x = (b2*c1 - b1*c2)/determinant; 
        double y = (a1*c2 - a2*c1)/determinant; 
        return make_pair(x, y); 
    } 
} 

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(pdd p, pdd q, pdd r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
} 

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(pdd p, pdd q, pdd r) 
{ 
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
	// for details of below formula. 
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; // colinear 

	return (val > 0)? 1: 2; // clock or counterclock wise 
} 

// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(pdd p1, pdd q1, pdd p2, pdd q2) 
{ 
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; // Doesn't fall in any of the above cases 
} 

// Driver program to test above functions 
int main() 
{ 
	//struct Point p1 = {1, 1}, q1 = {10, 1}; 
	//struct Point p1 = {a, b}, q1 = {c, d}; 
	float a,b,c,d,e,f,g,h;
	
	pdd p1 = make_pair(a, b); 
    pdd q1 = make_pair(c, d); 
    pdd p2 = make_pair(e, f); 
    pdd q2 = make_pair(g, h); 

	//struct Point p1 ,q1;
	//struct Point p2 ,q2;
	
	cout<<"Enter the coordinates of P1(x,y)\n";
	cin>>a
    cin>>b




	cout<<"Enter the coordinates of Q1(x,y)\n";
	cin>>c;
    cin>>d;

   
	cout<<"Enter the coordinates of P2(x,y)\n";
	
	cin>>e;
	cin>>f;
	
    cout<<"Enter the coordinates of Q2(x,y)\n";
	cin>>g;
	cin>>h;



	//struct Point p2 = {1, 2}, q2 = {10, 2}; 
	//struct Point p2 = {e, f}, q2 = {g, h}; 


	//doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No Intersection\n"; 
	
	if (doIntersect(p1, q1, p2, q2)){
	    
	    displayPoint(intersection);
	}

  else{
      
      cout<<"No Intersection\n";
  }
    
    
    
	p1 = {10, 0}, q1 = {0, 10}; 
	p2 = {0, 0}, q2 = {10, 10}; 
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 

	p1 = {-5, -5}, q1 = {0, 0}; 
	p2 = {1, 1}, q2 = {10, 10}; 
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 

	return 0; 
} 
