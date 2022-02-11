#include "json_info.h"


char                     buffer[1024];
FILE                    *file;

struct json_object      *parsed_Json;
struct json_object      *email;
struct json_object      *password;
struct json_object      *username;


void DefineJson() {
    file = fopen("/home/navin/Desktop/Programming shit i did/Launcher/AuthLauncher/temp/data.json", "r");
    fread(buffer, 1024, 1, file);
    fclose(file);
    
    parsed_Json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_Json, "username", &username);
    json_object_object_get_ex(parsed_Json, "password", &password);
    json_object_object_get_ex(parsed_Json, "email", &email);

}

const char *getUsername() {
    return json_object_get_string(username);
}
const char *getPassword() {
    return json_object_get_string(password);
}
const char *getEmail() {
    return json_object_get_string(email);
}

