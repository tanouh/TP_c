#include "Film.h"
#include <cstring>

// Constructor with parameters
Film::Film(std::string name, std::string pathname, int duration, const int* chapterDurations, int numChapters)
    : Videos(name, pathname, duration), chapters(nullptr), numChapters(0) {
    setChapters(chapterDurations, numChapters);
}

// Default constructor
Film::Film() : Videos(), chapters(nullptr), numChapters(0) {}

// Destructor (frees allocated memory)
Film::~Film() {
    delete[] chapters;
}

// Copy constructor (deep copy)
Film::Film(const Film& other) : Videos(other), chapters(nullptr), numChapters(0) {
    copyChapters(other.chapters, other.numChapters);
}

// Copy assignment operator
Film& Film::operator=(const Film& other) {
    if (this != &other) {
        Videos::operator=(other);
        delete[] chapters;  // Free existing memory
        copyChapters(other.chapters, other.numChapters);
    }
    return *this;
}

// Function to copy chapters data safely
void Film::copyChapters(const int* chapterDurations, int numChapters) {
    this->numChapters = numChapters;
    if (numChapters > 0) {
        chapters = new int[numChapters];
        std::memcpy(chapters, chapterDurations, numChapters * sizeof(int));
    } else {
        chapters = nullptr;
    }
}

// Getter functions
const int* Film::getChapters() const {
    return chapters;
}

int Film::getNumChapters() const {
    return numChapters;
}

// Setter function (handles dynamic allocation)
void Film::setChapters(const int* chapterDurations, int numChapters) {
    delete[] chapters;  // Free previous memory to prevent leaks
    copyChapters(chapterDurations, numChapters);
}

// Display function
void Film::display(std::ostream& out) const {
    Videos::display(out);
    out << "Number of chapters: " << numChapters << "\\n";
    for (int i = 0; i < numChapters; ++i) {
        out << "Chapter " << (i + 1) << ": " << chapters[i] << " seconds\\n";
    }
}
