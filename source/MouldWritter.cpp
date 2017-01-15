#include "MouldWritter.h"
#include <fstream>

using namespace std;

MouldWritter::MouldWritter(const string &fileName)
    : os_{make_unique<ofstream>(fileName)}
{
}

MouldWritter::~MouldWritter() = default;

bool MouldWritter::isOpen() const
{
    return os_->is_open();
}
