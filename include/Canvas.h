/**
 * @file Canvas.h
 * @author SeanP2001 
 * @brief Defines the Canvas class
 * @date 11/10/2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <vector>
#include <memory> // For smart pointers

#include <sstream>
#include <iomanip>

#include "Shape.h"

/**
 * @class Canvas
 * @brief Represents an area containing shapes
 * 
 */
class Canvas
{
    private:
        double width;                                   ///< Width of the canvas.
        double height;                                  ///< Height of the canvas.

        std::vector<std::unique_ptr<Shape>> shapes;     ///< A vector of unique pointers to Shape objects.

        const static int PRECISION;                     ///< Number of decimal places when formatting double values.

    public:
        /**
         * @brief Defualt constructor for a Canvas.
         * 
         * "width" and "height" are set to 0.
         */
        Canvas();

        /**
         * @brief Constructor for a Canvas, setting a specified width and height.
         * 
         * @param width Width of the canvas.
         * @param height Height of the canvas. 
         */
        Canvas(double width, double height);

        /**
         * @brief Constructor for a Canvas, setting a specified width, height and vector of Shapes.
         * 
         * @param width Width of the canvas.
         * @param height Height of the canvas. 
         * @param shapes Shapes drawn on the canvas.
         */
        Canvas(double width, double height, std::vector<std::unique_ptr<Shape>> shapes);



        /**
         * @brief Sets the width of the canvas.
         * 
         * @param width The new width.
         */
        void setWidth(const double width);

        /**
         * @brief Sets the height of the canvas.
         * 
         * @param height The new height.
         */
        void setHeight(const double height);

        /**
         * @brief Sets the width and height of the canvas.
         * 
         * @param width The new width.
         * @param height The new height.
         */
        void setSize(const double width, const double height);



        /**
         * @brief Gets the width of the canvas.
         * 
         * @return double The canvas width.
         */
        double getWidth() const;

        /**
         * @brief Gets the height of the canvas.
         * 
         * @return double The canvas height.
         */
        double getHeight() const;



        /**
         * @brief Adds a Shape object to the canvas.
         * 
         * @param shape The Shape object to be added.
         */
        void addShape(const std::unique_ptr<Shape> shape);

        /**
         * @brief Adds multiple Shape objects to the canvas.
         * 
         * @param shapes The vector of Shape objects to be added.
         */
        void addShapes(const std::vector<std::unique_ptr<Shape>> shapes);
         


        /**
         * @brief Gets a specified shape
         * 
         * @param shapeNo The index of the requested shape.
         * @return A const reference to the unique pointer of the requested Shape object.
         */
        const std::unique_ptr<Shape>& getShape(int shapeNo) const;

        /**
         * @brief Gets all of the Shape objects from the canvas.
         * 
         * @return A const reference to a vector of unique pointers to Shape objects.
         */
        const std::vector<std::unique_ptr<Shape>>& getShapes() const;
        

        /**
         * @brief Converts the canvas to a string representation.
         * 
         * @return std::string A string representing the canvas.
         */
        std::string toString() const;
};

#endif // _CANVAS_H_