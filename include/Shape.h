/**
 * @file Shape.h
 * @author SeanP2001 
 * @brief Defines the Shape abstract base class.
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>

/**
 * @class Shape
 * @brief An abstract base class representing shape objects, compatible with SVG elements and G-code instructions.
 * 
 * The Shape class serves as the foundation for various geometric shapes. Derived classes must implement
 * specific functionalities like generating SVG elements, G-code paths, and other relevant operations.
 */
class Shape
{
    private:

    public:
        //Shape();
        //virtual ~Shape();

        /**
         * @brief Gets the SVG representation of the shape.
         * @return std::string The SVG element representing the shape.
         */
        virtual std::string getSVGElement() const = 0;

        //virtual std::string getGcodePath() const = 0;
        //virtual std::string getGcodePocket() const = 0;
        //virtual std::string getGcodeOutline() const = 0;

        /**
         * @brief Converts the shape to a string representation.
         * @return std::string A string representing the shape.
         */
        virtual std::string toString() const = 0;

        /**
         * @brief Parses SVG attributes from the provided SVG element.
         * @param svgElement The SVG element containing shape attributes.
         */
        virtual void parseSVGAttributes(std::string svgElement) = 0;
};

#endif // _SHAPE_H_