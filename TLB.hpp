#ifndef TLB_
#define TLB_
//#include "TLB.cpp"
#include <vector>
#include "TLB_entry.cpp"

using std::vector;

//This class reprsents the TLB and the operations on it
//individual entries in the TLB are represented by the TLB_entry struct
class TLB{
private:
    vector<TLB_entry> data; // Pointer to array of entries
    //int size;
    int index = 0; //index of the least recently used item
    int maxsize = 64;
   
public:
    TLB(); //constructor
    ~TLB(); //desctructor
    void add_item(TLB_entry new_item); //add an item into the TLB
    TLB_entry replace(TLB_entry new_item); //replace an entry
    bool access(std::string tag); //check if tag is in the TLB (Maybe need to pas a TLB_entry)

    //Possibly only for debugging
    TLB_entry get_item(int pos); //return a specific item from the TLB 
    
}; // end TLB

//#include "TLB.cpp"
#endif
