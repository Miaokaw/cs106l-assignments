#ifndef CLASS_H
#define CLASS_H
#include <string>

class Person {
    int _age;;
    const std::string _name;
    std::string _friendName{""};

    int afterOneYear() {
        return ++_age;
    }

public:
    Person()
        : _age(0), _name("") {
    }

    Person(const int age,const std::string& name)
        : _age(age), _name(name) {
    }

    int getAge() { return afterOneYear(); }

    std::string getName() const { return _name; }

    std::string getFriendName() const { return _friendName; }
    void setFriendName(const std::string& friendName) {
        _friendName = friendName;
    }
};

#endif // CLASS_H
