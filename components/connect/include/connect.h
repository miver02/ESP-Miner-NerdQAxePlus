#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "lwip/sys.h"
#include <arpa/inet.h>
#include <lwip/netdb.h>

#include "freertos/event_groups.h"

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

// enum of wifi statuses
typedef enum
{
    WIFI_CONNECTED,
    WIFI_DISCONNECTED,
    WIFI_CONNECTING,
    WIFI_DISCONNECTING,
    WIFI_CONNECT_FAILED,
    WIFI_RETRYING,
} wifi_status_t;

void wifi_softap_on(void);
void wifi_softap_off(void);
void wifi_init(const char *wifi_ssid, const char *wifi_pass, const char *hostname);
EventBits_t wifi_connect(void);
void generate_ssid(char *ssid);
bool connect_get_ip_addr(char *buf, size_t buf_len);
const char* connect_get_mac_addr();

#ifdef __cplusplus
}
#endif

