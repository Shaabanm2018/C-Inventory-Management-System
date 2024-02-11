/********************************************
File name: TT08_A2_Shaaban_Mohammed_Najib.cpp
Course: TCP1101 Programming Fundamentals
Year: 2017/18 Trimester 1
Student: SHAABAN MOHAMMED NAJIB
ID: (1151304220)
Email: mohnajib1243@gmail.com
Phone: (0107065526)
********************************************/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


void pring(int arr[]); //function use for design the table
void pring1(int arr[]);   //function use for design the table
void copy(string c[], int size); //function use for copy feature
void past(string p[], int size);   // function use for past feature
void new1(string n[], int size);   //function use for create new table
void insert (string b[], int size);   // function use for insert feature 
void print(string p[],int arr[], int a);   // function use for design table 
void delete1(string d[],int size,int x,int y);  //function use for delete featrue
void max1(string l[], int size,int coll[8]);//function use for get the longest length 
void show_clip1(string b[], int size); // function use for show clip feature
void overwrite(string o[], int size); //function use for overwrite feature
void undo2(string u[], int size);   //function use for undo feature
void undo(string u1[], int size);//function use for undo feature
void cut(string c[], int size); // function use for cut feature
void find(string f[], int size);//function use to find feature
void save(string s[], int size); // function use for 
void load(); //function use for load feature


bool cond;           // bool varible to check of the error of enter different type

int line = 0,        // global integer variable with short name easy to use
i = 0,q = 0,z = 0
, z1 = 0, z3 = 0,
size = 100 , 
array1[100],size_clip = 0;


string name, clip[100], undoinsert[100],    //varible of string to stor name and to sotr the array1 use for undo feature
undoinsert1[100], undodelete[100], 
undooverwrite[100], undopast[100], undocut[100];


