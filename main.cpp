#include <iostream>
#include <fstream>

using namespace std; 

void encrypt_decrypt (const string & filename , char key) {
    fstream file (filename , ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "failed to open file " << filename << endl;
        return;
    }

    char buffer;
    while (file.get(buffer)){
        file.seekp(-1, ios::cur);
        buffer ^= key;
        file.put (buffer);
    }
    file.close ();
}

int main () {

    string filename = "test.txt";
    const char key = 0xFA;

    encrypt_decrypt (filename, key);
    cout << "File encrypted/decrypted successfully!" << endl;

    return 0;
}