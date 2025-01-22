#ifndef FILM_H
#define FILM_H

#include "Videos.h"
#include <iostream>

class Film : public Videos {
private:
    int* chapters = nullptr; // Pointer to an array of chapter durations
    int numChapters = 0;     // Number of chapters

    void copyChapters(const int* chapterDurations, int numChapters);

public:
    // Constructors
    Film(std::string name, std::string pathname, int duration, const int* chapterDurations, int numChapters);
    Film();

    // Destructor
    ~Film();

    // Copy constructor
    Film(const Film& other);

    // Assignment operator
    Film& operator=(const Film& other);

    // Getter functions
    const int* getChapters() const;
    int getNumChapters() const;

    // Setter function
    void setChapters(const int* chapterDurations, int numChapters);

    // Display function
    void display(std::ostream& out) const override;
};

#endif // FILM_H
