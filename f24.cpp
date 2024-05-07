#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class employee{
	int id;
	string name;
	string desg;
	double salary;
	vector<int> index;
	public:
		employee(){
			index=readIndexfile();
		}
		void add();
		void display();
		void displayAll();
		void Delete();

		vector<int> readIndexfile();
		void updateIndexfile();
};

void employee::add(){
	ofstream fout;
	fout.open("Employee.txt",ios::out | ios::app);
	cout<<"\n\tEnter ID:";
	cin>>id;
	cout<<"\n\tEnter Name:";
	cin>>name;
	cout<<"\n\tEnter Designation:";
	cin>>desg;
	cout<<"\n\tEnter Salary:";
	cin>>salary;
	
	fout<<id<<" "<<name<<" "<<desg<<" "<<salary<<endl;
	cout<<"\n\tEmplyoee Added"<<endl;
	fout.close();
	
	//Update the index file
	index.push_back(id);
	updateIndexfile();
}

void employee::Delete(){
	ifstream fin;
	fin.open("Employee.txt",ios::in);
	ofstream temp;
	temp.open("temp.txt",ios::out);
	int ID;
	int found=0;
	cout<<"\n\tEnter ID of emplyoee to be deleted:";
	cin>>ID;
	while(fin>>id>>name>>desg>>salary){
		if(id==ID){
			found=1;
			continue;
		}
		temp<<id<<" "<<name<<" "<<desg<<" "<<salary<<endl;
	}	
	fin.close();
	temp.close();
	if(found==0){
		cout<<"\n\tRecord not found";
		remove("temp.txt");
	}else{
		cout<<"\n\tRecord deleted successfully"<<endl;
		remove("Employee.txt");
		rename("temp.txt","Employee.txt");
	}
	
	//Update the index file
	bool flag=false;
	for(auto it = index.begin(); it != index.end(); ++it){
		if(*it==ID){
			index.erase(it);
			flag=true;
			break;
		}
	}
	if(flag){
		updateIndexfile();
	}
}

void employee::display(){
	ifstream fin;
	fin.open("Employee.txt",ios::in);
	int ID;
	cout<<"\n\tEnter ID of emplyoee to be display:";
	cin>>ID;
	bool found=false;
	while(fin>>id>>name>>desg>>salary){
		if(id==ID){
			cout<<"\n\tID:"<<id<<"\tName:"<<name<<"\tDesignation:"<<desg<<"\tSalary:"<<salary<<endl;
			found=true;
		}
	}
	if(!found){
		cout<<"\n\tRecord not found";
	}
	fin.close();
}

void employee::displayAll(){
	ifstream fin;
	fin.open("Employee.txt",ios::in);
	while(fin>>id>>name>>desg>>salary){
			cout<<"\n\tID:"<<id<<"\tName:"<<name<<"\tDesignation:"<<desg<<"\tSalary:"<<salary;
			cout<<endl;
	}
	fin.close();

}

vector<int> employee::readIndexfile(){
	ifstream indexfile;
	indexfile.open("index.txt",ios::in | ios::app);
	while(indexfile>>id){
		index.push_back(id);
	}
	indexfile.close();
	return index;
}

void employee::updateIndexfile(){
	ofstream indexfile;
	indexfile.open("index.txt",ios::out);	
	for(int id:index){
		indexfile<<id<<endl;
	}	
	indexfile.clear();
}

int main(){
	employee obj;
	int ch;
	do{
		cout << "\n\tMenu";
		cout<<"\n\t1.Add Employee\n\t2.Delete Employee\n\t3.Display Employee\n\t4.Display All Employee\n\t5.Exit"<<endl;
		cout<<"\n\tEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				obj.add();
				break;
			case 2:
				obj.Delete();
				break;
			case 3:
				obj.display();
				break;
			case 4:
				obj.displayAll();
				break;
			case 5:
				break;
		}
	}while(ch!=5);
}
