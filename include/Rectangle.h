/**
 * @file Rectangle.h
 * @author SeanP2001 
 * @brief Defines the Rectangle class, a concrete implementation of the Shape interface.
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <string>
#include <sstream>
#include <iomanip>
#include "Shape.h"

/**
 * @class Rectangle
 * @brief Represents a rectangular shape, implementing the Shape interface.
 * 
 * The Rectangle class provides functionality to work with rectangular shapes in the context of
 * SVG elements and G-code instructions.
 */
class Rectangle : public Shape
{
    private:
        double x;               ///< X-coordinate of the top-left corner of the rectangle.
        double y;               ///< Y-coordinate of the top-left corner of the rectangle.
        double width;           ///< Width of the rectangle.
        double height;          ///< Height of the rectangle.

        const static std::string ATTRIBUTE_NAMES[4]; ///< Array of attribute names for parsing SVG elements.
        const static int PRECISION; ///< Precision for formatting double values.

    public:

        /**
         * @brief Default constructor for a Rectangle.
         */
        Rectangle();

        /**
         * @brief Parameterized constructor for a Rectangle.
         * @param x X-coordinate of the top-left corner.
         * @param y Y-coordinate of the top-left corner.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         */
        Rectangle(double x, double y, double width, double height);
        
        /**
         * @brief Constructor for a Rectangle based on an SVG element.
         * @param svgElement The SVG element representing the rectangle.
         */
        Rectangle(const std::string& svgElement);

        //Rectangle(const std::string& gcode);

        /**
         * @brief Sets the X-coordinate of the top-left corner of the rectangle.
         * @param x The new X-coordinate.
         */
        void setX(double x);

        /**
         * @brief Sets the Y-coordinate of the top-left corner of the rectangle.
         * @param y The new Y-coordinate.
         */
        void setY(double y);

        /**
         * @brief Sets the width of the rectangle.
         * @param width The new width.
         */
        void setWidth(double width);

        /**
         * @brief Sets the height of the rectangle.
         * @param height The new height.
         */
        void setHeight(double height);

        /**
         * @brief Gets the X-coordinate of the top-left corner of the rectangle.
         * @return double The X-coordinate.
         */
        double getX() const;

        /**
         * @brief Gets the Y-coordinate of the top-left corner of the rectangle.
         * @return double The Y-coordinate.
         */
        double getY() const;

        /**
         * @brief Gets the width of the rectangle.
         * @return double The width.
         */
        double getWidth() const;

        /**
         * @brief Gets the height of the rectangle.
         * @return double The height.
         */
        double getHeight() const;

        /**
         * @brief Gets the SVG representation of the rectangle.
         * @return std::string The SVG element representing the rectangle.
         */
        std::string getSVGElement() const override;

        //std::string getGcodePath() const override;
        //std::string getGcodePocket() const override;
        //std::string getGcodeOutline() const override;

        /**
         * @brief Converts the rectangle to a string representation.
         * @return std::string A string representing the rectangle.
         */
        std::string toString() const override;

        /**
         * @brief Parses SVG attributes from the provided SVG element.
         * @param svgElement The SVG element containing rectangle attributes.
         */
        void parseSVGAttributes(std::string svgElement) override;
};

#endif // _RECTANGLE_H_