int main(){
	int x, y;
	char ans; //char varible for while loop 
	char undo1; //char varible for determin the Previous step
	string myarray1[100]; //create string myarray1
	for(int a =0 ; a < size; a++){
		myarray1[a] = " "; //assign all the position in the table to empty
	
	}
	cout << endl; //print out the initial screen
	cout << "* ---------------------------------------------" << endl;
	cout << endl << "File name : File.txt " << endl;
	cout << endl
	<< "[N]ew, [I}nsert, [D]elete, [O]verwrite, [L]oad, [S]save " << endl
	<< "[C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo,[Q]uit, " << endl
	<< "==> ";
	cin >> ans;
	//use for loop for difference character enter
	while(!((ans == 'i')||(ans == 'd')||(ans == 'o')||(ans == 'n')||
		  (ans =='s')||(ans == 'l')||(ans == 'c') ||(ans == 'b')||
		  (ans == 'x')||(ans == 'p')||(ans == 'f')||(ans == 'I')||
		  (ans == 'D')||(ans == 'O')||(ans == 'N')||(ans =='S')||
		  (ans == 'L')||(ans == 'C') ||(ans == 'B')||(ans == 'X')||(ans == 'P')||(ans == 'F')||(ans == 'u')||(ans == 'U'))){
			  cout << "[N]ew, [I}nsert, [D]elete, [O]verwrite, [L]oad, [S]save "<< endl
	<< "[C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo,[Q]uit," << endl 
	<< "==> ";
	cin >> ans;
		  }
	
	
	while((ans == 'i')||(ans == 'd')||(ans == 'o')||(ans == 'n')||(ans =='s')||(ans == 'l')||(ans == 'c')
		  ||(ans == 'b')||(ans == 'x')||(ans == 'p')||(ans == 'f')||(ans == 'I')||(ans == 'D')||(ans == 'O')
	      ||(ans == 'N')||(ans =='S')||(ans == 'L')||(ans == 'C')
		  ||(ans == 'B')||(ans == 'X')||(ans == 'P')||(ans == 'F')||(ans == 'u')||(ans == 'U'))
	{
		
		 // the following is the implementation for each function 
		 
		 
	if((ans=='i')||(ans == 'I')){
		cout << endl;
		insert(myarray1, size); //insert when user enter character i or I
		undo1 = 'i';
	}
	if((ans == 'd')||(ans == 'D')){
		cout << endl;
		delete1(myarray1, size, x, y); //delete fuction character D/d
		undo1= 'd';
	}
	if((ans == 'o')||(ans == 'O')){
		cout << endl;
		overwrite(myarray1, size);   //overwrite fuction character O/o
		undo1= 'o';
	}
	
	if((ans == 'n')||(ans == 'N')){
		cout <<endl;
		new1(myarray1, size);   //create new table character N/n
	}
	if((ans == 's')||(ans == 'S'))
	save(myarray1, size);	        //save table character S/s
	if((ans == 'l')||(ans == 'L'))
			    load();                //load table character L/l
	if((ans == 'c')||(ans == 'C')){
		cout << endl;
		copy(myarray1, size);  //copy fuction character D/d
		undo1 = 'c';
	}
	if((ans == 'b')||(ans == 'B'))
		show_clip1(myarray1, size);    //show clip fuction character B/b
	if((ans == 'p')||(ans == 'P')){
		cout <<endl;
		past(myarray1, size);      //past fuction character D/d
		undo1 = 'p';       
	}
	if((ans == 'x')||(ans =='X')){
		cout << endl;
		cut(myarray1, size);        //cut fuction character D/d
		undo1 = 'x';
	}
	if((ans == 'f')||(ans == 'F')){
		cout << endl;
		find(myarray1, size);    //find fuction character D/d
		
	}
	if((ans == 'q')||(ans == 'Q'))
		break;       //enter program when usert enter Q/q
	
	
	if((ans == 'u')||(ans == 'U')){
		// the following is undo function for each Previous step
		if(undo1 == 'd'){
			i = line;
			for(int a = 0; a < size ; a++)
				myarray1[a] = undodelete[a];
			undo2(myarray1, size);    
		}
			else if(undo1 == 'o'){
			for(int a = 0; a < size ; a++)
				myarray1[a] = undooverwrite[a];
			undo2(myarray1, size);
			}
			
			else if(undo1 == 'i')
			{
			
	
				i = z;
				line = z;
				for(int a = 0; a < size ; a++)
				myarray1[a] = undoinsert[a];
			
				undo2(myarray1, size);
			}
			
			else if(undo1 == 'p'){
				i = z3;
				for(int a = 0; a < size ; a++)
				myarray1[a] = undopast[a];
			undo2(myarray1, size);
		
			}
			
			else if(undo1 == 'x'){
				i = line;
				for(int a = 0; a < size ; a++)
				myarray1[a] = undocut[a];
			undo2(myarray1, size);
			}
			
			else if(undo1 == 'c'){
				for(int a = 0; a < size ; a++)
				clip[a] = " ";
			undo2(myarray1, size);
			}
			
			else undo(myarray1, size);
		
			
			
			
	}

	cout << "[N]ew, [I}nsert, [D]elete, [O]verwrite, [L]oad, [S]save "<< endl
	<< "[C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo,[Q]uit," << endl 
	<< "==> ";
	cin >> ans;
	
	
	while(!((ans == 'i')||(ans == 'd')||(ans == 'o')||(ans == 'n')||(ans =='s')||(ans == 'l')||(ans == 'c')
		  ||(ans == 'b')||(ans == 'x')||(ans == 'p')||(ans == 'f')||(ans == 'I')||(ans == 'D')||(ans == 'O')
	      ||(ans == 'N')||(ans =='S')||(ans == 'L')||(ans == 'C')
		  ||(ans == 'B')||(ans == 'X')||(ans == 'P')||(ans == 'F')||(ans == 'q')||(ans == 'Q')||(ans == 'u')||(ans == 'U'))){
			  cout << "[N]ew, [I}nsert, [D]elete, [O]verwrite, [L]oad, [S]save "<< endl
	<< "[C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo,[Q]uit," << endl 
	<< "==> ";
	cin >> ans;
		  }
	
	}
	
}

