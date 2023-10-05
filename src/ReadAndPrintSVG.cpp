#include <iostream>
#include <fstream>
#include <string>

void readAndPrintSVG(const std::string& filePath) 
{
    std::ifstream svgFile(filePath);   // Instantiate an input file stream

    // If the file fails to open, show an error messsage
    if(!svgFile.is_open()) 
    {
        std::cerr << "Error: Could not open SVG file: " << filePath << std::endl;
        return;
    }

    std::string line;                   // Create a string to store each line
    while(std::getline(svgFile, line))  // Go through each line of the file
    {
        std::cout << line << std::endl; // and print them to the terminal
    }

    svgFile.close();                    // close the file

    return;
}

int main(int argc, char* argv[]) 
{
    // If two argumnts have not been supplied (program name + argument)
    if(argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <path_to_svg_file>" << std::endl;
        return 1;                           // Return an error code
    }

    std::string filePath = argv[1]; // instnantiate a string var to store the argument
    readAndPrintSVG(filePath);      

    return 0;
}
