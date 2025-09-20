#include "Math.h"

sf::Vector2f Math::VectorNormalized(sf::Vector2f Vector){
    
        float magnitude = sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));

    sf::Vector2f normalizedVector;

    normalizedVector.x = Vector.x / magnitude;

    normalizedVector.y = Vector.y / magnitude;

    return normalizedVector;

}
