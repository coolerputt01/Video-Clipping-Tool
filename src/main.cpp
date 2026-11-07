#include <iostream>
#include "ai/core/Engine.hpp"
#include <string>
#include <string_view>


int main(int argc, char* argv[]){

    if(argc == 2 && std::string_view(argv[1]) == "--help"){
        std::cout << "Top The Goals Engine\n\n"
            << "Usage:\n"
            << "  ttg plan \"football story\"\n";
        return 0;
    }

    if(argc >= 3 && std::string_view(argv[1]) == "plan"){
        std::string idea = argv[2];

        for(int i = 3;i < argc;i++){
            idea += " ";
            idea += argv[i];
        }

        ai::Engine AI;
        std::cout<< AI.plan(idea);
        return 0;
    }

    std::cerr
        << "Invalid command.\n"
        << "Run ttg --help for usage.\n";

    return 1;


}