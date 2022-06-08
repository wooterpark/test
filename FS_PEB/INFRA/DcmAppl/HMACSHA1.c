/*
 * HMACSHA1.c
 *
 *  Created on: 2020Äê5ÔÂ8ÈÕ
 *      Author: fujian
 */
/*
 *******************************************************************************
 *                                  Include files
 *******************************************************************************
*/
#include "HAMCSHA1.h"

/*
*******************************************************************************
*                                   Global define
*******************************************************************************
*/

/*           HAMC-K				*/
__u8 K_LV1[K_LENGTH] = {0x12,0x1a,0x3a,0xce,0x58,0x27,0xa3,0xb6};
__u8 K_LV2[K_LENGTH] = {0x12,0x1a,0x3a,0xce,0x48,0x1c,0xe3,0x9e};
__u8 K_LV3[K_LENGTH] = {0x12,0x1a,0x3a,0xce,0x63,0x71,0x7c,0x23};
__u8 K_LV4[K_LENGTH] = {0x12,0x1a,0x3a,0xce,0x8c,0x9e,0xb2,0xa7};

#if defined(rol)
#undef rol
#endif

#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

#define __LITTLE_ENDIAN

#ifdef __LITTLE_ENDIAN
#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00)|(rol(block->l[i],8)&0x00FF00FF))
#else
#define blk0(i) block->l[i]
#endif

#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15]^block->l[(i+2)&15]^block->l[i&15],1))

#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);
/*
*******************************************************************************
*                                    Types
*******************************************************************************
*/
typedef struct
{
	__u32 state[5];			/* constant of SHA1 */
	__u32 count[2];			/* counter */
	__u8  buffer[64];		/* 512-bit message blocks */
} SHA1_CTX;

/*
*******************************************************************************
*                                     Data
*******************************************************************************
*/

/*
*******************************************************************************
*                                  Lacal Data
*******************************************************************************
*/

/*
*******************************************************************************
*                                  Extern Data
*******************************************************************************
*/

/*
*******************************************************************************
*                                  Prototypes
*******************************************************************************
*/
static void* my_memcpy(	void *dest, const void *src, __u32 count);
static void* my_memset(void *ptr,__u8 c,__u32 count);
static __u8 *my_strcpy(__u8 *dst,const __u8 *src);

void SHA1Transform(__u32 state[5], __u8 buffer[64]);
void SHA1Reset(SHA1_CTX *context);
void SHA1Input(SHA1_CTX *context, __u8* data, __u32 len);
void SHA1Result(__u8 digest[20], SHA1_CTX *context);
void SHA1Truncate(__u8* d1,	__u8* d2,__u32 len);
/*
*******************************************************************************
*                               Functions/Classes
*******************************************************************************
*/
/**********************************************************************************************
 * my_memcpy
 **********************************************************************************************/
/*
 *
 * Satic function,use to copy data.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
static void* my_memcpy
(
	void *dest,
	const void *src,
	__u32 count
)
{
	__u8 *tmp = dest;
	const __u8 *s = src;
	while (count--)
	{
		*(__u8 *)dest = *(__u8 *)src;
        dest = (__u8 *)dest + 1;
        src = (__u8 *)src + 1;
	}
	return dest;
}

/**********************************************************************************************
 * my_memset
 **********************************************************************************************/
/*
 *
 * Satic function,use to set memory.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
static void* my_memset
(
	void *ptr,
	__u8 c,
	__u32 count
)
{
    void * tmp = ptr;
    while(count--)
    {
        *(__u8 *)ptr = (__u8)c;
        ptr = (__u8 *)ptr + 1;
    }
    return tmp;
}
/**********************************************************************************************
 * my_strcpy
 **********************************************************************************************/
/*
 *
 * Satic function,use to copy string.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
static __u8 *my_strcpy
(
	__u8 *dst,
	const __u8 *src
)
{
    __u8 *ret = dst;
    while((* dst++ = * src++) != '\0');
    return ret;
}

/**********************************************************************************************
 * SHA1Transform
 **********************************************************************************************/
