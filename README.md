# [Ctring](http://127.0.0.1:5500/template/) ![Build Status](https://travis-ci.com/ThankfulBird/ctring.svg?branch=master)  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) [![Generic badge](https://img.shields.io/badge/version-v0.1.1-brightgreen.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/size-4.49kB-blueviolet.svg)](https://shields.io/) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity) [![Website shields.io](https://img.shields.io/website-up-down-green-red/http/shields.io.svg)](http://shields.io/)
Ctring is a C library created for string manipulation.
* __Mutable:__ The most robust aspect of this library is its mutability. With this feature, changing a string or adding substrings before or after it is very easy. And this method gives the programmer a lot of flexibility.
* __Brand New Declaration:__ Creating a string in C nowadays can be really complicated without any interface. Ctring deals with this problem in a very delicate way.
* __Miscellaneous and Plenty Functions:__ Reversing a string, finding a substring in another string or even converting uniquely defined string structure to a character array. All of them defined in this minimal yet powerful library.
# Installation
* String can be installed from [MediaFire.](http://www.mediafire.com/file/24zxio83teutlmi/ctring.h/file)   
* Or you can download it [from the website.](http://127.0.0.1:5500/template/).

You can start using library just including it like below:
```c
#include "ctring.h"
```
# Documentation
You can find documentation [on the website.](http://127.0.0.1:5500/template/)

Check out the [Getting Started](http://127.0.0.1:5500/template/introduction.html) for quick review.

The documentation devided into several sections:

* [Getting Started](http://127.0.0.1:5500/template/introduction.html)
* [Structures](http://127.0.0.1:5500/template/structures.html)
* [Functions](http://127.0.0.1:5500/template/functions.html)

You can improve it by sending pull requests to [this repository.](https://github.com/ThankfulBird/ctring)
# Examples
You can find alot of examples in website. Here is the first one to get you started:
```c
#include "ctring.h"

int main(int argc, char const *argv[])
{
  String string = create_string("Hello World!");
  print_string(string);
  return EXIT_SUCCESS;
}
```

This example will print "Hello World!" string on the screen.

You'll notice how easy to create a string only using `create_string` function without struggling all these complex middleware. This is one the most powerful sides of this library. It offers a well-thought abstraction. Without taking any control it gives you ligthweight coding benefit.

## Licence 
Ctring is [GNU Licensed.](https://github.com/ThankfulBird/ctring/blob/master/LICENSE)
