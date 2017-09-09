#include<iostream>
using namespace std;
//Route_Valid function is used to calculate whether with the given travel_time,ready_time,cancel_time arrays, is there a valid route or not.
int Route_Valid(int travel_time[], int ready_time[], int cancel_time[],int n)
{
	int current_time=0;// this variable will work like a real time clock and will show how much time has passed
	
	for(int i=0;i<n;i++)
	{
		
		if(i==0)
			current_time = current_time + ready_time[i];//because the driver will have to wait at the 1st person's location until he/she is ready. 
		else
		{
			current_time = current_time + travel_time[i-1];//to current time you will add travel_time[i-1] because for ith location the travel time is at (i-1)th location 
		}   
		if(current_time<ready_time[i])
		{
			current_time = current_time + (ready_time[i]-current_time);//because if the driver reaches earlier than the ready time, he will have to wait for ready_time[i]-current_time which will add to the current time
		}
		
		if((current_time + travel_time[i] >= cancel_time[i+1]) && (i<n-1) ) //beacuse if the current time + travel_time exceeds the cancel_time for (i+1)th location, then that passenger will be rejected 
		{ 
			return -1;// return value in case of failure
		}
	   
	}
	return current_time;//return output if everything is successful
	
	
	
}



int main()
{
	int n;
	cout<<"enter the number of requests"<<endl;
	cin>>n;
	int travel_time[n-1],ready_time[n-1],cancel_time[n-1];
	cout<<"enter the travel times: "<<endl;
	for(int i=0;i<n-1;i++)
	{
		cin>>travel_time[i];	
	}
	cout<<"enter the ready times: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>ready_time[i];
	}
	cout<<"enter the cancel times: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>cancel_time[i];
	}
	
	cout<<Route_Valid(travel_time,ready_time,cancel_time,n);
}
