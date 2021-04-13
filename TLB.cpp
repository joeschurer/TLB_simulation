//data types here could be optimized
struct TLB_entry{
    int tag;
    bool v,r,w,d;
    int num_accesses; //may use for replacement
}

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
}

bool TLB::access(int tag){
   //TLB_entry temp;
    //step thru the data and check for a match in each item
    for(int i=0; i < data.size(); i++){
        //if the data matches return true and increment the number of accesses
        if data[i].tag == tag{
            return true;
        }
    }
    return false;
}

TLB_entry TLB::get_item(int pos){
    reeturn data[pos];
}

//fully associative means the data can be placed in any unused block
void TLB::add_item(TLB_entry new_item){
    //if there is space simply add the item to the cache, else must replace
    if(data.size() < 64){
        data.insert(TLB_entry);
    } else {
        //do a replacement
        TLB_entry temp = this.replace(new_item)
    }
    
}