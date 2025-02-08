#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>


using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group : public std::list<MultimediaPtr>{
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
    // Destructor
    ~Group() {
        std::cout << "Destroying Group: " << name << std::endl;
    }

    // Remove an object from the group
    void removeMedia(MultimediaPtr media) {
        auto it = std::find_if(this->begin(), this->end(), 
                           [&media](const std::shared_ptr<Multimedia>& ptr) { 
                               return ptr == media; 
                           });
        if (it!= end()) {
            this->erase(it); 
            if (media.use_count() == 1){
                media.reset();

            }else {
                std::cout << "Object " << media->getFileName() << " is still referenced elsewhere." << std::endl;
            }
        } else {
            std::cout << "Object not found in the group." << std::endl;
        }
    }
};

#endif // GROUP_H
