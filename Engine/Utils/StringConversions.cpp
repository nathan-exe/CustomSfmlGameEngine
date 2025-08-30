//
// Created by Nathan on 23/08/2025.
//

#include "StringConversions.h"

#include <iostream>

#include "Math.h"

//== to string ==
std::string StringConversions::MatrixToString(const float* matrix)
{
    std::string result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result+=std::to_string(matrix[i+j*4])+"|";
        }
        result+="\n";
    }
    return result;
}

std::string StringConversions::TransformToString(const sf::Transform& transform)
{
    const float* matrix = transform.getMatrix();
    return StringConversions::MatrixToString(matrix);
}

string StringConversions::Vector2ToString(sf::Vector2f v)
{
    return  std::to_string(v.x)+","+std::to_string(v.y);
}

//== from string ==

float  StringConversions::FloatFromString(const string& s)
{
    return std::stof(s);
}

int StringConversions::IntFromString(const string& value)
{
    return std::stoi(value);
}

sf::Angle StringConversions::AngleFromString(const string& s)
{
    return sf::degrees(std::stof(s));
}

sf::Vector2f StringConversions::Vector2FromString(const string& s)
{
    Vector2f result;
    char delimiter = ',';
    size_t posVirgule =  s.find(',');
    if (posVirgule == std::string::npos)throw std::invalid_argument("c'est quoi ça ??");

    result.x = FloatFromString(s.substr( 0,s.length()- posVirgule-1));
    result.y = FloatFromString(s.substr(posVirgule + 1 ));
    return result;
}

sf::Color StringConversions::ColorFromString(const string& s)
{
    return sf::Color(std::stoi(s,nullptr, 0));
}
