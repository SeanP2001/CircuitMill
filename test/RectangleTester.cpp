/**
 * @file RectangleTester.cpp
 * @author SeanP2001 
 * @brief Test that all of the functions in the Rectangle class are working as expected
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/Rectangle.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    Rectangle* rect1 = new Rectangle();                
    std::cout << "Instantiate a Rectangle with the zero parameter constructor:\n" << rect1->toString() << "\n\n";             

    rect1->setX(10);
    std::cout << "Set x to " << rect1->getX() << ":\n" << rect1->toString() << "\n\n"; 

    rect1->setY(20);
    std::cout << "Set y to " << rect1->getY() << ":\n" << rect1->toString() << "\n\n"; 

    rect1->setWidth(30);
    std::cout << "Set width to " << rect1->getWidth() << ":\n" << rect1->toString() << "\n\n"; 

    rect1->setHeight(40);
    std::cout << "Set height to " << rect1->getHeight() << ":\n" << rect1->toString() << "\n\n"; 


    Rectangle* rect2 = new Rectangle(5, 15, 25, 35);                 
    std::cout << "Instantiate a Rectangle with the (x, y, w, h) constructor:\n" << rect2->toString() << "\n\n";   


    Rectangle* rect3 = new Rectangle("<rect x=\"50\" y=\"20\" width=\"150\" height=\"150\"style=\"fill:blue;stroke:pink;stroke-width:5;fill-opacity:0.1;stroke-opacity:0.9\" />");                 
    std::cout << "Instantiate a Rectangle with the SVG element constructor:\n" << rect3->toString() << "\n\n";  


    std::cout << "Put the Rectangle objects in a Shape vector and iterate through their strings:\n";
    std::vector<Shape*> shapes;                         // Instantiate a vector of shapes to contain all of shapes
    shapes.push_back(rect1);                            // Put the first Rectangle in the vector
    shapes.push_back(rect2);                            // Put the second Rectangle in the vector
    shapes.push_back(rect3);                            // Put the second Rectangle in the vector

    for (const auto& shape : shapes)                    // Go through all of the shapes
    {                  
        std::cout << shape->toString() << "\n";         // Printing the objects to the console
    }

    std::cout << "\nIterate through their SVG elements:\n";

    for (const auto& shape : shapes)                    // Go through all of the shapes
    {                  
        std::cout << shape->getSVGElement() << "\n";         // Printing the objects to the console
    }
}