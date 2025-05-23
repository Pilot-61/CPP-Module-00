#include "StoreData.hpp"

StoreData::StoreData(std::string filename, std::string s1, std::string s2)
{
    this->filename = filename;
    this->s1 = s1;
    this->s2 = s2;
}

void StoreData::replaceOcc()
{
    std::fstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    std::string newFile = filename + ".replace";
    std::ofstream outfile(newFile.c_str());

    if (!outfile)
    {
        std::cerr << "Error: could not open file " << newFile << std::endl;
        return;
    }
    if (s1.empty())
    {
        std::cerr << "Error: s1 or s2 is empty" << std::endl;
        return;
    }
    while (std::getline(infile, line, '\0'))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line;
    }

    infile.close();
    outfile.close();
}

std::string StoreData::getFilename(){
    return filename;
}
