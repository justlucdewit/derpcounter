#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "add") == 0){
        std::ofstream derpData("derps.data", std::ios::app);
        std::ifstream derpDataIn("derps.data");
        int derps = std::count(std::istreambuf_iterator<char>(derpDataIn),std::istreambuf_iterator<char>(), '\n');
        if (argc > 2){
            std::string newDerp = "\n";
            for (int i = 2; i<argc; i++){
                newDerp += argv[i];
                newDerp += " ";
            }
            derpData << newDerp;

            newDerp.erase(0, 1);
            newDerp.pop_back();
            std::cout << "added new derp: \"" << newDerp << "\"\nyou now have " << derps+1 << " derps";

        }else
            std::cout << "please specify what to add as a derp";
    }else if (argc > 1 && strcmp(argv[1], "count") == 0){
        std::ifstream derpData("derps.data");
        int derps = std::count(std::istreambuf_iterator<char>(derpData),std::istreambuf_iterator<char>(), '\n');
        std::cout << "you have a total of " << derps << " derps";
    }else if (argc > 1 && strcmp(argv[1], "list") == 0){
        std::ifstream derpData("derps.data");
        std::string derpItem;
        int i = 1;
        std::vector<std::string> derps;
        int numofderps = 0;
        while(std::getline(derpData, derpItem)){
            derps.push_back(derpItem);
            numofderps++;
        }
        std::reverse(derps.begin(), derps.end());
        derps.pop_back();
        for (const auto j : derps){
            std::cout << i << ") " << j << "\n";
            i++;
        }
    }else{
        std::cout << "invalid or no arguments provided";
    }
    std::cout << "\n";
    return 0;
}
