#include "user_auth.h"
#include <assert.h>
#include <stdio.h>

int main() {
    // Test admin user
    assert(get_user_level("admin", "admin123") == 3);

    // Test operational user
    assert(get_user_level("operator", "op123") == 2);

    // Test observation user
    assert(get_user_level("observer", "obs123") == 1);

    // Test invalid user
    assert(get_user_level("unknown", "password") == 0);

    printf("All tests passed!\n");
    return 0;
}