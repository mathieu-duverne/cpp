#include <iostream>
#include <memory>
#include <string>

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}
    ~Person() {
        std::cout << "Person " << name << " is being destroyed." << std::endl;
    }

    std::string getName() const { return name; }
    int getAge() const { return age; }

    void setName(const std::string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

private:
    std::string name;
    int age;
};

void useRawPointer() {
    Person* person = new Person("Alice", 30);
    std::cout << "Using raw pointer: " << person->getName() << ", " << person->getAge() << std::endl;
    delete person;
}

void useUniquePointer() {
    std::unique_ptr<Person> person = std::make_unique<Person>("Bob", 25);
    std::cout << "Using unique_ptr: " << person->getName() << ", " << person->getAge() << std::endl;
}

void useSharedPointer() {
    std::shared_ptr<Person> person1 = std::make_shared<Person>("Charlie", 40);
    {
        std::shared_ptr<Person> person2 = person1;
        std::cout << "Using shared_ptr (person1): " << person1->getName() << ", " << person1->getAge() << std::endl;
        std::cout << "Using shared_ptr (person2): " << person2->getName() << ", " << person2->getAge() << std::endl;
    }
    std::cout << "Using shared_ptr (person1) after person2 goes out of scope: " << person1->getName() << ", " << person1->getAge() << std::endl;
    }

int main() {
    useRawPointer();
    useUniquePointer();
    useSharedPointer();
    return 0;
}