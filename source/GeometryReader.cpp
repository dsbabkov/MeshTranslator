#include "GeometryReader.h"
#include <fstream>

using namespace std;

GeometryReader::GeometryReader(const string &fileName)
    : is_{make_unique<ifstream>(fileName)}
{
}

bool GeometryReader::isOpen() const
{
    return is_->is_open();
}

GeometryReader::~GeometryReader() = default;
