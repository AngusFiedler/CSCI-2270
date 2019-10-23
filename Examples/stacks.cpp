using namespace std;
struct Node(){
	int data;
	Node *next;
};
/*
private:
	Node *top;
	int MaxSize;
	int count;
public:
	isFull();	//checks if full
	isEmpty(); 	//checks if empty
	push(int item);	//add item to top of stack
	item pop();	//returns an item
	display();
*/
bool isEmpty(){
	if (top == NULL){
		return true;
	}
	else{
		return false;
	}
}

void push(int data){
	Node *temp = new Node();
	temp ->data = data;
	if(isEmpty()){
		top = temp;
		top->next = NULL;
	}
	else{
		temp->next = top;
		top = temp;
		temp = NULL:
	}
}

Node* pop(){
	if (!isEmpty()){
		temp = top;
		top = top->next;

	}
}


//ARRAY IMPLEMENTATION
class arrayStack{
	private:
		int top,count,MAXSIZE;
		string a[MAXSIZE];
	public:
		bool isFull(){
			if(top == MAXSIZE){
				return true;
			}
			return false;
		}
		void push(string newItem){
			if(!isFull()){
				a[top] = newItem;
				top++;
			}
			else{
				cout << "Stack Overflow" << endl;
			}
		}
		string pop(){
			string output;
			if(!isEmpty()){
				output = a[top];
				top--;
			}
			else{
				cout << "stack is empty" << endl;
				return NULL;
			}
			returrn output;
		}
}









