#include "Database.h"
#include <iostream>

Database::Database() {}

// Static method to get the instance of Database (Singleton)
Database& Database::getInstance() {
    static Database instance;
    return instance;
}

// Create and add a Photo object to the multimedia map
PhotoPtr Database::createPhoto(const std::string& name, const std::string& path, double latitude, double longitude) {
    auto photo = std::make_shared<Photos>(name, path, latitude, longitude);
    multimediaObjects[name] = photo;
    return photo;
}

// Create and add a Video object to the multimedia map
VideoPtr Database::createVideo(const std::string& name, const std::string& path, int duration) {
    auto video = std::make_shared<Videos>(name, path, duration);
    multimediaObjects[name] = video;
    return video;
}

// Create and add a Film object to the multimedia map
FilmPtr Database::createFilm(const std::string& name, const std::string& path, int duration, const int* chapterDurations, int numChapters) {
    auto film = std::make_shared<Film>(name, path, duration, chapterDurations, numChapters);
    multimediaObjects[name] = film;
    return film;
}

// Create and add a Group object to the groups map
GroupPtr Database::createGroup(const std::string& groupName) {
    auto group = std::make_shared<Group>(groupName);
    groups[groupName] = group;
    return group;
}

// Display a multimedia object by its name
void Database::displayMultimedia(const std::string& name) {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        it->second->display(std::cout); // Call the display method of the multimedia object
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

// Play a multimedia object by its name
void Database::playMultimedia(const std::string& name) {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        it->second->play(); // Call the play method of the multimedia object
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

// Display a group by its name
void Database::displayGroup(const std::string& groupName) {
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        it->second->display(std::cout); // Display group details
    } else {
        std::cout << "Group not found: " << groupName << std::endl;
    }
}

// Remove a multimedia object by its name from the database
void Database::removeMultimedia(const std::string& name) {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        // Remove object from all groups first
        for (auto& groupPair : groups) {
            groupPair.second->removeMedia(it->second);
        }
        multimediaObjects.erase(it);  // Then remove from the map
    } else {
        std::cout << "Multimedia object not found: " << name << std::endl;
    }
}

// Remove a group by its name from the database
void Database::removeGroup(const std::string& groupName) {
    auto it = groups.find(groupName);
    if (it != groups.end()) {
        // Remove the group
        groups.erase(it);
    } else {
        std::cout << "Group not found: " << groupName << std::endl;
    }
}
