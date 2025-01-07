#include "Myclass.h"

// Constructor
Myclass::Myclass(const std::string& name, const std::string& path) : objectName{name}, filePath{path} {}
Myclass::Myclass(){ Myclass::Myclass("", ""); }

// Getters
std::string Myclass::getObjectName() const {
        return objectName;
}

std::string Myclass::getFilePath() const {
        return filePath;
}

// Setters
void Myclass::setObjectName(const std::string& name) {
        objectName = name;
}

void Myclass::setFilePath(const std::string& path) {
        filePath = path;
}

// Destructor
Myclass::~Myclass() {}