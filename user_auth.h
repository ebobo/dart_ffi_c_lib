#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <stdbool.h>

// Api for user authentication and user management

// Function declaration for user authentication
bool am4_access_control_prompt_needed(int argc, char ** argv);
char * am4_access_control_get_current_user(void);

bool am4_access_control_verify_password(const char * username, const char * password);

bool am4_access_control_approve_new_current_user(const char * username);

int am4_access_control_process_timeout(void);
int am4_access_control_process_cancel(void);

// User management

bool am4_access_control_user_have_admin_rights(const char * username);

char * am4_access_control_get_database_file(void);
// Will return empty string "" if password complexity is not met

char * am4_access_control_compute_passwordhash(const char * password);

bool am4_access_control_distribute_database_file(const char * tmpfilename);

bool am4_access_control_lock_database_file(void);
bool am4_access_control_discard_database_lock(void);


// check if password is complex enough
bool isPasswordComplexEnough(const char *password);

#endif // USER_AUTH_H