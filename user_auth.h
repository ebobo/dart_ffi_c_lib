#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <stdbool.h>

// Function declaration
int get_user_level(const char* username, const char* password);

bool am4_access_control_prompt_needed(int argc, char ** argv);
char * am4_access_control_get_current_user(void);
bool am4_access_control_verify_password(char * user, char * password);
bool am4_access_control_approve_new_current_user(char * user);
int am4_access_control_process_timeout(void);
int am4_access_control_process_cancel(void);

#endif // USER_AUTH_H