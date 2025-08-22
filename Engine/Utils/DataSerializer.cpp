//
// Created by Nathan on 23/08/2025.
//

#include "DataSerializer.h"




std::string DataSerializer::MatrixToString(const float* matrix)
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

std::string DataSerializer::TransformToString(const sf::Transform& transform)
{
    const float* matrix = transform.getMatrix();
    return DataSerializer::MatrixToString(matrix);
}
