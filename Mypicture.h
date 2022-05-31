#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <array>

using namespace std;
using namespace sf;

class MyPicture
{
    Image  Image;
    Sprite Sprite;

public:

    // Ceci est le constructeur par copie
    MyPicture(const MyPicture& Copy) : Image(Copy.Image), Sprite(Copy.Sprite)
    {
        // Voilà la feinte : nous paramétrons le sprite afin qu'il
        // utilise notre image, plutôt que celle de Copy
        //Sprite.SetImage(Image);
    }  
};