#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/tcp.h>

#define MODULE_NAME "network_analysis"

static struct nf_hook_ops nfho;

// Function to analyze and process incoming packets
static unsigned int analyze_packet(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;

    // Check if the packet is an IPv4 TCP packet
    if (skb && skb->protocol == htons(ETH_P_IP)) {
        ip_header = ip_hdr(skb);
        if (ip_header && ip_header->protocol == IPPROTO_TCP) {
            tcp_header = (struct tcphdr *)((__u32 *)ip_header + ip_header->ihl);
            // Perform packet analysis here
            // For simplicity we will print source and destination IP addresses and ports
            printk(KERN_INFO "[%s] Source: %pI4:%d, Destination: %pI4:%d\n",
                   MODULE_NAME, &ip_header->saddr, ntohs(tcp_header->source),
                   &ip_header->daddr, ntohs(tcp_header->dest));
        }
    }

    return NF_DROP; // Allow the packet to continue processing
}

static int __init network_analysis_init(void) {
    printk(KERN_INFO "[%s] Initializing module\n", MODULE_NAME);

    // Initialize Netfilter hook
    nfho.hook = analyze_packet;
    nfho.hooknum = NF_INET_PRE_ROUTING; // Hook into the pre-routing stage
    nfho.pf = PF_INET; // IPv4 packets
    nfho.priority = NF_IP_PRI_FIRST; // Highest priority

    // Register the Netfilter hook
    nf_register_net_hook(&init_net, &nfho);

    return 0;
}

static void __exit network_analysis_exit(void) {
    printk(KERN_INFO "[%s] Exiting module\n", MODULE_NAME);

    // Unregister the Netfilter hook
    nf_unregister_net_hook(&init_net, &nfho);
}

module_init(network_analysis_init);
module_exit(network_analysis_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gabriel");
MODULE_DESCRIPTION("Simple kernel module for to show case the capabilities of Netfilter hooks in Linux kernel.");
