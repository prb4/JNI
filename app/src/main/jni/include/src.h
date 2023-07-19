/*
#include "command.h"
#include "obfuscation.h"
#include "branding.h"
#include "debug.h"
#include "encryption.h"
#include "exec.h"
#include "http.h"
#include "packing.h"
#include "senders.h"
#include "simpleparser.h"
#include "execHandlers.h"
#include "net.h"
#include "resume.h"
#include "maps.h"
*/
//#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

//#include <undertaker.h>

#ifndef UA_COPY_INT
#define UA_COPY_INT(p_buf,ivar) __builtin_memcpy(&(ivar), (p_buf), sizeof(ivar));
#endif

typedef struct {
    uint8_t* buffer;            // Pointer to HTTP response header & body
    uint8_t* body;              // Start of the HTTP resp body (inside buffer)
    ssize_t content_length;      // Length of `data`
    //we are running into alot of signed/unsigned comparison warnings with this but its a bit late to change
} http_response;


int download_file(const char* method, const char* url, http_response *resp);
//static int handleExec(uint8_t * buffer);
ssize_t getElfSize(char* io);	
//int _handleExec(uint8_t * buffer, size_t sz);
char * helloWrapper(void);

