#include "libms.hpp"

int main() {
	library lib;
	string title;
	string author;

	for(int i=0; i<3; i++) {
		cout << "Title: ";
		getline(cin, title);
		cout << "Author: ";
		getline(cin, author);
		lib.add_book(title, author);
	}
	lib.list_books();
	return 0;
}
