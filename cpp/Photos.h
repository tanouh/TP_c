/**
 * @file Photos
 * @author Tania Mahandry
 * @date 2025
 */
#ifndef PHOTOS_H
#define PHOTOS_H

#include <string>
#include "Multimedia.h"

/**
 * @class ¨Photos
 * @brief Class representing a photo with a name, file path, latitude, and longitude.
 */

class Photos : public Multimedia {
private:
        double latitude;
        double longitude;

public:
        /**
         * @brief Constructs a new Photos object with the given name, file path, latitude, and longitude.
         *
         * @param name The name of the photo.
         * @param filePath The file path of the photo.
         * @param latitude The latitude of the photo's location.
         * @param longitude The longitude of the photo's location.
         */
        Photos(const std::string& name, const std::string& filePath, double latitude, double longitude);
        Photos();

        // Destructor
        ~Photos(){
                std::cout << "Destroying Photos object: " << getFileName() << std::endl;
        };

        /**
         * @brief Retrieves the latitude of the photo.
         *
         * @return The latitude of the photo as a double.
         */
        double getLatitude() const;
        /**
         * @brief Retrieves the longitude of the photo.
         *
         * @return The longitude of the photo as a double.
         */
        double getLongitude() const;
        /**
         * @brief Sets the latitude of the photo.
         *
         * @param latitude The new latitude to set for the photo.
         */
        void setLatitude(double latitude);
        /**
         * @brief Sets the longitude of the photo.
         *
         * @param longitude The new longitude to set for the photo.
         */
        void setLongitude(double longitude);
        /**
         * @brief Displays the details of the photo, including its name, file path, latitude, and longitude.
         */
        void display(std::ostream& out) const override;

        /**
         * @brief Plays/shows the photo.
         */
        void play() const override;

};

#endif // PHOTOS_H