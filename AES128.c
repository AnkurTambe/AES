// Name: ANKUR TAMBE    RollNo: 201951025

#include <stdio.h>

static const unsigned __int8 s_box[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

static const unsigned __int8 s_box_inverse[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

static const unsigned __int32 round_constants[] = {
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000,
    0x1b000000, 0x36000000, 0x6c000000, 0xd8000000, 0xab000000, 0xed000000, 0x9a000000};

static const int ROUNDS = 10;

static const int NK = 4;

static const int NB = 4;

unsigned __int8 s_box_sub(unsigned __int8 v)
{
    return s_box[v];
}

unsigned __int8 sub_box_inverse(unsigned __int8 v)
{
    return s_box_inverse[v];
}

unsigned __int32 d_word_swap(unsigned __int32 v)
{
    return (((v & 0x000000FF) << 24) | ((v & 0x0000FF00) << 8) | ((v & 0x00FF0000) >> 8) | ((v & 0xFF000000) >> 24));
}

unsigned __int32 d_word_sub(unsigned __int32 v)
{
    unsigned __int32 x = 0;

    x |= ((unsigned __int32)s_box_sub((unsigned __int8)((v >> 0) & 0xFF))) << 0;
    x |= ((unsigned __int32)s_box_sub((unsigned __int8)((v >> 8) & 0xFF))) << 8;
    x |= ((unsigned __int32)s_box_sub((unsigned __int8)((v >> 16) & 0xFF))) << 16;
    x |= ((unsigned __int32)s_box_sub((unsigned __int8)((v >> 24) & 0xFF))) << 24;

    return x;
}

unsigned __int32 d_word_rot(unsigned __int32 v)
{
    unsigned __int32 x = v;

    return (v >> 8) | ((x & 0xFF) << 24);
}

// key scheduling algorithm
void key_scheduler(unsigned __int8 *key, unsigned __int8 *round)
{
    unsigned __int32 *w = (unsigned __int32 *)round;
    unsigned __int32 t;
    int i = 0;

    do
    {
        w[i] = *((unsigned __int32 *)&key[i * 4 + 0]);
    } while (++i < NK);

    do
    {
        if ((i % NK) == 0)
        {
            t = d_word_rot(w[i - 1]);
            t = d_word_sub(t);
            t = t ^ d_word_swap(round_constants[i / NK - 1]);
        }
        else if (NK > 6 && (i % NK) == 4)
        {
            t = d_word_sub(w[i - 1]);
        }
        else
        {
            t = w[i - 1];
        }
        w[i] = w[i - NK] ^ t;
    } while (++i < NB * (ROUNDS + 1));
}

// round key
void round_key_add(unsigned __int8 *st, unsigned __int8 *round, int nr)
{
    unsigned __int32 *w = (unsigned __int32 *)round;
    unsigned __int32 *s = (unsigned __int32 *)st;
    int i;

    for (i = 0; i < NB; i++)
    {
        s[i] ^= w[nr * NB + i];
    }
}

unsigned __int8 xt(unsigned __int8 x)
{
    return ((x << 1) ^ (((x >> 7) & 1) * 0x1b));
}

unsigned __int8 xts(unsigned __int8 x, int ts)
{
    while (ts-- > 0)
    {
        x = xt(x);
    }

    return x;
}

unsigned __int8 mul(unsigned __int8 x, unsigned __int8 y)
{
    return ((((y >> 0) & 1) * xts(x, 0)) ^ (((y >> 1) & 1) * xts(x, 1)) ^ (((y >> 2) & 1) * xts(x, 2)) ^ (((y >> 3) & 1) * xts(x, 3)) ^ (((y >> 4) & 1) * xts(x, 4)) ^ (((y >> 5) & 1) * xts(x, 5)) ^ (((y >> 6) & 1) * xts(x, 6)) ^ (((y >> 7) & 1) * xts(x, 7)));
}

// sub bytes
void sub_bytes(unsigned __int8 *st)
{
    int i, j;

    for (i = 0; i < NB; i++)
    {
        for (j = 0; j < 4; j++)
        {
            st[i * 4 + j] = s_box_sub(st[i * 4 + j]);
        }
    }
}

// inverse sub bytes
void sub_bytes_inverse(unsigned __int8 *st)
{
    int i, j;

    for (i = 0; i < NB; i++)
    {
        for (j = 0; j < 4; j++)
        {
            st[i * 4 + j] = sub_box_inverse(st[i * 4 + j]);
        }
    }
}

// shift rows
void shift_rows(unsigned __int8 *st)
{
    unsigned __int8 *s = (unsigned __int8 *)st;
    int i, j, r;

    for (i = 1; i < NB; i++)
    {
        for (j = 0; j < i; j++)
        {
            unsigned __int8 x = s[i];
            for (r = 0; r < NB; r++)
            {
                s[i + r * 4] = s[i + (r + 1) * 4];
            }
            s[i + (NB - 1) * 4] = x;
        }
    }
}

// inverse shift rows
void shift_rows_inverse(unsigned __int8 *st)
{
    unsigned __int8 *s = (unsigned __int8 *)st;
    int i, j, r;

    for (i = 1; i < NB; i++)
    {
        for (j = 0; j < NB - i; j++)
        {
            unsigned __int8 x = s[i];
            for (r = 0; r < NB; r++)
            {
                s[i + r * 4] = s[i + (r + 1) * 4];
            }
            s[i + (NB - 1) * 4] = x;
        }
    }
}

// mix coloumn
void mix_col(unsigned __int8 *st)
{
    unsigned __int8 y[16] = {2, 3, 1, 1, 1, 2, 3, 1, 1, 1, 2, 3, 3, 1, 1, 2};
    unsigned __int8 s[4];
    int i, j, r;

    for (i = 0; i < NB; i++)
    {
        for (r = 0; r < 4; r++)
        {
            s[r] = 0;
            for (j = 0; j < 4; j++)
            {
                s[r] = s[r] ^ mul(st[i * 4 + j], y[r * 4 + j]);
            }
        }
        for (r = 0; r < 4; r++)
        {
            st[i * 4 + r] = s[r];
        }
    }
}

// inverse mix column
void mix_col_inverse(unsigned __int8 *st)
{
    unsigned __int8 y[16] = {0x0e, 0x0b, 0x0d, 0x09, 0x09, 0x0e, 0x0b, 0x0d,
                             0x0d, 0x09, 0x0e, 0x0b, 0x0b, 0x0d, 0x09, 0x0e};
    unsigned __int8 s[4];
    int i, j, r;

    for (i = 0; i < NB; i++)
    {
        for (r = 0; r < 4; r++)
        {
            s[r] = 0;
            for (j = 0; j < 4; j++)
            {
                s[r] = s[r] ^ mul(st[i * 4 + j], y[r * 4 + j]);
            }
        }
        for (r = 0; r < 4; r++)
        {
            st[i * 4 + r] = s[r];
        }
    }
}

// function for printing data
void print_it(char *message, unsigned __int8 *info, int length)
{
    int i;

    printf("%8.8s: ", message);
    for (i = 0; i < length; i++)
    {
        printf(" %2.2x", info[i]);
    }
}

// function for aes encryption
int enc_func(unsigned __int8 *info, int length, unsigned __int8 *key)
{
    unsigned __int8 w[4 * 4 * 15] = {0};
    unsigned __int8 s[4 * 4] = {0};

    int nr, i, j;

    key_scheduler(key, w);

    for (i = 0; i < length; i += 4 * NB)
    {
        for (j = 0; j < 4 * NB; j++)
            s[j] = info[i + j];

        for (nr = 0; nr <= ROUNDS; nr++)
        {
            if (nr > 0)
            {

                sub_bytes(s);

                shift_rows(s);

                if (nr < ROUNDS)
                {
                    mix_col(s);
                }
            }

            round_key_add(s, w, nr);
        }

        for (j = 0; j < 4 * NB; j++)
            info[i + j] = s[j];
    }

    return 0;
}

// function for aes decrytion
int dec_func(unsigned __int8 *info, int length, unsigned __int8 *key)
{
    unsigned __int8 w[4 * 4 * 15] = {0};
    unsigned __int8 s[4 * 4] = {0};

    int nr, i, j;
    key_scheduler(key, w);

    for (i = 0; i < length; i += 4 * NB)
    {

        for (j = 0; j < 4 * NB; j++)
            s[j] = info[i + j];

        for (nr = ROUNDS; nr >= 0; nr--)
        {

            round_key_add(s, w, nr);

            if (nr > 0)
            {

                if (nr < ROUNDS)
                {
                    mix_col_inverse(s);
                }
                shift_rows_inverse(s);
                sub_bytes_inverse(s);
            }
        }

        for (j = 0; j < 4 * NB; j++)
            info[i + j] = s[j];
    }

    return 0;
}

void main()
{
    printf("\n\n");

    // taking input for the plaintext as char array
    char plain[17];
    unsigned __int8 plaintext[16];
    printf("Give plain1:\n");
    scanf(" %[^\n]", plain);
    // converting from char array to hex
    for (int i = 0; i < 16; i++)
    {
        plaintext[i] = (unsigned __int8)plain[i];
    }
    print_it("plain", plaintext, sizeof(plaintext));
    printf("\n\n");

    // taking input for the first key as char arrray
    char ke1[17];
    unsigned __int8 key1[16];
    printf("Give key1:\n");
    scanf(" %[^\n]", ke1);
    // converting from char array to hex
    for (int i = 0; i < 16; i++)
    {
        key1[i] = (unsigned __int8)ke1[i];
    }
    print_it("key1", key1, sizeof(key1));
    printf("\n\n");

    // taking a random key as second key
    char ke2[17] = {"ankurnagsentambe"};
    unsigned __int8 key2[16];
    printf("Random key2- ankurnagsentambe:\n");
    // converting from char array to hex
    for (int i = 0; i < 16; i++)
        key2[i] = (unsigned __int8)ke2[i];
    print_it("key2", key2, sizeof(key2));

    // encryption of plaintext using first key, we get ciphered text
    printf("\n\nAES128 enc_func using (plain,key1):\n");
    print_it("plain", plaintext, sizeof(plaintext));
    printf("\n");
    print_it("key1", key1, sizeof(key1));
    enc_func(plaintext, sizeof(plaintext), key1);
    printf("\nthis will give us the ciphered text-\n");
    print_it("ciphered", plaintext, sizeof(plaintext));

    // decryption of ciphered text using second key, we get second pre image
    printf("\n\nAES128 dec_func using (ciphered,key2):\n");
    print_it("ciphered", plaintext, sizeof(plaintext));
    printf("\n");
    print_it("key2", key2, sizeof(key2));
    dec_func(plaintext, sizeof(plaintext), key2);
    printf("\nthis will give us the second pre image-\n");
    print_it("2ndimg", plaintext, sizeof(plaintext));

    // encryption of second pre image using second key, we get back ciphered text
    printf("\n\nAES128 enc_func using (2ndimg,key2):\n");
    print_it("2ndimg", plaintext, sizeof(plaintext));
    printf("\n");
    print_it("key2", key2, sizeof(key2));
    enc_func(plaintext, sizeof(plaintext), key2);
    printf("\nthis will give us the compressed values-\n");
    print_it("ciphered", plaintext, sizeof(plaintext));

    printf("\n\n");
}