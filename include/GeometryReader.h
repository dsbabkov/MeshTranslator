#pragma once

#include <iosfwd>
#include <string>
#include <memory>

class GeometryReader
{
public:
    explicit GeometryReader(const std::string &fileName = "");
    ~GeometryReader();

    bool isOpen() const;

private:
    std::unique_ptr<std::ifstream> is_;
};
