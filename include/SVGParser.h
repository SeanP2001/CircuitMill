
#ifndef _SVG_PARSER_
#define _SVG_PARSER_

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

    public:
        SVGParser();
        SVGParser(const std::string& filePath);

        std::vector<Shape> parse();

        Rectangle parseRectangle();
};

#endif // _SVG_PARSER_