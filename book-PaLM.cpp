//Personal Library Manager (Book PaLM) created by Isaac Hepworth
//finished on 05/2/17 

#include <iostream>
#include <list>
#include <fstream>

using namespace std;
list<string> myBookList;
list<string> myWishList;
list<string>::iterator it;

string book = "";
string title = "";
string author = "";
string ispn = "";
string genre = "";
char yesOrNo = ' ';
int temp = 0;
int temp1 = 0;

	
// comparison, not case sensitive.
bool compare_nocase (const string& first, const string& second){
	unsigned int i=0;
	while ((i<first.length()) && (i<second.length())) {
		if (tolower(first[i])<tolower(second[i])){
			return true;
		}
		else if (tolower(first[i])>tolower(second[i])){
			return false;
		} 
		i++;
	}
	return (first.length() < second.length());
}
//test Author for invalid characters
bool testAuthor(string st){
	if(st.find_first_of("!@#$%^&*/()_-+='"";:|?>1234567890") == string::npos){
		return true;
	}else {
		return false;
	}
}
//test ispn for invalid characters
bool testIspn (string st){
	st.erase(std::remove(st.begin(), st.end(), '-'), st.end());
	if((st.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*/()_+='"";:|?,>. ") == string::npos && (st.length() == 10 || st.length() == 13)) || st == ""){
		return true;
	}else {
		return false;
	}
}
//test genre for invalid characters
bool testGenre(string st){
	if(st.find_first_of("!@#$%^&*/()_-+='"";:|?>1234567890") == string::npos){
		return true;
	}else {
		return false;
	}
}
//gives the user a chose to stop or contenue
bool choose(){
	cout << "Would you like to enter another book? (Y/N)";
	cin >> yesOrNo;
	while(1 != 0){
		cin.clear();
		cin.ignore(100, '\n');
		if(toupper(yesOrNo) == 'Y'){
			cout << endl;
			return true;
		}else if(toupper(yesOrNo) == 'N'){
			cout << endl;
			return false;
		}else{
			cout << "Please enter Y/N." << endl;
			cout << "Would you like to enter another book? (Y/N)";
			cin >> yesOrNo;
		}	
	}
}
//adds the file bookList.txt into the list myBookList
void fileToBook(){
	ifstream inFile;
	inFile.open("bookList.txt", ios::in);
	if (inFile.is_open()){
		getline(inFile, book, '\n');
		while (!inFile.eof()){
			myBookList.push_back (book);
			getline(inFile, book, '\n');
		}
	}else {
		cout << "bookList.txt could not be opened." << endl << endl;
	}
	inFile.close();
}
//adds the file wishList.txt into the list myWishList
void fileToWish(){
	ifstream inFile;
	inFile.open("wishList.txt", ios::in);
	if (inFile.is_open()){
		getline(inFile, book, '\n');
		while (!inFile.eof()){
			myWishList.push_back (book);
			getline(inFile, book, '\n');
		}			
	}else {
		cout << "wishList.txt could not be opened." << endl << endl;
	}
	inFile.close();
}
//displays the books in myBookList alphibeticly and numbered
void displayBook(){
	myBookList.sort(compare_nocase);
	temp1 = 1;
	cout << "Your Books:" << endl;
	for (it = myBookList.begin(); it != myBookList.end(); it++){
		cout << temp1 << ") " << *it << endl;
		temp1++;
	}
	cout << endl;
}
//displays the books in myWishList alphibeticly and numberd
void displayWish(){
	myWishList.sort(compare_nocase);
	temp1 = 1;
	cout << "Your Wish list:" << endl;
	for (it = myWishList.begin(); it != myWishList.end(); it++){
		cout << temp1 << ") " << *it << endl;
		temp1++;
	}
	cout << endl;
}
//adds books into the list myBookList
void addBook(){		
	cout << "Enter title of book (-1 to exit): ";
	getline(cin, title);
	while (title != "-1"){
		cout << "Enter Author of book: ";
		getline(cin, author);
		if (testAuthor(author)){
			cout << "Enter ISPN of book (can leave blank): ";
			getline(cin, ispn);
			if(testIspn(ispn)){
				cout << "Enter Genre of book (can leave blank): ";
				getline(cin, genre);
				if(testGenre(genre) || genre == ""){
					book = title + " *** " + author + " *** " + ispn + " *** " + genre;
				    myBookList.push_back (book);
				}else{
					cout << "The Genre you entered is invalid." << endl;
				}
			}else {
				cout << "The ISPN number you entered is invalid." << endl;
			}
		}else {
			cout << "The Author you entered is invalid." << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter title of book: ";
			getline(cin, title);
		}else{
			break;
		}
	}
	myBookList.sort(compare_nocase);
	myBookList.unique();
	cout << endl;
}
//adds books into the list myWishList
void addWish(){
	cout << "Enter title of book (-1 to exit): ";
	getline(cin, title);
	while (title != "-1"){
		cout << "Enter Author of book: ";
		getline(cin, author);
		if (testAuthor(author)){
			cout << "Enter ISPN of book (can leave blank): ";
			getline(cin, ispn);
			if(testIspn(ispn)){
				cout << "Enter Genre of book (can leave blank): ";
				getline(cin, genre);
				if(testGenre(genre) || genre == ""){
					book = title + " *** " + author + " *** " + ispn + " *** " + genre;
					myWishList.push_back (book);
				}else{
					cout << "The Genre you entered is invalid." << endl;
				}
			}else {
				cout << "The ISPN number you entered is invalid." << endl;
			}
		}else {
			cout << "The Author you entered is invalid." << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter title of book: ";
			getline(cin, title);
		}else{
			break;
		}
	}
	myWishList.sort(compare_nocase);
	myWishList.unique();
	cout << endl;
}
//removes books by title from the list myBookList 
void removeBook(){
	cout << "Enter the title of the book to be remove (-1 to exit): ";
	getline(cin, book);
	cout << endl;
	while (book != "-1"){
		temp = 0;
		temp1 = 1;
		for (it = myBookList.begin(); it != myBookList.end(); it++){
			string::size_type pos = it->find(" *** ");
			title = it->substr(0, pos);
			if(book == title){
				myBookList.remove(*it);
				cout << "Removed book" << endl;
				temp1++;
			}
		}
		if(temp1 == 1){
			cout << "book not found" << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter the title of the book to be remove: ";
			getline(cin, book);
		}else{
			break;
		}
	}
	cout << endl;
}
//removes books by title from the list myWishList
void removeWish(){
	cout << "Enter the title of the book to be remove (-1 to exit): ";
	getline(cin, book);
	cout << endl;
	while (book != "-1"){
		temp = 0;
		temp1 = 1;
		for (it = myWishList.begin(); it != myWishList.end(); it++){
			string::size_type pos = it->find(" *** ");
			title = it->substr(0, pos);
			if(book == title){
				myWishList.remove(*it);
				cout << "Removed book" << endl;
				temp1++;
			}
		}
		if(temp1 == 1){
			cout << "book not found" << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter the title of the book to be remove: ";
			getline(cin, book);
		}else{
			break;
		}
	}
	cout << endl;
}
//finds books by contents from the list myBookList
void findBook(){
	cout << "Enter the title, Author, or ISPN of the book to find (-1 to exit): ";
	getline(cin, book);
	while (book != "-1"){
		temp1 = 1;
		for (it = myBookList.begin(); it != myBookList.end(); it++){
			temp = it->find(book);
			if(temp != string::npos){
				cout << temp1 << ") " << *it << endl;
				temp1++;
			}
		}
		if(temp1 == 1){
			cout << "book not found" << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter the title, Author, or ISPN of the book to find: ";
			getline(cin, book);
			cout << endl;
		}else{
			break;
		}
	}
	cout << endl;
}
//finds books by contents from the list myWhishList
void findWish(){
	cout << "Enter the title, Author, or ISPN of the book to find (-1 to exit): ";
	getline(cin, book);
	cout << endl;
	while (book != "-1"){
		temp1 = 1;
		for (it = myWishList.begin(); it != myWishList.end(); ++it){
			temp = it->find(book);
			if(temp != string::npos){
				cout << temp1 << ") " << *it << endl;
				temp1++;
			}
		}
		if(temp1 == 1){
			cout << "book not found" << endl;
		}
		cout << endl;
		if(choose()){
			cout << "Enter the title, Author, or ISPN of the book to find: ";
			getline(cin, book);
			cout << endl;
		}else{
			break;
		}
	}
}
//writes myBookList to file bookList.txt by clearing the old file then writing to it
void bookToFile(){
	ofstream outFile;
	outFile.open("bookList.txt", ios::out | ios::trunc);
	if (outFile.is_open()){	
		while (!myBookList.empty()){
			outFile << myBookList.front() << endl;
			myBookList.pop_front();
		}
	}else {
		cout << "File could not be opened." << endl << endl;
	}
	outFile.close();
	cout << endl;
}
//writes myWishList to file wishList.txt by clearing the old file then writing to it
void wishToFile(){
	ofstream outFile;
	outFile.open("wishList.txt", ios::out | ios::trunc);
	if (outFile.is_open()){	
		while (!myWishList.empty()){
			outFile << myWishList.front() << endl;
			myWishList.pop_front();
		}
	}else {
		cout << "File could not be opened." << endl << endl;
	}
	outFile.close();
	cout << endl;
}
//main
int main(int argc, char *argv[]) {
	int menuOption = 0;
		
	fileToBook();
	fileToWish();
	while (menuOption != 9){
		cout << "1 Display Book list." << endl;
		cout << "2 Display Wish list." << endl;
		cout << "3 Add book to Book list." << endl;
		cout << "4 Add book to Wish list." << endl;
		cout << "5 Remove a book from book list." << endl;
		cout << "6 Remove a book from Wish list." << endl;
		cout << "7 Find a book in Book list." << endl;
		cout << "8 Find a book in Wish list." << endl;
		cout << "9 Exit program." << endl;
		cout << "Please enter your choice: ";
		cin >> menuOption;
		cin.clear();
		cin.ignore(100, '\n');
		while(!cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input.  Try again: ";
			cin >> menuOption;
		}
		cout << endl;
		if (menuOption == 1){
			displayBook();
		} else if (menuOption == 2){
			displayWish();
		} else if (menuOption == 3){
			addBook();
		} else if (menuOption == 4){
			addWish();
		} else if (menuOption == 5){
			displayBook();
			removeBook();		
		} else if (menuOption == 6){
			displayWish();
			removeWish();
		} else if (menuOption == 7){
			findBook();
		} else if (menuOption == 8){
			findWish();
		}
	}
	bookToFile();
	wishToFile();
}