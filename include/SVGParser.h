/**
 * @file SVGParser.h
 * @author SeanP2001 
 * @brief Defines the SVGParser static utility class for parsing SVG files.
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SVG_PARSER_H_
#define _SVG_PARSER_H_

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers


#include "Shape.h"
#include "Rectangle.h"

/**
 * @class SVGParser
 * @brief Utility class for parsing SVG files and generating corresponding shapes.
 * 
 * The SVGParser class provides static methods for parsing SVG files and creating
 * shape objects based on the content of the files. It supports parsing of specific
 * SVG elements like rectangles.
 */
class SVGParser
{
    private:
        const static std::string ELEMENT_NAMES[1];  ///< Array of recognized SVG element names.
        const static std::string START_MARKER;      ///< Start marker for identifying SVG elements.
        const static std::string END_MARKER;        ///< End marker for identifying SVG elements.

        /**
         * @brief Check if a string contains another string.
         * @param str The string to search in.
         * @param substr The substring to search for.
         * @return True if the substring is found, false otherwise.
         */
        static bool contains(const std::string& str, const std::string& substr);

        /**
         * @brief Check if a given SVG element is recognized.
         * @param svgElement The SVG element to check.
         * @return True if the element is recognized, false otherwise.
         */
        static bool containsRecognisedElement(const std::string& svgElement);

    public:
        /**
         * @brief Parse an SVG file and return a vector of shape objects.
         * @param filePath The path to the SVG file.
         * @return A vector of unique pointers to Shape objects.
         */
        static std::vector<std::unique_ptr<Shape>> parse(const std::string& filePath);
};

#endif // _SVG_PARSER_H_