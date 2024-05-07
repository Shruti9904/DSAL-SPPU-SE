#include <iostream>
#include <string>
using namespace std;

class node{
	public:
		string word;
		string meaning;
		node*left;
		node*right;
		
		node(string key,string keyMeaning){
			this->word=key;
			this->meaning=keyMeaning;
			this->left=NULL;
			this->right=NULL;
		}
};

class Dictionary{
	public:
		node* root,*q;
		Dictionary(){
			root=NULL;
			q=NULL;
		}
		void insert(node* p,string key,string keyMeaning);
		void display_asc(node*p);
		void display_des(node*p);
		void deleteWord(node*p,string key);
		void updateWord(node*p,string key);
		void comparisons(node*p,string key);
		node* min_node (node *p);
};

void Dictionary::insert(node* p,string key,string keyMeaning){

	if(key<p->word){
		if(p->left!=NULL){
			insert(p->left,key,keyMeaning);
		}
		else{
			p->left=new node(key,keyMeaning);
		}
	}
	if(key>p->word){
		if(p->right!=NULL){
			insert(p->right,key,keyMeaning);
		}
		else{
			p->right=new node(key,keyMeaning);
		}
	}			

}

void Dictionary::display_asc(node* p){
	if(p->left!=NULL){                                  //inorder
		display_asc(p->left);
	}
	cout<<"\n"<<p->word<<"  "<<p->meaning;
	if(p->right!=NULL){
		display_asc(p->right);
	}
}

void Dictionary::display_des(node* p){
	if(p->right!=NULL){
		display_des(p->right);
	}
	cout<<"\n"<<p->word<<"  "<<p->meaning;
	if(p->left!=NULL){
		display_des(p->left);
	}
}

void Dictionary::deleteWord(node* p,string key){
	node* s;
	q=p;
	while(p!=NULL){
		if(key<p->word){
			q=p;
			p=p->left;			
		}
		else if(key>p->word){
			q=p;
			p=p->right;
		}
		else if(key==p->word){                                //found the word to delete
			if(p->left==NULL && p->right==NULL){              //leaf node
				if(q->left==p){
					q->left=NULL;
					delete p;
					return;
				}else if(q->right==p){
					q->right=NULL;
					delete p;
					return;
				}
			}
			else if(p->right!=NULL && p->left==NULL){          //right child only
				if(q->left==p){
					q->left=p->right;
					delete p;
					return;					
				}else if(q->right==p){
					q->right=p->right;
					delete p;
					return;
				}
			}
			else if(p->right==NULL && p->left!=NULL){          //left child only
				if(q->left==p){
					q->left=p->left;
					delete p;
					return;					
				}else if(q->right==p){
					q->right=p->left;
					delete p;
					return;
				}				
			}
			else if(p->right!=NULL && p->left!=NULL){          //both child
                s = min_node (p -> right);
                p -> word = s -> word;
                p -> meaning = s -> meaning;
                deleteWord (s, s -> word);
                return;
			}			
		}
	}	
	cout<<"\nWord not found";
}

node* Dictionary::min_node (node *p) {
    while (p -> left != NULL) {
        q = p;
        p = p -> left;
    }
    return p;
}

void Dictionary::updateWord(node* p,string key){
	string newMeaning;
	while(p!=NULL){
		if(key<p->word){
			p=p->left;			
		}
		else if(key>p->word){
			p=p->right;
		}
		else if(key==p->word){
			cout<<"\nEnter new meaning:";
			getline(cin>>ws,newMeaning);
			p->meaning=newMeaning;
			return;
		}
	}
	cout<<"\nWord not found";
}

void Dictionary::comparisons(node* p,string key){
	static int count=0;
	while(p!=NULL){
		if(key<p->word){
			count++;
			p=p->left;			
		}
		else if(key>p->word){
			count++;
			p=p->right;
		}
		else if(key==p->word){
			count++;
			cout<<"\nNumber of comparisons to find " << key <<":"<<count;
			return;
		}
	}
	cout<<"\nWord not found";
}

int main(){
	int ch,n;
	string word,meaning;
	Dictionary d;
	do{
		cout<<"\nMain Menu:";
		cout<<"\n1.Insert new words\n2.Display Dictionary in ascending order\n3.Display Dictionary in Descending order";
		cout<<"\n4.Delete a word\n5.Search and Update a word\n6.Find no of comparisons\n7.Exit";
		cout<<"\n\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter the no of words to insert:";
				cin>>n;
				for(int i=0;i<n;i++){
					cout<<"\nEnter word:";
					cin>>word;
					cout<<"Enter meaning:";
					getline(cin>>ws,meaning);
                    if (d.root == NULL)
                        d. root = new node (word, meaning);
                    else
                        d.insert (d.root, word, meaning);		
				}
				break;
			case 2:
				cout<<"\nDictionary in Ascending order:";
				d.display_asc(d.root);
				cout<<endl;
				break;
			case 3:
				cout<<"\nDictionary in Descending order:";
				d.display_des(d.root);
				cout<<endl;
				break;	
			case 4:
				cout<<"\nEnter the word to delete:";
				cin>>word;
				d.deleteWord(d.root,word);
				break;
			case 5:
				cout<<"\nEnter the word to update:";
				cin>>word;	
				d.updateWord(d.root,word);
				break;
			case 6:
				cout<<"\nEnter the word to find comparisons:";
				cin>>word;
				d.comparisons(d.root,word);
				break;
			case 7:
				break;					
		}
	}while(ch!=7);
}
