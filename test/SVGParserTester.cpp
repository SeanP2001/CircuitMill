
#include <iostream>
#include <vector>
#include <memory> // For smart pointers

#include "SVGParser.h"
#include "Shape.h"

// open the file passed by argument
// parse it
// print out all of the shape objects

int main(int argc, char* argv[]) 
{
    // If two argumnts have not been supplied (program name + argument)
    if(argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_svg_file>" << std::endl;
        return 1;                           // Return an error code
    }

    std::string filepath = argv[1]; // instnantiate a string var to store the argument

    std::vector<std::unique_ptr<Shape>> shapes = SVGParser::parse(filepath);

    for (const auto& shape : shapes)                    // Go through all of the shapes
    {                  
        std::cout << shape->toString() << "\n";         // Printing the objects to the console
    }

    return 0;
}