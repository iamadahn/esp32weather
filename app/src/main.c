#include <stdio.h>
#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/net/wifi.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/net_event.h>
#include <zephyr/net/net_mgmt.h>
#include <zephyr/net/wifi_mgmt.h>

#define WIFI_USER_SSID  "ssid"
#define WIFI_USER_PSK   "psk"

static struct k_sem net_cb_sem;
static struct net_mgmt_event_callback mgmt_cb;

static void
net_handler(struct net_mgmt_event_callback *cb, uint32_t mgmt_event, struct net_if *iface) {
	if (mgmt_event != NET_EVENT_IPV4_ADDR_ADD) {
		return;
	}

	for (int i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {
		char buf[NET_IPV4_ADDR_LEN];

		if (iface->config.ip.ipv4->unicast[i].ipv4.addr_type !=
							NET_ADDR_DHCP) {
			continue;
		}

		printk("   Address[%d]: %s\n", net_if_get_by_iface(iface),
		net_addr_ntop(AF_INET,
		    &iface->config.ip.ipv4->unicast[i].ipv4.address.in_addr,
					  buf, sizeof(buf)));
		k_msleep(100);

		printk("    Subnet[%d]: %s\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
				       &iface->config.ip.ipv4->unicast[i].netmask,
				       buf, sizeof(buf)));
		k_msleep(100);

		printk("    Router[%d]: %s\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
						 &iface->config.ip.ipv4->gw,
						 buf, sizeof(buf)));
		k_msleep(100);

		printk("Lease time[%d]: %u seconds\n", net_if_get_by_iface(iface),
			iface->config.dhcpv4.lease_time);
		k_msleep(100);
	}

	k_sem_give(&net_cb_sem);
}

int
main(void) {
    k_sem_init(&net_cb_sem, 0, 1);

    struct net_if *iface = net_if_get_default();

	if(iface == NULL){
		printk("iface is NULL\n");
		k_msleep(100);
		return false;
	}

	if (net_if_flag_is_set(iface, NET_IF_UP)) {
			printk("Net if is already up\n");
			k_msleep(100);
	} else {
		uint32_t raised_event;
		const void *info;
		size_t info_len;

		printk("Waiting for net if being up\n");
		int ret = net_mgmt_event_wait_on_iface(net_if_get_default(),
						NET_EVENT_IF_UP, &raised_event, &info,
						&info_len, K_SECONDS(60));
		k_msleep(100);

		if (ret != 0) {
			printk("Timeout: Net if cannot bring up\n");
			k_msleep(100);
			return false;
		} else {
			printk("Net if is up\n");
			k_msleep(100);
		}
	}

	net_mgmt_init_event_callback(&mgmt_cb, net_handler,
				     NET_EVENT_IPV4_ADDR_ADD);

	net_mgmt_add_event_callback(&mgmt_cb);

    struct wifi_connect_req_params wifi_connect_params;
    wifi_connect_params.security = WIFI_SECURITY_TYPE_PSK;
    wifi_connect_params.channel = WIFI_CHANNEL_ANY;
    wifi_connect_params.psk = WIFI_USER_PSK;
    wifi_connect_params.psk_length = strlen(wifi_connect_params.psk);
    wifi_connect_params.ssid = WIFI_USER_SSID;
    wifi_connect_params.ssid_length = strlen(wifi_connect_params.ssid);

    if (net_mgmt(NET_REQUEST_WIFI_CONNECT, iface,
			&wifi_connect_params, sizeof(struct wifi_connect_req_params))) {
		printk("Connection failed\n");
		k_msleep(100);
		return false;
	} else {
		printk("Connection requested...\n");
		k_msleep(100);

		k_sem_take(&net_cb_sem, K_FOREVER );
	}

	printk("Connection successed\n");
	k_msleep(100);

    while (true) {
        printk("Zephreertos wifi test: %s\n", CONFIG_BOARD);
        k_msleep(1000);
    }

    return(0);
}
