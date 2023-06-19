#include "BoostIntrusive.h"

#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>

// boost::intrusive::link_mode<boost::intrusive::auto_unlink> - автоматическое удаление, тогда можно удалять без pop_back

class Person : public boost::intrusive::list_base_hook</* mode */>
{
private:
    std::string name;
    int age;

public:
    Person() = delete;

    Person(std::string name, int age) :
        name(std::move(name)),
        age(age)
    {

    }

    ~Person() = default;

    auto getName() const -> const std::string&
    {
        return this->name;
    }

    auto getAge() const -> int
    {
        return this->age;
    }

    auto setName(const std::string& name) -> void
    {
        this->name = name;
    }

    auto setAge(int age) -> void
    {
        this->age = age;
    }

};

auto BoostIntrusive::exampleBoostIntrusiveList() -> void
{
    Person firstPerson  { "Jimm", 44 };
    Person secondPerson { "Tom",  17 };
    Person thirdPerson  { "Kate", 35 }; // не может быть удалёт с помощью delete
    Person* fourthPerson = new Person("Mark", 13); // может быть удалёт с помощью delete

    boost::intrusive::list<Person> people;

    people.push_back(firstPerson);
    people.push_back(secondPerson);
    people.push_back(thirdPerson);
    people.push_back(*fourthPerson);

    firstPerson.setName("Anna");

    //people.pop_back();   // сначала убрать из списка
    //delete fourthPerson; // потом удалить, или

    people.pop_back_and_dispose([](Person* person) { delete person; }); // убирает и удаляет элемент

    for (const auto& person : people)
        qDebug() << person.getName().c_str();
}

class Animal
{
private:
    std::string name;
    int age;
public:
    boost::intrusive::set_member_hook<> set_hook;

    Animal() = delete;

    Animal(std::string n, int age) :
        name(std::move(n)),
        age(age)
    {

    }

    ~Animal() = default;

    bool operator<(const Animal& animal) const
    {
        return this->age < animal.age;
    }

    auto getName() const -> const std::string&
    {
        return this->name;
    }

    auto getAge() const -> int
    {
        return this->age;
    }

    auto setName(const std::string& name) -> void
    {
        this->name = name;
    }

    auto setAge(int age) -> void
    {
        this->age = age;
    }

};

auto BoostIntrusive::exampleBoostIntrusiveSet() -> void
{
    Animal firstAnimal("cat", 12);
    Animal secondAnimal("shark", 7);
    Animal thirdAnimal("spider", 1);

    typedef boost::intrusive::member_hook<Animal, boost::intrusive::set_member_hook<>, &Animal::set_hook> hook;
    boost::intrusive::set<Animal, hook> animals;

    animals.insert(firstAnimal);
    animals.insert(secondAnimal);
    animals.insert(thirdAnimal);

    for (const auto& animal : animals)
        qDebug() << animal.getName().c_str();
}
