
#pragma once

#include <memory>
#include <string>

namespace HelloNativeLib {

class HelloSharedLib {
public:
    virtual ~HelloSharedLib() {}

    static std::shared_ptr<HelloSharedLib> create();

    virtual std::string fromCpp() = 0;
};

}  // namespace HelloNativeLib
