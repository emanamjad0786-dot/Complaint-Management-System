#include<iostream>
using namespace std;
// Base Class / parent class

class Complaint {
	
	// Attributes
	
protected:
	
		int complaintID;
		string userName;
		string complaintDetails;
		string status;
		
    //Methods
    
public:
	
	// Input Function to take input/ complain from user
	
 void inputComplaint() {
 	
 	cout<<" Enter Your ID ";
 	
 	cin>>complaintID;
 	
 	cout<<" Enter Your Name ";
 	
 	cin>>userName;
 	
 	cin.ignore();
 	
 	cout<<" Enter Your Complain ";
 	
    getline(cin, complaintDetails);

    status = "Pending";
    
 }	
 
 // Display Function to display complain details
 
 void displayComplaint() {
 	
 	cout<<"\n ID : "<<complaintID<<endl;
 	cout<<" User Name : "<<userName<<endl;
 	cout<<" Complain  : "<<complaintDetails<<endl;
 	cout<<" Status : "<<status<<endl;
	 
}	
	 int getID(){
	 	
        return complaintID;
    }

    string getUserName(){
        return userName;
    }

    void updateStatus(string s){
        status = s;
    }
};
/* Derived class 
single Inheritence --> ComplaintManager derived from base class(parent class) complaint
*/
class ComplaintManager : public Complaint {
	
public:
	
	//Array
	
	Complaint c[100];
	int count=0;
	
	// Add Complaint
	
	void addComplaints() {
		
	
    if(count >= 100) {

        cout<<"\n Storage Full\n";
    }

    else {

        c[count].inputComplaint();
        count++;

        cout<<" Complaint Added"<<endl;
    }
}

   // View Complaint
   
void viewComplaints(){
	
        if(count == 0) {

            cout<<"\n No Complaints Available "<<endl;
        }

        else {

            for(int i=0; i<count; i++) {

                c[i].displayComplaint();
            }
        }

	
	
}

  // Delete Complaint
	
	void deleteComplaints(int searchID) {
		
        int found = 0;

        for(int i=0; i<count; i++){

            if (c[i].getID() == searchID){

                for(int j=i; j<count-1; j++){

                    c[j] = c[j+1];
                }

                count--;
                found = 1;

                cout<<"\nComplaint Deleted Successfully\n";
                break;
            }
        }
              if(found == 0){
            cout<<"\nComplaint Not Found\n";
        }
}

  // Update Complaint
	void updateComplaints(int searchID){
		
     int found = 0;

        string newStatus;

        for(int i=0; i<count; i++) {

            if(c[i].getID() == searchID) {

                cout<<" Enter New Status : ";
                cin.ignore();
                getline(cin, newStatus);
                c[i].updateStatus(newStatus);

                found = 1;

                cout<<"\n Complaint Updated Successfully"<<endl;
            }
        }

        if(found == 0){
            cout<<"\nComplaint Not Found "<<endl;
        }
}
	
	void searchComplaints(int searchID) {
		
		
		 int found = 0;

        for(int i=0; i<count; i++) {

            if(c[i].getID() == searchID) {

                c[i].displayComplaint();

                found = 1;
            }
        }

        if(found == 0) {

            cout<<"\n Complaint Not Found\n";
        }
    }
    
    void searchComplaints(string name) {
		
		
		 int found = 0;

        for(int i=0; i<count; i++) {

            if(c[i].getUserName() == name) {

                c[i].displayComplaint();

                found = 1;
            }
        }

        if(found == 0) {

            cout<<"\n Complaint Not Found\n";
        }
    }


   void showALLComplaints(){
   	
   	if(count == 0){

            cout<<"\nNo Complaints Available\n";
        }

        for(int i=0; i<count; i++){

            c[i].displayComplaint();
        }
    }
    
      
}; 

/* Derived class 
 MultiLevel Inheritence --> Admin derived from Complaint Manager and 
                            Complaint Manager derived from base class complaint 
*/
class Admin : public ComplaintManager {
private:
	int adminID;
	string adminName;
	
public:
	
	void manageComplaints() {
	 
	cout<<"\nAdmin Managing Complaints...\n";

}
	
};

/* Derived class 
 MUltiple Inheritence --> staff class derived from complaint class and complaintmanager class
*/

class Staff : public Complaint , public ComplaintManager {
private:
	int staffID;
	string staffName;
public:
	
	void resolveComplaint(int searchID) {
		
		updateComplaints(searchID);

        cout<<"\nComplaint Resolved "<<endl;
    }

	void checkStatus(int searchID) {
		
		 searchComplaints(searchID);
}
	
};
int main(){
	ComplaintManager CM;
	Admin a;
	Staff s;
	
	int pick;
	int id;
	string name;
	
	do{
		
	cout<<"\n * Complaint Managment System *"<<endl;
	cout<<"  Menu: "<<endl;
	cout<<" 1. Add Complaint "<<endl;
	cout<<" 2. View Complaint "<<endl;
	cout<<" 3. Search Complaint By ID"<<endl;
	cout<<" 4. Search Complaint By User Name"<<endl;
	cout<<" 5. Delete  Complaint "<<endl;
	cout<<" 6. Update Complaint "<<endl;
	cout<<" 7. Manage Complaint "<<endl;
	cout<<" 8. Reslove Complaint "<<endl;
	cout<<" 0. Exit "<<endl;
		
	cout<<" Pick a category...";
	cin>>pick;
	   
	   switch(pick){
	   
        case 1:

            CM.addComplaints();
            break;

        case 2:

            CM.viewComplaints();
            break;

        case 3:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.searchComplaints(id);
            break;
            
        case 4:

            cout<<" Enter User Name : ";
            cin.ignore();
            getline(cin, name);
            CM.searchComplaints(name);
            break;

        case 5:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.deleteComplaints(id);
            break;

        case 6:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.updateComplaints(id);
            break;

        case 7:

            a.manageComplaints();
            break;

        case 8:

            cout<<" Enter Complaint ID : ";
            cin>>id;

            CM.updateComplaints(id);

         cout<<"\n Complaint Resolved"<<endl;
        
            break;

        case 0:

            cout<<"\n Exit "<<endl;;
            break;

        default:

            cout<<"\n Invalid Choice"<<endl;
        }

	}
	while(pick!=0);
	
}
