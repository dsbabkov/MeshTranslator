#pragma once

#include <iosfwd>
#include <memory>
#include <string>

class GeometryReader;

class MouldWritter{
public:
    MouldWritter(const std::string &fileName);
    ~MouldWritter();

    bool isOpen() const;

    void writeNodeNumbering(GeometryReader &meshReader);

    static std::string temperatureToString(int celcius);

private:
    std::unique_ptr<std::ofstream> os_;
};
