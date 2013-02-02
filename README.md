Browser
=======

License (unixhub)
-----------------

    Copyright (c) 2013, Patrick Louis <patrick@unixhub.net>

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

        1.  The author is informed of the use of his/her code. The author does not have to consent to the use; however he/she must be informed.
        2.  If the author wishes to know when his/her code is being used, it the duty of the author to provide a current email address at the top of his/her code, above or included in the copyright statement.
        3.  The author can opt out of being contacted, by not providing a form of contact in the copyright statement.
        4.  If any portion of the author’s code is used, credit must be given.
                a. For example, if the author’s code is being modified and/or redistributed in the form of a closed-source binary program, then the end user must still be made somehow aware that the author’s work has contributed to that program.
                b. If the code is being modified and/or redistributed in the form of code to be compiled, then the author’s name in the copyright statement is sufficient.
        5.  The following copyright statement must be included at the beginning of the code, regardless of binary form or source code form.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    Except as contained in this notice, the name of a copyright holder shall not
    be used in advertising or otherwise to promote the sale, use or other dealings
    in this Software without prior written authorization of the copyright holder.

About
-----

Inspired by the python library **mechanize.Browser** <br>
A Simple to use yet efficient headers only library (wrapped over **libcurl** / **curl** wrapper) to emulate a browser in C++.
It helps and simplify web interaction. <br>
All the regex are written by hand reducing the dependencies to one library: libcurl; which is pretty small. <br>
Keep in mind that this is really **alpha**. <br>

Why
---

I made this library to make it easier to translate my python script that use mechanize.Browser into C++. Without this library the process to do what I normally do in python is a huge pain. <br>
I might soon write the whole the cheat sheet of the equivalence of the python mechanize.Browser into the C++ Browser. <br>
You can take a look at this example of the python library called mechanize.Browser() which inspired me http://stockrt.github.com/p/emulating-a-browser-in-python-with-mechanize/ , imagine doing a simple thing like that in C++ and that's what the library does. <br>

Missing
-------

* Nice Error handling (to not make the browser suddenly crash in case of errors)
* proxy auth type and http auth type for this: http://user:password@www.example.com
* ssl 3.0 and tls 1.0 same as a real browser but might add dependencies
* threaded ssl openssl gnuTLS
* br.follow_link()
* br.encoding() for utf-8 and others
* curl_multi   using this for multiple handle at the same time and pipelining
* check the $(curl-config --feature) to know with which feature the cULR library was built
* change br.response into a class like in python: <br>
>>> dir(br.response())
['__copy__', '__doc__', '__getattr__', '__init__', '__iter__', '__module__', '__repr__', '__setattr__', '_headers', '_seek_wrapper__cache', '_seek_wrapper__have_readline', '_seek_wrapper__is_
closed_state', '_seek_wrapper__pos', '_seek_wrapper__read_complete_state', 'close', 'get_data', 'geturl', 'info', 'invariant', 'next', 'read', 'readline', 'readlines', 'seek', 'set_data', 'te
ll', 'wrapped', 'xreadlines']