#ifndef KEYHASH_HH_
#define KEYHASH_HH_

#include <cstdint>

static const unsigned long TABLE_SIZE = 127;

typedef unsigned char byte;

size_t get16Bits(byte *d)
{
    return ((uint32_t)(((const byte*)d)[1])<<8)+(((uint32_t)((const byte*)d)[0]));
}

template<typename K>struct KeyHash{
    unsigned long operator()(const K& key) {
        int len = sizeof(key);
        int rem = len&3;
        byte* data = (byte*)&key;
        uint32_t hashv = len,tmp;
        len>>=2;

        for(;len>0;--len){
            hashv+= get16Bits(data);
            tmp = (get16Bits(data+2)<<11)^hashv;
            hashv = (hashv<<16)^tmp;
            data += 2*sizeof(uint16_t);
            hashv +=(hashv>>11);
        }
        switch(rem){
            case 3: hashv += get16Bits(data);
                    hashv ^= (hashv<<16);
                    hashv ^= (signed char)data[sizeof(uint16_t)]<<16;
                    hashv += hashv>>11;
                    break;
            case 2: hashv += get16Bits(data);
                    hashv ^= hashv<<11;
                    hashv ^= hashv>>17;
                    break;
            case 1: hashv += (signed char)*data;
                    hashv ^= hashv<<10;
                    hashv += hashv>>1;
        }
        hashv ^= hashv << 3;
        hashv += hashv >> 5;
        hashv ^= hashv << 4;
        hashv += hashv >> 17;
        hashv ^= hashv << 25;
        hashv += hashv >> 6;
        //unsigned long r = *reinterpret_cast<unsigned long*>((int*)&key);
        return hashv;
    }
};

#endif
