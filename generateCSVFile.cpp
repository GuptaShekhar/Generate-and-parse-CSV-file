#include <bits/stdc++.h>
#include<ctime>
using namespace std;
mutex logMutex;

bool fileExists(string& fileName) {
    return static_cast<bool>(ifstream(fileName));
}
bool writeCsv(string &fileName, string column1, int col){                   // generate header for CSV file
    fstream file;
    file.open (fileName, ios::out | ios::app);
    if (file) {
        file << "\"" << column1 << "\",";
        for(int j=0;j<col-1;j++)
            file<< "day"+to_string(j+1)<<",";
        file <<"day"+to_string(col)<<  endl;
        return true;
    } else {
        return false;
    }
}

bool writeCsvFile(string &fileName, string column1, int col) {

    srand(clock());                                                     // seed that dont allow repetition
    
    fstream file;
    file.open (fileName, ios::out | ios::app);
    if (file) {
        file << "\"" << column1 << "\",";
        for(int j=0;j<col-1;j++)
            file<< to_string((rand()%56) - 10)<<",";
        file <<to_string((rand()%56) - 10)<<  endl;
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    if(argc<4){
        cout<<"Insufficient no. of parameter\n";
        return 0;
    }

    int col=stoi(argv[1]);
    int row=stoi(argv[2]);
    string csvFile=argv[3];
    if(row==0 || col==0){
        cout<<"No data given and No CSV file generated"<<endl;
        return 0;
    }
    
    if(!fileExists(csvFile))
        writeCsv(csvFile, "City", col);

    for (int i = 1; i <= row; ++i) {
        
        if (!writeCsvFile(csvFile, "city"+to_string(i), col)) {
            cerr << "Failed to write to file: " << csvFile << "\n";
        }
    }
    return 0;
}