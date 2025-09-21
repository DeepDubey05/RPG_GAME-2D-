#include "Math.h"

sf::Vector2f Math::VectorNormalized(sf::Vector2f Vector){
    
        float magnitude = sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));

    sf::Vector2f normalizedVector;

    normalizedVector.x = Vector.x / magnitude;

    normalizedVector.y = Vector.y / magnitude;

    return normalizedVector;

}

/*
if(rect1.right > rect2.left &&
rect2.right > rect1.left &&
rect2.bottom > rect1.top &&
rect1.bottom > rect2.top)
*/
 bool Math::CheckRectCollision(sf::FloatRect rect1,sf::FloatRect rect2){

    if(rect1.left + rect1.width > rect2.left &&
    rect2.left + rect2.width > rect1.left &&
    rect2.top + rect2.height > rect1.top &&
    rect1.top + rect1.height > rect2.top){
        return true;
    }
    return false;
}