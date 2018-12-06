#include "Product.h"
#include "Search.h"
#include <fstream>
#include <iostream>

using namespace std;



int main(){




Search iTems;
Product item("725177540363","Belle and The Yank 1/4");
int e = -1;



ifstream file;
file.open("test.txt", std::ios::binary);
if(file.is_open()){
	
	while(!file.eof()){
		cout<<"File Opened"<<endl;//
		string s1;
		getline(file, s1, ','); 
        string UPC = s1;
     
        string s2;
        
        cout<<UPC<<endl;
        getline(file, s2, ',');

        string description = s2;
        cout<<description<<endl;
        iTems.insertProductBST(item);
        iTems.insertArray(item);
        
        
    }
    
}


iTems.searchProductBST(e,item);
iTems.searchProductArray(item);


return 0;


}