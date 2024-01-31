#ifndef SEAD_EXP_HEAP_H_
#define SEAD_EXP_HEAP_H_

#include <heap/seadHeap.h>

namespace sead {

// TODO

class ExpHeap : public Heap
{
public:
    virtual const void* getStartAddress() const;
    virtual const void* getEndAddress() const;
    virtual size_t getSize() const;

public:
    static ExpHeap* tryCreate(u32 size, const SafeString& name, Heap* parent = nullptr, HeapDirection direction = cHeapDirection_Forward, bool enable_lock = false);
};

} // namespace sead

#endif // SEAD_EXP_HEAP_H_
