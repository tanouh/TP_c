//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
using namespace std;
#include "Photos.h"
#include "Videos.h"
#include "Multimedia.h"
#include "Film.h"

void testMultimediaTab(){
    Multimedia* photo1 = new Photos("ChillGuy", "multimedias/chill_guy.jpg", 50, 50);
    Multimedia* video1 = new Videos("Something in the sky", "multimedias/free_video.mov", 15);
    Multimedia* video2 = new Videos("Ocean", "multimedias/nice_dolphin.mp4", 17);
    Multimedia* photo2 = new Photos("Peppa pig", "multimedias/peppa_pig.jpg", 50, 50);
    Multimedia* photo3 = new Photos("Pikachu", "multimedias/picachu.png", 50, 50);
    Multimedia* video3 = new Videos("Waves", "multimedias/wave.mp4", 13);

    Multimedia* multimedia[6] = {photo1, video1, video2, photo2, photo3, video3};

    for (int i = 0 ; i < 6 ; i++){
        multimedia[i]->play();
    }
}
void testFilmMemoryHandling() {
    // Définition initiale des chapitres
    int chapterDurations[] = {3, 4, 5, 3};
    int numChapters = sizeof(chapterDurations) / sizeof(chapterDurations[0]);

    // Création de l'objet Film
    Film myFilm("My Movie", "multimedias/free_video.mp4", 15, chapterDurations, numChapters);
    std::cout << "Initial film data:" << std::endl;
    myFilm.display(std::cout);

    // Modification du tableau d'origine (devrait être sans effet sur myFilm)
    chapterDurations[0] = 999;
    chapterDurations[1] = 999;
    std::cout << "\nAfter modifying original chapterDurations array:" << std::endl;
    myFilm.display(std::cout);

    // Suppression du tableau initial (devrait être sans effet sur myFilm)
    int* newChapters = new int[3]{5, 5, 5};
    myFilm.setChapters(newChapters, 3);
    delete[] newChapters;

    std::cout << "\nAfter setting new chapters and deleting the source array:" << std::endl;
    myFilm.display(std::cout);

    // Vérification avec une nouvelle allocation de mémoire
    int* anotherChapters = new int[2]{7, 8};
    myFilm.setChapters(anotherChapters, 2);

    std::cout << "\nAfter setting another new chapter array:" << std::endl;
    myFilm.display(std::cout);

    delete[] anotherChapters; // Nettoyage mémoire après utilisation
}

void testCopyMemory(){
    int chapters[] = {3, 6, 8};
    Film film1("My Movie", "multimedias/nice_dolphin.mp4", 17, chapters, 3);
    
    std::cout << "Original film details:" << std::endl;
    film1.display(std::cout);

    // Testing copy constructor
    Film film2 = film1;
    std::cout << "\nCopied film details (film2):" << std::endl;
    film2.display(std::cout);

    // Testing assignment operator
    Film film3;
    film3 = film1;
    std::cout << "\nAssigned film details (film3):" << std::endl;
    film3.display(std::cout);
}

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;
    testCopyMemory();
    return 0;

}
