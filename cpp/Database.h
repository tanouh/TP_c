/**
 * @file Database.h
 * @brief This file contains the definition of the Database class.
 * 
 * The Database class manages multimedia objects and groups.
 * It provides methods to create, add, display, play, and remove multimedia objects and groups.
 * 
 * @author Tania Mahandry
 * @date 2025
 */
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



 /**
    * @class Database
    * @brief Singleton class to manage multimedia objects and groups.
    * 
    * The Database class provides methods to create, add, display, play, and remove multimedia objects and groups.
    * It uses maps to store multimedia objects and groups by their names.
    * The constructor is private to prevent direct creation of objects.
    */

class Database {
private:
    std::map<std::string, MultimediaPtr> multimediaObjects; // Map for multimedia objects
    std::map<std::string, GroupPtr> groups; // Map for groups

    Database(); // Private constructor to prevent direct creation of objects

public:
     /**
    * @brief Get the singleton instance of the Database class.
    * 
    * @return Reference to the singleton instance of the Database class.
    */
    static Database& getInstance(); // Singleton access method

    /**
    * @brief Create and add a Photo object to the database.
    * 
    * @param name The name of the photo.
    * @param path The file path of the photo.
    * @param latitude The latitude where the photo was taken.
    * @param longitude The longitude where the photo was taken.
    * @return Shared pointer to the created Photo object.
    */
    PhotoPtr createPhoto(const std::string& name, const std::string& path, double latitude, double longitude);
    /**
    * @brief Create and add a Video object to the database.
    * 
    * @param name The name of the video.
    * @param path The file path of the video.
    * @param duration The duration of the video in seconds.
    * @return Shared pointer to the created Video object.
    */
    VideoPtr createVideo(const std::string& name, const std::string& path, int duration);
    /**
    * @brief Create and add a Film object to the database.
    * 
    * @param name The name of the film.
    * @param path The file path of the film.
    * @param duration The duration of the film in seconds.
    * @param chapterDurations Array of durations for each chapter.
    * @param numChapters The number of chapters in the film.
    * @return Shared pointer to the created Film object.
    */
    FilmPtr createFilm(const std::string& name, const std::string& path, int duration, const int* chapterDurations, int numChapters);

    /**
    * @brief Create and add a Group object to the database.
    * 
    * @param groupName The name of the group.
    * @return Shared pointer to the created Group object.
    */
    GroupPtr createGroup(const std::string& groupName);
    /**
    * @brief Display information about a multimedia object by name.
    * 
    * @param name The name of the multimedia object.
    */
    void displayMultimedia(const std::string& name);
    /**
    * @brief Play a multimedia object by name.
    * 
    * @param name The name of the multimedia object.
    */
    void playMultimedia(const std::string& name);
     /**
    * @brief Display information about a group by name.
    * 
    * @param groupName The name of the group.
    */
    void displayGroup(const std::string& groupName);

     /**
    * @brief Remove a multimedia object from the database by name.
    * 
    * @param name The name of the multimedia object.
    */
    void removeMultimedia(const std::string& name);
     /**
    * @brief Remove a group from the database by name.
    * 
    * @param groupName The name of the group.
    */
    void removeGroup(const std::string& groupName);

    // Disable copying and assignment
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

#endif // DATABASE_H
