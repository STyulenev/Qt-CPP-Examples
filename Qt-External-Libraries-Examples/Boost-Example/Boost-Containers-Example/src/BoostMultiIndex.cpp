#include "BoostMultiIndex.h"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>

namespace BoostMultiIndex {

class Person
{
public:
    std::string name;
    std::string surname;
    uint8_t age;

    Person(std::string name, std::string surname, uint8_t age) :
        name(std::move(name)),
        surname(std::move(surname)),
        age(age)
    {

    }
};

using Persons = boost::multi_index::multi_index_container<
    Person, // or boost::shared_ptr<Person>
    boost::multi_index::indexed_by<
        // Для получения по имени, как ключу
        boost::multi_index::hashed_unique<
            boost::multi_index::tag<class PersonsByName>, // .get<PersonsByName>();, else .get<0>;
            boost::multi_index::member<Person, decltype(Person::name), &Person::name> // для доступа к public поле напрямую по имени
        >,
        // Для получения по фамилии, как ключу
        boost::multi_index::hashed_unique<
            boost::multi_index::tag<class PersonsBySurname>,
            boost::multi_index::member<Person, decltype(Person::surname), &Person::surname>
        >,
        // Для получения по имени и фамилии, как ключу
        boost::multi_index::hashed_non_unique<
            boost::multi_index::tag<class PersonsByNameAndSurname>,
            boost::multi_index::composite_key<
                Person,
                boost::multi_index::member<Person, decltype(Person::name), &Person::name>,
                boost::multi_index::member<Person, decltype(Person::surname), &Person::surname>
            >
        >
    >
>;

auto exampleBoostMultiIndex() -> void
{
    Persons persons
    {
        Person{"Anna", "Kisly", 24},
        Person{"Julia", "Smith", 44},
        Person{"Kamila", "Grey", 45}
    };

    auto const& personsByName = persons.get<PersonsByName>();
    auto annaIter = personsByName.find("Anna");
    qDebug() << "find by name:" << annaIter->name.c_str() << annaIter->surname.c_str() << annaIter->age;

    auto const& personsBySurname = persons.get<PersonsBySurname>();
    auto juliaIter = personsBySurname.find("Smith");
    qDebug() << "Find by surname:" << annaIter->name.c_str() << annaIter->surname.c_str() << annaIter->age;

    auto const& personsByNameAndSurname = persons.get<PersonsByNameAndSurname>();
    auto kamilaIter = personsByNameAndSurname.find(boost::make_tuple("Kamila", "Grey"));
    qDebug() << "Find by name and surname:" << kamilaIter->name.c_str() << kamilaIter->surname.c_str() << kamilaIter->age;
}

class Animal
{
private:
    std::string name;
    int legs;

public:
    Animal(std::string name, int legs) :
        name{std::move(name)},
        legs(legs)
    {

    }

    auto operator<(const Animal& animal) const -> bool {
        return this->legs < animal.legs;
    }

    auto getName() const -> const std::string& {
        return this->name;
    }
};

using Animals = boost::multi_index::multi_index_container<
        Animal, // or boost::shared_ptr<Animal>
        boost::multi_index::indexed_by<
            boost::multi_index::ordered_unique<boost::multi_index::identity<Animal>
        >,
        boost::multi_index::hashed_unique<
            boost::multi_index::tag<class AnimalsByName>, // .get<AnimalsByName>();, else .get<1>;
            boost::multi_index::const_mem_fun<Animal, const std::string&, &Animal::getName> // для доступа к private поле через геттер
            >
        >
    >;

auto exampleBoostMultiIndex2() -> void
{
    Animals animals;

    animals.emplace("cat", 4);
    animals.emplace("shark", 0);
    animals.emplace("spider", 8);

    qDebug() << animals.begin()->getName().c_str();

    const auto& name_index = animals.get<AnimalsByName>();
    qDebug() << name_index.count("shark");
}

} // namespace BoostMultiIndex