/*
 *
 * This function use to calculate the SHA1 digest.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void SHA1Transform
(
	__u32 state[5],		/* constants used in SHA1 */
	__u8 buffer[64]		/* data to be hashed */
)
{
	__u32 a, b, c, d, e;
	typedef union {
		__u8 c[64];
		__u32 l[16];
	} CHAR64LONG16;

	CHAR64LONG16* block;

	static __u8 workspace[64];
    block = (CHAR64LONG16*)workspace;
    my_memcpy(block, buffer, 64);

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    /* 80 steps used to calculate SHA1 digest */
    R0(a,b,c,d,e, 0); R0(e,a,b,c,d, 1); R0(d,e,a,b,c, 2); R0(c,d,e,a,b, 3);
    R0(b,c,d,e,a, 4); R0(a,b,c,d,e, 5); R0(e,a,b,c,d, 6); R0(d,e,a,b,c, 7);
    R0(c,d,e,a,b, 8); R0(b,c,d,e,a, 9); R0(a,b,c,d,e,10); R0(e,a,b,c,d,11);
    R0(d,e,a,b,c,12); R0(c,d,e,a,b,13); R0(b,c,d,e,a,14); R0(a,b,c,d,e,15);
    R1(e,a,b,c,d,16); R1(d,e,a,b,c,17); R1(c,d,e,a,b,18); R1(b,c,d,e,a,19);
    R2(a,b,c,d,e,20); R2(e,a,b,c,d,21); R2(d,e,a,b,c,22); R2(c,d,e,a,b,23);
    R2(b,c,d,e,a,24); R2(a,b,c,d,e,25); R2(e,a,b,c,d,26); R2(d,e,a,b,c,27);
    R2(c,d,e,a,b,28); R2(b,c,d,e,a,29); R2(a,b,c,d,e,30); R2(e,a,b,c,d,31);
    R2(d,e,a,b,c,32); R2(c,d,e,a,b,33); R2(b,c,d,e,a,34); R2(a,b,c,d,e,35);
    R2(e,a,b,c,d,36); R2(d,e,a,b,c,37); R2(c,d,e,a,b,38); R2(b,c,d,e,a,39);
    R3(a,b,c,d,e,40); R3(e,a,b,c,d,41); R3(d,e,a,b,c,42); R3(c,d,e,a,b,43);
    R3(b,c,d,e,a,44); R3(a,b,c,d,e,45); R3(e,a,b,c,d,46); R3(d,e,a,b,c,47);
    R3(c,d,e,a,b,48); R3(b,c,d,e,a,49); R3(a,b,c,d,e,50); R3(e,a,b,c,d,51);
    R3(d,e,a,b,c,52); R3(c,d,e,a,b,53); R3(b,c,d,e,a,54); R3(a,b,c,d,e,55);
    R3(e,a,b,c,d,56); R3(d,e,a,b,c,57); R3(c,d,e,a,b,58); R3(b,c,d,e,a,59);
    R4(a,b,c,d,e,60); R4(e,a,b,c,d,61); R4(d,e,a,b,c,62); R4(c,d,e,a,b,63);
    R4(b,c,d,e,a,64); R4(a,b,c,d,e,65); R4(e,a,b,c,d,66); R4(d,e,a,b,c,67);
    R4(c,d,e,a,b,68); R4(b,c,d,e,a,69); R4(a,b,c,d,e,70); R4(e,a,b,c,d,71);
    R4(d,e,a,b,c,72); R4(c,d,e,a,b,73); R4(b,c,d,e,a,74); R4(a,b,c,d,e,75);
    R4(e,a,b,c,d,76); R4(d,e,a,b,c,77); R4(c,d,e,a,b,78); R4(b,c,d,e,a,79);
    /* Return the SHA1 digest */
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    a = b = c = d = e = 0;
}

/**********************************************************************************************
 * SHA1Reset
 **********************************************************************************************/
/*
 *
 * This function will initialize the context in preparation
 * for computing a new SHA1 message digest.
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void SHA1Reset
(
	SHA1_CTX* context	/* SHA1 structure need to reset */
)
{
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
    context->state[4] = 0xC3D2E1F0;
    context->count[0] = context->count[1] = 0;
}
/**********************************************************************************************
 * SHA1Input
 **********************************************************************************************/
/*
 *
 * This function will process the message stored in the "data".
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void SHA1Input
(
	SHA1_CTX* context,		/* result returned from here */
	__u8* data,	/* data to be processed */
	__u32 len				/* data length  */
)
{
	__u32 i, j;

    j = context->count[0];
    if ((context->count[0] += len << 3) < j)
		context->count[1]++;
    context->count[1] += (len>>29);
    j = (j >> 3) & 63;
    if ((j + len) > 63) {
        my_memcpy(&context->buffer[j], data, (i = 64-j));
        SHA1Transform(context->state, context->buffer);
        for ( ; i + 63 < len; i += 64) {
            SHA1Transform(context->state, &data[i]);
        }
        j = 0;
    }
    else i = 0;
    my_memcpy(&context->buffer[j], &data[i], len - i);
}
/**********************************************************************************************
 * SHA1Input
 **********************************************************************************************/
