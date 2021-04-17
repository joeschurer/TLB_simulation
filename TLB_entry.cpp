#ifndef TLBENTRY_H
#define TLBENTRY_H
#include <string>

//Struct to represent an entry
struct TLB_entry{
    std::string tag;
    char access_type;
    int num_accesses = 0; //may use for replacement
};

#endif
