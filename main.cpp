#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem{

private:
	bool completed;
	int id;
	std::string description;

public:
	TodoItem() : id(0), description(""), completed(false) {}
	~TodoItem() = default;

	bool create(std::string newDescription) {
		id = rand() % 100 + 1;
		description = newDescription;
		return 1;
	}

	int getID() {return id;}
	bool isCompleted() {return completed;}
	std::string getDescription() {return description;}

	void setCompleted(bool val) {completed = val;}

};

int main() {

	char inputOption;
	int inputID;
	std::string inputDescription;
	std::string version = "v0.2.0";
	
	std::list<TodoItem> TodoItems;
	std::list<TodoItem>::iterator it;

	srand(time(NULL));

	TodoItems.clear();

	while(1) {

		system("cls");

		std::cout << "Todo" << version << std::endl;

		for(it = TodoItems.begin(); it != TodoItems.end(); it++) {
			
			std::string completed = it->isCompleted() ? "done" : "not done";

			std::cout << it->getID() << " | " << it->getDescription() << " | " << completed << std::endl;

		}

		if(TodoItems.empty()) {
			std::cout << "Add your first todo" << std::endl;
		}

		std::cout << std::endl << std::endl;

		std::cout << "[a]dd new todo" << std::endl;
		std::cout << "[c]omplete a todo" << std::endl;
		std::cout << "[q]uit" << std::endl;
	
		std::cout << "Enter your choice: ";
		std::cin >> inputOption;

		if(inputOption == 'q') {
			std::cout << "Have a great day";
			break;
		}

		else if(inputOption == 'a') {
			std::cout << "Enter a description" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, inputDescription);

			TodoItem newItem;
			newItem.create(inputDescription);

			TodoItems.push_back(newItem);

		}

		else if(inputOption == 'c') {
			
			std::cout << "Enter the id";
			std::cin >> inputID;

			for(it = TodoItems.begin(); it != TodoItems.end(); it++) {

				if(inputID == it->getID()) {
					it->setCompleted(true);
					break;
				}

			}
					
		}
			
	}

	return 0;
		

}
