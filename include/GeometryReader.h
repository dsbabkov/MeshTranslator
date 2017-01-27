#pragma once

#include <iosfwd>
#include <string>
#include <memory>

class GeometryReader
{
    enum ReadFlags {
        CastNodeCountRead = 1 << 0,
        CastElementCountRead = 1 << 1,
        CastNodesRead = 1 << 2,
        CastElementsRead = 1 << 3,
        CastFacesRead = 1 << 4,
        MouldNodeCountRead = 1 << 5,
        MouldElementCountRead = 1 << 6,
        MouldNodesRead = 1 << 7,
        MouldElementsRead = 1 << 8,
        MouldFacesRead = 1 << 9,
    };

public:
    explicit GeometryReader(const std::string &fileName = "");
    ~GeometryReader();

    bool isOpen() const;
    std::ifstream *getStream() const;

private:
    void skipCast();

private:
    std::unique_ptr<std::ifstream> is_;
};
