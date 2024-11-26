#include "wifi.h"

#include <stddef.h>

#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/logging/log.h>
#include <zephyr/net/wifi.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/net_event.h>
#include <zephyr/net/net_mgmt.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/socket.h>

#define API_SERVER "google.com"
#define API_URL "80"

LOG_MODULE_REGISTER(wifi);

static struct k_sem net_cb_sem;
static struct net_mgmt_event_callback mgmt_cb;

static void net_mgmt_event_callback_handler(struct net_mgmt_event_callback *cb,
                                uint32_t mgmt_event,
                                struct net_if *iface)
{
    if(mgmt_event != NET_EVENT_IPV4_ADDR_ADD) {
        return;
    }

    for (int i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {
        char buf[NET_IPV4_ADDR_LEN];

        if (iface->config.ip.ipv4->unicast[i].ipv4.addr_type != NET_ADDR_DHCP) {
            continue;
        }
    }

    k_sem_give(&net_cb_sem);
}

int wifi_connect(const void* ssid, const void* psk)
{
    if ((ssid == NULL) | (psk == NULL)) {
        LOG_ERR("No ssid or psk provided.");
        return 1;
    }

    const char *wifi_ssid = (const char*)ssid;
    const char *wifi_psk = (const char*)psk;

    k_sem_init(&net_cb_sem, 0, 1);

    struct net_if *iface = net_if_get_default();

    if(iface == NULL){
        LOG_ERR("iface is NULL");
        return 1;
    }

    if (net_if_flag_is_set(iface, NET_IF_UP)) {
        LOG_INF("Net if is already up");
    } else {
        uint32_t raised_event;
        const void *info;
        size_t info_len;

        LOG_INF("Waiting for net if being up");
        int ret = net_mgmt_event_wait_on_iface(net_if_get_default(),
						                       NET_EVENT_IF_UP,
                                               &raised_event,
                                               &info,
						                       &info_len,
                                               K_SECONDS(60));

        if (ret != 0) {
            LOG_ERR("Timeout: Net if cannot bring up");
            return 1;
        } else {
            LOG_INF("Netif is up");
        }
    }

    net_mgmt_init_event_callback(&mgmt_cb,
                                 net_mgmt_event_callback_handler,
				                 NET_EVENT_IPV4_ADDR_ADD);

    net_mgmt_add_event_callback(&mgmt_cb);

    struct wifi_connect_req_params wifi_connect_params;
    wifi_connect_params.security = WIFI_SECURITY_TYPE_PSK;
    wifi_connect_params.channel = WIFI_CHANNEL_ANY;
    wifi_connect_params.psk = wifi_psk;
    wifi_connect_params.psk_length = strlen(wifi_connect_params.psk);
    wifi_connect_params.ssid = wifi_ssid;
    wifi_connect_params.ssid_length = strlen(wifi_connect_params.ssid);
    wifi_connect_params.band = WIFI_FREQ_BAND_2_4_GHZ;
    wifi_connect_params.mfp = WIFI_MFP_OPTIONAL;

    if (net_mgmt(NET_REQUEST_WIFI_CONNECT,
                 iface,
                 &wifi_connect_params,
                 sizeof(struct wifi_connect_req_params))) {
        LOG_ERR("Connection failed.");
        return 1;
    } else {
        LOG_INF("Connection requested.");
        k_sem_take(&net_cb_sem, K_FOREVER );
    }

	LOG_INF("Connection successed.");

    struct addrinfo hints, *res;
    int sock;

    LOG_INF("Google HTTP GET test request - google.com:80/\n");
    k_msleep(100);

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int ret = getaddrinfo(API_SERVER, API_URL, &hints, &res);
    LOG_INF("getaddrinfo status: %d\n", ret);
    k_msleep(100);

    if (ret != 0) {
        LOG_INF("Unable to resolve address, quitting\n");
        return 1;
    }

    return 0;
}
