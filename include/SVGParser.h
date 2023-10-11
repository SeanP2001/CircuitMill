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
 * shape objects based on the content of the file. 
 * 
 * The list of supported shapes currently includes:
 * - Rectangles
 */
class SVGParser
{
    private:
        const static std::string ELEMENT_NAMES[1];  ///< Array of recognized SVG element names. This will be updated as more shapes are added to the parser.
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
         * 
         * Checks if `svgElement` contains any of the recognised elements found in the `ELEMENT_NAMES` array.
         */
        static bool containsRecognisedElement(const std::string& svgElement);

    public:
        /**
         * @brief Parse an SVG file and return a vector of shape objects.
         * @param filepath The path to the SVG file.
         * @return A vector of unique pointers to Shape objects.
         * 
         * This function reads an SVG file line by line, extracts SVG elements,
         * and creates corresponding shape objects. It supports a finite list of 
         * SVG elements which are defined in the `ELEMENT_NAMES` array.
         * The parsed shapes are returned in a vector.
         *
         * The parsing process involves:
         *   1. Opening the SVG file.
         *   2. Reading each line and extracting SVG elements by finding their `START_MARKER` and `END_MARKER`.
         *   3. Instantiating shape objects, passing the SVG elements.
         *   4. Adding the created shapes to a vector.
         *   5. Returning the vector of shapes.
         *
         * Example Usage:
         * ```cpp
         * std::vector<std::unique_ptr<Shape>> shapes = SVGParser::parse("path/to/file.svg");
         * ```
         */
        static std::vector<std::unique_ptr<Shape>> parse(const std::string& filepath);
};

#endif // _SVG_PARSER_H_