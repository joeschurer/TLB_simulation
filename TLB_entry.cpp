#ifndef TLBENTRY_H
#define TLBENTRY_H
#include <string>

//data types here could be optimized
struct TLB_entry{
    std::string tag;
    char access_type;
    int num_accesses = 0; //may use for replacement
};

#endif
