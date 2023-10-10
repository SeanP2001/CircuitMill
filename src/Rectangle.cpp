/**
 * @file Rectangle.cpp
 * @author SeanP2001 
 * @brief Implements the Rectangle class.
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Rectangle.h"

const std::string Rectangle::ATTRIBUTE_NAMES[] = {"x", "y", "width", "height"};
const int Rectangle::PRECISION = 6;                                                 // The number of decimal places for the shape attributes 

// CONSTRUCTORS
Rectangle::Rectangle() : x(0), y(0), width(0), height(0) {}
Rectangle::Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
Rectangle::Rectangle(const std::string& svgElement) : x(0), y(0), width(0), height(0) {parseSVGAttributes(svgElement);}
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
double Rectangle::getX() const
{
    return x;
}

double Rectangle::getY() const
{
    return y;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getHeight() const
{
    return height;
}


/*
https://www.w3schools.com/graphics/svg_rect.asp

<rect x="50" y="20" width="150" height="150" />
*/
std::string Rectangle::getSVGElement() const 
{
    std::ostringstream svgElement;   

    svgElement << "<rect x=\"";
    svgElement << std::fixed << std::setprecision(PRECISION) << x;          // format (fixed = decimal notation)(set precision = decimal places)
    svgElement << "\" y=\"";
    svgElement << std::fixed << std::setprecision(PRECISION) << y; 
    svgElement << "\" width=\"";
    svgElement << std::fixed << std::setprecision(PRECISION) << width;      // format (fixed = decimal notation)(set precision = decimal places)
    svgElement << "\" height=\"";
    svgElement << std::fixed << std::setprecision(PRECISION) << height; 
    svgElement << "\" />";
     
    return svgElement.str();
}


/*
https://www.intuwiz.com/rectangle.html

PARAMETERS NEEDED:
    Tool movement: ON / OUTSIDE / INSIDE 	
    Cutting direction: CLOCKWISE / ANTICLOCKWISE	
    Side a (height): 20
    Side b (width):	25
    Tool diameter: 6
    Total depth of cutting:	1.00
    Depth of cutting per pass: 1.00
    Feed Rate (X,Y G00): 70
    Feed Rate (X,Y G01): 50
    Feed Rate (Z G00): 70
    Feed Rate (Z G01): 50
    Distance Xc: 5
    Distance Yc: 15
    Safe Z above surface: 0.5
 
NC FILE:
%
G00 Z0.5 (raise the tool to the clearance height)
G00 X0 Y0 (the movement of the tool to the start point of the milling (point 5))
G01 Z-1 F50 (lower the tool to the desired cutting depth)
G01 X0 Y20 F50 (milling side a)
G01 X30 Y20 (milling side b)
G01 X30 Y0 (milling side a)
G01 X0 Y0 (milling side b, return to the start point for milling) 
G00 Z0.5 F70 (raise the tool to the clearance height)
M30 (end of the control program)
%
*/
/*
std::string Rectangle::getGcodePath() const 
{
    std::ostringstream gcodePath;   

    return gcodePath.str();
}

std::string Rectangle::getGcodePocket() const 
{

}

std::string Rectangle::getGcodeOutline() const 
{

}
*/

std::string Rectangle::toString() const 
{
    std::ostringstream rectangleString;

    rectangleString << "Rectangle[x=";
    rectangleString << std::fixed << std::setprecision(PRECISION) << x;     // format (fixed = decimal notation)(set precision = decimal places)
    rectangleString << ", y=";
    rectangleString << std::fixed << std::setprecision(PRECISION) << y;     
    
    rectangleString << ", width=";
    rectangleString << std::fixed << std::setprecision(PRECISION) << width;     
    rectangleString << ", height=";
    rectangleString << std::fixed << std::setprecision(PRECISION) << height;
    rectangleString << "]";        
    
    return rectangleString.str();
}

void Rectangle::parseSVGAttributes(std::string svgElement) 
{
    for(std::string attribute : ATTRIBUTE_NAMES)
    {
        std::string searchTerm = attribute + "=\"";

        size_t posBefore = svgElement.find(searchTerm) + searchTerm.length();
        size_t posAfter = svgElement.find("\"", posBefore);

        if(attribute == ATTRIBUTE_NAMES[0])
        {
            x = std::stod(svgElement.substr(posBefore, posAfter));
        }
        else if(attribute == ATTRIBUTE_NAMES[1])
        {
            y = std::stod(svgElement.substr(posBefore, posAfter));
        }
        else if(attribute == ATTRIBUTE_NAMES[2])
        {
            width = std::stod(svgElement.substr(posBefore, posAfter));
        }
        else if(attribute == ATTRIBUTE_NAMES[3])
        {
            height = std::stod(svgElement.substr(posBefore, posAfter));
        }
    }
}