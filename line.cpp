#include <bits/stdc++.h> 
#include <iostream> 
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>

#define pdd pair<double, double> 
using namespace std; 

//struct Point 
//{ 
//	int first; 
//	int second; 
//}; 


int orientation(pdd p1, pdd p2,pdd p3);
string Inter(pdd a, pdd b,pdd p, pdd q);
string InterPoint(pdd a, pdd b,pdd p, pdd q);
string GetPointCords(pdd a);


int orientation(pdd p1, pdd p2,pdd p3){
	double dx21 = p2.first - p1.first;
	double dy21 = p2.second - p1.second;
	double dx31 = p3.first - p1.first;
	double dy31 = p3.second - p1.second;
	if (dx21*dy31 < dy21*dx31) return -1; // ccw

	if (dx21*dy31 > dy21*dx31) return +1; // cw

	if (dx21*dx31 < 0 || dy21*dy31<0) return -1; // ccw

	if (dx31*dx31 + dy31*dy31 > dx21*dx21 + dy21*dy21) return +1; //cw

	return 0; // p3 is inside p1,p2
}

string Inter(pdd a, pdd b,pdd p, pdd q){

    //Cross Intersection
    if( orientation(a,b,p)*orientation(a,b,q)<0 && orientation(p,q,a)*orientation(p,q,b)<0){
        //Get point of Intersection
        return InterPoint(a,b,p,q);
    }

    //Segment intersection
    if( orientation(a,b,p)*orientation(a,b,q)==0 && orientation(p,q,a)*orientation(p,q,b)==0){

        //Segment one line has same first and second in both points return point cord
        if(a.first==b.first && a.second==b.second){
            return GetPointCords(a);
        }

        if(p.first==q.first && p.second==q.second){
            return GetPointCords(q);
        }

        //Segment where lines have a common point
        if(((b.first==p.first && b.second==p.second) || (a.first==p.first && a.second==p.second)) && !((b.first==q.first && b.second==q.second) || (a.first==q.first && a.second==q.second))){
            return GetPointCords(p);
        }

        if(((b.first==q.first && b.second==q.second) || (a.first==q.first && a.second==q.second)) && !((b.first==p.first && b.second==p.second) || (a.first==p.first && a.second==p.second))){
            return GetPointCords(q);
        }

        return "segment intersection";
    }
    return "no intersection";
}

string GetPointCords(pdd a){
    ostringstream text;
    text << fixed <<setprecision(2) << (double)(a.first) << " " <<setprecision(2) << (double)(a.second);
    return text.str();
}

string InterPoint(pdd a, pdd b,pdd p, pdd q){
    double ua1 = ((q.first-p.first)*(a.second-p.second)-(q.second-p.second)*(a.first-p.first));
    double ua2 = ((q.second-p.second)*(b.first-a.first)-(q.first-p.first)*(b.second-a.second));
    double ua = ua1/ua2;
    double ub1 = ((b.first-a.first)*(a.second-p.second)-(b.second-a.second)*(a.first-p.first));
    double ub2 = ((q.second-p.second)*(b.first-a.first)-(q.first-p.first)*(b.second-a.second));
    double ub = ub1/ub2;

    double first = a.first + ua*(b.first-a.first);
    double second = a.second + ub*(b.second-a.second);

    ostringstream text;
    text << fixed << setprecision(2) << first << " " << setprecision(2) << second;
    return text.str();
}



int main (){
	bool beginFlag=false;
    string line;
    while(getline(cin,line)){
        if(line == "0 0 0 0 0 0 0 0"){
        	return(0);
        }else if(beginFlag){
        	cout << "\n";
        }
        istringstream ss(line);
        pdd p1,p2,p3,p4;
        ss >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
        cout << Inter(p1,p2,p3,p4);     
        cout.flush();
        beginFlag=true;
    }
    return 0;
}
