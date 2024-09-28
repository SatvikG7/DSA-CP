#include <iostream>
#include <string>
#include <filesystem>
#include <regex>
#include <fstream>

namespace fs = std::filesystem;

// Function to sanitize the folder name
std::string sanitizeFolderName(const std::string& name) {
    std::string sanitized = name;
    std::replace(sanitized.begin(), sanitized.end(), ' ', '_');
    sanitized.erase(std::remove_if(sanitized.begin(), sanitized.end(), 
                                   [](char c) { return !std::isalnum(c) && c != '_'; }), 
                    sanitized.end());
    return sanitized;
}

int main() {
    std::string contestNumber, problemLetter, problemName;

    std::cout << "Enter contest number: ";
    std::getline(std::cin, contestNumber);

    std::cout << "Enter problem letter: ";
    std::getline(std::cin, problemLetter);

    std::cout << "Enter problem name: ";
    std::getline(std::cin, problemName);

    std::string sanitizedProblemName = sanitizeFolderName(problemName);

    // Create the folder structure
    fs::path basePath = "C:\\USERS\\SATVI\\CODE\\DSA-CP\\Codeforces";
    fs::path contestPath = basePath / contestNumber;
    fs::path problemPath = contestPath / (problemLetter + "." + sanitizedProblemName);

    try {
        fs::create_directories(problemPath);
        fs::path mainCppPath = problemPath / "main.cpp";
        fs::path readmePath = problemPath / "README.md";

        // Create empty files
        std::ofstream(mainCppPath.string());
        std::ofstream(readmePath.string());

        std::cout << "Folder structure created successfully:" << std::endl;
        std::cout << problemPath << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error creating folder structure: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}