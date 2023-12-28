#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#include <string>
#endif

using namespace std;

#define EMPTY_LIST_ERROR "The list is empty."
#define INVALID_POS_ERROR "Invalid position."

template <class my_type>
class list {
	struct node {
		my_type data;
		node* next;
	};
  node* head = nullptr;
  int size = 0;

public:

	bool is_empty() {
		return size == 0;
	}
	int get_size() {
		return size;
	}
	node* create_node(my_type data) {
		return new node{data, nullptr};
	}
	void insert_beg(my_type data) {
		node* new_node = create_node(data);
		new_node->next = head;
		head = new_node;
		size++ ;
	}
	void delete_at(int pos) {
		if(is_empty()) cout << EMPTY_LIST_ERROR << endl;
		else if(pos > size || pos < 1) cout << INVALID_POS_ERROR << endl;
		else if(pos == 1) {
			node* tmp = head;
			head = head->next;
			delete tmp;
			size-- ;
		}
		else {
			node* tmp = head;
			int i = 1;
			while(i < pos - 1) {
				tmp = tmp->next;
				i++ ;
			}
			node* node_at_pos = tmp->next;
			tmp->next = node_at_pos->next;
			delete node_at_pos;
			size-- ;
		}
	}
	my_type get_data_at(int pos) { // to develop
		node* tmp = head;
		int i = 1;
		while(i < pos) {
			tmp = tmp->next;
			i++ ;
		}
		return tmp->data;
	}
};

class library {
	struct book {
		int book_id;
		string title;
		string author;
		string lang;
		string category;
		int pub_year;
		int pages_nbr;
		int rate;
	};
	list<book> lib;
	int cur_id = 0;

public:

	// int search_by_id(int b_id) {}

	// int find_book() {}

	void add_book(string title, string author, string lang = "en", string category = "-", int pub_year = 0, int pages_nbr = 0, int rate = 0) {
		book new_book = {cur_id, title, author, lang, category, pub_year, pages_nbr, rate};
		lib.insert_beg(new_book);
		cur_id++ ;
	}

	// void rm_book(int b_id) {}

	void print_book(book bk) {
		cout << endl;
		cout << "ID: " << bk.book_id << endl;
		cout << "Title: " << bk.title << endl;
		cout << "Author: " << bk.author << endl;
		cout << "Language: " << bk.lang << endl;
		cout << "Number of pages: " << bk.pages_nbr << endl;
		cout << "Rate: " << bk.rate << "/5"  << endl;
		cout << endl;
	}

	void list_books() {
		cout << "** Book list **" << endl << endl;
		for(int i=1; i<=lib.get_size(); i++)
			print_book(lib.get_data_at(i));
		cout << "Total books: " << lib.get_size() << endl;
	}

	// void update_book_info() {}
};
