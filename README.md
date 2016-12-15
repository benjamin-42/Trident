# Trident
#### Original by Benjamin Randazzo

This exploits the following two CVEs:
* **CVE-2016-4655:** allow an attacker to obtain sensitive information from kernel memory via a crafted app
* **CVE-2016-4656:** allow an attacker to execute arbitrary code in a privileged context or cause a denial of service (memory corruption) via a crafted app

CVE-2016-4657 (the WebKit exploit) is *not* being exploited despite the name of the project being called *Trident*. Only kernel vulnerabilities are being exploited here.

As of this writing, Trident can elevate its own process's privileges to `root`, but **it does not function as a jailbreak yet.** It is still missing vital jailbreak kernel patches (sandbox, code-signing enforcement, etc.).

iOS 9.3.5 is not supported.

Supported device targets:
* iPhone5,2 (N42AP), iOS 9.2.1 (Dillon 13D15)
* iPhone4,1 (N94AP), iOS 9.3.1 (Eagle 13E238)
* iPhone4,1 (N94AP), iOS 9.3.2 (Frisco 13F69)
* iPhone5,2 (N42AP), iOS 9.3.2 (Frisco 13F69)
* iPhone5,3 (N48AP), iOS 9.3.2 (Frisco 13F69)
* iPhone5,3 (N48AP), iOS 9.3.3 (Genoa 13G34)
* iPad2,1 (K93AP), iOS 9.3.2 (Frisco 13F69)
* iPad2,2 (K94AP), iOS 9.3.2 (Frisco 13F69)
* iPad2,3 (K95AP), iOS 9.3.2 (Frisco 13F69)
* iPad2,4 (K93AAP), iOS 9.3.2 (Frisco 13F69)
* iPad2,3 (K95AP), iOS 9.3.3 (Genoa 13G34)
* iPad3,1 (J1AP), iOS 9.3.4 (Genoa 13G35)
* Want to contribute a device target? [Karen (angelXwind) wrote a tutorial on how to find addresses for Trident.](https://angelxwind.net/?page/trident-address-tutorial)

References:
[Original exploit disclosure by Lookout](http://info.lookout.com/rs/051-ESQ-475/images/lookout-pegasus-technical-analysis.pdf)  
[OS X exploit by jndok](https://jndok.github.io/2016/10/04/pegasus-writeup/)

Thanks: Lookout, Pangu team, i0n1c, jndok, kernelpool, planetbeing, qwertyoruiop, winocm
  
> I could feel  
> it coming back  
> I didn't know  
> was I built to last  
> I've come so far so fast  
> and it feels like a hundred years  
> am I dreaming'  
> is it gonna last  
> I could be  
> better still  
> than anything  
> I've done  
> I know ya think  
> You could do too  
> I know ya think  
> You feel it's true  
> Its the little things in life  
> that I feel