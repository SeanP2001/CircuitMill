
#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>

class Shape
{
    private:

    public:
        //Shape();
        //virtual ~Shape();

        virtual std::string getSVGElement() const = 0;
        //virtual std::string getGcodePath() const = 0;
        //virtual std::string getGcodePocket() const = 0;
        //virtual std::string getGcodeOutline() const = 0;

        virtual std::string toString() const = 0;
};

#endif // _SHAPE_H_