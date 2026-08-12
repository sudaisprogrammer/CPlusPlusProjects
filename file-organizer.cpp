#include <iostream>
#include <filesystem>
#include<ostream>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    string downloads = "C:\\Users\\HP\\Downloads";
    // C:\Users\HP\Downloads
    for (const auto& file : fs::directory_iterator(downloads))
    {
        if (!fs::is_regular_file(file))
            continue;

        string extension = file.path().extension().string();

        if (extension.empty())
            continue;

        // Remove '.'
        string folderName = extension.substr(1);

        // Convert to uppercase
        for (char& c : folderName)
            c = toupper(c);

        fs::path folderPath = fs::path(downloads) / folderName;

        //Create folder if it doesn't exist
        fs::create_directories(folderPath);

        // Move file
        fs::path destination = folderPath / file.path().filename();

        fs::rename(file.path(), destination);
    }

    cout << "Files organized successfully!" << endl;

    return 0;
}