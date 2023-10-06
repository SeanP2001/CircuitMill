#include "SVGParser.h"

SVGParser::SVGParser()
{

}

SVGParser::SVGParser(const std::string& filePath)
{

}

std::vector<Shape> SVGParser::parse()
{

}

std::vector<Shape> SVGParser::parse()
{

}

std::vector<Shape> SVGParser::parse(const std::string& svgElement)
{

}

Rectangle SVGParser::parseRectangle(const std::string& rectangleElement)
{
    return Rectangle(getSVGDoubleAttribute("x", rectangleElement), getSVGDoubleAttribute("y", rectangleElement), getSVGDoubleAttribute("width", rectangleElement), getSVGDoubleAttribute("height", rectangleElement));
}

std::string SVGParser::getSVGAttribute(const std::string attributeName, const std::string& svgElement)
{
    std::string attribute = attributeName + "=\"";

    size_t posBefore = svgElement.find(attribute) + attribute.length();
    size_t posAfter = svgElement.find("\"", posBefore);

    return svgElement.substr(posBefore, posAfter);
}

double SVGParser::getSVGDoubleAttribute(const std::string attributeName, const std::string& svgElement)
{
    return std::stod(getSVGAttribute(attributeName, svgElement));
}
