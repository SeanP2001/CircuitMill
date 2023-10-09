#include "SVGParser.h"

const std::string SVGParser::ELEMENT_NAMES[] = {"rect"};

std::vector<std::unique_ptr<Shape>> SVGParser::parse(const std::string& filePath)
{
    // create a shape vector
    // Open the file
    // read each line and identify elements "<" start "/>" end
    // for each element, find the element name
    // instantiate a shape of that type and add it to the shape vector

    std::vector<std::unique_ptr<Shape>> shapes;                                     // Create a shape vector to contain all of the shapes found in the file (unique_ptr for auto memory management)

    std::ifstream svgFile(filePath);                                                // Instantiate an input file stream

    // If the file fails to open, show an error messsage
    if(!svgFile.is_open()) 
    {
        std::cerr << "Error: Could not open SVG file: " << filePath << std::endl;
        return shapes;
    }

    std::string line;                                                               // Create a string to store each line
    while(std::getline(svgFile, line))                                              // Go through each line of the file
    {
        size_t posBefore = line.find("<");                                          // Find the start and end of each element 
        size_t posAfter = line.find("/>", posBefore) + 2;                           // THIS WILL NOT CURRENTLY HANDLE MULTI-LINE ELEMENTS
        std::string svgElement = line.substr(posBefore, posAfter);              

        if(svgElement.find(ELEMENT_NAMES[0]) != std::string::npos)                  // If that element contains the name of a known element
        {
            auto rect = std::make_unique<Rectangle>(svgElement);                    // Instantiate the relevant shape object (as unique for automatic memory management)

            shapes.push_back(std::move(rect));                                      // And add it to the shapes vector (moving rather than copying across)
        }
    }

    svgFile.close();                                                                // close the file

    return shapes;                                                                  // Return the shapes vector
}