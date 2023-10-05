
#include "Rectangle.h"

// CONSTRUCTORS
Rectangle::Rectangle() : x(0), y(0), width(0), height(0) {}
Rectangle::Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
//Rectangle::Rectangle(const std::string& svgElement)
//Rectangle::Rectangle(const std::string& gcode)

// SETTERS
void Rectangle::setX(double x)
{
    this->x = x;
}

void Rectangle::setY(double y)
{
    this->y = y;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

void Rectangle::setHeight(double height)
{
    this->height = height;
}

// GETTERS
double Rectangle::getX()
{
    return x;
}

double Rectangle::getY()
{
    return y;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}


// <rect width="300" height="100" style="fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,0)" />
std::string Rectangle::getSVGElement() const 
{
    std::ostringstream svgElement;   

    svgElement << "<rect width=\"" << width << "\" height=\"" << height << "\">";
     
    return svgElement.str();
}

std::string Rectangle::getGcodePath() const 
{

}

std::string Rectangle::getGcodePocket() const 
{

}

std::string Rectangle::getGcodeOutline() const 
{

}