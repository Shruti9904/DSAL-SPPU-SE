#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student {
    int roll;
    string name;
    char div;
    string add;

public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout;
    fout.open("student.txt", ios::out | ios::app); // Open in text mode with file name "student.txt"
    do {
        cout << "\n\tEnter Roll No of Student    : ";
        cin >> roll;
        cout << "\n\tEnter a Name of Student     : ";
        cin >> name;
        cout << "\n\tEnter a Division of Student : ";
        cin >> div;
        cout << "\n\tEnter a Address of Student  : ";
        cin >> add;
        fout << roll << " " << name << " " << div << " " << add << endl; // Write to text file
        cout << "\n\tDo You Want to Add More Records(y/n): ";
        cin >> ans;
    } while (ans == 'y');
    fout.close();
}

void student::display() {
    ifstream fin;
    fin.open("student.txt", ios::in); // Open file with name "student.txt" in read mode
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin >> roll >> name >> div >> add) { // Read from text file
        cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << add;
    }
    cout<<endl;
    fin.close();
}

int student::search() {
    int r, found = 0;
    ifstream fin;
    fin.open("student.txt", ios::in); // Open file with name "student.txt" in read mode
    cout << "\n\tEnter a Roll No: ";
    cin >> r;
    while (fin >> roll >> name >> div >> add) { // Read from text file
        if (roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << add;
            found = 1;
            break;
        }
    }
	if(found==0){
		cout<<"\n\tRecord not found";		
	}
    fin.close();
    return found;
}

void student::Delete(){
	int r;
	cout<<"\n\tEnter Roll no:";
	cin>>r;
	ifstream fin;
	fin.open("student.txt",ios::in);
	ofstream fout;
	fout.open("temp.txt",ios::out);
	bool deleted=false;
	while(fin>>roll>>name>>div>>add){
		if(roll==r){
            cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << add;
			deleted=true;
			continue;
		}
		fout<< roll << " " << name << " " << div << " " << add << endl;
	}	
	fin.close();
	fout.close();
	if(!deleted){
		cout<<"\n\tRecord not found";
		remove("temp.txt");
	}
	else{
		remove("student.txt");
		rename("temp.txt","student.txt");
		cout<<"\n\tRecord deleted";
	}
}

int main() {
    student obj;
    int ch;
    char ans;
    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.Delete();
            break;
        case 4:
            if (obj.search() == 0)
                cout << "\n\tRecord Not Found...\n";
            break;
        case 5:
            break;
        }
    } while (ch!=5);
    return 1;
}