void new1(string n[], int size){
	for(int a =0 ; a < size; a++)
		n[a] = " ";  //assign all the position in the table to empty
	i = 0;
	int s = 0;
	
	cout << "New file name ==> ";  
	cin >> name;  // stor the name of the table 
	cout << endl;
	//print out the new table
	cout << "File name : " << name << endl;
	max1(n, size, array1);  //max function to determin the longest length of the word in the table
	pring(array1); //pring function use for design table format
	pring1(array1); //pring1 function use for design table format
	pring(array1);  
	cout << " | 00 | ";
	print(n,array1, s); //print function to print the content of the table 
	pring(array1); 
}

void insert (string b[], int size){
	for(int a = 0; a < size; a++)
		undoinsert[a] = b[a]; //function use for undo feature
		char a; //use for insert word in the table
	char s[80]; //use for insert word in the table
	z = 0; 
	z = i;
	//do wille loop for error of differente type enter
	 do {
		cout << "Tile number ==> "; 
			 cin >> q; 
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	
	q = q - 1;
	if(q > i)
		i =q;
		line = i;
	cout << "Text ==> ";
	// do while loop for insert freature
	while (true) { 
	((cin >> s));
	
	
	//shift each word to the right 
	if(b[q] != " "){
	{
		for(int y = size-1; y >= q; y--){
			if(b[y] != " ")
				b[y+1] = b[y];
			
		}
	}
			b[q] = s;
			q++;
			i++;
			line++;
	}
	else {
	b[q] =s;
	q++;
	i++;
	line++;
	}
	
	while (cin.peek() == ' ')
		cin.get(a);
	
	if (cin.peek() == '\n')
		break;
	
	} 
	
	for(int a = 0; a < size; a++)
		undoinsert1[a] = undoinsert[a]; // function use for undo feature
	
	
	int numline = i / 8;  //determin how many line print in the table
	 // the followin is print out the table after insert feature
	max1(b, size, array1);
	cout << endl;
	cout << "File name : " << name << endl;
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(b,array1, a);
	r = r + 8;

	}
	pring(array1);
	z3 = i; // use for undo feature
}

