#include<iostream>
#include<cmath>
using namespace std;

//this class calculates the distance between two points A and B and through another point Z
class Dist_A_Z_B{
		public:
		int dist(int a[], int b[], int c[],int z[]);
};
//check function checks the the distance if x is picked up and if y is picked up and picks up the shorter one of the two
int check(int x, int y,int z)
{
	if((x < y) && (x < 2*z)) //for picking up passenger X
	{
		return 1;
	}
	else if((y < x) && (y < 2*x))//for picking up passenger Y 
	{
		return 2;
	}
	else
	{
		return -1;
	}
}
//dist calculates the distance between points a,b,c and a point z 
int Dist_A_Z_B::dist(int a[2],int b[2],int c[2],int z[2])
{
		int dist_a_b,dist_a_c,dist_c_z,dist_z_b,dist_a_c_z_b;
	
	dist_a_b = abs((b[0]-a[0])) + abs((b[1]-a[1]));
	
	dist_a_c = abs((c[0]-a[0])) + abs((c[1]-a[1]));
	
	dist_c_z= abs((z[0]-c[0])) + abs((z[1]-c[1]));
	
	dist_z_b = abs((b[0]-z[0])) + abs((b[1]-z[1]));
	
	dist_a_c_z_b = dist_a_c + dist_c_z + dist_z_b;
	
	
	return dist_a_c_z_b;
}


int main()
{
	Dist_A_Z_B X,Y;
	int a[2],b[2],c[2],x[2],y[2],a_c_x_b,a_c_y_b,a_b;
	cout<<"enter the location of the first person: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>a[i];
	}
	cout<<"enter the location of the destination: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>b[i];
	} 
	cout<<"enter the location at which driver gets the request: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>c[i];
	}
	cout<<"enter the location of passenger X: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>x[i];
	}
	cout<<"enter the location of passenger Y: "<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>y[i];
	}
	a_b = abs((b[0]-a[0])) + abs((b[1]-a[1]));//distance between a and b
	a_c_x_b=X.dist(a,b,c,x);//distance between a,b through c and x
	a_c_y_b=Y.dist(a,b,c,y);//distance between a,b through c and y
	
	cout<<check(a_c_x_b,a_c_y_b,a_b);
	
	return 0;
	
}
