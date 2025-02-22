/**
 * @file Film.h
 * @brief The Film class is a derived class of the Videos class. It represents a film with chapters.
 * @author Tania Mahandry
 * @date 2025
 */
#ifndef FILM_H
#define FILM_H

#include "Videos.h"
#include <iostream>

/**
 * @class Film
 * @brief A class representing a film, which is a type of video with chapters.
 * 
 * The Film class inherits from the Videos class and adds functionality to handle chapters.
 */
class Film : public Videos {
private:
    int* chapters = nullptr; ///< Pointer to an array of chapter durations
    int numChapters = 0;     ///< Number of chapters

    /**
     * @brief Copies chapter durations from another array.
     * 
     * @param chapterDurations Pointer to the array of chapter durations to copy.
     * @param numChapters Number of chapters in the array.
     */
    void copyChapters(const int* chapterDurations, int numChapters);

public:
    /**
     * @brief Constructs a Film object with the specified parameters.
     * 
     * @param name Name of the film.
     * @param pathname Path to the film file.
     * @param duration Duration of the film.
     * @param chapterDurations Pointer to the array of chapter durations.
     * @param numChapters Number of chapters in the array.
     */
    Film(std::string name, std::string pathname, int duration, const int* chapterDurations, int numChapters);

    /**
     * @brief Default constructor for the Film class.
     */
    Film();

    /**
     * @brief Destructor for the Film class.
     */
    ~Film();

    /**
     * @brief Copy constructor for the Film class.
     * 
     * @param other The Film object to copy from.
     */
    Film(const Film& other);

    /**
     * @brief Assignment operator for the Film class.
     * 
     * @param other The Film object to assign from.
     * @return A reference to the assigned Film object.
     */
    Film& operator=(const Film& other);

    /**
     * @brief Gets the array of chapter durations.
     * 
     * @return A pointer to the array of chapter durations.
     */
    const int* getChapters() const;

    /**
     * @brief Gets the number of chapters.
     * 
     * @return The number of chapters.
     */
    int getNumChapters() const;

    /**
     * @brief Sets the chapter durations.
     * 
     * @param chapterDurations Pointer to the array of chapter durations.
     * @param numChapters Number of chapters in the array.
     */
    void setChapters(const int* chapterDurations, int numChapters);

    /**
     * @brief Displays the film information.
     * 
     * @param out The output stream to display the information to.
     */
    void display(std::ostream& out) const override;
};

#endif // FILM_H
