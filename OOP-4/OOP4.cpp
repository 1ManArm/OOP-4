#include <iostream>
#include <string>
#include <vector>

class Client {
private:
	std::string _name;
	int _id;
	//static std::vector<Client*>_clients;
	
	void showClient() {
		std::cout << "Имя: |" << _name << '\n';
		std::cout << "ID:  |" << _id << '\n';
		std::cout << "######################" << '\n';
	}
public:
	Client(std::string name, int id, std::vector<Client*>&client) : _name(name), _id(id) {
		client.push_back(this);
	}
	static void showClients(std::vector<Client*>&clients) {
		for (const auto& it : clients)
			it->showClient();
	}
};

//SOLID
//S - single responsibility principle
//Принцип единой ответственности

class Animal {
private:
	std::string _type;
public:
	Animal(std::string type) : _type(type) { }

	virtual std::string getSound() = 0;

};

class Cow : public Animal {
public:
	Cow(): Animal ("Cow") {}

	std::string getSound() override{
		return "Mooo";
	}
};

class Cat : public Animal {
public:
	Cat() : Animal("Cat") {}

	std::string getSound() override{
		return "Meow";
	}
};

class Dog : public Animal {
public:
	Dog() : Animal("Dog") {}

	std::string getSound() override{
		return "Bark";
	}
};

class Lion : public Animal {
public:
	Lion() : Animal("Lion") {}

	std::string getSound() override{
		return "RRRR";
	}
};

void AnimalSound(Animal &animal) {
	/*if (animal.getType() == "Lion")
		std::cout << "RRRRR";
	else if (animal.getType() == "Cat")
		std::cout << "MRRRR";
	else if (animal.getType() == "Dog")
		std::cout << "Gav";
	else if (animal.getType() == "Cow")
		std::cout << "Mooo";*/

	std::cout << animal.getSound() << std::endl;
}

class Vector {
private:
	int _size;
	int *_arrayPtr;
public:
	Vector() {
		_size = 0;
		_arrayPtr = nullptr;
	}

	void push_back(int element) {
		_size++;
		int *newArray = new int[_size];
		
		if (_arrayPtr == nullptr) {
			newArray[0] = element;
			_arrayPtr = newArray;
			return;
		}

		for (int i = 0; i < _size - 1; ++i)
			newArray[i] = _arrayPtr[i];

		newArray[_size - 1] = element;

		delete[]_arrayPtr;

		//int* temp = _arrayPtr;

		_arrayPtr = newArray;

		//delete[]temp;
	}

	void showElements() {
		for (int i = 0; i < _size; ++i)
			std::cout << i << " элемент: " << _arrayPtr[i] << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	/*std::vector<Client*>clients;
	Client* client1 = new Client("John", 20, clients);
	Client* client2 = new Client("Alex", 17, clients);
	Client* client3 = new Client("Kieran", 32, clients);
	Client::showClients(clients);*/

	/*Cat* cat = new Cat();
	Dog* dog = new Dog();
	Cow* cow = new Cow();
	Lion* lion = new Lion();
	AnimalSound(*cat);
	AnimalSound(*dog);
	AnimalSound(*cow);
	AnimalSound(*lion);*/

	Vector* vector = new Vector();
	vector->push_back(20);
	vector->push_back(35);
	vector->push_back(50);
	vector->push_back(15);
	vector->push_back(32);
	vector->showElements();

	return 0;
}