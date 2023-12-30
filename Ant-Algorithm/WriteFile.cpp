//  Created by Семён Шестаков on 31.12.2023.
#include "WriteFile.hpp"

// constructor
File::File() { file = "save.txt";}
File::File(string& _name) { file = _name + ".txt";}

// write
void File::save() {
    ofstream out;
    out.open(file, ios::out);
    
    if (out.is_open()) {
        out << "S" << endl;
        for (const auto& elm: vecPoints){
            cout << elm->getX() << " " << elm->getY() << endl;
            out << "P " << elm->getX() << " " << elm->getY() << endl;
        }
        out << 'E' << endl;
        // S
        // P 10 10
        // P 5 5
        // E
        cout << "OK!\n";
    }
    out.close();
    cout << file << " Close\n";
}

// read
vecCords* File::read() {
    vecPoints.clear();
    ifstream in;
    in.open(file);
    vecCords* temp = new vecCords;
    
    if (in.is_open()) {
        
        char F;
        while (in >> F) {
            handler(F, in);
        }
        cout << "OK!\n";
    }
    in.close();
    cout << file << " Close\n";
    
    return temp;
}

bool File::handler(char F, ifstream& in) {
    if (F == 'P') {
        cord x,y;
        in >> x >> y;
        ptrPoint temp = make_shared<Point>(x, y);
        vecPoints.push_back(temp);
        return true;
    }
    if (F == 'S') {
        
    }
    return false;
}


Data data;

Data::Data(){
    
}
void Data::operator()(size_t n){}
void Data::save(){}
