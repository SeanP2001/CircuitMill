
#ifndef _RECTANGLE_
#define _RECTANGLE_

#include <string>
#include <sstream>
#include "Shape.h"

class Rectangle : public Shape
{
    private:
        double x;
        double y;
        double width;
        double height;

    public:
        Rectangle();
        Rectangle(double x, double y, double width, double height);
        Rectangle(const std::string& svgElement);
        Rectangle(const std::string& gcode);

        void setX(double x);
        void setY(double y);
        void setWidth(double width);
        void setHeight(double height);

        double getX();
        double getY();
        double getWidth();
        double getHeight();

        std::string getSVGElement() const override;
        std::string getGcodePath() const override;
        std::string getGcodePocket() const override;
        std::string getGcodeOutline() const override;
};

#endif // _RECTANGLE_