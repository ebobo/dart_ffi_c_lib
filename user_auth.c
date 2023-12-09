#include <string.h>

// Function to determine user level based on username and password
int get_user_level(const char* username, const char* password) {
    // Example hardcoded users
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        return 3; // Admin level
    } else if (strcmp(username, "operator") == 0 && strcmp(password, "op123") == 0) {
        return 2; // Operational user
    } else if (strcmp(username, "observer") == 0 && strcmp(password, "obs123") == 0) {
        return 1; // Observation user
    }

    return 0; // User not found or wrong credentials
}
