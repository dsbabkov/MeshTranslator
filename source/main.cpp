#include <iostream>

#include "GeometryReader.h"
#include "MouldWritter.h"

int main(int argc, char *argv[])
{
    if (argc != 3){
        std::cerr << "Wrong argument count\n";
        return 1;
    }

    GeometryReader meshReader(argv[1]);
    if (!meshReader.isOpen()){
        std::cerr << "Can not open file for read\n";
        return 2;
    }

    MouldWritter mouldWritter(argv[2]);
    if (!mouldWritter.isOpen()){
        std::cerr << "Can not open file for write\n";
        return 3;
    }

    return 0;
}
