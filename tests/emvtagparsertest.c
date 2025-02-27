//###############################################################################
//TODO:
//	Change hash table "value" type to atlv_t instead of char[]
//	Make atlv_t database
//	Make tlv_decode logic
//###############################################################################
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tlv.h>
#include <hashtable.h>
#include <emvTagList.h>


/*Se hace un test con la cadena hexadecimal 6F1A840E315041592E5359532E4444463031A5088801025F2D02656E
cuyo significado es el siguiente:
6F(File Control Information(FCI) Template)
	1A
	84(Dedicated File(DF) Name)
		0E -len
		315041592E5359532E4444463031 - value(1PAY.SYS.DDF01 en hexa)
	A5(File Control information(FCI) Propietary template)
	08-len
		88(Short File Identifier(SFI))
			01- len
			02 -value
		5F2D(language preference)
			02-len
			656E-value
*/
int main(){
	dict_t *dict[HASHSIZE];
	tlvInfo_t *t;
	tlvInfo_t t2;
	int idx = 0;
	int tindex = 0;
	unsigned short size;

	unsigned char test[] = {0x9F,0x26,0x08,0x5D,0x1D,0xDC,0xAF,
							0xF7,0x44,0xB2,0x48,0x9F,0x10,0x07,
							0x06,0x02,0x01,0x03,0xA0,0x08,0x06,
							0x9F,0x37,0x04,0x88,0xC5,0x0F,0x63,
							0x9F,0x36,0x02,0x01,0xE6,0x95,0x05,
							0x00,0x00,0x00,0x00,0x00,0x9A,0x03,
							0x22,0x08,0x15,0x9C,0x01,0x00,0x9F,
							0x02,0x06,0x00,0x00,0x00,0x00,0x10,
							0x00,0x5F,0x2A,0x02,0x02,0x14,0x9F,
							0x1A,0x02,0x02,0x14,0x82,0x02,0x1D,
							0x80,0x9F,0x03,0x06,0x00,0x00,0x00,
							0x00,0x00,0x00,0x5F,0x34,0x01,0x00,
							0x9F,0x27,0x01,0x80,0x9F,0x33,0x03,
							0x00,0x68,0x88,0x9F,0x34,0x03,0x1F,
							0x02,0x02,0x9F,0x35,0x01,0x22,0x84,
							0x08,0xA0,0x00,0x00,0x00,0x25,0x01,
							0x04,0x03,0x9F,0x09,0x02,0x00,0x00,
							0x9F,0x1E,0x08,0x36,0x30,0x33,0x31,
							0x34,0x30,0x36,0x31,0x9F,0x41,0x00,
							0xDF,0x81,0x25,0x06,0xCA,0xFE,0xBA,0xBE,0xFF,0xFF};

	memset(dict, 0, sizeof(dict));
	emvInit(dict);

	addItem(0x9F6E, emvInfo_set(PRIMITIVE, TERMINAL, 0x00, "4", "Enhanced Contactless Reader Capabilities"), dict);

	
	memset(&t2, 0, sizeof(tlvInfo_t));
	t2.tlv.Tag = 0x9F6E;

	emvInfo_get(&t2, &idx, dict);
	printf("%X:[%s] %s", t2.tlv.Tag, t2.RangeLen, t2.Description);

	displayTable(dict);

	

	//unsigned char test[] = { 0x9F,0x41,0x00,0xDF,0x81,0x25,0x06,0xCA,0xFE,0xBA,0xBE,0xFF,0xFF };

	//unsigned char test[] = {0x9F, 0x35, 0x00}; //consulta de tag
	size = sizeof(test)/sizeof(test[0]);
	t = (tlvInfo_t*)malloc(sizeof(tlvInfo_t)*size);
	memset(t, NULL, size);
	tlvInfo_init(t);
	
	emvParse(test, size, t, &tindex , 0, dict);
	emvPrint_result(t, tindex);
	free(t);

	return 0;
}
