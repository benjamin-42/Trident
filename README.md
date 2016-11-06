# Trident

Exploitation of:
* CVE-2016-4655: allow an attacker to obtain sensitive information from kernel memory via a crafted app
* CVE-2016-4656: allow an attacker to execute arbitrary code in a privileged context or cause a denial of service (memory corruption) via a crafted app

CVE-2016-4657 (WebKit exploit) is NOT included even if the project is called _Trident_, it is only about kernel vulns here.

The exploit target is iOS 9.3.4 (13G35) for iPad3,1 (32-bit only).
The objective is to gain root access over the device.

At this point it is possible to jailbreak the device, by patching more kernel functions: for sandbox and code signing enforcement.

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