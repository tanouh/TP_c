#ifndef Multimedia_H
#define Multimedia_H

#include <string>
#include <iostream>


class Multimedia {
private:
        std::string fileName;
        std::string filePath;

public:
        // Constructor
        /**
         * Constructs a Multimedia object with the given name and path.
         *
         * @param name The name of the object.
         * @param path The file path associated with the object.
         */
        Multimedia(const std::string& name, const std::string& path) : fileName{name}, filePath{path} {};
        Multimedia();
        // Getters
        /**
         * Retrieves the name of the Multimedia object.
         *
         * @return The name of the object as a string.
         *         If the name is not set, an empty string is returned.
         */
        std::string getFileName() const;
 /**
         * Retrieves the filepath of the Multimedia object.
         *
         * @return The name of the object as a string.
         *         If the name is not set, an empty string is returned.
         */
        std::string getFilePath() const;

        // Setters
        /**
         * Sets the name of the Multimedia object.
         *
         * @param name The new name to set for the object.
         */
        void setFileName(const std::string& name);
        /**
         * Sets the file path of the Multimedia object.
         *
         * @param path The new file path to set for the object.
         */
        void setFilePath(const std::string& path);

        // Destructor
        /**
         * Destroys the Multimedia object.
         */
        ~Multimedia() {};

        // Print functions
        /**
         * Prints the name of the Multimedia object to the given output stream.
         *
         * @param out The output stream to print the name to.
         */
        void displayFileName(std::ostream& out) const;
        /**
         * Prints the file path of the Multimedia object to the given output stream.
         *
         * @param out The output stream to print the file path to.
         */
        void displayFilePath(std::ostream& out) const;
        // Additional function
        void displayDetails(std::ostream& out) const;
};

#endif // Multimedia_H

