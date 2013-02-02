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
<pre>
>>> dir(br.response())
['__copy__', '__doc__', '__getattr__', '__init__', '__iter__', '__module__', '__repr__', '__setattr__', '_headers', '_seek_wrapper__cache', '_seek_wrapper__have_readline', '_seek_wrapper__is_
closed_state', '_seek_wrapper__pos', '_seek_wrapper__read_complete_state', 'close', 'get_data', 'geturl', 'info', 'invariant', 'next', 'read', 'readline', 'readlines', 'seek', 'set_data', 'te
ll', 'wrapped', 'xreadlines']</pre>
* Review the whole code to make it more clean and more efficient

________________________________________________________________________________

<pre>
**BROWSER**
void init();
void clean();
bool error();
std::string status();
std::string info()
forms_class forms;
forms_class::form_class form;
links_class links;
void select_form(int number_start_from_zero);
void fetch_forms(bool allow);
void fetch_links(bool allow);
void submit(int timeout);
void set_direct_form_post(bool direct,std::string url);
std::string escape(std::string the_string);
std::string unescape(std::string the_string);
void limit_speed(int limit);
void limit_time(int limit);
void set_http_tunel(bool allow);
void set_proxy_login(std::string username, std::string passwd);
void addheaders(std::string headers_to_add[2]);
void adduseragent(std::string theuseragent);
void addheaders(std::string header_to_add,std::string second_header_to_add);
void addheaders(std::map<std::string, std::string> Headers);
void addheaders(std::vector<std::string> Headers);
void open(std::string url, int usertimeout,bool save_history);
void open(std::string url, std::string post_data, int usertimeout);
void open(std::string url, int usertimeout,std::string post_data);
void open_novisit(std::string url, int usertimeout);
void set_handle_redirect(bool allow);
void set_handle_gzip(bool allow);
void set_handle_ssl(bool allow);
void set_verbose(bool allow);
void set_cookie(std::string cookies);
void set_cookiejar(std::string cookiejar);
void set_cookiejar();
void set_dns(std::string dns_server);
void set_proxy(bool allow);
void set_proxy(std::string proxy, std::string type);
void set_interface(std::string interface_name, long int port, long int max_port);
void set_http_version_1_0(bool set_it);
void write_bytes(std::string filename);
std::string getcookies();
void reload();
std::string geturl();
std::string title();
bool intitle(std::string str);
bool inresponse(std::string str);
bool inurl(std::string str);
std::string response();
void head_request(bool allow);
CURL *get_handle();
void close();
void clear_history();
void history();
void back(int timeout);
bool viewing_html();

**links**
std::string url();
std::string name();
std::string title();
std::string target();
std::string all()

**forms**
std::vector <std::string> form_raw_container;
forms_class(std::string whole_html);
forms_class();
~forms_class();
void initialize(std::string whole_html);
std::string all();
int size();
std::vector <form_class> all_forms;
form_class operator[ ]  (int ite);

    **textarea**
    std::string value();
    std::string name();

    **select**
    std::vector <option> options;
    void change_name(std::string new_name);
    std::string name();

        **option**
        bool     selected_;
        bool selected();
        std::string value();

    **input**
    std::string name();
    std::string type();
    std::string value();
    void change_name(std::string new_name);
    void change_type(std::string new_type);
    void change_value(std::string new_value);

    **form**
    std::vector < select_struct > select;
    std::vector < input_struct  > input;
    std::vector <textarea_struct> textarea;
    bool direct_post = false;
    std::map <std::string, std::string> bytes_;
    void bytes(std::string name, std::string content_type="");
    std::string url();
    std::string method();
    bool multipart();
    void clear();
    std::string *operator[ ]  (std::string name);


**regex**
bool remove_html_comment(std::string & html_response);
void remove_html_comments(std::string & html_response);
void lower_it(std::string income, std::string & outcome);
void upper_it(std::string income, std::string & outcome);
bool word_in(std::string the_string, std::string to_search);
std::string get_after_equal(std::string html_response, std::string seeking);
void replaceAll(std::string& str, const std::string& from, const std::string& to);
std::string get_between_two_closed(std::string raw_input,std::string seeking);
void get_between_two(std::string raw_input, std::string seeking, std::vector <std::string> & container);
void get_after_delimiter(std::string html_response, std::string seeking, std::vector <std::string> &form_container);
void get_from_intern(std::string raw_input, std::string word,std::string word2, std::vector <std::string> & container);

</pre>

Examples
--------

* Simply Open a page an check the content: <br>

```c++
#include "Browser.hpp"
#include <iostream>
//set up a browser instance
Browser br;
//use gzip compression
br.set_handle_gzip(true);
//allow browser redirection
br.set_handle_redirect(true);
br.open("http://www.somepage.com");
//you can also set the timeout this way for 10s:
/*
br.open("http://www.somepage.com",10);
*/
//you can even post right away some data this way:
/*
br.open("http://www.somepage.com","datatopost=something");
//or with timeout
br.open("http://www.somepage.com","datatopost=something",10);
//or even this way is possible
br.open("http://www.somepage.com",10,"datatopost=something");
*/
//check some info
std::cout<<br.info()
         <<"\n"
         <<br.status()
         <<"\n"
         <<br.response()
         <<"\n"
         <<br.links().all();
         <<"\n"
         <<br.forms().all();
//you can loop through the links this way:
for(int i=0;i<br.links.size();i++)
    cout<<br.links[i]<<"\n";
//you can loop through the forms this way:
for(int i=0;i<br.forms.size;i++)
    cout<<br.forms[i]<<"\n";
//...and this is just the beginning of how easy it is!
```


