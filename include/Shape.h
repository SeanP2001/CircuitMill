
#ifndef _SHAPE_
#define _SHAPE_

#include <string>

class Shape
{
    private:

    public:
        Shape();
        virtual ~Shape();

        virtual std::string getGcodePath() const = 0;
        virtual std::string getGcodePocket() const = 0;
        virtual std::string getGcodeOutline() const = 0;
};

#endif // _SHAPE_