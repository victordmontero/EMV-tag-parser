#ifndef EMVTAGLIST_H
#define EMVTAGLIST_H

#include "hashtable.h"
#include "tlv.h"

#define CONSTRUCTED 1
#define PRIMITIVE 0
#define ISSUER 2
#define ICC 1
#define TERMINAL 0

tlvInfo_t* emvInfo_set(unsigned char PC, unsigned char Source,
	unsigned short Template, unsigned char* RangeLen, unsigned char* Description);

int emvInfo_get(tlvInfo_t* t, int* tindex, dict_t* hashtab[HASHSIZE]);

tlvInfo_t  emvParse(unsigned char arr[], unsigned short size, tlvInfo_t* t, int* tindex, int index, dict_t* hashtab[HASHSIZE]);

void emvPrint_result(tlvInfo_t* t, int tindex);
void emvPrint_resultString(tlvInfo_t* t, int tindex, char* output);

char* emvPrint_tabs(int numTabs);

char* emvPrint_Source(unsigned char source);

void emvInit(dict_t* hashtab[HASHSIZE]);

#endif //EMVTAGLIST_H
