#include <iostream>
#include "TLB_entry.cpp"
#include <vector>
#include "TLB.hpp"
#include <string>
#include <fstream>

using namespace std;

int main(void){
    //initialize a tlb
    TLB cache;

    //Variables used in calculating hitrate
    int hits,mises;
    float hit_rate;
    
    vector<TLB_entry> data;
    TLB_entry new_item;
	
	//code to read in items from the file
	ifstream input_file("cc1.din");
	if(input_file.is_open()){
		
		string line; //contains the indiv. line
		int start,end; //used to split up the line
		char type; //will contain the access type
		string addr; //will hold the address on each line
		
		while(getline(input_file,line)){
			type = line[0];
			line = line.substr(1,line.size());
			start = line.find_first_not_of(" \n\t");
			end = line.find_last_not_of(" \n\t");
			addr = line.substr(start,end+1);
			
			new_item.access_type = type;
			new_item.tag = addr;//note should eventually remove offset prob
			data.push_back(new_item);
			
			//use for debug only
			//cout << type << "-" << addr << endl;
		}
	}
	
	/*new_item.tag = 1;
	
    for(int i=0; i < 64; i++){
		cache.add_item(new_item);
    }
	
	cache.add_item(new_item);
	bool test = cache.access(1);
		
	cout << "Found: " << test << "\n";
	*/

    return 0;
}