/*
 *
 * Pad the message to 512 bits, and calaulate the SHA1 digest.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void SHA1Result
(
	__u8 digest[20],	/* SHA1 digest  */
	SHA1_CTX* context			/* message need to pad and calculate  */
)
{
	__u32 i, j;
	__u8 finalcount[8];
	/* Pad the message */
    for (i = 0; i < 8; i++) {
        finalcount[i] = (__u8)((context->count[(i >= 4 ? 0 : 1)]
         >> ((3-(i & 3)) * 8) ) & 255);
    }
    SHA1Input(context, (__u8 *)"\200", 1);
    while ((context->count[0] & 504) != 448) {
        SHA1Input(context, (__u8 *)"\0", 1);
    }
    SHA1Input(context, finalcount, 8);
    for (i = 0; i < 20; i++) {
        digest[i] = (__u8)
         ((context->state[i>>2] >> ((3-(i & 3)) * 8) ) & 255);
    }
    /* Wipe variables */
    i = j = 0;
    my_memset(context->buffer, 0x00, 64);
    my_memset(context->state, 0x00, 20);
    my_memset(context->count, 0x00, 8);
    my_memset(&finalcount, 0x00, 8);
	/* Calculate the SHA1 digest */
    SHA1Transform(context->state, context->buffer);
}
/**********************************************************************************************
 * SHA1Truncate
 **********************************************************************************************/
/*
 *
 * This function use to truncate the digest to the length needed.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void SHA1Truncate
(
	__u8* d1,		/* data to be truncated */
	__u8* d2,		/* truncated data */
	__u32 len		/* length in bytes to keep */
)
{
	__u32 i ;
	for (i = 0 ; i < len ; i++)
		d2[i] = d1[i];
}
/**********************************************************************************************
 * HMACSHA1
 **********************************************************************************************/
/*
 *
 * Calculte the HMAC-SHA1 digest.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
void HMACSHA1
(
	__u8* k,		/* data of HMAC-K */
	__u8* d,		/* data to be Hash */
	__u8* out		/* digest output buffer */
)
{
	SHA1_CTX ictx, octx ;
	__u8 isha[SHA_DIGESTSIZE], osha[SHA_DIGESTSIZE] ;
	__u8 buf[SHA_BLOCKSIZE] ;
	__u32 i ;

	/*************** Perform inner SHA1 ******************/
	SHA1Reset(&ictx) ;

	for (i = 0 ; i < K_LENGTH ; ++i)				/* Pad k with ipad */
		buf[i] =  k[i] ^ 0x36 ;
	for (i = K_LENGTH ; i < SHA_BLOCKSIZE ; ++i)
		buf[i] = 0x36 ;

	SHA1Input(&ictx, buf, SHA_BLOCKSIZE) ;			/* start with inner pad */
	SHA1Input(&ictx, d, SEED_LENGTH) ;				/* then text of datagram */
	SHA1Result(isha, &ictx) ;						/* finish up 1st pass */
	/*************** Perform outer SHA1 ******************/
	SHA1Reset(&octx) ;								/* innt context for 1st pass*/

	for (i = 0 ; i < K_LENGTH ; ++i)				/* Pad K with opad */
		buf[i] =  k[i] ^ 0x5C ;
	for (i = K_LENGTH ; i < SHA_BLOCKSIZE ; ++i)
		buf[i] = 0x5C ;

	SHA1Input(&octx, buf, SHA_BLOCKSIZE) ;			/* start with outer pad */
	SHA1Input(&octx, isha, SHA_DIGESTSIZE) ;		/* then results of 1st hash */
	SHA1Result(osha, &octx) ;						/* finish up 2nd pass */

	/*************** Truncate the results ****************/
	SHA1Truncate(osha, out, KEY_LENGTH) ;
}

/**********************************************************************************************
 * main
 **********************************************************************************************/
/*
 *
 * For test.
 *
 *
 * \author     Chen Haizheng/Sun Jia
 *
 * \return
 *
 * \note
 *
 * \history
 *
 **********************************************************************************************/
//__u32 main()
//{
//	__u8 Seed[SEED_LENGTH],Key[KEY_LENGTH];
//
//	my_strcpy(Seed,"Brilliance_auto!");
//
//	HMACSHA1(K_LV1,Seed,Key);
//	/* Key = 0x15 4A ED 59 CF B3 2E DC 37 8D 30 6B 0F 02 AB 6B */
//	HMACSHA1(K_LV2,Seed,Key);
//	/* Key = 0xB4 36 B5 C7 49 AB BC 4D 68 ED DD B6 28 11 66 81 */
//	HMACSHA1(K_LV3,Seed,Key);
//	/* Key = 0x5D 79 E2 D1 14 B6 3C B3 FC 38 07 42 8D 72 03 47 */
//	HMACSHA1(K_LV4,Seed,Key);
//	/* Key = 0x86 8F 07 E6 05 97 88 FA DF E9 FB 35 1B 69 E8 54 */
//	return 0;
//}
/*****************************************************************************
 *                                    E O F
 *****************************************************************************/

