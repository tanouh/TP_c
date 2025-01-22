//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
using namespace std;
#include "Photos.h"
#include "Videos.h"
#include "Multimedia.h"


int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    
    // Photos photo1("ChillGuy", "multimedias/chill_guy.jpg", 50, 50);
    // photo1.display(std::cout);
    // photo1.play();	
    
    // Videos video1("Something in the sky", "multimedias/free_video.mov", 15);
    // video1.display(std::cout);
    // video1.play();

    Multimedia* photo1 = new Photos("ChillGuy", "multimedias/chill_guy.jpg", 50, 50);
    Multimedia* video1 = new Videos("Something in the sky", "multimedias/free_video.mov", 15);
    Multimedia* video2 = new Videos("Ocean", "multimedias/nice_dolphin.mov", 17);
    Multimedia* photo2 = new Photos("Sunset", "multimedias/sunset.jpg", 50, 50);
    Multimedia* photo3 = new Photos("Pikachu", "multimedias/picachu.png", 50, 50);
    Multimedia* video3 = new Videos("Waves", "multimedias/wave.mp4", 13);

    Multimedia* multimedia[6] = {photo1, video1, video2, photo2, photo3, video3};

    for (int i = 0 ; i < 6 ; i++){
        multimedia[i]->display(std::cout);
    }
    return 0;

}
