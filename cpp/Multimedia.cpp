#include "Multimedia.h"
// Constructor
Multimedia::Multimedia() : Multimedia("", "") {}

// Getters
std::string Multimedia::getFileName() const {
    return this->fileName;
}

std::string Multimedia::getFilePath() const {
        return this->filePath;
}

// Setters
void Multimedia::setFileName(const std::string& name) {
        fileName = name;
}

void Multimedia::setFilePath(const std::string& path) {
        filePath = path;
}

// Print functions
void Multimedia::displayFileName(std::ostream& out) const {
    out << "File name: " << fileName << std::endl;
}
void Multimedia::displayFilePath(std::ostream& out) const {
    out << "File path: " << filePath << std::endl;
}
void Multimedia::display(std::ostream& out) const {
    out << "Multimedia base details :" << std::endl; 
    out << "\tFile name: " << fileName << std::endl;
    out << "\tFile path: " << filePath << std::endl;
}
