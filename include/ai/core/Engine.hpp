#pragma once

#include <iostream>
#include <string>
#include <string_view>

namespace ai{

    class Engine {
        public:
            std::string plan(std::string_view story) const;
    };

}