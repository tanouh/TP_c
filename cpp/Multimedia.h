/**
 * @file Multimedia.h
 * @brief Multimedia class header file
 * @author Tania Mahandry
 * @date 2025
 */


#ifndef Multimedia_H
#define Multimedia_H

#include <string>
#include <iostream>

/**
 * @brief The Multimedia class
 * 
 * This class represents a multimedia object.
 */
class Multimedia {
private:
        std::string fileName;
        std::string filePath;

public:
        /**
         * @brief a Multimedia object with the given name and path.
         * @param name The name of the object.
         * @param path The file path associated with the object.
         */
        Multimedia(const std::string& name, const std::string& path) : fileName{name}, filePath{path} {};
        Multimedia();
        /**
         * @brief Retrieves the name of the Multimedia object.
         * @return The name of the object as a string.
         *         If the name is not set, an empty string is returned.
         */
        std::string getFileName() const;
        /**
         *@brief  Retrieves the filepath of the Multimedia object.
         *
         * @return The name of the object as a string.
         *         If the name is not set, an empty string is returned.
         */
        std::string getFilePath() const;

        /**
         * @brief Sets the name of the Multimedia object.
         *
         * @param name The new name to set for the object.
         */
        void setFileName(const std::string& name);
        /**
         * @brief Sets the file path of the Multimedia object.
         *
         * @param path The new file path to set for the object.
         */
        void setFilePath(const std::string& path);

        /**
         * @brief Destroys the Multimedia object.
         */
        ~Multimedia() {
                std::cout << "Destroying Multimedia object: " << fileName << std::endl;
        };

        /**
         * @brief Prints the name of the Multimedia object to the given output stream.
         *
         * @param out The output stream to print the name to.
         */
        void displayFileName(std::ostream& out) const;
        /**
         * @brief Prints the file path of the Multimedia object to the given output stream.
         *
         * @param out The output stream to print the file path to.
         */
        void displayFilePath(std::ostream& out) const;
        /**
         * @brief Prints the details of the Multimedia object to the given output stream.
         *
         * @param out The output stream to print the details to.
         */
        virtual void display(std::ostream& out) const = 0;

        /**
         * @brief the multimedia object.
         */
        virtual void play() const = 0;
};

#endif // Multimedia_H

