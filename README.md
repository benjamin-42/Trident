# Trident

This exploits the following two CVEs:
* CVE-2016-4655: allow an attacker to obtain sensitive information from kernel memory via a crafted app
* CVE-2016-4656: allow an attacker to execute arbitrary code in a privileged context or cause a denial of service (memory corruption) via a crafted app

CVE-2016-4657 (WebKit exploit) is NOT included despite the name of the project being called *Trident*. Only kernel vulnerabilities are being exploited here.

The objective of the exploit is to gain root access over the device.

At this point it would be possible to jailbreak the device by applying more patches to the kernel (for sandbox, code signing enforcement and more). jk9357 did it and released [Home Depot](http://wall.supplies), a jailbreak based on this exploit.

iOS 9.3.5 is not supported as vulnerabilities have been patched in that version.

Supported devices: see offsetfinder.h

[Guide for finding offsets by angelXwind](https://angelxwind.net/?page/trident-address-tutorial)

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
