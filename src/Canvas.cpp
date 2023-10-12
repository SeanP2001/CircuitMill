
#include "Canvas.h"

const int Canvas::PRECISION = 6;  

Canvas::Canvas() : width(0), height(0) {}
Canvas::Canvas(double width, double height) : width(width), height(height) {}
Canvas::Canvas(double width, double height, std::vector<std::unique_ptr<Shape>> shapes) : width(width), height(height), shapes(shapes) {}


void Canvas::setWidth(const double width)
{
    this->width = width;
}

void Canvas::setHeight(const double height)
{
    this->height = height;
}

void Canvas::setSize(const double width, const double height)
{
    this->width = width;
    this->height = height;
}

double Canvas::getWidth() const
{
    return width;
}

double Canvas::getHeight() const
{
    return height;
}

void Canvas::addShape(const std::unique_ptr<Shape> shape)
{
    this->shapes.push_back(std::move(shape));   // move transfers ownership to the Canvas shapes vector
}

void Canvas::addShapes(const std::vector<std::unique_ptr<Shape>> shapes)
{
    for(const auto& shape : shapes)
    {
        this->shapes.push_back(std::move(shape));
    }
}
    
const std::unique_ptr<Shape>& Canvas::getShape(int shapeNo) const
{
    return shapes.at(shapeNo);
}

const std::vector<std::unique_ptr<Shape>>& Canvas::getShapes() const
{
    return shapes;
}

std::string Canvas::toString() const
{
    std::ostringstream canvasString;

    canvasString << "Canvas[width=";
    canvasString << std::fixed << std::setprecision(PRECISION) << width;     // format (fixed = decimal notation)(set precision = decimal places)
    canvasString << ", height=";
    canvasString << std::fixed << std::setprecision(PRECISION) << height;     
    
    canvasString << ", shapes=";

    for(auto& shape : shapes)
    {
        canvasString << "\n    " << shape->toString();
    }

    canvasString << "]";        
    
    return canvasString.str();
}