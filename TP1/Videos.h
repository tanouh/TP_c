#ifndef VIDEOS_H
#define VIDEOS_H

#include "Multimedia.h"

class Videos : public Multimedia {
private:
        int duration; // Duration in seconds

public:
        /**
         * Constructs a new Videos object with the given name, file path, and duration.
         *
         * @param name The name of the video.
         * @param pathname The file path of the video.
         * @param duration The duration of the video in seconds.
         */
        Videos(std::string name, std::string pathname, int duration);
        /**
         * Default constructor for the Videos class.
         * Initializes the Multimedia base class and sets the duration to 0.
         */
        Videos();
        // Getters and Setters
        /**
         * Retrieves the duration of the video in seconds.
         *
         * @return The duration of the video as an integer.
         */
        int getDuration() const;
        /**
         * Sets the duration of the video in seconds.
         *
         * @param duration The new duration to set for the video.
         */
        void setDuration(int duration) ;

        // Display function
        /**
         * Displays the details of the video, including its name, file path, and duration.
         */
        void display(std::ostream& out) const;
};

#endif // VIDEOS_H