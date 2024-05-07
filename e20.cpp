#include <iostream>
#include <queue>
#include <string>
using namespace std;

enum PatientType{
	Serious,
	Non_Serious,
	General_Checkup
};

class Patient{
	string name;
	PatientType type;
	public:
		Patient(string n,PatientType t){
			this->name=n;
			this->type=t;
		}
		bool operator<(const Patient &other) const{
			return type > other.type;
		}
		string getName() const{
			return name;
		}
		PatientType getType() const{ 
			return type;
		}
};
int main(){
//	priority_queue<Patient> queue;
//	queue.push(Patient("Shruti",General_Checkup));
//	queue.push(Patient("Neha",Serious));
//	queue.push(Patient("Riya",Non_Serious));
//	queue.push(Patient("Shreya",General_Checkup));
//	queue.push(Patient("OM",Serious));	
//	
//	while(!queue.empty()){
//		Patient currentPatient=queue.top();
//		queue.pop();
//		
//		string priority;
//		switch(currentPatient.getType()){
//			case Serious:
//				priority="Serious";
//				break;
//			case Non_Serious:
//				priority="Non_Serious";
//				break;
//			case General_Checkup:
//				priority="General_Checkup";
//				break;
//				
//		}
//		
//		cout<<"Patient:"<<currentPatient.getName()<<" "<<"Priority:"<<priority<<endl;
//	}
	
    priority_queue<Patient> hospitalQueue;

    // Taking input for patients from the user
    int n;
    cout<<"Enter no of patients to be added:";
    cin>>n;
    
    for (int i = 0; i < n; ++i) {
        string name;
        int condition;

        cout << "Enter patient's name: ";
        cin >> name;

        cout << "Enter patient's condition (0 for SERIOUS, 1 for NON_SERIOUS, 2 for GENERAL_CHECKUP): ";
        cin >> condition;

        PatientType type;
        switch (condition) {
            case 0:
                type = Serious;
                break;
            case 1:
                type = Non_Serious;
                break;
            case 2:
                type = General_Checkup;
                break;
            default:
                cout << "Invalid condition. Setting condition to GENERAL_CHECKUP." << endl;
                type = General_Checkup;
                break;
        }

        hospitalQueue.push(Patient(name, type));
    }
    
    // Serving patients in priority order
    while (!hospitalQueue.empty()) {
        Patient currentPatient = hospitalQueue.top();
        hospitalQueue.pop();

        string priority;
        switch (currentPatient.getType()) {
            case Serious:
                priority = "Serious";
                break;
            case Non_Serious:
                priority = "Non-Serious";
                break;
            case General_Checkup:
                priority = "General Checkup";
                break;
        }

        cout << "Patient Name: " << currentPatient.getName() << ", Priority: " << priority<< endl;
    }

    return 0;
}
