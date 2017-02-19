#include <iostream>
#include <string>

class Animal{
	std::string _name;
	int _age;

	public:
		Animal(int age){ _age = age; }
		Animal(std::string name, int age){ _age = age; _name = name;}

		std::string getName() const { return _name; }
		int getAge() const { return _age; }

		void sleep(){ std::cout << getName() << " sleeps." << std::endl; }

		bool operator==(const Animal &animal){ return _name == animal.getName() && _age == animal.getAge(); }

		friend std::ostream & operator << (std::ostream &o, const Animal &a) { 
			o << "Name: " << a._name << " Age: " << a._age;
			return o;
		}
};

class Cat: public Animal{
	int _lives;

	public:
		Cat(std::string name, int age, int lives):Animal(name, age) { _lives = lives;}

		int getLives() const { return _lives; }

		void climb(){ std::cout << getName() << ": climbs a tree." << std::endl; }

		bool operator==(const Cat &cat){ return (Animal) *this == (Animal &) cat && _lives == getLives(); }

		friend std::ostream & operator << (std::ostream &o, const Cat &cat) { 
			o << (Animal&) cat << " Lives: " << cat._lives;
			return o;
		}
};

class Dog: public Animal{
	double _weight;

	public:
		Dog(std::string name, int age, double weight):Animal(name, age) { _weight = weight;}

		double getWeight() const { return _weight; }

		void bark(){ std::cout << getName() << " says: 'Woof Woof'." << std::endl; }

		bool operator==(const Dog &dog){ return (Animal) *this == (Animal &) dog && _weight == getWeight(); }

		friend std::ostream & operator << (std::ostream &o, const Dog &dog) { 
			o << (Animal&) dog << " Weight: " << dog._weight;
			return o;
		}
};

int main(){
	Animal animal("Mogli", 19);
	Animal animal2("Bali", 19);
	Animal animal3(15);

	if(animal == animal2) std::cout << "Same animal." << std::endl;
	else std::cout << "Diferent animals." << std::endl;

	Dog dog("Tobias", 11, 2.5);
	Dog dog2("Bobby", 9, 15.6);

	if(dog == dog2) std::cout << "Same dog." << std::endl;
	else std::cout << "Diferent dogs." << std::endl;

	Cat cat("Lemon", 9, 5);
	Cat cat2("Simba", 5, 15);

	if(cat == cat2) std::cout << "Same cat." << std::endl;
	else std::cout << "Diferent cats." << std::endl;

	dog.bark();
	cat.climb();
	animal.sleep();

	std::cout << animal << std::endl;
	std::cout << animal2 << std::endl;
	std::cout << animal3 << std::endl;
	std::cout << dog << std::endl;
	std::cout << dog2 << std::endl;
	std::cout << cat << std::endl;
	std::cout << cat2 << std::endl;

	return 0;
};