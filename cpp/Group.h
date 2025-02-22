/**
 * @file Group.h
 * @brief Group class to store a collection of multimedia objects
 * @author Tania Mahandry
 * @date 2025
 */

#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>


using MultimediaPtr = std::shared_ptr<Multimedia>;

/**
 * @class Group
 * @brief Group class to store a collection of multimedia objects

 */
class Group : public std::list<MultimediaPtr>{
private:
    std::string name;  // Name of the group

public:
    /**
     * @brief Group constructor
     * @param groupName The name of the group
     */
    Group(const std::string& groupName) : name(groupName) {}

    /**
     * @brief Retrieves the name of the group
     * @return The name of the group as a string
     */
    std::string getName() const { return name; }

    /** 
     * @brief Displays the group information
     * @param out The output stream to display the information
     */
    void display(std::ostream& out) const {
        out << "Group: " << name << std::endl;
        for (const auto& media : *this) {
            media->display(out);
        }
    }
    /**
     * @brief Destructor for the Group class
     */
    ~Group() {
        std::cout << "Destroying Group: " << name << std::endl;
    }

    /**
     * @brief Add a multimedia object to the group
     * @param media The multimedia object to add to the group
     */
    void addMedia(MultimediaPtr media) {
        this->push_back(media);
    }
    /**
     * @brief Remove a multimedia object to the group
     * @param media The multimedia object to add to the group
     */
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
