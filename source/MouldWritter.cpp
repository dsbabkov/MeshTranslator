#include "GeometryReader.h"
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

void MouldWritter::writeNodeNumbering(GeometryReader &meshReader)
{
    *os_ << "DATA START FILE\r\n"
           "T in mould :\r\n"
           "-***-\r\n"
           "DATA GEOMETRY\r\n"
           "C:\\poligon\\PROGEKTS\\golova\\Head_s3.cst\r\n";

    ifstream *is = meshReader.getStream();
    is->seekg(0);

    int nodeCount = -1;
    int elementCount = -1;

    *is >> nodeCount >> elementCount;
    *os_ << nodeCount << ' ' << elementCount << ' ' << nodeCount << "\r\n";

    string line;
    getline(*is, line);

    for (int i = 0; i < nodeCount; ++i){
        float x, y, z;
        *is >> x >> z >> y;
        *os_ << x << ' ' << y << ' ' << z << ' ' << i + 1 << "\r\n";
        getline(*is, line);
    }

    for (int i = 0; i < elementCount * 2; ++i){
        getline(*is, line);
        *os_ << line << "\r\n";
    }

    *os_ << "0 0 0\r\n"
            "-***-\r\n"
            "\r\n"
            "DATA CALCULATION\r\n"
            "\r\n"
            "\r\n"
            "#\r\n"
            "0.00\r\n";

    int valuesInRow = 0;
    for (int i = 0; i < nodeCount; ++i){
        constexpr int maxValuesInRow = 105;
        if (++valuesInRow > maxValuesInRow){
            *os_ << '\r\n';
        }

        *os_ << temperatureToString(i);
    }
}

string MouldWritter::temperatureToString(int celcius)
{
    int kelvins = celcius + 273;
    std::string result;

    int left = kelvins / 100;
    int right = kelvins - left * 100;

    result.push_back(static_cast<char>(left + 0x21));
    result.push_back(static_cast<char>(right + 0x21));

    return result;
}
