//  Created by Семён Шестаков on 31.12.2023.
#ifndef WriteFile_hpp
#define WriteFile_hpp

#include "point.hpp"
#include <fstream>

struct Cord {
    cord x;
    cord y;
};

typedef vector<Cord> vecCords;

class File {
private:
    string file;
    size_t _num = 0;
    bool handler(char, ifstream&);
public:
    File(string&);
    File();
    void save();
    vecCords* read();
};

class Data {
private:
    vector<vecCords*> data;
    File file;
public:
    Data();
    void operator()(size_t);
    void save();
    
};
extern Data data;

#endif /* WriteFile_hpp */
