//Assignment 1.1
//Sneha Mohanty
//Ankit Satpute

#include <bits/stdc++.h> 
#include <iostream> 
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#define pdd pair<double, double> 
using namespace std; 


int orientation(pdd p1, pdd p2,pdd p3){

    //take points p1,p2,p3
    // difference in x coordinates of 1st and 2nd point 
	double dx21 = p2.first - p1.first;

    //difference in y coordinates of 1st and 2nd point 
	double dy21 = p2.second - p1.second;

    // difference in x coordinates of 1st and 3rd point 
	double dx31 = p3.first - p1.first;

    //difference in y coordinates of 1st and 3rd point 
	double dy31 = p3.second - p1.second;

    
    
    // conditions for clockwise , anticlockwise and collinear 
    if ((dx21*dy31 > dy21*dx31)||(dx31*dx31 + dy31*dy31 > dx21*dx21 + dy21*dy21)||(dx31*dx31 + dy31*dy31 > dx21*dx21 + dy21*dy21)) {



    // clockwise case
        return(1); 
    } 

	else if ((dx21*dy31 < dy21*dx31)||(dx21*dx31 < 0) || (dy21*dy31<0)) {

     // counter-clockwise case
        return(-1);
    } 


    else {
        
    // p3 is on line p1 p2 , the points are collinear 

        return 0; 
    }

	
}


int orientation(pdd p1, pdd p2,pdd p3);
string intersect_coords(pdd a, pdd b,pdd p, pdd q);
string segment_coords(pdd a);


//returns the type of intersection 
string type_intersection(pdd a, pdd b,pdd p, pdd q){

    //Different slope case
    //intersection at a point 
    if( orientation(a,b,p)*orientation(a,b,q)<0 && orientation(p,q,a)*orientation(p,q,b)<0){
        //Get point of Intersection
        return intersect_coords(a,b,p,q);
    }
    
    //same slope cases
    //Segment intersection
    else if( orientation(a,b,p)*orientation(a,b,q)==0 && orientation(p,q,a)*orientation(p,q,b)==0){

           
            if(a.first==b.first && a.second==b.second){
                return segment_coords(a);
            }

            else if((p.first==q.first && p.second==q.second)||(((b.first==q.first && b.second==q.second) || (a.first==q.first && a.second==q.second)) && !((b.first==p.first && b.second==p.second) || (a.first==p.first && a.second==p.second))) ){
                return segment_coords(q);
            }

             //Segment where lines have a common point
            else if(((b.first==p.first && b.second==p.second) || (a.first==p.first && a.second==p.second)) && !((b.first==q.first && b.second==q.second) || (a.first==q.first && a.second==q.second))){
                return segment_coords(p);
            }

            //intersection in a segment
            else {
                return "Segment intersection";
                }


            }

    // no intersection case
    else{

            return "No intersection";

      }          

     
}

string segment_coords(pdd a){
    ostringstream coords;
    coords << fixed <<setprecision(2) << (double)(a.first) << " " <<setprecision(2) << (double)(a.second);
    return coords.str();
}

string intersect_coords(pdd a, pdd b,pdd p, pdd q){
    
    
    double diff1 = ((q.first-p.first)*(a.second-p.second)-(q.second-p.second)*(a.first-p.first));
    double diff2 = ((q.second-p.second)*(b.first-a.first)-(q.first-p.first)*(b.second-a.second));
    
    
    double diva = diff1/diff2;
    
    
    
    double diff3 = ((b.first-a.first)*(a.second-p.second)-(b.second-a.second)*(a.first-p.first));
    double diff4 = ((q.second-p.second)*(b.first-a.first)-(q.first-p.first)*(b.second-a.second));
   
   
   double divb = diff3/diff4;

    double fp = a.first + diva*(b.first-a.first);
    double sp = a.second + divb*(b.second-a.second);

    ostringstream coords;
    coords << fixed << setprecision(2) << fp << " " << setprecision(2) << sp;
    return coords.str();
}



int main (){
    
    
	bool boolFlag=false;
    string text;
    while(getline(cin,text)){
        if(text == "0 0 0 0 0 0 0 0"){
        	return(0);
        }else if(boolFlag){
        	cout << "\n";
        }
        istringstream ss(text);
        pdd p1,p2,p3,p4;
        ss >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
       
       
        cout << type_intersection(p1,p2,p3,p4);     
        cout.flush();
        
        boolFlag=true;
    }
    return 0;
}
