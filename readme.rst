=============================
Intel(R) C for Metal Compiler
=============================

.. contents::
   :local:
   :depth: 2

Introduction
============

The Intel(R) C for Metal compiler is a open source compiler that implements C for Metal programming language. C for Metal is a new GPU kernel programming language for Intel HD Graphics. 

This document is a starting guide for setting up the development environment, 
building and using this compiler.

License
=======

The Intel(R) C for Metal Compiler is distributed under the MIT license. You may obtain a copy of the License at: https//opensource.org/licenses/MIT

Linux prerequisites
===================

Currently We test our opensource compiler on Centos-7.3 and Ubuntu-16.04.

In order to download and build the compiler, we need the following:

- CMake
- gcc 
- git
- make
- Python

Dependences (Intel Components)
==============================

There is no other dependences in order to build the compiler.

However, in order to build and run those sample applications we provide, the easiest way to get start is to download the development package, which we have uploaded under the release tab of this github project.

Please refer to the readme included in the package for its usage.

Several initial releases of the development packages are still saved on 01.org. 

- Intel(R) C for Metal development package 
  https://01.org/C-for-Metal-development-package/ 

The source code for all the components in the development package are published on github.com/intel. We are planning to publish these scripts soon  (work in progress). 

Building the compiler
=====================

The compiler can be built using the provided script. 

To build the compiler in the default way, but in debug mode (so you get asserts
and you can debug the compiler):

.. code-block:: text

  support/scripts/build.bash -d

The compiler has now been built to a single cmc executable in a build
directory whose name depends on the options to build.bash.
For example, ``build.64.linux/bin/cmc``.

To see the other options available with build.bash, use

.. code-block:: text

  support/scripts/build.bash -h

Running the compiler
====================

.. code-block:: text

  build.64.linux/bin/cmc -isystem support/include test/open_examples/linear_walker/linear_walker_genx.cpp -march=SKL

That will generate a vISA file ``linear_walker_genx.isa`` in the current directory.

See document `cmcuserguide` for more command line options.

Documentation
=============

The formatted documentation starts at

  support/docs/_build/html/index.html

(This path is relative to your cm-compiler root, i.e. where your llvm, support
and test directories are.)

Building and running the examples
=================================

Having installed the C for Metal runtime + driver (from the developement package).  You may use the compiler binary (cmc) you build from source to replace the cmc binary coming with the developement package (under compiler/bin).

You can build and run examples under test/open_examples.

Refer to the readme under test/open_examples.

Building the compiler on Windows
================================

Our build script is written in Bash. Therefore the recommended environment is Windows+Cygwin.

However, besides Cygwin, You also need Windows-native installation of the following:

- Visual Studio (2012 or later)
- CMake (the Windows version)
- Python (the Windows version, installed in c:\\python27)

Cygwin installation and packages
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Go to http://www.cygwin.com/ and install cygwin (64 bit is recommended).

You will probably need to install the following extra Cygwin 
packages during setup. The web site has documentation on how to do this if
you are not familiar with it or can't work it out from the UI.

Basic prerequisites:

- git
- python
- unzip
- curl

Build-command in Cygwin using Visual Studio
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: text

  support/scripts/build.bash -s vs2015 -d -m --32

Supported platforms
===================

Intel Atom and Core processors supporting Gen9/Gen10 graphics device

Submitting and publishing changes
=================================

We welcome contributions to the compiler and the examples, including bug fixes, optimizations, and new features.

You may create a new pull request on github for your code changes. We will review it, test it, and give you our feedback. When the change is finalized, we will push it to the project repository.

For any new example using C for Metal, as long as you have the entire application that can be built and run on either Linux or Windows, you can email it to the maintainer of this project. We can help you customize it, and publish it in our open-example folder.

(*) Other names and brands maybe claimed as property of others.

