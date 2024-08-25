/** Test cases for the wrapper around Poly1305 and GMAC
*/

#include "assert.h"
#include "../kem.h"

/**
* Test that the wrapper around Poly1305 is correct.
* This is done by computing the digest of a non-zero message with a zero key, which should produce
* a tag that is all zeros
*/
static int test_mac_poly1305(void) {
    uint8_t key[32];
    for(size_t i = 0; i < sizeof(key); i++) {
        key[i] = 0x00;
    }
    unsigned char msg[] = "Hello, world";
    unsigned char digest[16];
    for(size_t i = 0; i < sizeof(digest); i++) {
        digest[i] = 0xFF;
    }

    mac_poly1305(key, msg, sizeof(msg), digest);
    for(size_t i = 0; i < sizeof(digest); i++) {
        if (digest[i] != 0x00) {
            return 1;
        }
    }
    

    return 0;
}

int main(void) {
    int r = 0;
    r |= test_mac_poly1305();

    if (r) {
        return 1;
    }

    return 0;
}
