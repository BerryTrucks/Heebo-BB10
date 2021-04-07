#Heebo: [Heebo] for BlackBerry 10

This is a Heebo Port for BlackBerry 10 by [summeli]
Heebo is a simple and addictive “Match 3” game with quirky characters for Harmattan (N9/N950) phones. 

#Build

Setup your blackberry development environment and check to see if you have
your **_author.p12_**, **_bbidtoken.csk_** and **_debugtoken.bar_** in your **_~/.rim_** folder.
Then go your project folder using a terminal emulator and
type **_make_** to build the libraries and then enter this command-

`blackberry-nativepackager -package <package_name>.bar -sign -storepass <your_keystorepass> -configuration Device-Release bar-descriptor.xml`

##License

Heebo is Lincesed under GNU GENERAL PUBLIC LICENSE Version 3
See COPYING for full lisence

-------
[Heebo]: http://gitorious.org/heebo "Heebo Gitorious page"
[summeli]: www.summeli.fi
