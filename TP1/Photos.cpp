#include "Photos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Photos::Photos(const std::string& name, const std::string& path, double latitude, double longitude): Multimedia(name, path), latitude(latitude), longitude(longitude) {}

Photos::Photos(): Multimedia() {
        std::srand(std::time(0));
        latitude = static_cast<double>(std::rand()) / RAND_MAX * 100;
        longitude = static_cast<double>(std::rand()) / RAND_MAX * 100;
}

void Photos::display(std::ostream& out) const {
        Multimedia::display(out);
        out << "Multimedia type : Photos";
        out << "Photo latitude: " << latitude << std::endl;
        out << "Photo longitude: " << longitude << std::endl;
}

void Photos::setLatitude(double latitude) {
        this->latitude = latitude;
}

double Photos::getLatitude() const {
        return latitude;
}

void Photos::setLongitude(double longitude) {
        this->longitude = longitude;
}

double Photos::getLongitude() const {
        return longitude;
}