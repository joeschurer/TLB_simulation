#include "TLB.hpp"
#include <iostream>

//constructor
TLB::TLB(){}

//destructor
TLB::~TLB(){}

//Function to replace an item in the cache
//Current algorithm is FIFO
void TLB::replace(TLB_entry new_item){
	//replace the oldest item in the cache
	/*E.g. On first replacement, replace the 0th item in the cache
	 * On next replacement the item in pos 1 ...
	 */
    data[index] = new_item;
    
    //increment the index and if it caps, roll it over
    if(index < 63){
		index++;
	}else{
		index = 0;
	}
   
}

/*/function to search the TLB for a desired tag
bool TLB::access(std::string tag){
    //step thru the data and check for a match in each item
    for(int i=0; i < data.size(); i++){
        //if the data matches return true and increment the number of accesses
        if(data[i].tag == tag){
			data[i].num_accesses++;
            return true;
        }
    }
    return false;
}*/

//function to access an item by its index
TLB_entry TLB::get_item(int pos){
    return data[pos];
}

//function to add an item into the TLB
//fully associative means the data can be placed in any unused block
void TLB::add_item(TLB_entry new_item){
    //first check if an item is already the cache
    for(int i=0; i < data.size(); i++){
        //if the data matches return and increment the number of accesses
        if(data[i].tag == new_item.tag){
			data[i].num_accesses++;
			
			//std::cout << "Hit on already included tag: " << new_item.tag << " - " << data[i].num_accesses << std::endl;
			//std::cout << data[i].access_type << " - " << new_item.access_type <<std::endl;
			hits++;
            return;
        }
    }
    
    //if there is space simply add the item to the cache, else must replace
    if(data.size() < 64){
        data.push_back(new_item);
    } else {
        //do a replacement
        //TLB_entry temp = this->replace(new_item);
        this->replace(new_item);
    }
    misses++;
}


//getters for hits and misses
int TLB::get_hits(){ return hits; }
int TLB::get_misses(){ return misses; }
