
#pragma once

#include <memory>
#include <string>

namespace HelloNativeLib {

class HelloStaticLib {
public:
    virtual ~HelloStaticLib() {}

    static std::shared_ptr<HelloStaticLib> create();

    virtual std::string fromCpp() = 0;
};

}  // namespace HelloNativeLib
