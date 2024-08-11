// Waqas_22i2469

// Assignment # 1 

/*
FAST university has hired you to make an operating system for their lifts. Below are specifications of the lifts OS.
The lift will be place in a building with 6 floors including a basement. 
From basement to top floors are labeled as -1,0,1,2,3,4 respectively. 
In the morning, the lift goes operation from the basement. The lift can go up and down. 
If maintained is required, the lift can be halted. If the lift is halted, the lift not usable during that period. 
Once unhalted, the lift can be used again.
With the help of above information, make a lift operating system 
*/

#include<iostream>
using namespace std;

int liftup(int current_floor,int requested_floor )
{
	//recurrsive funcation to take lift up
	if (current_floor == requested_floor)
	{
		return requested_floor;
	}
	else
	{
		cout<< endl << "Going Up! " << endl << endl;
		current_floor += 1;
		liftup (current_floor , requested_floor);
	}
}
int liftdown(int current_floor,int requested_floor )
{
	//recurrsive funcation to bring the lift down
	if (current_floor == requested_floor)
	{
		return requested_floor;
	}
	else
	{
		cout<< endl << "Going Down! " << endl << endl;
		current_floor -= 1;
		liftdown (current_floor , requested_floor);
	}
}

int lift_operating_system(int requested_floor, int current_floor, char lift_status)
{
	//all lift related logic will be written in this bloack along with validation. In this funcation, decide
	//if the lift goes up or down
	
	if (requested_floor == current_floor)
	{
		cout<<"You are already on this floor! " << endl;
	}
	
	if ((requested_floor < current_floor) && (lift_status == 'W'))
	{
		current_floor = liftdown (current_floor , requested_floor);
	}
	
	if ((requested_floor > current_floor) && (lift_status == 'W'))
	{
		current_floor = liftup (current_floor , requested_floor);
	}
	
	if (lift_status =='H')
	{
		cout<<"Lift is Halted! So We cannot go up or down !" << endl;
	}
	
	cout<<"You are currently on floor : " << current_floor << endl << endl;
	return current_floor;
}

char halt_lift(char status)
{
	//halts the lift, no up and down operation can be performed. Stored H for halting
	status = 'H';
	return status;
}
char un_halt_lift(char status)
{
	//Unhatls the lift. Store W which represents that the lift is working
	status = 'W';
	return status;
}
main()
{
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service; //choice of user
	int requested_floor; //floor the lift goes on
	char status= 'W'; //W for working , H for halted
	while(1)
	{
		cout<<"Please select a function of your choice";
		cout<< endl << "1. Go to a specific floor";
		cout<< endl << "2. Halt Lift";
		cout<< endl << "3. Unhalt Lift";
		cout<< endl << "4. Exit" << endl;

		cin >> requested_service;
		cout<< endl;
		
		switch(requested_service)
		{
		    case 1:
			{
				cout << endl << "Enter Floor of choice ";
				cin >> requested_floor;
				cout<<endl;
				
				while(requested_floor < -1 || requested_floor > 4)
	            {
		            cout<<"Invalid Floor Requested! Enter Again : "<< endl;
		            cin >> requested_floor;
	            }
				
				cout<<"Currently On Floor : " << current_floor << endl << endl;
				current_floor = lift_operating_system(requested_floor , current_floor , status);//arguments 
				//your code here
				break;
			}
		    case 2:
			{
				cout<< "Lift Halted !" << endl;
				status = halt_lift (status);
				break;
			}
		    case 3:
			{
				cout<< "Lift Unhalted !" << endl;
				status = un_halt_lift(status);		
				break;
			}
		    case 4:
			{
				cout<<"Exiting!" << endl;
				return 0;
			}
		}
	}
}
