
#ifndef _SVG_PARSER_H_
#define _SVG_PARSER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Shape.h"
#include "Rectangle.h"

class SVGParser
{
    private:
        std::ifstream file;

        int getwidth(const std::string& svgElement);

    public:
        SVGParser();
        SVGParser(const std::string& filePath);

        std::vector<Shape> parse();
        std::vector<Shape> parse(const std::string& svgElement);

        Rectangle parseRectangle(const std::string& rectangleElement);

        std::string getSVGAttribute(const std::string attributeName, const std::string& rectangleElement);
        double getSVGDoubleAttribute(const std::string attributeName, const std::string& rectangleElement);
};

#endif // _SVG_PARSER_H_