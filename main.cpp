using namespace std;

#include "reader.hpp"

int main(int argc, char** argv){
    
    Battalion data[1000];
    load_data(data);

    for(int i = 0; i < 1000; ++i){
        cout << i << ": " << data[i].getCode() << "-" << data[i].getId() << endl;
    }
    return 0;
}