#include "TLB.hpp"
#include <iostream>

//constructor
TLB::TLB(){
    //size - 0;
    //data = new TLB_entry[1];
    //Currently will dynamically adjust the size of the TLB but maybe set to maxisize
}

//destructor
TLB::~TLB(){
    //delete [] data;
	//data = nullptr;
}

//implement some replacement policy here
//will prob only be called by other functions in the class
TLB_entry TLB::replace(TLB_entry new_item){
    //possibly LRU or FIFO
    //FIFO may be easier
    std::cout << "A replacement would have occured here.\n";
}

bool TLB::access(std::string tag){
   //TLB_entry temp;
    //step thru the data and check for a match in each item
    for(int i=0; i < data.size(); i++){
        //if the data matches return true and increment the number of accesses
        if(data[i].tag == tag){
			data[i].num_accesses++;
            return true;
        }
    }
    return false;
}

TLB_entry TLB::get_item(int pos){
    return data[pos];
}

//fully associative means the data can be placed in any unused block
void TLB::add_item(TLB_entry new_item){
    //if there is space simply add the item to the cache, else must replace
    if(data.size() < 64){
        data.push_back(new_item);
    } else {
        //do a replacement
        TLB_entry temp = this->replace(new_item);
    }
    
}
