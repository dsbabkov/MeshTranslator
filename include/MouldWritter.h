#pragma once

#include <iosfwd>
#include <memory>
#include <string>

class MouldWritter{
public:
    MouldWritter(const std::string &fileName);
    ~MouldWritter();

    bool isOpen() const;

private:
    std::unique_ptr<std::ofstream> os_;
};
