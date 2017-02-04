#ifndef fuctions_h
#define fuctions_h
#include <fstream>

using namespace std;

void procura(string ficheiro ) {
    
    fstream file(ficheiro, ios::in|ios::out);
    if(!file ) cout << "error a abriri o ficheiro." << endl;
    
    //file.seekp(2, ios::cur);
    //file << "aleatorio ";
    file.seekg(2, ios::beg);
    char ch;
    while(file.get(ch)) {
        cout.put(ch);
    }
    
}

void getLenghtFile(string file) {
    
    ifstream stream(file, ifstream::binary);
    if(stream) {
        stream.seekg(0, stream.end);
        int long lenght = stream.tellg();
        stream.seekg(0, stream.beg);
        
        char * buffer = new char[lenght];
        
        stream.read(buffer, lenght);
        stream.close();
        cout.write(buffer, lenght);
        cout << lenght << endl;
        
        delete [] buffer;
    }
    
}

void readFile(string file) {
    
    ifstream inFile;
    
    inFile.open(file);
    
    if(inFile.is_open()) {
        
        while(inFile) {
        
            string line;
            
            getline(inFile, line, ':');
           
            //inFile.get();
            inFile >> ws; // c++11 style to leave space away
            
            //if(!inFile) break;
            
            cout << line << endl;
            
        }
        
        inFile.close();
        
    }else {
        cout << "could not opem a file "  << file << endl;
    }
}
void createFile(string nameFile) {
    
    ofstream outfile;
    outfile.open(nameFile);
    if(outfile.is_open()) {
        cout << "file create." << endl;
        for (int i = 1; i < 10; i++) {
            if(i < 9)
                outfile << i << ". Number line." << endl;
            if(i == 9)
                outfile << i << ". e chegamos a ultima" << endl;
            
        }
        
        outfile.close();
    } else {
        cout << "could not create a file  " << nameFile << endl;
    }
}

void mightGoWrong() {
    
    bool error = false;
    bool error2 = false;
    bool error3 = true;
    
    if(error) {
        throw 8;
    }
    if(error2) {
        throw "Uma cena";
    } if(error3) {
        throw std::string("String");
    }
}

void tryIt() {
    try {
        mightGoWrong();
    } catch(int e) {
        std::cout << "Error code: " << e << std::endl;
    } catch(char const *e) {
        std::cout << "Error char: " << e << std::endl;
    } catch(std::string &e) {
        std::cout << "Error sting: " << e << std::endl;
    }
    
    std::cout << "continue the program " << std::endl;
    
}

#endif /* fuctions_h */
