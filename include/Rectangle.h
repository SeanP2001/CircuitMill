
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <string>
#include <sstream>
#include <iomanip>
#include "Shape.h"

class Rectangle : public Shape
{
    private:
        double x;
        double y;
        double width;
        double height;

        const static std::string ATTRIBUTE_NAMES[4];
        const static int PRECISION;

    public:
        Rectangle();
        Rectangle(double x, double y, double width, double height);
        Rectangle(const std::string& svgElement);
        //Rectangle(const std::string& gcode);

        void setX(double x);
        void setY(double y);
        void setWidth(double width);
        void setHeight(double height);

        double getX() const;
        double getY() const;
        double getWidth() const;
        double getHeight() const;

        std::string getSVGElement() const override;
        //std::string getGcodePath() const override;
        //std::string getGcodePocket() const override;
        //std::string getGcodeOutline() const override;

        std::string toString() const override;

        void parseSVGAttributes(std::string svgElement) override;
};

#endif // _RECTANGLE_H_