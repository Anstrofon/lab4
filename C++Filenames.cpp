#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using namespace std;

int main()
{
    string path;

    cout << "Enter catalog path: ";
    getline(cin, path);

    cout << "Catalog: " << fs::path(path) << endl;
    cout << "Files: " << endl;

    for (const auto& entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry.status()))
        {
            cout << entry.path().filename() << endl;
        }
    }
    cout << "\n" << endl;
    cout << "Folders: " << endl;
    for (const auto& entry : fs::directory_iterator(path))
    {
        if (fs::is_directory(entry.status()))
        {
            cout << entry.path().filename() << endl;
        }
    }

    return 0;
}
