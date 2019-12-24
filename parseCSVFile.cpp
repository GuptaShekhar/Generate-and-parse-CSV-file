#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> parseCsvFile(string inputFileName) {
 
    ifstream inputFile(inputFileName);
    vector<vector<int>> data;
    
    int l=0;
    string s1;
    getline(inputFile, s1);
    
    while(inputFile){
        l++;
        string s;
        if(!getline(inputFile,s)) break;

        istringstream ss(s);
        vector<int> t;
        int i=0;
        while(ss){
            string line;
            if(!getline(ss, line, ',')) break;
            if(i!=0){
                t.push_back(stoi(line));
            }

            i++;

        }
    
        data.push_back(t); 
    }
    return data;
}
int main(int argc, char **argv) {

    if(argc<2){
        cout<<"Insufficient no. of parameter\n";
        return 0;
    }
    string csvFile = argv[1];
    vector<vector<int>> data = parseCsvFile(csvFile);
    int row = data.size();
    if(row==0){
        cout<<"No row\n";
        return 0;;
    }
    int col = data[0].size();
    if(col==0){
        cout<<"No column"<<endl;
        return 0;
    }

    cout<<"row-wise stats"<<endl<<endl;
    for(int i=0;i<row;i++){
        vector<int> rowdata(data[i].begin(), data[i].end());
        int sum=0;
        for(int j=0;j<col;j++)
        sum+=rowdata[j];

        sort(rowdata.begin(), rowdata.end());


        double mean = sum/(double)col;
        cout<<"row"<<i+1<<" mean: "<<mean<<endl;


        if(col%2==0)
            cout<<"row"<<i+1<<" median: "<<(rowdata[col/2]+rowdata[col/2 -1])/(double)2<<endl;          //even length median
        else
            cout<<"row"<<i+1<<" median: "<<rowdata[col/2]<<endl;                                        // odd length median
        
        double sd=0;
        for(int j=0;j<col;j++){
            sd+=((double)data[i][j]-mean)*((double)data[i][j]-mean);
        }
        sd/=(double)(col-1);
        sd = (int)sqrt(sd);
        cout<<"row"<<i+1<<" standard deviation: "<<sd<<endl;
    }
    
    cout<<"column-wise stats"<<endl<<endl;
    for(int i=0;i<col;i++){
        vector<int> coldata;
        for(int j=0;j<row;j++)
        coldata.push_back(data[j][i]);
    
        int sum=0;
        for(int j=0;j<row;j++)
        sum+=coldata[j];

        sort(coldata.begin(), coldata.end());


        double mean = sum/(double)row;
        cout<<"col"<<i+1<<" mean: "<<mean<<endl;                                


        if(row%2==0)
            cout<<"col"<<i+1<<" median: "<<(coldata[row/2]+coldata[row/2 -1])/(double)2<<endl;          // even length median
        else
            cout<<"col"<<i+1<<" median: "<<coldata[row/2]<<endl;                                        //odd length median


        double sd=0;
        for(int j=0;j<row;j++){
            sd+=((double)coldata[j]-mean)*((double)coldata[j]-mean);
        }
        sd/=(double)(row-1);
        sd = (int)sqrt(sd);;

        cout<<"col"<<i+1<<" standard deviation: "<<sd<<endl;
    }
    return 0;
}