//
// Created by Nathan on 23/08/2025.
//

#ifndef TESTSFML_STRINGCONVERSIONS_H
#define TESTSFML_STRINGCONVERSIONS_H
#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class StringConversions
{
public :
    //to string
    static string MatrixToString(const float* matrix);
    static string TransformToString(const sf::Transform& transform);
    static string Vector2ToString(sf::Vector2f vector2);

    //from string
    static float FloatFromString(const string& s);
    static int IntFromString(const string& value);
    static sf::Angle AngleFromString(const string& s);

    ///vector must be formated like so : "x,y"
    static sf::Vector2f Vector2FromString(const string& s);
    static sf::Color ColorFromString(const string& s);
};


#endif //TESTSFML_STRINGCONVERSIONS_H