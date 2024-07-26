
#include<iostream>
using namespace std;

//this is how node of tree is defined
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		//since each node has the address to node corresponding to the left and dright of root we are able to access the whole tree from the root node
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

//this is creation of binary tree
void buildTree(Node*& root){
	
	//this is start of creation of binary tree
	int var;
//	cout<<" Enter the value : ";
	cin>>var;
	
	//if user enters -1, then there is no node present
	if(var == -1) return;
	
	
	root = new Node(var);
	
//	cout<<"now enter data which you want to be left of "<<var;
	buildTree(root->left);
	
//	cout<<"now enter data which you want to be right of "<<var;
	buildTree(root->right);
}


//pre order travesing
//it implies we first traverse the node, then the element to left and then right of it
void printPreOrderTraversal(Node* root){
	//N L R
	if(root == NULL) return;
	
	cout<<root->data<<" ";
	printPreOrderTraversal(root->left);
	printPreOrderTraversal(root->right);
}

void printInOrderTraversal(Node* root){
	//L N R
	if(root == NULL) return;
	
	printInOrderTraversal(root->left);
	cout<<root->data<<" ";
	printInOrderTraversal(root->right);
}

void printPostOrderTraversal(Node* root){
	//L R N
	if(root == NULL) return;
	
	printPostOrderTraversal(root->left);
	printPostOrderTraversal(root->right);
	cout<<root->data<<" ";
}

int main(){
	//since we havee created a node, start creation of binary tree
	Node* root;
	buildTree(root);
	
	//5 4 1 -1 -1 7 -1 -1 3 2 -1 -1 5 9 -1 -1 10 -1 -1
	cout<<"Preorder traversal: "<<endl;
	printPreOrderTraversal(root);
	cout<<endl;
	
	cout<<"Inorder traversal: "<<endl;
	printInOrderTraversal(root);
	cout<<endl;
	
	cout<<"Postorder traversal: "<<endl;
	printPostOrderTraversal(root);
	return 0;
}
#include<iostream>
using namespace std;
int main(){
	string text;
	text = "hi guys how are you doing today, did you get time to watch the new spiderverse film and now i want you to find the letter with maximum frequency in this sentence";
	
	//	cout<<text[0]<<endl;
	//	cout<<text[1]<<endl;
	//	cout<<text[2]<<endl;
	//	cout<<text[3]<<endl;
	
	//to store all freq i will first define array of size 26
	int freq[26]; 
	
	int i;
	for(i=0;i<26;i++) freq[i]=0;
	
	for(i=0;i<text.length();i++){
		if(text[i] != ' '){
			freq[text[i]-'a']++;
			//we are finding the index of which we have to increment directly from the value of text[i]-'a'	
		}
	}
	
	char temp;
	int max;
	for(i=0,temp='a',max=0;i<26;i++){
		cout<<"The frequency of the char  "<<temp<<" is "<<freq[i]<<endl;
		temp++;
		
		if(freq[i] > max) max=freq[i];
	}
	
	cout<<"The max freq is: "<<max;
	return 0;
}
