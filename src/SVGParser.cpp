/**
 * @file SVGParser.cpp
 * @author SeanP2001 
 * @brief Implements the SVGParser class.
 * @date 10/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SVGParser.h"

const std::string SVGParser::ELEMENT_NAMES[] = {"rect"};
const std::string SVGParser::START_MARKER = "<";
const std::string SVGParser::END_MARKER = "/>";

bool SVGParser::contains(const std::string& str, const std::string& substr)
{
    return str.find(substr) != std::string::npos;
}

bool SVGParser::containsRecognisedElement(const std::string& line)
{
    for(auto elementName : ELEMENT_NAMES)
    {
        if(contains(line, elementName))
        {
            return true;
        }
    }

    return false;
}

std::vector<std::unique_ptr<Shape>> SVGParser::parse(const std::string& filepath)
{
    // create a shape vector
    // Open the file
    // read each line and identify elements "<" start "/>" end
    // for each element, find the element name
    // instantiate a shape of that type and add it to the shape vector

    std::vector<std::unique_ptr<Shape>> shapes;                                     // Create a shape vector to contain all of the shapes found in the file (unique_ptr for auto memory management)

    std::ifstream svgFile(filepath);                                                // Instantiate an input file stream

    // If the file fails to open, show an error messsage
    if(!svgFile.is_open()) 
    {
        std::cerr << "Error: Could not open SVG file: " << filepath << std::endl;
        return shapes;
    }

    std::string line;                                                               // Create a string to store each line
    std::string svgElement;                                                         // Create a string to store each element

    size_t posBefore;                                                               // Marker for the beginning of the element
    size_t posAfter;                                                                // Marker for the end of the element

    bool withinElement = false;                                                     // Indicates whether the start of the element has been found but not the end

    while(std::getline(svgFile, line))                                                                          // Go through each line of the file
    {
        if(contains(line, START_MARKER) && contains(line, END_MARKER) && containsRecognisedElement(line))       // If the line constains a complete knownn element (both start and end markers)
        {
            posBefore = line.find(START_MARKER);                                                                // Get the positions of the start and end
            posAfter = line.find(END_MARKER) + END_MARKER.length(); 

            svgElement = line.substr(posBefore, posAfter);                                                      // and save the element
        }
        else if(contains(line, START_MARKER) && !contains(line, END_MARKER) && containsRecognisedElement(line)) // If the line only contains a start marker (of a known element)
        {
            withinElement = true;                                                                               // Mark that the current line is within an element (has been started but not ended)

            posBefore = line.find(START_MARKER);                                                                // Find the start postion

            svgElement = line.substr(posBefore, line.length());                                                 // and save the element so far
        }
        else if(!contains(line, START_MARKER) && contains(line, END_MARKER))                                    // If the line  only contains an end marker
        {
            withinElement = false;                                                                              // Mark that the element has been ended

            posAfter = line.find(END_MARKER) + END_MARKER.length();                                             // find the end position 

            svgElement += line.substr(0, posAfter);                                                             // an add the last part to the element
        }
        else if(withinElement && !contains(line, START_MARKER) && !contains(line, END_MARKER))                  // If within an element
        {
            svgElement += line;                                                                                 // add the line to the element             
        }

        if(contains(line, END_MARKER))                                  // If an element has finished in this line
        {
            if(contains(svgElement, ELEMENT_NAMES[0]))                  // If that element contains the name of a known element
            {
                auto rect = std::make_unique<Rectangle>(svgElement);    // Instantiate the relevant shape object (as unique for automatic memory management)

                shapes.push_back(std::move(rect));                      // And add it to the shapes vector (moving rather than copying across)
            }
        }

    }

    svgFile.close();                                                    // close the file

    return shapes;                                                      // Return the shapes vector
}