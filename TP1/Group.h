#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <iostream>
#include <memory>
#include "Multimedia.h"

class Group : public std::list<std::shared_ptr<Multimedia>> {
private:
    std::string name;  // Name of the group

public:
    // Constructor
    Group(const std::string& groupName) : name(groupName) {}

    // Accessor for the group name
    std::string getName() const { return name; }

    // Display method for all objects in the group
    void display(std::ostream& out) const {
        out << "Group: " << name << std::endl;
        for (const auto& media : *this) {
            media->display(out);
        }
    }
};

#endif // GROUP_H
