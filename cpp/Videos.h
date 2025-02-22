/**
 * @file Video.h
 * @author Tania Mahandry
 * @date 2025
 */
#ifndef VIDEOS_H
#define VIDEOS_H
/**
 * @class Videos
 * @brief Class representing videos
 */

#include "Multimedia.h"

class Videos : public Multimedia {
private:
        int duration; // Duration in seconds

public:
        /**
         * @brief Constructs a new Videos object with the given name, file path, and duration.
         *
         * @param name The name of the video.
         * @param pathname The file path of the video.
         * @param duration The duration of the video in seconds.
         */
        Videos(std::string name, std::string pathname, int duration);
        /**
         * @brief Default constructor for the Videos class.
         *      Initializes the Multimedia base class and sets the duration to 0.
         */
        Videos();

        // Destructor 
        ~Videos() {
                std::cout << "Destroying Videos object: " << getFileName() << std::endl;
        }

        /**
         * @brief Retrieves the duration of the video in seconds.
         *
         * @return The duration of the video as an integer.
         */
        int getDuration() const;
        /**
         * @brief Sets the duration of the video in seconds.
         *
         * @param duration The new duration to set for the video.
         */
        void setDuration(int duration) ;


        /**
         * @brief Displays the details of the video, including its name, file path, and duration.
         */
        void display(std::ostream& out) const override;

        /**
         * @brief Plays the video.
         */
        void play() const override;
};

#endif // VIDEOS_H