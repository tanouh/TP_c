#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
#include <map>
#include <string>
#include "Multimedia.h"
#include "Photos.h"
#include "Videos.h"
#include "Film.h"
#include "Group.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;
using PhotoPtr = std::shared_ptr<Photos>;
using VideoPtr = std::shared_ptr<Videos>;
using FilmPtr = std::shared_ptr<Film>; 

class Database {
private:
    std::map<std::string, MultimediaPtr> multimediaObjects; // Map for multimedia objects
    std::map<std::string, GroupPtr> groups; // Map for groups

    Database(); // Private constructor to prevent direct creation of objects

public:
    static Database& getInstance(); // Singleton access method

    // Methods to create and add multimedia objects
    PhotoPtr createPhoto(const std::string& name, const std::string& path, double latitude, double longitude);
    VideoPtr createVideo(const std::string& name, const std::string& path, int duration);
    FilmPtr createFilm(const std::string& name, const std::string& path, int duration, const int* chapterDurations, int numChapters);

    // Method to create and add groups
    GroupPtr createGroup(const std::string& groupName);

    // Methods to display multimedia or groups by name
    void displayMultimedia(const std::string& name);
    void playMultimedia(const std::string& name);
    void displayGroup(const std::string& groupName);

    // Methods to remove multimedia or groups by name
    void removeMultimedia(const std::string& name);
    void removeGroup(const std::string& groupName);

    // Disable copying and assignment
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

#endif // DATABASE_H