void delete1(string d[], int size, int x, int y){
	
	int f;
	for(int a = 0; a < size; a++)
		undodelete[a] = d[a]; // function use for undo featrue
	
			//do while loop for error differente type enter
	 do {
		cout << "From Tile Number ==> ";
		cin >> x;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	x = x -1;
		//do while loop for error differente type enter
		 do {
			cout << "To Tile Number ==> ";
			cin >> y;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	f = y - x;
	i = i - f;
	//shift the words to the left after delete prosses
		for (int r = y; r <= size - 1; r++){
			if(d[r] != " ");
		d[x] = d[r];
		d[r] = " ";
		x++;
		}
	
	// The following is the print out the table after delete feature
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(d, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(d,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}

void overwrite(string o[], int size){
	for(int a = 0; a < size; a++)
		undooverwrite[a] = o[a];   // function use for undo feature
		char a;
		int t;
	char s[80];
	
	
	//do while loop for error differente type enter
	do {
		cout << "Tile number ==> ";
		cin >> t;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	t = t - 1;
	cout << "Text ==>";
	//do while loop for overwrite feature prosses
	while (true) { 
	((cin >> s));
	if(o[t] != " "){
		o[t] = s;
		t++;
	}
	else {
	o[t] = s;
	o[t] = " ";
	t++;
	
	}
	while (cin.peek() == ' ')
		cin.get(a);
	
	if (cin.peek() == '\n')
		break;
	
	}
		//The following is print out the table after overwrite prosses
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(o, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(o,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}


void save(string s[], int size){
	ofstream out_stream;  
	int arr[8]; 
	char name1[30]; //varible to stor the name of the new varible
	max1(s, size, arr);
	//The prosses for save the table 
	cout << "Enter file name ";
	cin >> name1;
	out_stream.open(name1);  
	out_stream << "File name : " << name << endl;
	out_stream << " |----+";
		for(int y = 0; y < 8; y++) // for loop to save the design of the table
	out_stream << setfill('-')<<setw(arr[y]+4 )<< "+";
		out_stream << endl;
		//save the design of the table using for loop
		int r= 0;
		out_stream << " |    | ";
	for(int y = 0; y < 8; y++ )
	out_stream << y+1 << setfill(' ') << setw(arr[y]+3) << " | ";  
	out_stream << endl;
		
		int numline = i / 8;
	//for loop to save the design of the table
	for(int a = 0; a <= numline; a++){
		
	out_stream << " |----+";
		for(int y = 0; y < 8; y++)
	out_stream << setfill('-')<<setw(arr[y]+4 )<< "+";
		out_stream << endl;
		
		
	
	if(a == 0)
	out_stream << " | 00 | ";
	else if(a == 1)
	out_stream << " | 08 | ";
	else 
		out_stream << " | "<<r<<" | ";
	r = r + 8;

	
	int x =0;
		for(int y = a * 8; y < (a +1) * 8; y++){
			out_stream << s[y];
				out_stream << setfill(' ') << setw(arr[x]-s[y].length()+3) << "|" << " ";
				
	x++;
}
	out_stream << endl;

	}
	out_stream << " |----+";
		for(int y = 0; y < 8; y++)
	out_stream << setfill('-')<<setw(arr[y]+4 )<< "+";
		out_stream << endl;
		
	out_stream.close();
	cout << "File saved. " << endl; //print out file saved after save prosses
			cout << endl;
			
}

void load(){
	
	string line;
			char name3[30]; //use for save the name of the file
			cout << endl;
			cout << "File name ==> ";
			cin >> name3; //sotr the name of the file
			cout << endl;
			ifstream file(name3);
			//if the name of the file does not exist
			if(file.fail()){
				cout << endl;
				cout << "SORRY " << endl << "THIS FILE DOES NOT EXIST " << endl;
				cout << "PLEASE TRY AGAIN ";
				cout << endl << endl;
			} 
			//else then load the file
		else 
		{
			while(getline(file, line))
			{
				
				cout << line << endl;
			}
			file.close(); //close the file after load
		}
		
}

void copy(string c[], int size){
	int x, y;
	
	//do while loop for error differente type enter
	do {
		cout << "From Tile Number ==> ";
		cin >> x;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	x = x -1;
	
	//do while loop for error differente type enter
	do {
		cout << "To Tile Number ==> ";
		cin >> y;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(99, '\n');  
		}while(cond);
	
	y = y - 1;
	int f = 0;
	//for loop to save the words in the new array1 use for show-clip
	for(int a = x; a <= y; a++){
		clip[f] = c[a];
	f++;
	size_clip = f;
	}
	
	//The followin is print out the table 
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(c, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(c,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}

void show_clip1(string b[], int size){
	cout << endl;
	cout << "Clipboard : ";
	cout << endl;
	//for loop to show clip
	for(int a = 0; a < size_clip ; a++)
		cout << clip[a] << " ";
	cout << endl;
	// the following is the print out the table after show clip prosses
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(b, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(b,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}

void past(string p[], int size){
	int t;
	 
	for(int a = 0; a < size ; a++)
			undopast[a] = p[a]; //function use for undo feature
	 
	 //do while loop for error differente type enter
	do {
		cout << "Tile Number ==> ";
		cin >> t;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	
	t = t -1;
	//for loop to shift each word to the right
	for(int a = 0; a < size_clip; a++){
		for(int f = size-1; f >= t; f--)
			if(p[f] != " "){
				p[f+1] = p[f];
			p[f] = " ";
			}
	}
	for(int a =0; a< size_clip; a++)
	{
		
		p[t] = clip[a];
		t++;
		i++;
		if(t > i)
			i = t;
	}
		
		//The following is the print out the table after past featrue
		int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(p, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(p,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}


void cut(string c[], int size){
	int x, y;
	int f1; 
	for(int a = 0; a < size; a++)
		undocut[a] = c[a];    //function use for undo featrue
	
	//do while loop for error differente type enter
	do {
		cout << "From Tile Number ==> ";
		cin >> x;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	x = x -1;
	//do while loop for error differente type enter
	do {
	cout << "To Tile Number ==> ";
	cin >> y;
		cond = cin.fail();
		cin.clear();
		 cin.ignore(999, '\n');  
		}while(cond);
	
	f1 = y - x;
	i = i - f1;
	int f = 0;
	for(int a = x; a < y; a++){
		clip[f] = c[a];
	f++;
	size_clip = f;
	}
	//for loop to shift each word to the left after cut prosses
		for (int r = y; r <= size-1; r++){
			if(c[r] != " ");
		c[x] = c[r];
		c[r] = " ";
		x++;
		}
	
	// the following is the print out the table after the prosses
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(c, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(c,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}

void find(string f[], int size){
	string serch; //varible use for serch prosses
	string find;
	cout << "Enter text to find : ";
	cin >> serch;  //stor the world
	//for loop to find the word
	for(int a = 0; a <= i; a++)
		if(f[a] == serch)
			find = f[a];
		
		//the following is the print out the table	
		int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(f, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	r = r + 8;

	
	//the prosses is if the word find then chang the character | to =
	int x =0;
	for(int y = a * 8; y < (a +1) * 8; y++){
		cout << f[y];
		if(f[y] != find)
			cout << setfill(' ') << setw(array1[x]-f[y].length()+3) << "|" << " ";
			else if(f[y] == find){
			cout << setfill(' ') << setw(array1[x]-f[y].length()+3) << "=" << " ";
		
			}
	x++;
}
	cout << endl;
	
	}
	pring(array1);
	
}

void undo(string u1[], int size){
	
	//The following is the print the table in the Previous time
	int numline = i / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(u1, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(u1,array1, a);
	r = r + 8;

	}
	pring(array1);
	
	
}

void undo2(string u[], int size){
	
	//function use for undo feature 
	//The follwoing is the print out the table
	int numline = line / 8;
	cout << endl;
	cout << "File name : " << name << endl;
	max1(u, size, array1);
	pring(array1);
	pring1(array1);
	int r= 0;
	for(int a = 0; a <= numline; a++){
	pring(array1);
	if(a == 0)
	cout << " | 00 | ";
	else if(a == 1)
	cout << " | 08 | ";
	else 
		cout << " | "<<r<<" | ";
	print(u,array1, a);
	r = r + 8;

	}
	pring(array1);
	
}

void max1(string l[], int size, int coll[8]){
	//function to determin the longest length for the words
	//for loop using to find the longest length
	for(int c = 0; c < 8; c++){
		coll[c] = l[c].length();
		for(int i = c + 8; i < size; i+=8 ){
		if(coll[c] < l[i].length())
		coll[c] = l[i].length();
		}
		}
}

void print(string p[],int arr[],  int a){
	//function use to print out the content of the array1 in the tabl
	//for loop using
	int x =0;
	for(int y = a * 8; y < (a +1) * 8; y++){
		cout << p[y];
		cout << setfill(' ') << setw(arr[x]-p[y].length()+3) << "|" << " ";
	x++;
}
	cout << endl;
		
}

void pring(int arr[]){
	//function to design table 
	//using for loop
	cout << " |----+";
	for(int y = 0; y < 8; y++)
		cout << setfill('-')<<setw(arr[y]+4 )<< "+";
		cout << endl;
}

void pring1(int arr[]){
	//function use to design table
	//using for loop
	cout << " |    | ";
	for(int y = 0; y < 8; y++ )
		cout << y+1 << setfill(' ') << setw(arr[y]+3) << " | "; 
		cout << endl;
}
