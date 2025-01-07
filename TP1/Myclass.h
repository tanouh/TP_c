#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

class Myclass {
private:
        std::string objectName;
        std::string filePath;

public:
        // Constructor
        Myclass(const std::string& name, const std::string& path) : objectName{name}, filePath{path} {};
        Myclass();
        // Getters
        std::string getObjectName() const;
        std::string getFilePath() const;

        // Setters
        void setObjectName(const std::string& name);
        void setFilePath(const std::string& path);

        // Destructor
        ~Myclass() {};
};



#endif // MYCLASS_H

