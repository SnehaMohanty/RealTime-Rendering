// Example program
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#define pdd pair<float, float>
using namespace std; 

float area(pdd A, pdd B, pdd C)
{
	return abs((A.first*(B.second - C.second) + B.first * (C.second - A.second) + C.first * (A.second - B.second)) / 2.0);
}

bool isInside(pdd P, pdd Q, pdd R, pdd S)
{
	/* Calculate area of triangle ABC */
	float A = area(P,  Q,  R);

	/* Calculate area of triangle PBC */
	float A1 = area( S, Q, R);

	/* Calculate area of triangle PAC */
	float A2 = area( P, S, R);

	/* Calculate area of triangle PAB */
	float A3 = area( P, Q, S);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

int main()
{
	
	char a[201][221];

	bool beginFlag=false;
    string line;
    while(getline(cin,line)){
        if(line == "0 0 0 0 0 0 "){
        	break;
        }else if(beginFlag){
        	cout << "\n";
        }
        istringstream ss(line);
        pdd p1,p2,p3,p4;
        ss >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
        
        	for (int i = 20; i > -1; i--) {
		for (int j = 0; j < 21; j++)
		{
			a[i][j] = '.';
			p4 = make_pair(j, i);
			if (isInside(p1, p2, p3, p4)) {
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
