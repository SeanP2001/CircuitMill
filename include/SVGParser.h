
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

class SVGParser
{
    private:
        const static std::string ELEMENT_NAMES[1];
        const static std::string START_MARKER;
        const static std::string END_MARKER;

        static bool contains(const std::string& str, const std::string& substr);
        static bool containsRecognisedElement(const std::string& svgElement);

    public:
        static std::vector<std::unique_ptr<Shape>> parse(const std::string& filePath);
};

#endif // _SVG_PARSER_H_