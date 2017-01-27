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

void GeometryReader::skipCast()
{
    int nodeCount = -1;
    int elementCount = -1;

    *is_ >> nodeCount >> elementCount;
    string line;
    getline(*is_, line);

    for (int i = 0; i < nodeCount + elementCount * 2; ++i){
        getline(*is_, line);
    }
}

ifstream *GeometryReader::getStream() const
{
    return is_.get();
}

GeometryReader::~GeometryReader() = default;
