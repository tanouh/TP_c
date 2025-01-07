#include "Videos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Videos::Videos(std::string name, std::string pathname, int duration) : Multimedia(name, pathname), duration(duration) {}

Videos::Videos() : Multimedia(){
        std::srand(std::time(0));
        duration = std::rand() % 1000; // Random duration between 0 and 999 seconds
}
void Videos::display(std::ostream& out) const{
        Multimedia::display(out);
        out << "Multimedia type : Videos";
        out << "Video duration: " << duration << " seconds" << std::endl;
}
int Videos::getDuration() const {
    return duration;
}

void Videos::setDuration(int duration) {
    this->duration = duration;
}