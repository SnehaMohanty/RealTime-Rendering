//Assignment_1.2
//Sneha Mohanty
//Ankit Satpute 
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#define pdd pair<float, float>
using namespace std; 


// Check if the point lies within the triangle by taking sum of inner triangles formed and returning true or false
bool inTriangle(pdd P, pdd Q, pdd R, pdd S)
{
	/* Calculate area of triangle PQR */
	float A = area(P,  Q,  R);

	/* Calculate area of triangle SQR */
	float A1 = area( S, Q, R);

	/* Calculate area of triangle PSR*/
	float A2 = area( P, S, R);

	/* Calculate area of triangle PQS */
	float A3 = area( P, Q, S);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

float area(pdd A, pdd B, pdd C)
{

	//return the absolute value of area ( should be >= 0 ) after calculation 
	return abs((A.first*(B.second - C.second) + B.first * (C.second - A.second) + C.first * (A.second - B.second)) / 2.0);
}



int main()
{
	
	char a[201][221];

	bool beginFlag=false;
    string line;
    while(getline(cin,line)){
        if(line == "0 0 0 0 0 0"){
        	return(0);
        }else if(beginFlag){
        	cout << "\n";
        }


        istringstream ss(line);

        //consider four points of type pdd 

        pdd p1,p2,p3,p4;

        //input the first three point coordinates (x,y) 
        ss >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
        

        // print '.' by default in 2D array 'a' and '*' in case of the points lying inside and on the triangle given by p1, p2 and p3
        	for (int i = 20; i > -1; i--) {
		for (int j = 0; j < 21; j++)
		{
			a[i][j] = '.';
			p4 = make_pair(j, i);
			if (inTriangle(p1, p2, p3, p4)) {
				a[i][j] = '*';
			}

			cout << a[i][j];
		}
		cout << "\n";
	}
        cout.flush();
        beginFlag=true;
    }
    return 0;
}
